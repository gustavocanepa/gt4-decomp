/* compiler: ee-gcc2.96-no-strict-aliasing */
/* Drains a stream into its buffer in 0x800-byte reads while forced or while the buffer holds less
   than 0x5000 bytes and has room; returns the bytes read. buf is set inside a do-while(0) so it is
   scheduled into the entry jump's delay slot, as in retail. */
typedef int s32;
struct Buf { s32 x0, x4, x8, xC; };
struct Req { s32 p; s32 n; };
struct Self { char pad[0x630]; Buf buf; char pad2[0x75C - 0x640]; s32 x75C; };
extern "C" s32 func_004AF8B8(Self *, Req *);
extern "C" void func_006111F0(Buf *, s32, s32);
static inline s32 avail(Buf *b) { s32 v = b->xC; return v < 0 ? 0 : v; }
extern "C" s32 func_00558038(Self *s, s32 force) {
    s32 total = 0;
    Buf *buf;
    do { buf = &s->buf; } while (0);
    goto test;
body:
    {
        Req r;
        r.p = s->x75C;
        r.n = 0x800;
        s32 n = func_004AF8B8(s, &r);
        func_006111F0(buf, s->x75C, n);
        total += n;
        if (n != 0x800) goto done;
    }
test:
    if (force || buf->x8 < 0x5000) {
        if (avail(buf) >= 0x800) goto body;
    }
done:
    return total;
}
