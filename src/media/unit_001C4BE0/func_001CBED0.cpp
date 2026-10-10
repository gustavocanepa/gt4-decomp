struct Text {
    short pad0[3];
    short lineLength;
    char pad8[0xB8];
    char buf[1];
};

extern "C" void func_001CBED0(Text *t, const char *src)
{
    char *dst = t->buf;
    int n;
    char c;

    t->lineLength = 32;
    n = 0;
    while ((c = *src++) != 0) {
        if (c == '\r' || c == '\n') {
            t->lineLength = n;
        } else {
            *dst++ = c;
            n++;
        }
    }
}
