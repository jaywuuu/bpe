#include <iostream>

#include "bpe.h"
#include "text.h"

using namespace bpe;

int main(int argc, char *argv[]) {
  std::cout << "BPE\n";

  TextString text("This is some text.");
  std::cout << text << std::endl;

  TextFile file("../tests/fromFile.txt");
  std::cout << file << std::endl;
}