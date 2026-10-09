typedef int s32;

extern "C" void *D_006187A8;
extern "C" char D_0068E430[];

extern "C" void *func_00127B38(void *arg0, s32 arg1) {
    void *v = D_006187A8;
    if (v == 0) {
        return D_0068E430;
    }
    return (char *)v + (arg1 << 7) + 4;
}
