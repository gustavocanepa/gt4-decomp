typedef int s32;

struct List;

extern List D_00621F58;

extern "C" void func_00463908(List *arg0, s32 *arg1);

extern "C" void func_003EDA10(s32 *arg0) {
    if (arg0 != 0) {
        func_00463908(&D_00621F58, arg0);
    }
}
