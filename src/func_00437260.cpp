typedef int s32;

struct Obj {
    char pad[0x1118];
    s32 unk1118;
};

extern "C" void func_0057B1A8(s32 arg0, s32 arg1);
extern char D_00846378[];

extern "C" void func_00437260(Obj *arg0) {
    func_0057B1A8((s32)D_00846378, arg0->unk1118);
}
