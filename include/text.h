#ifndef __text_h__
#define __text_h__

#include <ostream>
#include <string>
#include <vector>

namespace bpe {

class Text {
protected:
  Text() = default;

public:
  void print(std::ostream &os) const;

protected:
  std::vector<uint8_t> data;
};

class TextFile : public Text {
public:
  TextFile(const std::string &file);
};

class TextString : public Text {
public:
  TextString(const std::string &text);
};

std::ostream &operator<<(std::ostream &os, const Text &text);

} // namespace bpe

#endif
