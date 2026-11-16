/* Counts the leading characters of a 16-bit string for which func_004C4CB8 gives a negative
   result. */
extern "C" int func_004C4CB8(unsigned short c) throw();
extern "C" int func_004C5018(unsigned short *s) {
    int n = 0;
    while (*s != 0) {
        if (func_004C4CB8(*s++) < 0) {
            n++;
            continue;
        }
        return n;
    }
    return n;
}
