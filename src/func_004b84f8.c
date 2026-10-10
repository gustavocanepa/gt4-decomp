struct S { char pad[0x858]; int idx; };
int func_004B84F8(struct S *s) {
    char *e = (char *)s + s->idx * 0x41C;
    return *(int *)(e + 0x438);
}
