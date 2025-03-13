#ifndef __bpe_h__
#define __bpe_h__

#include <unordered_set>

namespace bpe {

class Text;
using Token = uint16_t;

class BPE {
public:
  BPE(Text &text);
  void encode();

private:
  void analyze();

private:
  Text &text;
  Token current_tok = 1;
  std::unordered_set<Token> vocab;
};

} // namespace bpe

#endif