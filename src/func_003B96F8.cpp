typedef int s32;

struct Obj {
    char pad[0x6C];
    s32 unk6C;
};

extern "C" void func_00388880();
extern "C" void func_00394A98(void *arg0, s32 arg1);

extern "C" void func_003B96F8(Obj *arg0) {
    Obj *s0 = arg0;
    func_00388880();
    func_00394A98((char *)s0 + 0x22708, s0->unk6C);
}
