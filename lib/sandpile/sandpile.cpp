#include "sandpile.h"
#include "../setupBMP/setupBMP.h"

bool Sandpile::Topple() {
  bool is_ready = true;
  for (int i = 0; i < height; ++i) {
    for (int j = 0; j < width; ++j) {
      if (field[i][j] < 4) {
        continue;
      }
      is_ready = false;
      short padding_left = 0;
      short padding_top = 0;
      if (i + 1 >= height) {
        AddToBottom();
      }
      if (j + 1 >= width) {
        AddToRight();
      }
      if (i - 1 < 0) {
        AddToTop();
        padding_top = 1;
      }
      if (j - 1 < 0) {
        AddToLeft();
        padding_left = 1;
      }
      ++field[i - 1 + padding_top][j + padding_left];
      ++field[i + 1 + padding_top][j + padding_left];
      ++field[i + padding_top][j - 1 + padding_left];
      ++field[i + padding_top][j + 1 + padding_left];
      field[i + padding_top][j + padding_left] -= 4;
    }
  }

  return is_ready;
}
