#include "parser.h"
#include "../sandpile/sandpile.h"

void Sandpile::ParseTsv(const char* filename) {
  std::ifstream data(filename);
  if (!data.is_open()) {
    std::cerr << "No correct filename found...." << '\n';
    exit(EXIT_FAILURE);
  }
  int16_t x, y;
  int64_t value;
  while (data >> x >> y >> value) {
    width = std::max(width, x);
    height = std::max(height, y);
    min_width = std::min(min_width, x);
    min_height = std::min(min_height, y);
  }
  data.close();

  height = height - min_height + 1;
  width = width - min_width + 1;

  field = new uint64_t* [height] {};
  for (int i = 0; i < height; ++i) {
    field[i] = new uint64_t [width] {};
  }

  std::ifstream file(filename);
  while (file >> x >> y >> value) {
    field[y - min_height][x - min_width] = value;
  }
}
