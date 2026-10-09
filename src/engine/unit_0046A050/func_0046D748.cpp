typedef int s32;

struct Obj {
    s32 unk0;
    s32 unk4;
    char pad[0xAA4 - 8];
    s32 unkAA4;
};

extern "C" void func_0046D748(Obj *arg0) {
    s32 val = arg0->unkAA4;
    s32 result = 0;
    arg0->unk4 = 1;
    if (val < 3) {
        result = 0 < val;
    }
    arg0->unk0 = result;
}
