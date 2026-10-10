extern "C" char D_00631880[];
extern "C" char D_006318B0[];
extern "C" void func_00576788(void *lock);
extern "C" void func_005767C0(void *lock);
extern "C" void func_0057CC80(void *list, void *item);

extern "C" void func_004ACE08(void *item) {
    void *lock = D_00631880;
    func_00576788(lock);
    func_0057CC80(D_006318B0, item);
    func_005767C0(lock);
}
