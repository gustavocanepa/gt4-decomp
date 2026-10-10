typedef int s32;
typedef unsigned char u8;
typedef unsigned short u16;

struct Obj { char pad[0x30]; u16 f30; u8 f32; u8 f33; };
extern u8 D_006224A6;
extern u8 D_006224A8;

extern "C" s32 func_003F9470(Obj *o) {
    if (o->f30)
        return 1;
    if (D_006224A6) {
        if (o->f32)
            return 1;
        if (!D_006224A8) {
            if (o->f33)
                return 1;
        }
    }
    return 0;
}
