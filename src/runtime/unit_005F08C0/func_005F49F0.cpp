extern "C" void func_00346080(void *self, int delta);

extern "C" void func_005F49F0(void *self, signed char *cur, signed char *next) {
    func_00346080(self, *next - *cur);
    *cur = *next;
}
