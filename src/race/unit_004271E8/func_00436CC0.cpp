typedef int s32;

struct Obj {
    char pad[0x10B0];
    s32 unk10B0;
};

extern char D_00846358[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_00436CC0(struct Obj *arg0) {
    func_0057B1A8(D_00846358, arg0->unk10B0);
}
