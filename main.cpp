#include "lib/parser/parser.h"
#include "lib/sandpile/sandpile.h"
#include "lib/setupBMP/setupBMP.h"


int main(int argc, char** argv) {
  Arguments arguments = ParseArguments(argc, argv);
  Sandpile sandpile = Sandpile();
  sandpile.ParseTsv(arguments.input);
  if (arguments.iteration == 0) {
    arguments.iteration = INT64_MAX;
  }
  int64_t count = 0;
  while (arguments.iteration > 0) {
    if (sandpile.Topple())
      break;
    ++count;
    if (count % arguments.frequency == 0) {
      BMP file = BMP(sandpile.height, sandpile.width);
      file.Export(arguments.output, sandpile.field);
    }
    --arguments.iteration;
  }
  BMP file = BMP(sandpile.height, sandpile.width);
  file.Export(arguments.output, sandpile.field);

  for (int i = 0; i < sandpile.height; ++i) {
    delete[] sandpile.field[i];
  }
  delete[] sandpile.field;

  return 0;
}
