typedef void (*FnPtr)(void *arg0);

struct Obj00567C98 {
    char pad0[0x20];
    FnPtr unk20;
};

extern "C" void func_00567C98(struct Obj00567C98 *arg0) {
    arg0->unk20(arg0);
}
