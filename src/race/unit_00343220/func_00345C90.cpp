typedef unsigned long long u64;

extern "C" u64 func_0057AD58(void *bits, int count);

extern "C" int func_00345C90(void *bits) {
    int n = 0;
    while (func_0057AD58(bits, 1))
        n++;
    return (int)func_0057AD58(bits, n) + (1 << n);
}
