class A {
    int data[0xC];
public:
    ~A() __asm__("func_00574DA8");
};

class B {
    int a;
    int b;
public:
    virtual ~B() __asm__("func_0057CA38");
};

class D_00688E18 : public B {
public:
    virtual ~D_00688E18() {}
};

extern A D_00631880;
extern D_00688E18 D_006318B0;

extern "C" void func_00574D78(A *o);
extern "C" void func_0060AB60(D_00688E18 *o);

extern "C" void func_004ADE08(int init, int prio)
{
    if (prio == 0xFFFF && init == 1) {
        func_00574D78(&D_00631880);
    }
    if (prio == 0xFFFF && init == 1) {
        func_0060AB60(&D_006318B0);
    }
    if (prio == 0xFFFF && init == 0) {
        D_006318B0.D_00688E18::~D_00688E18();
    }
    if (prio == 0xFFFF && init == 0) {
        D_00631880.~A();
    }
}
