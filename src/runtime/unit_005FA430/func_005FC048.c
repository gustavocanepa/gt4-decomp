void *func_005FCAA0(void);
void *func_005FC048(void) {
    char *t = func_005FCAA0();
    *(void **)(t + 0xAC) = t;
    *(void **)(t + 0xA8) = t;
    return t;
}
