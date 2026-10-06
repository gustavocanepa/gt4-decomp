Known facts about Gran Turismo 4's code (learned while matching; add new ones as they are found):
- Game code is C++; old g++ ABI. Virtual calls look like: vtbl = *(obj+k); entry = vtbl + 8*i;
  delta = (short)entry[0]; fn = entry[4]; fn(obj + delta, ...). Write them in C style with a
  struct VEntry { short delta; short index; R (*fn)(...); }.
- Strings keep their length 16 bytes before the text.
- sqrt is inline asm: __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)).
- Numbers may be stored as full-width EUC digits (0xA3B0 + digit).
- Constructors: `r = base_ctor(self); self->vtbl = D_xxxxxxxx; return r;` (vtable pointer often
  at offset 4, after the first member).
