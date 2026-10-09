typedef float f32;
typedef int s32;

struct Obj {
    char pad[0x24];
    f32 unk24;
    char pad2[0xC];
    s32 unk34;
};

extern "C" void func_002CDB08(Obj *arg0, f32 fparg0) {
    arg0->unk24 = fparg0;
    arg0->unk34 = 1;
}
