extern "C" void func_003285A8(void *arg0);
extern "C" void func_003285F8(void *arg0);

extern "C" void func_005D87E8(void **arg0, void **arg1, void **arg2) {
    void **it = arg0;
    if (it != arg1) {
        do {
            if (it != arg2) {
                void *val = *arg2;
                if (val != 0) {
                    func_003285A8(val);
                }
                void *old = *it;
                if (old != 0) {
                    func_003285F8(old);
                }
                *it = val;
            }
            it += 1;
        } while (it != arg1);
    }
}
