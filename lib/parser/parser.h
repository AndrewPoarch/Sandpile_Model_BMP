#pragma once

#include <fstream>
#include <cinttypes>
#include <iostream>
#include <cstring>


struct Arguments {
  const char* input;
  const char* output;
  int64_t iteration;
  int64_t frequency;

  Arguments() {
    input = nullptr;
    output = nullptr;
    iteration = 0;
    frequency = 0;
  }
};

Arguments ParseArguments(int& argc, char**& argv);
