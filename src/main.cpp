#include <exception>
#include <iostream>
#include <string>

#include "bpe.h"
#include "text.h"

using namespace bpe;

enum class InType : int { file = 0, string };

struct Params {
  std::string in;
  InType inType;
};

Params process_command_line_args(int argc, char *argv[]) {
  Params p;

  if (argc <= 1) {
    return p;
  }

  auto check_input_args = [&](size_t i) -> void {
    if (p.in.size()) {
      throw std::runtime_error(
          "Invalid command line arguments.  Input already defined.");
    }
    if (i + 1 >= argc) {
      throw std::runtime_error("Invalid command line arguments.  Not enough "
                               "arguments for specifying inputs.");
    }
  };

  for (int i = 0; i < argc; ++i) {
    std::string arg(argv[i]);
    if (arg == "--file") {
      check_input_args(i);
      std::string file(argv[i + 1]);
      p.in = file;
      p.inType = InType::file;
    } else if (arg == "--string") {
      check_input_args(i);
      std::string str(argv[i + 1]);
      p.in = str;
      p.inType = InType::string;
    }
  }

  return p;
}

int main(int argc, char *argv[]) {
  std::cout << "BPE\n";
  std::unique_ptr<Text> text;
  try {
    Params p = process_command_line_args(argc, argv);
    switch (p.inType) {
    case InType::file: {
      text = std::make_unique<TextFile>(p.in);
      break;
    }
    case InType::string: {
      text = std::make_unique<TextString>(p.in);
      break;
    }
    }
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 0;
  }

  BPE bpe(*text);

  return 0;
}