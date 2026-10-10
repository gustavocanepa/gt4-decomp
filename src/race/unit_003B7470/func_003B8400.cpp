typedef int s32;
typedef float f32;

struct Vec3_003B8400 {
    f32 x, y, z;
};

struct Obj_003B8400 {
    char pad0[0xA0C];
    Vec3_003B8400 pos;
    f32 mA18;
    f32 mA1C;
    f32 mA20;
    f32 mA24;
    s32 mA28;
};

extern "C" s32 func_00498518(Obj_003B8400 *o, Vec3_003B8400 *pos);

extern "C" void func_003B8400(Obj_003B8400 *o, const Vec3_003B8400 *pos, f32 u0, f32 u1, f32 a, f32 b, f32 c, f32 d) {
    o->mA18 = a;
    o->pos.x = pos->x;
    o->pos.y = pos->y;
    o->pos.z = pos->z;
    o->mA1C = b;
    o->mA20 = c;
    o->mA24 = d;
    o->mA28 = func_00498518(o, &o->pos) != 0;
}
