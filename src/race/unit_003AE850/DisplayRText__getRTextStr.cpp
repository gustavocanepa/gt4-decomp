typedef int s32;

extern char D_00621880[];
extern s32 D_00621888;

extern "C" s32 func_00485FF0(void *arg0, s32 arg1, s32 arg2);

extern "C" s32 DisplayRText__getRTextStr(s32 arg0) {
    return func_00485FF0(D_00621880, D_00621888, arg0);
}
