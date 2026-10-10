struct Found {
    int a;
    int index;
    int c;
    int d;
};

extern "C" Found func_0045B368(void *table, void *key, void *type);
extern "C" void func_003E92A8(void *a, void *b, void *c);
extern char D_0069F320[];

extern "C" void func_0033A4F8(void *key, void *table, void *a, void *c)
{
    Found f = func_0045B368(table, key, D_0069F320);
    if (f.index >= 0)
        func_003E92A8(a, key, c);
}
