struct A;
struct B;

extern A *D_00624980;
extern B *D_00624984;

extern "C" void func_004901D0(A *a);
extern "C" void func_00490200(B *b);
extern "C" void func_005C1628(void *p);

extern "C" void func_0048FA40(void) {
    A *a = D_00624980;
    if (a != 0) {
        D_00624980 = 0;
        func_004901D0(a);
        func_005C1628(a);
    }
    B *b = D_00624984;
    if (b != 0) {
        D_00624984 = 0;
        func_00490200(b);
        func_005C1628(b);
    }
}
