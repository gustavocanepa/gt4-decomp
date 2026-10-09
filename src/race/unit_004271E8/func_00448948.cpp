typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x11];
    u8 unk11;
};

extern "C" s32 func_00448948(Obj *arg0) {
    return arg0->unk11 >= 0x64;
}
