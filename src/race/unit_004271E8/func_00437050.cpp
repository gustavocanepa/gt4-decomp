typedef int s32;

struct Obj {
    char pad[0x112C];
    s32 unk112C;
};

extern char D_00846360[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_00437050(struct Obj *arg0) {
    func_0057B1A8(D_00846360, arg0->unk112C);
}
