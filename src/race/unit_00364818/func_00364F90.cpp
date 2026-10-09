typedef int s32;
typedef short s16;
typedef float f32;

struct Inner { char pad[0x1648]; s16 unk1648; };

struct Outer { Inner *ptr; };

extern "C" f32 func_00364F90(Outer *arg0) {
    return (f32)arg0->ptr->unk1648;
}
