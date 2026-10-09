typedef int s32;

extern s32 D_0064D260;
extern s32 D_0064D25C;
extern s32 D_00873560;

extern "C" void func_00578500(s32 arg0);
extern "C" void func_00557E68(s32 arg0, s32 arg1);
extern "C" void func_00578480(s32 arg0);

void func_005588F0(s32 arg0)
{
    if (D_0064D260 != 0) {
        if (D_00873560 != 0) {
            func_00578500(D_0064D25C);
            func_00557E68(D_00873560, arg0);
            func_00578480(D_0064D25C);
        }
    }
}
