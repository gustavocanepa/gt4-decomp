/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Cursor {
    unsigned char *p;
    int m14;
    int m18;
    void put(unsigned char c) { *p++ = c; }
};
struct Buf {
    int m0;
    int cap;
    int len;
    int mC;
    Cursor cur;
};
extern "C" void func_0046F2B8(Buf *b);

extern "C" void func_0046F378(Buf *b, unsigned int c)
{
    func_0046F2B8(b);
    if (b->cap - b->len < 8) {
        b->cur.m14 = 1;
        b->cur.m18 = 1;
        return;
    }
    b->cur.put(c >> 8);
    b->cur.put(c);
    b->len += 2;
}
