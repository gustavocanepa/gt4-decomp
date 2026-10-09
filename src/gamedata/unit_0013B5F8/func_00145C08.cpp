typedef int s32;

struct Obj {
    char pad0[0x14];
    void *unk14;
};

extern "C" s32 func_00441248(void *arg0);
extern "C" s32 func_00445808(s32 arg0);

extern "C" void func_00145C08(Obj *arg0) {
    func_00445808(func_00441248(arg0->unk14));
}
