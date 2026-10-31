/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Static constructors/destructors of two stream objects (init 1: func_00556578, func_00556838;
   init 0: their inline destructors in reverse order). The base destructor is declared throw(),
   which lets reorg reuse the epilogue's ld $s0 in the last test's delay slot (bnez, not bnel).
   key() (declared, never defined) keeps the vtables out of this object: they are the original's. */
class B {
    int data[0x18];
public:
    virtual ~B() throw() __asm__("func_00556450");
};

class D_006899C0 : public B {
public:
    virtual ~D_006899C0() {}
    virtual void key();
};

class D_00689970 : public B {
public:
    virtual ~D_00689970() {}
    virtual void key();
};

extern D_006899C0 D_008720C0;
extern D_00689970 D_00872128;

extern "C" void func_00556578(D_006899C0 *o);
extern "C" void func_00556838(D_00689970 *o);

extern "C" void func_00556BB8(int init, int prio)
{
    if (prio == 0xFFFF && init == 1) {
        func_00556578(&D_008720C0);
    }
    if (prio == 0xFFFF && init == 1) {
        func_00556838(&D_00872128);
    }
    if (prio == 0xFFFF && init == 0) {
        D_00872128.D_00689970::~D_00689970();
    }
    if (prio == 0xFFFF && init == 0) {
        D_008720C0.D_006899C0::~D_006899C0();
    }
}
