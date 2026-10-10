struct S { char pad[0xFC]; int f; };
extern "C" void func_002C93C0(S *, int, int);
extern "C" int func_002C95B8(S *s, int b) {
    if (s->f != 0) {
        func_002C93C0(s, b, 1);
        return 2;
    }
    return 0;
}
