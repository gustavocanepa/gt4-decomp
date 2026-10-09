extern "C" void type_info__virtual_00(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *__array_type_info__vtable;

extern "C" void __array_type_info__virtual_00(void *arg0, int arg1) {
    *(void **)((char *)arg0 + 0x4) = &__array_type_info__vtable;
    type_info__virtual_00(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
