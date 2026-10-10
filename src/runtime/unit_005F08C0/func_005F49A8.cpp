/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;

extern "C" void func_00346080(void *, int);

extern "C" void func_005F49A8(void *self, u8 *cur, u8 *next) {
    func_00346080(self, *next - *cur);
    *cur = *next;
}
