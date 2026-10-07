typedef unsigned int u32;
typedef unsigned char u8;

struct S { char pad[0x789]; u8 unk789; };

extern "C" u32 func_0035C838(S *arg0) {
    return arg0->unk789 >> 4;
}
