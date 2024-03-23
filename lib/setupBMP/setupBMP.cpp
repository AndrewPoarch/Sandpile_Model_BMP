#include "setupBMP.h"

int BMP::file_counter = 1;
const char* postfix = ".bmp";

int CountPadding(int m_width) {
  return (4 - ((m_width / 2 + m_width % 2)  % 4)) % 4;
}

void BMP::Export(const char* output, uint64_t** field) const {
  std::filesystem::path filename = output;
  char num_char[10];
  std::sprintf(num_char, "%d", file_counter);
  filename += num_char;
  filename += postfix;

  std::ofstream file(filename, std::ios::out | std::ios::binary);

  if (!file.is_open()) {
    std::cerr << "File could not be opened\n";
    return;
  }
  unsigned char file_header[file_header_size];
  for (int i = 0; i < file_header_size; ++i) {
    file_header[i] = 0;
  }
  file_header[0] = 'B';
  file_header[1] = 'M';
  file_header[2] = file_size;
  file_header[3] = file_size >> 8;
  file_header[4] = file_size >> 16;
  file_header[5] = file_size >> 24;
  file_header[10] = file_header_size + information_header_size + palette_size;

  unsigned char information_header[information_header_size];
  for (int i = 0; i < information_header_size; ++i) {
    information_header[i] = 0;
  }
  information_header[0] = information_header_size;
  information_header[4] = m_width;
  information_header[5] = m_width >> 8;
  information_header[6] = m_width >> 16;
  information_header[7] = m_width >> 24;
  information_header[8] = m_height;
  information_header[9] = m_height >> 8;
  information_header[10] = m_height >> 16;
  information_header[11] = m_height >> 24;

  information_header[12] = 1;
  information_header[14] = 4; // bits per pixel
  information_header[32] = 5;

  file.write(reinterpret_cast<char*>(file_header), file_header_size);
  file.write(reinterpret_cast<char*>(information_header), information_header_size);

  unsigned char white[] = {0xff, 0xff, 0xff, 0};
  unsigned char green[] = {0, 0xff, 0, 0};
  unsigned char yellow[] = {0, 0xff, 0xff, 0};
  unsigned char purple[] = {0xff, 0x00, 0xff, 0};
  unsigned char black[] = {0x22, 0x22, 0x22, 0};

  file.write(reinterpret_cast<char*>(white), 4);
  file.write(reinterpret_cast<char*>(green), 4);
  file.write(reinterpret_cast<char*>(yellow), 4);
  file.write(reinterpret_cast<char*>(purple), 4);
  file.write(reinterpret_cast<char*>(black), 4);

  for (int i = m_height - 1; i >= 0; --i) {

    for (int j = 0; j < m_width; ++j) {
      uint8_t pixels = 0;
      if (j + 1 < m_width) {
        pixels += (field[i][j] << 4);
        pixels += (field[i][j + 1]);
        ++j;
      } else {
        pixels += (field[i][j] << 4);
      }
      file << pixels;
    }
    for (int k = 0; k < CountPadding(m_width); ++k) {
      file << 0;
    }
  }
  ++file_counter;
  file.close();
}
