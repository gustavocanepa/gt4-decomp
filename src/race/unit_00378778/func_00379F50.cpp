typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x27C];
    s32 unk27C;
    char pad2[0x28C - 0x27C - 4];
    f32 unk28C;
    char pad3[0x294 - 0x28C - 4];
    s32 unk294;
};

extern "C" void func_00379F50(Obj *arg0, s32 arg1, f32 fparg0) {
    arg0->unk294 = arg1;
    arg0->unk28C = fparg0;
    arg0->unk27C = 2;
}
