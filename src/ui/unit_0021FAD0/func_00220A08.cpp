typedef int s32;

struct Obj_00220A08 {
    char pad[8];
    s32 unk8;
};

extern "C" void func_001062B8(void *arg0);
extern "C" char D_006184D0[];

extern "C" void func_00220A08(Obj_00220A08 *arg0) {
    if (arg0->unk8 > 0) {
        return;
    }
    return func_001062B8(D_006184D0);
}
