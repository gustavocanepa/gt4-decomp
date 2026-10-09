typedef int s32;
typedef unsigned char u8;

struct Sub {
    char pad[0x18];
    s32 unk18;
};

struct Obj {
    char pad[0xAD0];
    struct Sub sub;
};

extern "C" void RaceOnboardPanel__virtual_21(struct Obj *arg0, u8 arg1) {
    struct Sub *p = &arg0->sub;

    p->unk18 = (p->unk18 & ~0xFF) | arg1;
}
