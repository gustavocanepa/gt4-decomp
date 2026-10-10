struct Val { int w[4]; };
struct Ctx { void *vm; };
struct Obj { char pad[0xC]; char *h; };
extern "C" void HCodeFrame__structor_0(void *, char **);
extern "C" void func_0030BB18(Val *);
extern "C" void hThread__setArguments(void *, char *, int, int, Val *);
extern "C" void func_00309378(Val *, int);

extern "C" void hScriptFunction__call_const_2(Obj *self, Ctx *c, int a, int b)
{
    HCodeFrame__structor_0(c->vm, &self->h);
    void *vm = c->vm;
    char *code = self->h + 0x10;
    Val v;
    func_0030BB18(&v);
    hThread__setArguments(vm, code, a, b, &v);
    func_00309378(&v, 2);
}
