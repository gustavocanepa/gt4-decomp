/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): the type_info function of libio's class iostream (compiler-generated from its declaration).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef struct {
    int inited;
} Module_00614CB0;

extern Module_00614CB0 D_008A1C10;
extern char D_006CF808[];
extern char D_006CF818[];

void func_00614108(void);
void func_00614570(void);
void func_005BFB40(Module_00614CB0 *m, const char *a, const char *b, int n);

Module_00614CB0 *func_00614CB0(void) {
    if (D_008A1C10.inited == 0) {
        func_00614108();
        func_00614570();
        func_005BFB40(&D_008A1C10, D_006CF808, D_006CF818, 2);
    }
    return &D_008A1C10;
}
