extern "C" char D_00655340[];
extern "C" void func_00576100(void *lock);
extern "C" void func_00576140(void *lock);
extern "C" void func_00559918(void *self);

extern "C" void func_00559C80(void *self) {
    void *lock = D_00655340;
    func_00576100(lock);
    func_00559918(self);
    func_00576140(lock);
}
