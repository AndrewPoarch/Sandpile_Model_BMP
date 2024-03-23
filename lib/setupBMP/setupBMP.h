#include "../sandpile/sandpile.h"
#include "../parser/parser.h"

#include <filesystem>

struct BMP {
  static const int file_header_size = 14;
  static const int information_header_size = 40;
  static const int palette_size = 20;
  int file_size;
  uint16_t m_width;
  uint16_t m_height;
  static int file_counter;

  BMP(uint16_t height, uint16_t width) {
    m_width = width;
    m_height = height;
    file_size = file_header_size + information_header_size + palette_size
        + (m_height * m_width);
  }
  void Export(const char* output, uint64_t** field) const;
};
