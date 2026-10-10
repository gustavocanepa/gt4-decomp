extern int D_0086F610;
extern "C" int func_005B72A8(void); /* lock */
extern "C" void func_005B72F8(void); /* unlock */
extern "C" void func_005ADBC0(void); /* yield */

extern "C" void func_0054DAB8(void) {
    int *busy = &D_0086F610;
    func_005B72A8();
    while (*busy) {
        func_005B72F8();
        func_005ADBC0();
        func_005B72A8();
    }
    return func_005B72F8();
}
