typedef int s32;
typedef unsigned long long u64;

struct Obj { char pad[0x98]; s32 unk98; };

extern "C" u64 func_00266128(Obj *arg0) {
    u64 v = arg0->unk98;
    v = v >> 2;
    return v & 1;
}
