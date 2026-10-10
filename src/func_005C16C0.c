/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libgcc2.c-style __terminate (noreturn call through the terminate hook) glued to the
   following eh helper that returns &(*get_eh_context())->field at +8. */
typedef void (*vfp)(void);

extern vfp D_00659A24 __attribute__((__noreturn__));
extern void **func_005BC6E8(void);

void func_005C16C0(void) {
    (*D_00659A24)();
}

void *func_005C16D8(void) {
    return (char *)*func_005BC6E8() + 8;
}
