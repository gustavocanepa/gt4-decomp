typedef int s32;

typedef s32 (*FnPtr)(void);
extern FnPtr D_00659970;

extern "C" s32 func_005BC6E8(void) {
    return D_00659970() + 8;
}
