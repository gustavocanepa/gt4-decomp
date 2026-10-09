typedef int s32;

struct Obj_001FD4F8 {
    char pad[0xB4];
    s32 unkB4;
    char pad2[0xDC - 0xB8];
    s32 unkDC;
};

extern "C" void func_0054E1D0(s32 arg0);

extern "C" void func_001FD4F8(Obj_001FD4F8 *arg0) {
    func_0054E1D0(arg0->unkB4);
    arg0->unkDC = 0;
}
