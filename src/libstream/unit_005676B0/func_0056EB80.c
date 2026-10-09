typedef int s32;
s32 func_0057F260(s32);
void func_005A609C(s32, s32);
struct B { char pad[0x30]; s32 size; };

s32 func_0056EB80(struct B *b, s32 base, s32 off, s32 s) {
    s32 n;
    s32 avail = b->size - off * 4;
    if (s == 0) return 0;
    n = func_0057F260(s) + 1;
    if (n < 0 || avail < n) return -0x21F;
    func_005A609C(base + off * 4, s);
    return n;
}
