typedef int s32;
typedef unsigned short u16;

struct Dev {
    char pad[0x4A];
    volatile u16 unk4A;
};

extern "C" s32 func_004A5BE0(s32 arg0) {
    struct Dev *p = (struct Dev *)0x70002000;
    return p->unk4A | arg0;
}
