typedef short s16;

void func_00346080(void *, int);

void func_005F4A38(void *self, s16 *cur, s16 *target) {
    func_00346080(self, *target - *cur);
    *cur = *target;
}
