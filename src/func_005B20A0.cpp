/* compiler: ee-gcc2.9-991111 */
extern "C" void *func_005B1E80(void *);
extern "C" void func_005B1ED8(void *);
extern "C" void func_005ADBC0(void);

extern "C" void func_005B20A0(void *self) {
    for (;;) {
        void *e;
        while ((e = func_005B1E80(self)) != 0) {
            func_005B1ED8(e);
        }
        func_005ADBC0();
    }
}
