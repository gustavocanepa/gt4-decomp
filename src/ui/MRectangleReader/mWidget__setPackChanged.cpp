typedef float f32;

struct Rect {
    f32 x, y, w, h;
    Rect(f32 x_, f32 y_, f32 w_, f32 h_) : x(x_), y(y_), w(w_), h(h_) {}
};

extern "C" Rect mWidget__setPackChanged(const Rect &r, f32 s) {
    f32 w = r.w * s;
    f32 h = r.h * s;
    return Rect(r.x + (r.w - w) * 0.5f, r.y + (r.h - h) * 0.5f, w, h);
}
