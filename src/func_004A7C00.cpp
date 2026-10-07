typedef int s32;
typedef unsigned char u8;

struct Dev {
    char pad[0x138];
    volatile u8 unk138;
    volatile u8 unk139;
    volatile u8 unk13A;
};

extern "C" s32 func_004A7C00(void) {
    struct Dev *p = (struct Dev *)0x70002000;
    s32 b = p->unk139;
    s32 c = p->unk13A;
    s32 a = p->unk138;
    return a | (b << 8) | (c << 0x10);
}
