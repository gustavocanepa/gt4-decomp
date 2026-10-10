typedef int s32;
typedef unsigned char u8;

struct Stream {
    u8 *begin;
    u8 *end;
    u8 *cur;
};

extern "C" s32 GT4Model__BinStreamBase__get(Stream *s) {
    if (s->cur < s->end)
        return *s->cur++;
    s->cur++;
    return 0;
}
