typedef int s32;
typedef unsigned int u32;

struct Stream_0033A7D0 {
    s32 m0;
    u32 pos;
    u32 end;
};

struct Saved_0033A7D0 {
    char data[0x10];
};

extern "C" void func_0045B620(Saved_0033A7D0 *s, Stream_0033A7D0 *st);
extern "C" void func_0045B740(Saved_0033A7D0 *s, Stream_0033A7D0 *st);
extern "C" void func_0033A488(Stream_0033A7D0 *st, Saved_0033A7D0 *s, void *x);

extern "C" bool func_0033A7D0(Stream_0033A7D0 *st, void *x) {
    Saved_0033A7D0 s;
    func_0045B620(&s, st);
    func_0033A488(st, &s, x);
    func_0045B740(&s, st);
    Stream_0033A7D0 *r = (st->end > st->pos) ? 0 : st;
    return r != 0;
}
