extern "C" char func_0045B0F8(int arg0);

extern "C" void func_0045B268(int arg0, char *arg1, int arg2) {
    int count;
    char *p;

    count = arg2;
    p = arg1;
    if (count != 0) {
        do {
            count -= 1;
            *p = func_0045B0F8(arg0);
            p += 1;
        } while (count != 0);
    }
}
