extern "C" void func_004082F0(void *self, int index, int value);

extern "C" void func_00408EE0(void *self, int value) {
    func_004082F0(self, 0, value);
    func_004082F0(self, 1, value);
    func_004082F0(self, 2, value);
}
