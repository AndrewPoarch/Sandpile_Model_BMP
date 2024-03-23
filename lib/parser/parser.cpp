#include "parser.h"

const char* kOutput = "--output";
const char* kInput = "--input";
const char* kIterations = "--max-iter";
const char* kFrequency = "--freq";

const size_t kLengthOfOut = strlen(kOutput);
const size_t kLengthOfIn = strlen(kInput);
const size_t kLengthOfIter = strlen(kIterations);
const size_t kLengthOfFreq = strlen(kFrequency);

Arguments ParseArguments(int& argc, char**& argv) {
  Arguments arguments = Arguments();
  for (int i = 1; i < argc; ++i) {
    if (i + 1 >= argc) {
      std::cerr << "No value found for " << argv[i];
      break;
    }
    if (!strncmp(argv[i], kOutput, kLengthOfOut) || !strcmp(argv[i], "-o")) {
      arguments.output = argv[i + 1];
      ++i;
    } else if (!strncmp(argv[i], kInput, kLengthOfIn) || !strcmp(argv[i], "-i")) {
      arguments.input = argv[i + 1];
      ++i;
    } else if (!strncmp(argv[i], kIterations, kLengthOfIter) || !strcmp(argv[i], "-m")) {
      arguments.iteration = std::stoll(argv[i + 1]);
      ++i;
    } else if (!strncmp(argv[i], kFrequency, kLengthOfFreq) || !strcmp(argv[i], "-f")) {
      arguments.frequency = std::stoll(argv[i + 1]);
      ++i;
    }
  }

  return arguments;
}
