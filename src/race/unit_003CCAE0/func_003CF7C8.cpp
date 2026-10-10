extern "C" int func_003C9F38(void *self);

extern "C" int func_003CF7C8(void *self, int mode) {
    int n = func_003C9F38(self);
    if (n == 0)
        return 0;
    if (mode == 0) {
        if (n < 3)
            return 0;
        return 1;
    }
    if (mode == 1)
        return n < 4;
    return 0;
}
