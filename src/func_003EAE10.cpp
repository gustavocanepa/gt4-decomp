typedef int s32;

struct Obj {
    char pad[0x958];
    s32 unk958;
};

extern "C" void func_003893C0(void *arg0);

extern "C" void func_003EAE10(void *arg0, struct Obj *arg1) {
    func_003893C0(arg0);
    arg1->unk958 = 1;
}
