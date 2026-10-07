typedef int s32;
typedef short s16;
typedef unsigned char u8;

struct Sub {
    char pad[0x654];
    s32 unk654;
    s16 unk658;
    u8 unk65A;
};

extern "C" void func_00366388(char *arg0) {
    Sub *p = (Sub *)(arg0 + 0x104);
    p->unk65A = 0;
    p->unk658 = 0;
    p->unk654 = 0;
}
