typedef unsigned char u8;
typedef unsigned short u16;
struct Ctx;
struct FloatRec { float f; u8 n; u8 m; u8 data[1]; };
struct HalfRec { u16 n; u16 m; u8 data[1]; };
struct Node { char *base; u16 index; };
extern "C" void func_0049DCB0(Ctx *, u8 *, int, int, float);
extern "C" void func_0049DB08(Ctx *, u8 *, int, float);
extern "C" void func_0049D728(Ctx *, u8 *, int, int);
extern "C" void func_0049D580(Ctx *, u8 *, int);
extern "C" void func_0049DA60(Ctx *c, Node *node, int flags) {
    FloatRec *rec = (FloatRec *)(node->base + node->index * 16);
    u8 *q;
    int n, m;
    if (flags & 0x20) {
        float f;
        f = rec->f;
        m = rec->m;
        n = rec->n;
        q = rec->data;
        if (m != 0) { func_0049DCB0(c, q, n, m, f); return; }
        else { func_0049DB08(c, q, n, f); return; }
    } else {
        q = (u8 *)rec;
        n = *(u16 *)q; q += 2;
        m = *(u16 *)q; q += 2;
        if (m != 0) { func_0049D728(c, q, n, m); return; }
        else { func_0049D580(c, q, n); return; }
    }
}
