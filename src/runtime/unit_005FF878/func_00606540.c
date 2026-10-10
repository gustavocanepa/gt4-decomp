void *func_006065A0(void);
void *func_00606540(void) {
    char *t = func_006065A0();
    *(void **)(t + 0xEC) = t;
    *(void **)(t + 0xE8) = t;
    return t;
}
