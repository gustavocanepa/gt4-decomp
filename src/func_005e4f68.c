struct E { int a[4]; };
extern void func_002030E8(struct E *, int);
void func_005E4F68(struct E *first, struct E *last, int x) {
    for (; first != last; ++first) func_002030E8(first, x);
}
