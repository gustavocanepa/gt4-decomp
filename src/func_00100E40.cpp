typedef int s32;

extern "C" s32 D_00617CB0;
extern char D_00100EE0[];

extern "C" void func_00109580(s32 arg0, void *arg1);

extern "C" void func_00100E40(s32 arg0) {
    if (D_00617CB0 == 0) {
        func_00109580(arg0, D_00100EE0);
    }
}
