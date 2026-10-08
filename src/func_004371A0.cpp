typedef int s32;

struct Obj {
    char pad[0x117C];
    s32 unk117C;
};

extern char D_00846368[];

extern "C" void func_0057B1A8(void *arg0, s32 arg1);

extern "C" void func_004371A0(struct Obj *arg0) {
    func_0057B1A8(D_00846368, arg0->unk117C);
}
