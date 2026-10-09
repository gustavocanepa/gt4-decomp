typedef int s32;

struct Obj {
    char pad0[4];
};

typedef void *(Obj::*PM)(void);

struct Handle {
    Obj *p;
    char pad[0xC];
};

extern "C" void func_001BB248(void *arg0, int arg1);
extern "C" void func_001BB2A0(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FE278(void *arg0, void *arg1);
extern "C" void func_003285A8(void *p);
extern "C" void func_003285F8(void *p);

static inline Obj *hget(Handle *h) { return h->p; }

extern "C" void func_005CFBD8(void **arg0, void *arg1, s32 arg2, s32 arg3, PM pmf) {
    Handle h;
    Handle o;
    Handle *po = &o;

    func_001BB2A0(po, arg1);
    {
        void *r = (hget(po)->*pmf)();
        Handle *ph = &h;
        func_002FE278(ph, r);
        if ((void *)arg0 != (void *)ph) {
            void *p = ph->p;
            if (p != 0) {
                func_003285A8(p);
            }
            if (*arg0 != 0) {
                func_003285F8(*arg0);
            }
            *arg0 = p;
        }
        func_002FC870(ph, 2);
    }
    func_001BB248(po, 2);
}
