struct S { char pad[0x1c]; unsigned char f[0x80]; };
int func_0047D0E8(struct S *s, unsigned i) {
    if (i >= 0x80) return 0;
    return s->f[i] & 1;
}
