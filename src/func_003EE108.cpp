typedef int s32;

struct Inner_003870B8 {
    char pad0[0xDC];
    s32 unkDC;
};

struct Obj_003870B8 {
    char pad0[0x6C];
    Inner_003870B8 *unk6C;
};

extern "C" void func_00109830(void);

extern "C" void func_003EE108(Obj_003870B8 *arg0) {
    if (arg0->unk6C->unkDC == 0) {
        func_00109830();
    }
}
