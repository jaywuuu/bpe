
#include "bpe.h"
#include "text.h"

namespace bpe {

BPE::BPE(Text &text) : text(text) {}

void BPE::encode() { analyze(); }

void BPE::analyze() {}

} // namespace bpe