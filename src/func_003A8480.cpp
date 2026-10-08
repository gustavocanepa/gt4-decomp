typedef int s32;
typedef unsigned char u8;

struct Sub {
    s32 unk0;
};

struct Obj {
    char pad[0x290];
    struct Sub sub;
};

extern "C" void func_003A8480(struct Obj *arg0, u8 arg1) {
    struct Sub *p = &arg0->sub;

    p->unk0 = (p->unk0 & ~0xFF) | arg1;
}
