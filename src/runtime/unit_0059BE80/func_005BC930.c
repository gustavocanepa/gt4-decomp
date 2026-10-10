/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of libgcc.a (libgcc2.c, config/fp-bit.c or frame.c), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef void (*Func)(void);

extern Func D_00659970;
extern int D_00659974;

void func_005BC710(void);
void func_005BC930(void);
void func_005BC998(void);

void func_005BC930(void)
{
    Func *entry = &D_00659970;

    if (*entry == func_005BC930)
        *entry = func_005BC998;
    if (D_00659974 == 0)
        func_005BC710();
    (*entry)();
}
