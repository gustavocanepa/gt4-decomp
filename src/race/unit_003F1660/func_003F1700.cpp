typedef unsigned char u8;

extern u8 D_006224A8;

struct Obj {
    char pad[0x1B8];
    u8 unk1B8;
};

extern "C" void func_003F1700(struct Obj *arg0) {
    if (D_006224A8 != 0) {
        arg0->unk1B8 = arg0->unk1B8 & 0xC0;
        return;
    }
    arg0->unk1B8 = 0;
}
