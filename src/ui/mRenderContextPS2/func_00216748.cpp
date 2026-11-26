/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct Tex;
struct Rect { char pad0[0x8]; s32 width; };
struct Jitter { f32 x; f32 y; };

extern "C" void func_001056A0(Tex *) throw();
extern "C" void func_00105728(Rect *) throw();
extern "C" s32 func_00105818(Rect *) throw();
extern "C" void func_004A1638(s32);
extern "C" void func_004A2808(s32, f32);
extern "C" void func_004A4550(s32, s32);
extern "C" void func_004A4810(s32, s32, s32);
extern "C" void func_004A6668(f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void func_004A6788(f32, f32, f32, f32, f32, f32, f32, f32);
extern "C" void func_004AA1D8(f32, f32, f32, f32);
extern "C" void func_004AB040(s32);

/* Four sub-pixel offsets of the accumulation passes. */
extern Jitter D_00697B20[4];

/* Draws the texture once at full weight, then blends four jittered copies over it with
   weights 2/5, 2/7, 2/9, 2/11; the strips a positive offset uncovers at the left and top
   edges are filled with the texture's first texel column / row. */
extern "C" void func_00216748(Tex *tex, Rect *r) {
    f32 one = 1.0f;
    s32 w = r->width;
    s32 h = func_00105818(r);
    func_00105728(r);
    func_001056A0(tex);
    f32 fw = (f32)w;
    func_004A4550(4, 2);
    f32 fh = (f32)h;
    func_004A4550(5, 2);
    f32 zero = 0.0f;
    func_004A4810(0, 0, w - 1);
    f32 weight = 3.0f;
    func_004A4810(1, 0, h - 1);
    func_004AB040(5);
    func_004AB040(6);
    func_004AA1D8(one, one, one, one);
    func_004A6668(zero, zero, fw, fh, zero, zero, fw, fh);
    func_004AA1D8(1.0f, 1.0f, 1.0f, 1.0f);
    func_004A1638(6);
    for (s32 i = 0; i < 4; i++) {
        f32 next = weight + 2.0f;
        weight = next;
        func_004A2808(100, 2.0f / next);
        f32 x = D_00697B20[i].x;
        f32 y = D_00697B20[i].y;
        func_004A6788(x, y, (f32)(w + 1) + x, (f32)(h + 1) + y, 0.0f, 0.0f, (f32)(w + 1), (f32)(h + 1));
        if (0.0f < x) {
            func_004A6668(0.0f, 0.0f, x, (f32)h, 0.0f, 0.0f, 1.0f, (f32)h);
        }
        if (0.0f < y) {
            func_004A6668(0.0f, 0.0f, (f32)w, y, 0.0f, 0.0f, (f32)w, 1.0f);
        }
    }
}
