typedef int s32;

struct Obj {
    char pad[0x114C];
    s32 unk114C;
};

extern char D_00846388[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_00437320(struct Obj *arg0) {
    func_0057B1A8(D_00846388, arg0->unk114C);
}
