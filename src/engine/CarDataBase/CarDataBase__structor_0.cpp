typedef int s32;

struct Obj {
    char pad[0xC];
    void *vtbl;
};

extern char CarDataBase__vtable[];
extern "C" s32 func_0044FFA0(Obj *arg0);

extern "C" s32 CarDataBase__structor_0(Obj *arg0) {
    arg0->vtbl = CarDataBase__vtable;
    return func_0044FFA0(arg0);
}
