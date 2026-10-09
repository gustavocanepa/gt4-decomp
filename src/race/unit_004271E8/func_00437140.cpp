typedef int s32;

struct Obj {
    char pad[0x110C];
    s32 unk110C;
};

extern char D_00846368[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_00437140(struct Obj *arg0) {
    func_0057B1A8(D_00846368, arg0->unk110C);
}
