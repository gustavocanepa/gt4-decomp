inline void *operator new(unsigned int, void *p) throw() { return p; }

/* The singleton class (D_006898D8 in src/func_00553310.cpp), named after its constructor so the
   call resolves. */
struct func_00553310 {
    func_00553310();
};

extern char D_0086FF70[];
extern func_00553310 *D_0064CCA8;

extern "C" void func_005532C0(void) {
    if (D_0064CCA8 == 0)
        D_0064CCA8 = new (D_0086FF70) func_00553310;
}
