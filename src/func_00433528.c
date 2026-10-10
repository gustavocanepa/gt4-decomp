struct E { int a, b; float c; int pad[9]; };
float func_00433528(struct E *t, unsigned i) {
    struct E *e;
    if (i < 10u) { e = &t[i]; return e->c; }
    return 0.0f;
}
