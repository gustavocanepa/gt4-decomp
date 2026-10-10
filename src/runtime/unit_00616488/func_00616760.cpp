struct B0 { int a; B0(int v) { a = v; } virtual ~B0(); };
struct __si_type_info__vtable : B0 {
    int c;
    __si_type_info__vtable(int x, int y);
    virtual ~__si_type_info__vtable();
};
__si_type_info__vtable::__si_type_info__vtable(int x, int y) : B0(x) {
    c = y;
}
