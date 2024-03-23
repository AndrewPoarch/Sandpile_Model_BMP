#pragma once

#include "../parser/parser.h"

#include <fstream>
#include <cinttypes>
#include <iostream>
#include <cstring>

struct Sandpile {
  int16_t width;
  int16_t height;
  int16_t min_width;
  int16_t min_height;
  uint64_t** field;

  Sandpile() {
    width = INT16_MIN;
    height = INT16_MIN;
    min_width = INT16_MAX;
    min_height = INT16_MAX;
  }
  bool Topple();

  void ParseTsv(const char* filename);

  void AddToLeft();

  void AddToRight();

  void AddToTop();

  void AddToBottom();
};
