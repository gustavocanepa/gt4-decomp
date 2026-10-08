typedef int s32;

struct Handle {
    void *p;
    char pad[0xC];
};

extern "C" void func_002D8AB0(void *arg0, int arg1);
extern "C" void func_002D8B08(void *arg0, void *arg1);
extern "C" void func_002DB080(void *arg0, void *arg1, char *arg2);
extern "C" void func_0022ACC8(void *arg0, int arg1);
extern "C" void func_0022AD20(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" char *func_002FE250(void *arg0);

extern "C" void func_002D8FA8(void *arg0, void *arg1, s32 n, void **args) {
    if (n >= 2) {
        Handle h0;
        Handle b;
        Handle c;
        Handle *pb;
        Handle *pc;
        func_002D8B08(&h0, arg1);
        pb = &b;
        func_0022AD20(pb, args);
        pc = &c;
        func_002FC8C8(pc, args + 1);
        {
            void *bp = pb->p;
            void *hp = h0.p;
            func_002DB080(hp, bp, func_002FE250(pc->p));
        }
        func_002FC870(pc, 2);
        func_0022ACC8(pb, 2);
        func_002D8AB0(&h0, 2);
    }
}
