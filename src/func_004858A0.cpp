typedef int s32;

extern char D_00688B40[];

extern "C" void *func_00574D78(void *self);

struct Obj {
    char pad0[0x30];
    s32 unk30;
    s32 unk34;
    s32 unk38;
    void *vtbl;
    Obj() __asm__("func_004858A0");
};

Obj::Obj() {
    vtbl = D_00688B40;
    func_00574D78(this);
    unk30 = 0;
    unk34 = 0;
    unk38 = 0;
}
