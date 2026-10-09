typedef int s32;
typedef short s16;
typedef unsigned short u16;
typedef signed char s8;
typedef unsigned char u8;
typedef long s64;
typedef float f32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern "C" void func_0016D848(void *);
extern "C" void func_0016D7F0(void *, s32);
extern "C" void func_00148140(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_0013BD68(void *, s32);

extern "C" void MGarage__get_riding_car(s32 *arg0) {
    s32 buf0[4];
    s32 v_s0;
    func_0016D848(buf0);
    v_s0 = *(s32 *)((char *)buf0[0] + 0x10);
    func_0016D7F0(buf0, 0x2);
    func_00148140(buf0, v_s0 + 0x7d08);
    *(s32 *)((char *)buf0[0] + 0x180) = *(s32 *)((char *)((0x10000 + v_s0)) - 0x7e38);
    if ((char *)arg0 != (char *)buf0) {
        v_s0 = buf0[0];
        if (v_s0 != 0) {
            func_003285A8(v_s0);
        }
        if (*(s32 *)(char *)arg0 != 0) {
            func_003285F8(*(s32 *)(char *)arg0);
        }
        *(s32 *)(char *)arg0 = v_s0;
    }
    func_0013BD68(buf0, 0x2);
}
