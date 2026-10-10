/* compiler: ee-gcc2.96-nsa-nosib */
extern char D_00654D40[];
extern void func_00576788(void *);
extern void func_005767C0(void *);
extern void func_00577F80(void);
extern int func_0058D4C8(void);

void func_005621C0(void) {
    func_00576788(D_00654D40);
    while (func_0058D4C8() != 0)
        func_00577F80();
    func_005767C0(D_00654D40);
}
