extern "C" void *D_006187A8;
extern "C" char D_0068E430[];

extern "C" void *func_00127A68(void) {
    void *v = D_006187A8;
    if (v == 0) {
        return D_0068E430;
    }
    return (char *)v + 0x3C8;
}
