typedef int s32;

struct Buf {
    char *data;
    s32 len;
};

struct Obj {
    s32 a;
    Buf buf;
};

extern "C" s32 func_00605850(char, char);
extern "C" s32 func_00605638(char *, char *, char *, char *, s32 (*)(char, char));

extern "C" s32 func_00474940(Obj *self, char *s, s32 n) {
    Buf *b = &self->buf;
    return func_00605638(b->data, b->data + b->len - 1, s, s + n, func_00605850);
}
