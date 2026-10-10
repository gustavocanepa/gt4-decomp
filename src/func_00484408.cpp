extern "C" void *func_00481410(void *self, int key);
extern "C" void *func_00481230(void *self, int key);
extern "C" void func_00476790(void *item, int value);

extern "C" int func_00484408(void *self, int key, int value, int create) {
    if (create) {
        func_00476790(func_00481410(self, key), value);
        return 1;
    }
    void *p = func_00481230(self, key);
    if (!p)
        return 0;
    func_00476790(p, value);
    return 1;
}
