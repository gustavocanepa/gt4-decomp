extern char D_00655340[]; /* mutex */
extern "C" void func_00576100(void *mutex);
extern "C" void func_00576140(void *mutex);
extern "C" void func_0055A340(void *self, void *arg);
extern "C" void func_00559E88(void *self);

extern "C" void func_0055A258(void *self, void *arg) {
    void *mutex = D_00655340;
    func_00576100(mutex);
    func_0055A340(self, arg);
    func_00559E88(self);
    func_00576140(mutex);
}
