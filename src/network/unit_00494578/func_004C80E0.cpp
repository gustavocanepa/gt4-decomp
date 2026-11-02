/* Looks a request up in a context and applies it: builds the request, fetches the node, hands
   its fields to apply() and releases the node on every path; a 0x11xx lookup error counts as 0.
   The callees are the context's methods, so `this` goes to $a0 last, as in retail. */
struct Req { char data[0x30]; };
struct Node { int x0; int x4; unsigned short x8; };
struct Obj { int x0; int x4; };
extern "C" void func_004C9428(Req *, int, int *);
struct Ctx {
    int lookup(int key, Req *r, Node **out) __asm__("func_004C0D60");
    void release(Node *n) __asm__("func_004C8BB0");
    int apply(int a, int n, int p, Obj *o) __asm__("func_004C81D8");
};
extern "C" int func_004C80E0(Ctx *c, int a, int key, Obj *o, int mode) {
    Req r;
    Node *node = 0;
    func_004C9428(&r, mode, o ? &o->x4 : 0);
    int rc = c->lookup(key, &r, &node);
    if (rc < 0) {
        c->release(node);
        return (rc & 0x7F00) == 0x1100 ? 0 : rc;
    }
    if (rc == 0 || node == 0) {
        c->release(node);
        return 0;
    }
    rc = c->apply(a, node->x8, node->x4, o);
    if (rc < 0) {
        c->release(node);
        return rc;
    }
    c->release(node);
    return 0;
}
