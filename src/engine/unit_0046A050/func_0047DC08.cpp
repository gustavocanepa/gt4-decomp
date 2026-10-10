struct Vec2 { float x, y; };
struct Mat { float m[16]; };

struct Node {
    char pad[0x2C];
    char xform[0x2C];
    Node *parent;
};

extern "C" void func_0047E400(void *xform, Mat *m);
extern "C" void func_0047E1B8(const Mat *m, const Vec2 *in, Vec2 *out);

extern "C" void func_0047DC08(Node *n, Vec2 *p) {
    Vec2 v = *p;
    Mat m;
    func_0047E400(n->xform, &m);
    func_0047E1B8(&m, &v, p);
    if (n->parent)
        func_0047DC08(n->parent, p);
}
