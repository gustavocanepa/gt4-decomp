typedef float f32;

struct Vec2 { f32 x; f32 y; };
struct Src { char pad[0x78]; f32 unk78; f32 unk7C; };

extern "C" void *func_00267D30(Vec2 *arg0, Src *arg1) {
    arg0->x = arg1->unk78;
    arg0->y = arg1->unk7C;
    return arg0;
}
