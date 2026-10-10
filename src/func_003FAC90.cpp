struct Obj {
    int handle;
};

extern "C" void func_003FABA0(Obj *o, int handle, int flags);
extern "C" void func_003FAFE8(Obj *o);
extern "C" void func_003FAD78(Obj *o);
extern "C" void func_003FB1E0(Obj *o);

extern "C" void func_003FAC90(Obj *o, int mode) {
    func_003FABA0(o, o->handle, 0);
    if (o->handle == 0)
        return;
    switch (mode) {
    case 1:
        func_003FAFE8(o);
        break;
    case 2:
        func_003FAD78(o);
        break;
    default:
        func_003FB1E0(o);
        break;
    }
}
