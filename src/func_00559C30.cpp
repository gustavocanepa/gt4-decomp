extern "C" char D_00655340[];
extern "C" void func_00576100(void *lock);
extern "C" void func_00576140(void *lock);

struct Obj {
    int f0;
    int value;
};

extern "C" void func_00559C30(Obj *o, int value) {
    void *lock = D_00655340;
    func_00576100(lock);
    o->value = value;
    func_00576140(lock);
}
