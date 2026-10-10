struct Req {
    int f0;
    int busy;
    int f8;
};

extern "C" Req D_0086DD80[];
extern "C" void func_0054C788(void *arg);
extern "C" void func_0054C1F0(int ch, int a, int b, int d, int c, void (*cb)(void *), void *arg);

extern "C" void func_0054C8A0(int ch, int a, int b, int c, int d) {
    Req *r = &D_0086DD80[ch];
    r->busy = 1;
    func_0054C1F0(ch, a, b, d, c, func_0054C788, r);
}
