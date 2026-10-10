/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;

struct Hdr { char pad[0x20]; u16 n0, n1, n2; };
struct View { Hdr *h; s32 *a; s32 *b; s32 *d; s32 *c; char pad[0xC]; s32 data[1]; };

extern "C" View *func_00454650(Hdr *h, View *v) {
    s32 *p = v->data;
    v->a = p;
    p += h->n0;
    v->b = p;
    p += h->n1;
    v->c = p;
    p += h->n2;
    v->h = h;
    v->d = p;
    return v;
}
