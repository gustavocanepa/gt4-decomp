typedef int s32;

extern char D_00845C40[];

struct Obj {
    char pad[4];
    s32 unk4;
};

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_0042FB60(struct Obj *arg0) {
    func_0057B1A8(D_00845C40, arg0->unk4);
}
