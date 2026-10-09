static inline void relocate(int *field, int base)
{
    if (*field) *field += base;
}
void func_00485CA8(int *p, int base)
{
    relocate(&p[0], base);
    relocate(&p[1], base);
}
