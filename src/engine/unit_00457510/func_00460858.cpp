struct Mutex;
extern "C" Mutex D_00846890;
extern "C" void func_00576788(Mutex *m);
extern "C" void func_005767C0(Mutex *m);

struct Shared {
    int m0;
    int refs;
};

extern "C" Shared D_008468C0;
extern "C" void func_004616A0(Shared *s);
extern "C" void func_00461380(void);

extern "C" void func_00460858(int id)
{
    func_00576788(&D_00846890);
    if (id == -1) {
        if (--D_008468C0.refs == 0) {
            func_004616A0(&D_008468C0);
            func_00461380();
        }
    }
    func_005767C0(&D_00846890);
}
