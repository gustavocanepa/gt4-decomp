typedef unsigned int u32;

struct S { char pad[0x98]; u32 unk98; };

extern "C" u32 func_002662A0(S *arg0) {
    return arg0->unk98 >> 31;
}
