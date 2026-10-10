struct R { char d[0x30]; };
struct S { int a; struct R *tbl; };
float func_0034A888(char *t) {
    char *b = *(char **)(t + 4) + *(unsigned char *)(t + 0x544) * 0x30;
    return *(float *)(b + 0xCAE4);
}
