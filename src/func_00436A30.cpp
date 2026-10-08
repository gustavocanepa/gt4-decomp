typedef int s32;

struct Obj {
    char pad[0x10E4];
    s32 unk10E4;
};

extern char D_00846340[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_00436A30(struct Obj *arg0) {
    func_0057B1A8(D_00846340, arg0->unk10E4);
}
