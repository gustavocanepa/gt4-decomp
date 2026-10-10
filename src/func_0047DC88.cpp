struct Vec2 { float x, y; };
struct Mat { float m[16]; };

struct Node {
    char pad[0x2C];
    char xform[0x2C];
    Node *parent;
};

extern "C" void func_0047E400(void *xform, Mat *m);
extern "C" void func_0047E110(const Mat *m, const Vec2 *in, Vec2 *out);

extern "C" void func_0047DC88(Node *n, Vec2 *p, int noTranslate) {
    if (n->parent)
        func_0047DC88(n->parent, p, noTranslate);
    Vec2 v = *p;
    Mat m;
    if (noTranslate) {
        m.m[12] = 0.0f;
        m.m[13] = 0.0f;
    }
    func_0047E400(n->xform, &m);
    func_0047E110(&m, &v, p);
}
