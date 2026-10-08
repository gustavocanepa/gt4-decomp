typedef int s32;

struct Obj {
    char pad[0x1114];
    s32 unk1114;
};

extern char D_00846370[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_00437200(struct Obj *arg0) {
    func_0057B1A8(D_00846370, arg0->unk1114);
}
