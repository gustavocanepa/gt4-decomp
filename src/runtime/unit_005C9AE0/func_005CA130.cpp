extern "C" void func_0021B5B8(int arg0, int arg1);

extern "C" int func_005CA130(int arg0, int arg1, int arg2) {
    int ptr = arg2;
    int idx = arg0;
    int limit = arg1;

    if (idx != limit) {
        do {
            if (ptr != 0) {
                func_0021B5B8(ptr, idx);
            }
            idx += 4;
            ptr += 4;
        } while (idx != limit);
    }
    return ptr;
}
