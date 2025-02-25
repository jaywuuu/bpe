
#include "text.h"

#include <exception>
#include <fstream>
#include <sstream>

namespace bpe {

void Text::print(std::ostream &os) const {
  for (const auto v : data) {
    os << v;
  }
}

TextFile::TextFile(const std::string &file) {
  std::ifstream in(file);
  if (!in.is_open()) {
    throw std::runtime_error("Cannot open file: " + file);
  }

  std::string line;
  std::stringstream ss;
  while (std::getline(in, line)) {
    ss << line << std::endl;
  }

  auto text = ss.str();
  if (text.size()) {
    data = std::vector<uint8_t>(text.begin(), text.end());
  }
}

TextString::TextString(const std::string &text) {
  if (text.size() != 0) {
    data = std::vector<uint8_t>(text.begin(), text.end());
  }
}

std::ostream &operator<<(std::ostream &os, const Text &text) {
  text.print(os);
  return os;
}

} // namespace bpe