/* compiler: ee-gcc2.96-nosib */
typedef long long s64;

extern "C" void func_00444690(void *self, s64 v);
extern "C" void func_00444480(void *self, s64 v);

extern "C" void func_00444440(void *self, s64 v) {
    if ((v >> 32) == 0x26) {
        func_00444690(self, v);
    } else {
        func_00444480(self, v);
    }
}
