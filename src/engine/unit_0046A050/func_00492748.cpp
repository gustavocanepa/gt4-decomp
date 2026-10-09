typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

struct Glyph {
    char pad0[0x10];
    u8 w;
    u8 h;
    s8 x;
    s8 y;
    u8 adv;
};

struct Text {
    char pad0[0x14];
    Glyph *glyph;
    s32 tex;
    char pad1C[0x8];
    f32 sx;
    f32 sy;
    char pad2C[0x4];
    f32 x;
    f32 y;
    char pad38[0x10];
    s32 color;
    char pad4C[0x24];
    f32 shadow;
    char pad74[0x4];
    s32 flag;
    char pad7C[0x24];
    s32 ch;
};

typedef void (*DrawFn)(s32, s32, f32, f32, f32, f32);

extern s32 D_00624988;
extern "C" void func_00491F98(void);
extern "C" void func_004923F8(s32, f32, f32, f32, f32);
extern "C" s32 func_00490660(Text *, f32);


extern "C" s32 func_00492748(s32 code, DrawFn draw, Text *t) {
    Glyph *g = t->glyph;
    s32 kern = t->flag != 0;
    f32 sx = t->sx;
    f32 sy = t->sy;
    s32 tex = t->tex;
    f32 x0 = t->x + (f32)(g->x + kern) * sx;
    f32 y0 = t->y + (f32)g->y * sy;
    f32 x1 = x0 + (f32)g->w * sx;
    f32 y1 = y0 + (f32)g->h * sy;

    if (draw != 0 && tex != 0) {
        f32 d = t->shadow;
        if (d > 0.0f) {
            s32 saved = D_00624988;
            D_00624988 = t->color;
            func_00491F98();
            draw(tex, code, x0 + d, y0 + d, x1 + d, y1 + d);
            D_00624988 = saved;
            func_00491F98();
            func_004923F8(tex, x0, y0, x1, y1);
        } else {
            draw(tex, code, x0, y0, x1, y1);
        }
    }
    if (func_00490660(t, (f32)(g->adv + kern) * sx) == 0) {
        s32 c = t->ch;
        if (code != 0xFF63 && !((u32)(c - 0x3001) < 2 || c == 0x300C || c == 0x3083 || c == 0x3085 ||
            c == 0x3087 || c == 0x3063 || c == 0xFF0D || c == 0x2E || c == 0x2C || c == 0x27)) {
            return 1;
        }
    }
    t->flag = 0;
    return 0;
}
