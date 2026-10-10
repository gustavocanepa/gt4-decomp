typedef int s32;

struct List;

extern List D_00621F58;
extern char D_00621F78[];

extern "C" s32 *func_003ED848(char *, s32 *);
extern "C" s32 *func_00463908(List *arg0, s32 *arg1);

extern "C" s32 *func_003EDA90(s32 *arg0) {
    if (arg0 != 0) {
        arg0 = func_003ED848(D_00621F78, arg0);
        if (arg0 != 0)
            arg0 = func_00463908(&D_00621F58, arg0);
    }
    return arg0;
}
