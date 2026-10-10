struct Buf {
    char *base;
    int m4;
    char *cur;
};

struct Cursor {
    int m0;
    int pos;
    int end;
    int mC;
};

extern "C" void func_0045B620(Cursor *c, Buf *b);
extern "C" int func_0045B348(Cursor *c, const char *tag);
extern "C" void GT4Model__BinStreamReader__readArray(Buf *b, const char *name, int len);
extern "C" void func_0045B740(Cursor *c, Buf *b);
extern const char D_0069F300[];

extern "C" void func_0033A838(Buf *b, const char *name) {
    Cursor c;
    func_0045B620(&c, b);
    if (!func_0045B348(&c, D_0069F300)) {
        b->cur = b->base + c.pos;
        return;
    }
    if (name)
        GT4Model__BinStreamReader__readArray(b, name, c.end - 8);
    func_0045B740(&c, b);
}
