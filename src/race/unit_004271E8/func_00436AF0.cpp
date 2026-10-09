typedef int s32;

struct Obj {
    char pad[0x10F8];
    s32 unk10F8;
};

extern char D_00846348[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_00436AF0(struct Obj *arg0) {
    func_0057B1A8(D_00846348, arg0->unk10F8);
}
