typedef unsigned char u8;
typedef unsigned long long u64;

struct Obj { char pad[0x9C]; u8 unk9C; };

extern "C" u64 func_00266428(Obj *arg0) {
    u64 v = arg0->unk9C;
    return v >> 7;
}
