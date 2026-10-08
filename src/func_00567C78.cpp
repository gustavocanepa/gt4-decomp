typedef void (*FnPtr)(void);

struct Obj {
    char pad0[0x14];
    FnPtr unk14;
};

extern "C" void func_00567C78(struct Obj *arg0) {
    arg0->unk14();
}
