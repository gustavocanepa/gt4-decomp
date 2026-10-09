typedef unsigned char u8;
typedef int s32;

struct Obj {
    char pad[8];
    s32 unk8;
};

extern "C" u8 func_003BACE0(Obj *arg0, s32 arg1) {
    u8 r = *((u8 *)arg0 + 9);
    if (arg1 != 0) {
        arg0->unk8 = arg0->unk8 & 0xFFFF00FF;
    }
    return r;
}
