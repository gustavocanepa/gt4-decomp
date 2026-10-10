struct R { int pad; int pad1; int f; };
void func_003A35F0(struct R *s, int x) {
    if ((unsigned)(x + 0x1FFFFFE) > 0x3FFFFFDu) x = 0x1FFFFFF;
    s->f = x;
}
