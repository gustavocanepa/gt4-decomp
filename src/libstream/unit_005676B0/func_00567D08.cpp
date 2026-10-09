typedef void (*FnPtr)(void *);

struct VTable {
    char pad[0x24];
    FnPtr fn24;
};

struct Obj {
    VTable *vtbl;
};

extern "C" void func_00567D08(Obj *arg0) {
    arg0->vtbl->fn24(arg0);
}
