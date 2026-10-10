typedef int s32;

struct Buf {
    s32 unk0;
    void *data;
    s32 size;
    s32 cap;
    s32 pad[4];
};

extern "C" s32 func_001CDAC8(void *, void *, Buf *, s32);
extern "C" void func_00575DA0(void *);

extern "C" bool func_001CDF58(void *a, void *b) {
    Buf buf;
    buf.data = 0;
    buf.size = 0;
    buf.cap = 0;
    bool ok = func_001CDAC8(a, b, &buf, 0) == 0;
    if (buf.data != 0)
        func_00575DA0(buf.data);
    return ok;
}
