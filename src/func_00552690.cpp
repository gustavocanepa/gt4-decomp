inline void *operator new(unsigned int, void *p) throw() { return p; }

/* The singleton class (D_006898D8 in src/func_00552730.cpp), named after its constructor so the
   call resolves. */
struct func_00552730 {
    func_00552730();
};

extern char D_0086FE50[];
extern func_00552730 *D_0064C8B8;

extern "C" void func_00552690(void) {
    if (D_0064C8B8 == 0)
        D_0064C8B8 = new (D_0086FE50) func_00552730;
}
