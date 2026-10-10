extern "C" int &func_0044A860(void *self, int key);

extern "C" void func_0044ABC0(void *self, int key) {
    if (func_0044A860(self, key) < 0x7FFFFFFF)
        func_0044A860(self, key)++;
}
