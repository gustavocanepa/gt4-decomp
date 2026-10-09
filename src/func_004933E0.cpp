typedef int s32;

extern "C" char D_00491FC0[];
extern "C" char D_00492198[];

extern "C" s32 func_00492EF0(s32 arg0, void *arg1, void *arg2, s32 arg3);

extern "C" s32 func_004933E0(s32 arg0, s32 arg1, s32 arg2) {
    return func_00492EF0(arg0, D_00491FC0, D_00492198, arg2);
}
