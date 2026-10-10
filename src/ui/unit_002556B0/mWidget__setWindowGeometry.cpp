typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Rect {
    f32 x;
    f32 y;
    f32 w;
    f32 h;
};

struct Widget {
    char pad0[0x44];
    f32 f44;
    f32 f48;
    char pad4c[0x8];
    void *parent;
    char pad58[0x40];
    u32 flags_lo : 21;
    u32 size_dirty : 1;
};

extern s32 D_00619374;

extern "C" void mWidget__getWindowSize(void *arg0, f32 *arg1, f32 *arg2);
extern "C" void func_0025BA38(void *arg0, f32 *arg1, f32 *arg2);
extern "C" u32 func_002662A0(struct Widget *arg0);
extern "C" s32 func_00267698(struct Widget *arg0);

extern "C" void mWidget__setWindowGeometry(struct Widget *self, struct Rect *r, f32 *px, f32 *py, f32 *pw, f32 *ph) {
    f32 sx;
    f32 sy;
    f32 w = r->w;
    f32 h = r->h;

    switch (func_00267698(self)) {
    case 1:
        mWidget__getWindowSize(self->parent, &sx, &sy);
        if (px != 0) r->x = *px / sx;
        if (py != 0) r->y = *py / sy;
        if (pw != 0) w = *pw / sx;
        if (ph != 0) h = *ph / sy;
        break;
    case 2:
        if (px != 0) r->x = *px;
        if (py != 0) r->y = *py;
        if (pw != 0) w = *pw;
        if (ph != 0) h = *ph;
        break;
    case 3:
        sy = 0.0f;
        sx = 0.0f;
        if (self->parent != 0) func_0025BA38(self->parent, &sy, &sx);
        if (px != 0) r->x = *px + sy;
        if (py != 0) r->y = *py + sx;
        if (pw != 0) w = *pw;
        if (ph != 0) h = *ph;
        break;
    }

    if (pw != 0 && w != r->w) {
        r->w = w;
        self->size_dirty = 1;
    }
    if (ph != 0 && h != r->h) {
        r->h = h;
        self->size_dirty = 1;
    }
    if (r->w < 0.0f) r->w = 0.0f;
    if (r->h < 0.0f) r->h = 0.0f;

    if (D_00619374 != 0 && func_002662A0(self) != 0) {
        self->f44 = r->w;
        self->f48 = r->h;
    }
}
