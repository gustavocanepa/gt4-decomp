typedef int s32;

struct Obj {
    char pad[0x958];
    s32 unk958;
};

extern "C" void func_00389268(void *arg0);

extern "C" void func_003EACE8(void *arg0, struct Obj *arg1) {
    func_00389268(arg0);
    arg1->unk958 = 1;
}
