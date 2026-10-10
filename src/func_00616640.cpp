struct Obj {
    int m0;
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual int v3(int n, int a, char *begin, char *end);
    int check(int n, int a, char *begin, char *end) __asm__("func_00616640");
};

int Obj::check(int n, int a, char *begin, char *end) {
    if (n >= 0)
        return (end - begin) == n ? 6 : 1;
    if (n == -2)
        return 1;
    return v3(n, a, begin, end);
}
