/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): a function of libgcc.a (libgcc2.c, config/fp-bit.c or frame.c), in libgcc.a's code at 0x5ba060-0x5c1ce0.
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
typedef void (*FuncPtr)(void);

extern "C" void func_005BCA00(void);

extern FuncPtr D_00659970;

extern "C" void func_005BC918(void) {
    D_00659970 = func_005BCA00;
}
