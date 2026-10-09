typedef int s32;

struct S005CD068 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" void func_005A609C(s32 arg0);

extern "C" void func_005CD068(struct S005CD068 *arg0) {
    func_005A609C(arg0->unk10 + 0x138C);
}
