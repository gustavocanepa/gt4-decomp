extern "C" void func_00578500(int);
extern "C" int func_00578168(void *obj, int a1, int a2, void *buf, int size);

extern "C" int func_0060FE40(int *obj) {
    char raw[0x80];
    int *buf = (int *)(((unsigned int)raw + 0x3F) & ~0x3F);
    func_00578500(obj[0]);
    func_00578168(obj, 0, 0, buf, 0x40);
    return buf[0];
}
