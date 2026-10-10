/* compiler: ee-gcc2.96-no-strict-aliasing */
/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __do_global_dtors (libgcc2.c).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* The function's own statics (p = __DTOR_LIST__ + 1, completed) live in its .data and are
 * reached through their addresses; __EH_FRAME_BEGIN__ is 0x006D3E00. */
typedef void (*func_ptr)(void);

extern func_ptr *D_00659964;
extern int D_00659968;
extern char D_006D3E00[];
extern void *func_005BED78(void *begin);

void func_005BC438(void) {
    while (*D_00659964) {
        D_00659964++;
        (*(D_00659964 - 1))();
    }
    if (!D_00659968) {
        D_00659968 = 1;
        func_005BED78(D_006D3E00);
    }
}
