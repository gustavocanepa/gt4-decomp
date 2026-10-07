extern "C" int func_005ADCE0(int arg0);

extern "C" int func_00539B08(void *arg0) {
    if (arg0 == 0) {
        return 2;
    }
    int r = func_005ADCE0(*(int *)((char *)arg0 + 0xC));
    return (~r != 0) ? 0 : 0x384;
}
