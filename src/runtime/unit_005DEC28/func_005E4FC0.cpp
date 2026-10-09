extern "C" void func_002030C0(int arg0, int arg1);

extern "C" int func_005E4FC0(int arg0, int arg1, int arg2) {
    int ptr = arg2;
    int idx = arg0;
    int limit = arg1;

    if (idx != limit) {
        do {
            if (ptr != 0) {
                func_002030C0(ptr, idx);
            }
            idx += 0x10;
            ptr += 0x10;
        } while (idx != limit);
    }
    return ptr;
}
