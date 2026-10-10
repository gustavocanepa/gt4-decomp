typedef int s32;

struct Sym {
    s32 id;
    s32 pad[3];
};

extern char D_00620178[];

extern "C" s32 func_00327A10(const char *name);
extern "C" void func_00328738(void *self, Sym *sym);

extern "C" void func_002ECDE0(void *self) {
    Sym s;
    s.id = func_00327A10(D_00620178);
    func_00328738(self, &s);
}
