typedef float f32;

static inline f32 maxf(f32 a, f32 b) { f32 r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline f32 minf(f32 a, f32 b) { f32 r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct FontManager;
extern FontManager *PDISTD__global_font_manager;

extern "C" void func_00490518(FontManager *m);
extern "C" void func_004905B0(FontManager *m, f32 r, f32 g, f32 b, f32 a);

extern "C" void func_0044DF20(f32 r, f32 g, f32 b, f32 a) {
    func_00490518(PDISTD__global_font_manager);
    func_004905B0(PDISTD__global_font_manager, 0.0f, 0.0f, 0.0f, minf(maxf((a - 0.25f) * 0x1.555554p+0f, 0.0f), 1.0f));
}
