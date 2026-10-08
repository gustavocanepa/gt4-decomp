typedef int s32;

struct Obj {
    char pad[0x80];
    s32 unk80;
};

extern "C" void func_00370548(Obj *arg0, void *arg1, s32 arg2);

extern "C" void func_00370928(Obj *arg0) {
    func_00370548(arg0, (char *)arg0 + 0x60, arg0->unk80);
}
