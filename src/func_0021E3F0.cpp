typedef int s32;

struct Handle {
    void *p;
    char pad[0xC];
};

extern "C" void func_0021D978(void *arg0, int arg1);
extern "C" void func_0021D9D0(void *arg0, void *arg1);
extern "C" void func_0021FC78(void *arg0, void *arg1, char *arg2);
extern "C" void func_0022ACC8(void *arg0, int arg1);
extern "C" void func_0022AD20(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" char *func_00314AD8(void *arg0);

extern "C" void func_0021E3F0(void *arg0, void *arg1, s32 n, void **args) {
    if (n >= 2) {
        Handle h0;
        Handle b;
        Handle c;
        Handle *pb;
        Handle *pc;
        func_0021D9D0(&h0, arg1);
        pb = &b;
        func_0022AD20(pb, args);
        pc = &c;
        func_00312370(pc, args + 1);
        {
            void *bp = pb->p;
            void *hp = h0.p;
            func_0021FC78(hp, bp, func_00314AD8(pc->p));
        }
        func_00312318(pc, 2);
        func_0022ACC8(pb, 2);
        func_0021D978(&h0, 2);
    }
}
