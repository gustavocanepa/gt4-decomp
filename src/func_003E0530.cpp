typedef int s32;
typedef float f32;
typedef unsigned char u8;

struct Profile_003E0530 {
    char pad0[0x134];
    const char *name;
};

struct Entry_003E0530 {
    s32 m0;
    char name[0x20];
    u8 m24;
    char pad25[0xF];
    u8 m34;
    char pad35[0xB4 - 0x35];
    s32 mB4;
    s32 mB8;
    f32 mBC;
};

extern "C" Profile_003E0530 *D_00621870;
extern "C" u8 D_006A3800;
extern "C" char *func_005A609C(char *dst, const char *src);

extern "C" void func_003E0530(Entry_003E0530 *e) {
    func_005A609C(e->name, D_00621870->name);
    u8 c = D_006A3800;
    e->m34 = c;
    e->m24 = c;
    e->mB8 = -1;
    e->mBC = -1.0f;
    e->mB4 = 1;
    e->m0 = -1;
}
