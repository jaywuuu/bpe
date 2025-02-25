#ifndef __bpe_h__
#define __bpe_h__

namespace bpe {

class Text;

class BPE {
public:
  BPE(Text &text);

private:
  Text &text;
};

} // namespace bpe

#endif