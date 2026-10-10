extern "C" char GT4Model__BinStreamReader__read8u(int arg0);

extern "C" void GT4Model__BinStreamReader__readArray(int arg0, char *arg1, int arg2) {
    int count;
    char *p;

    count = arg2;
    p = arg1;
    if (count != 0) {
        do {
            count -= 1;
            *p = GT4Model__BinStreamReader__read8u(arg0);
            p += 1;
        } while (count != 0);
    }
}
