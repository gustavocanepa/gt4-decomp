typedef int s32;

struct Obj {
    char pad[0x2C];
    s32 unk2C;
    s32 unk30;
};

extern "C" void func_002CDAA0(struct Obj *arg0) {
    arg0->unk2C = arg0->unk2C ^ 1;
    arg0->unk30 = arg0->unk30 ^ 1;
}
