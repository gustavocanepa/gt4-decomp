/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __get_dynamic_handler_chain? (libgcc2.c).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef int s32;

typedef s32 (*FnPtr)(void);
extern FnPtr D_00659970;

extern "C" s32 func_005BCBF8(void) {
    return D_00659970() + 0x4;
}
