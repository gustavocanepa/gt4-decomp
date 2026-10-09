typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Arg1 {
    char pad[5];
    u8 unk5;
    u16 unk6;
};

struct Arg0 {
    s32 unk0;
    s32 unk4;
};

extern "C" s32 func_005599D0(Arg0 *arg0, Arg1 *arg1) {
    return (((arg1->unk5 << 0x10) | arg1->unk6) << arg0->unk0) + arg0->unk4;
}
