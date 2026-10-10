struct Obj {
    char pad0[0x3E8];
    int stream;
    char pad3EC[0x10];
    int thread;
    int sema;
};

extern "C" int func_005ADCE0(int sema);
extern "C" int func_005ADCC0(int sema);
extern "C" int func_005ADBD0(int thread);
extern "C" unsigned int func_0054FEA8(int stream);
extern "C" unsigned int func_0054FE98(void);

extern "C" void func_0054E340(Obj *o) {
    func_005ADCE0(o->sema);
    if (o->thread != -1) {
        unsigned int used = func_0054FEA8(o->stream);
        int pct = used * 10 / func_0054FE98();
        if (pct >= 9) {
            func_005ADBD0(o->thread);
            o->thread = -1;
        }
    }
    func_005ADCC0(o->sema);
}
