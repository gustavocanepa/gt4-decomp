typedef int s32;

struct Obj {
    char pad0[0x5C];
    s32 unk5C;
    s32 unk60;
};

extern "C" void func_00345B90(struct Obj *arg0, s32 arg1, s32 arg2);

extern "C" void func_00346890(struct Obj *arg0, s32 arg1) {
    s32 temp_a1 = arg0->unk5C + (arg1 << 16);
    arg0->unk60 = temp_a1;
    func_00345B90((struct Obj *)((char *)arg0 + 8), temp_a1 + 0x14F4, 0xEB04);
}
