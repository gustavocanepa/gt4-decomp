extern "C" void *func_0041A988(void *self, int i);
extern "C" void func_00418A58(void *item, void *data);

extern "C" void func_00419D18(void *self, char *data) {
    for (int i = 0; i < 20; i++) {
        func_00418A58(func_0041A988(self, i), data);
        data += 0x40;
    }
}
