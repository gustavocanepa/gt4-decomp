/* compiler: ee-gcc2.96-as2004 */
struct Gains {
    float a[2];
    float b[2];
    float c[4];
    float d[4];
    int e[4];
};

extern "C" void func_003F92D0(Gains *g)
{
    int i;
    for (i = 0; i < 2; i++) {
        g->a[i] = 1.0f;
        g->b[i] = 1.0f;
    }
    for (i = 0; i < 4; i++) {
        g->c[i] = 1.0f;
        g->d[i] = 1.0f;
        g->e[i] = 0;
    }
}
