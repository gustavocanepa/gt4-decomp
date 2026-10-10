extern unsigned func_00539528(void);
unsigned func_00528940(unsigned n) {
    unsigned r;
    do { r = func_00539528() % n; } while (r == 0);
    return r;
}
