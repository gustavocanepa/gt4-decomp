/* compiler: ee-gcc2.9-991111 */
struct Entry { int w[4]; };
extern void func_005B20E0(void);
extern int func_005ADCE0(int sema);
extern int func_005ADCC0(int sema);
extern int D_00658348;
extern struct Entry D_008897C0[];

struct Entry *func_005B2348(unsigned int n)
{
    struct Entry *e;
    func_005B20E0();
    func_005ADCE0(D_00658348);
    if (n >= 32) {
        func_005ADCC0(D_00658348);
        return 0;
    }
    e = &D_008897C0[n];
    func_005ADCC0(D_00658348);
    return e;
}
