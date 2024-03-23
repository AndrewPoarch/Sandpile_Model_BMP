#include "sandpile.h"

void Sandpile::AddToRight() {
  ++width;
  uint64_t** new_field = new uint64_t* [height];
  for (int16_t i = 0; i < height; ++i) {
    new_field[i] = new uint64_t [width] {};
  }
  for (int16_t i = 0; i < height; ++i) {
    for (int16_t j = 0; j < width - 1; ++j) {
      new_field[i][j] = field[i][j];
    }
  }
  for (int16_t i = 0; i < height; ++i) {
    delete[] field[i];
  }
  delete[] field;
  field = new_field;
}

void Sandpile::AddToBottom() {
  ++height;
  uint64_t** new_field = new uint64_t* [height];
  for (int16_t i = 0; i < height; ++i) {
    new_field[i] = new uint64_t [width] {};
  }
  for (int16_t i = 0; i < height - 1; ++i) {
    for (int16_t j = 0; j < width; ++j) {
      new_field[i][j] = field[i][j];
    }
  }
  for (int16_t i = 0; i < height - 1; ++i) {
    delete[] field[i];
  }
  delete[] field;
  field = new_field;
}

void Sandpile::AddToTop() {
  ++height;
  uint64_t** new_field = new uint64_t* [height];
  for (int16_t i = 0; i < height; ++i) {
    new_field[i] = new uint64_t [width] {};
  }
  for (int16_t i = 0; i < height - 1; ++i) {
    for (int16_t j = 0; j < width; ++j) {
      new_field[i + 1][j] = field[i][j];
    }
  }
  for (int16_t i = 0; i < height - 1; ++i) {
    delete[] field[i];
  }
  delete[] field;
  field = new_field;
}

void Sandpile::AddToLeft() {
  ++width;
  uint64_t** new_field = new uint64_t* [height];
  for (int16_t i = 0; i < height; ++i) {
    new_field[i] = new uint64_t [width] {};
  }
  for (int16_t i = 0; i < height; ++i) {
    for (int16_t j = 0; j < width - 1; ++j) {
      new_field[i][j + 1] = field[i][j];
    }
  }
  for (int16_t i = 0; i < height; ++i) {
    delete[] field[i];
  }
  delete[] field;
  field = new_field;
}
