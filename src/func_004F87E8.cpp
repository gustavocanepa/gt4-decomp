typedef int s32;

struct S004F87E8 {
    char pad0[0x170];
    s32 unk170;
};

extern "C" void func_004F8790(struct S004F87E8 *arg0);

extern "C" void func_004F87E8(struct S004F87E8 *arg0, s32 arg1) {
    func_004F8790(arg0);
    arg0->unk170 = arg1;
}
