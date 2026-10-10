class B {
    int a;
    int b;
public:
    virtual ~B() __asm__("func_00578F48");
};

class D_00659B88 : public B {
public:
    virtual ~D_00659B88() {}
};

extern D_00659B88 D_00617CB8;
extern D_00659B88 D_00617CF8;

extern "C" void func_00100E10(D_00659B88 *o);
extern "C" void func_00100E70(D_00659B88 *o);

extern "C" void func_00101450(int init, int prio)
{
    if (prio == 0xFFFF && init == 1) {
        func_00100E10(&D_00617CB8);
    }
    if (prio == 0xFFFF && init == 1) {
        func_00100E70(&D_00617CF8);
    }
    if (prio == 0xFFFF && init == 0) {
        D_00617CF8.D_00659B88::~D_00659B88();
    }
    if (prio == 0xFFFF && init == 0) {
        D_00617CB8.D_00659B88::~D_00659B88();
    }
}
