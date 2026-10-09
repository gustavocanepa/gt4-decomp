typedef int s32;

struct Obj {
    char pad[0x8];
    s32 unk8;
};

extern "C" void func_00500CB8(s32 arg0, struct Obj *arg1);

extern "C" void func_004F7118(struct Obj *arg0) {
    func_00500CB8(arg0->unk8, arg0);
}
