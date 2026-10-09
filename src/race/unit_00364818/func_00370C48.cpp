extern "C" void func_005F5040(void *arg0, void *arg1);

extern "C" void func_00370C48(void *arg0) {
    void *t = (char *)arg0 + 0xD8;
    func_005F5040((char *)arg0 + 0x28, t);
}
