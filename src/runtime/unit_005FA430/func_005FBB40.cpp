typedef int s32;

extern "C" s32 func_003B7668(void *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" s32 func_005FBB40(char *arg0, s32 arg1, s32 arg2) {
    return func_003B7668(arg0 + 0xF4, arg1, arg2, 0);
}
