struct Rect {
    float x1, y1, x2, y2;
    Rect &operator=(const Rect &o)
    {
        if (this != &o) {
            x1 = o.x1;
            y1 = o.y1;
            x2 = o.x2;
            y2 = o.y2;
        }
        return *this;
    }
};

struct RectStack {
    int m0;
    Rect *begin;
    Rect *end;
    bool empty() const { return begin == end; }
    Rect &top() { return end[-1]; }
};

struct Obj {
    char pad0[0x40];
    RectStack clip;
};

extern "C" bool func_0026F7E8(Obj *o, Rect *out) {
    RectStack *s = &o->clip;
    if (!s->empty()) {
        Rect &r = s->top();
        if (r.x2 - r.x1 > 0.0f && r.y2 - r.y1 > 0.0f) {
            *out = r;
            return true;
        }
    }
    return false;
}
