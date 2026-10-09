typedef int s32;
typedef unsigned char u8;

struct Obj {
    char pad[0x24];
    s32 unk24;
};

extern "C" void func_005F8AD8(struct Obj *arg0, u8 arg1) {
    arg0->unk24 = (arg0->unk24 & ~0xFF) | arg1;
}
