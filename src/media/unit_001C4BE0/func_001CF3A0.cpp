typedef unsigned short u16;
typedef signed char s8;

struct Obj {
    char pad0[0x48];
    u16 unk48;
    char pad48[0x141 - 0x4A];
    s8 unk141;
};

extern "C" s8 func_001CF3A0(struct Obj *arg0) {
    u16 flag = arg0->unk48 & 1;
    if ((flag & 0xFFFF) == 0) {
        return -1;
    }
    return arg0->unk141;
}
