
extern "C" int func_004B2488(const unsigned char *a, unsigned int alen, const unsigned char *b, unsigned int blen)
{
    if (alen <= blen) {
        for (unsigned int i = 0; i < alen; i++) {
            int d = a[i] - b[i];
            if (d) return d;
        }
        return alen == blen ? 0 : -1;
    } else {
        for (unsigned int i = 0; i < blen; i++) {
            int d = a[i] - b[i];
            if (d) return d;
        }
        return 1;
    }
}
