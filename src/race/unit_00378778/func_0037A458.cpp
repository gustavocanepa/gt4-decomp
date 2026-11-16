/* compiler: ee-gcc2.96-no-strict-aliasing */
#include "types.h"
#include "m2c_macros.h"
#define NULL 0
static inline float abs_(float f) { float r; __asm__("abs.s %0, %1" : "=f"(r) : "f"(f)); return r; }
static inline void scale_(float *p, float k) { *p *= k; }
static inline float root_(float x) { float r; __asm__("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
static inline float sqrt_(float x) { float r; __asm__ volatile("sqrt.s %0, %1" : "=f"(r) : "f"(x)); return r; }
extern "C" void RacePS2Base__tf();
extern "C" void RaceBase__tf();
extern "C" f32 func_00345198(s32);
extern "C" f32 func_003451A8(s32);
extern "C" f32 func_003451B0(s32);
extern "C" s32 func_0034A8B0(s32, f32 *, f32 *);
extern "C" f32 func_0036F980(char *, f32) throw();
extern "C" f32 func_0037A418(f32, f32, f32) throw() __attribute__((const));
extern "C" f32 func_0037A448(f32, f32, f32) throw() __attribute__((const));
extern "C" void func_0037B020(char *);
extern "C" void func_0037B580(char *);
extern "C" void func_0037B918(char *);
extern "C" void func_00384A70(char *, s32, f32, f32);
extern "C" void func_00384B70(char *, f32);
extern "C" void func_00385098(char *, f32);
extern "C" void func_003853A0(char *, f32);
extern "C" void func_003FC698(char *, f32 *);
extern "C" float func_003FC948(f32, f32, f32, int *);
extern "C" s32 func_003FD528(s32, int *, f32 *, f32 *);
extern "C" f32 func_003FD7E0(f32, f32, f32, f32);
extern "C" void func_004A0690();
extern "C" void func_004A06F0();
extern "C" void func_004A53F8();
extern "C" void func_004A5400();
extern "C" void func_004A7454();
extern "C" void func_004A7550(char *);
extern "C" void func_004A79D8(f32);
extern "C" f32 func_00578598(s32);
extern "C" char *__dynamic_cast_2(s32, void (*)(), int, char *, void (*)(), char *) throw();
extern "C" f32 func_005F5010(f32 *);

// Old GNU C++ RTTI stores the complete-object adjustment beside the type callback.
struct RttiEntry { short adjustment, index; int typeInfo; };
static inline char *checkedRaceCast(char *object) {
    if (!object) return 0;
    RttiEntry *entry = *(RttiEntry **)(object + 0x64);
    return __dynamic_cast_2(entry->typeInfo, RacePS2Base__tf, 0, object + entry->adjustment, RaceBase__tf, object);
}

extern "C" s32 func_0037A458(char *arg0, char *arg1, s32 arg2, char *arg3) {
    struct { int flag; float y, x; } work;
    float vec[3];
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f21;
    f32 temp_f21_2;
    f32 temp_f21_3;
    f32 temp_f22;
    f32 temp_f22_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 var_f0;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f20;
    f32 var_f21;
    f32 var_f23;
    f32 var_f24;
    f32 var_f25;
    f32 var_f26;
    s32 temp_s0;
    s32 temp_s4;
    s32 temp_v0;
    s32 var_v0;
    s32 var_v1;
    u32 temp_s2;
    char *temp_v0_2;
    char *temp_v1;
    char *temp_v1_2;
    char *temp_v1_3;
    char *temp_v1_4;
    char *var_a2;
    char *var_v0_2;

    temp_v1 = M2C_FIELD(arg0, char **, 0) + 0x138;
    temp_s4 = M2C_FIELD(M2C_FIELD(arg0, char **, 0x18C), s32 *, 0x18);
    M2C_FIELD(arg0, f32 *, 0x270) = 0x0.0p+0f;
    M2C_FIELD(temp_v1, M2C_UNK (**)(char *, s32), 4)(arg0 + M2C_FIELD(temp_v1, s16 *, 0), arg2);
    temp_v1_2 = M2C_FIELD(arg0, char **, 0) + 0xB8;
    temp_s2 = M2C_FIELD(temp_v1_2, u32 (**)(char *), 4)(arg0 + M2C_FIELD(temp_v1_2, s16 *, 0));
    temp_v0 = M2C_FIELD(arg0, s32 *, 0x27C);
    switch (temp_v0) {
    case 1:
        temp_f20 = M2C_FIELD(arg0, f32 *, 0x284);
        temp_f21 = M2C_FIELD(arg0, f32 *, 0x288);
        func_003FC948(temp_f20, temp_f21, func_003FD7E0(temp_f20, temp_f21, M2C_FIELD(arg0, f32 *, 0x280), M2C_FIELD(arg3, f32 *, 0x34)), &work.flag);
        if (work.flag != 0) {
            M2C_FIELD(arg0, s32 *, 0xE8) = M2C_FIELD(arg0, s32 *, 0x294);
        }
        break;
    case 2:
        if (M2C_FIELD(arg0, f32 *, 0x28C) < ((f32) M2C_FIELD(arg0, s32 *, 0x140) / 0x1.e000000000000p+5f)) {
            M2C_FIELD(arg0, s32 *, 0xE8) = M2C_FIELD(arg0, s32 *, 0x294);
        }
        break;
    case 3:
        temp_f1 = (f32) M2C_FIELD(arg0, s32 *, 0x140) / 0x1.e000000000000p+5f;
        if (M2C_FIELD(arg0, f32 *, 0x28C) < temp_f1) {
            M2C_FIELD(arg0, s32 *, 0xE8) = (s32) M2C_FIELD(arg0, s32 *, 0x294);
        }
        if (M2C_FIELD(arg0, f32 *, 0x290) < temp_f1) {
            M2C_FIELD(arg0, s32 *, 0xE8) = 3;
        }
        break;
    case 4:
        if (func_003FD528(M2C_FIELD(M2C_FIELD(arg0, char **, 0x18C), s32 *, 0x18), &work.flag, &work.y, &work.x)) {
            M2C_FIELD(arg0, s32 *, 0x144) = 0;
        } else if (M2C_FIELD(arg0, s32 *, 0x144) > 480) {
            M2C_FIELD(arg0, f32 *, 0x28C) = -0x1.0000000000000p+0f;
        }
        temp_f1_2 = (f32) M2C_FIELD(arg0, s32 *, 0x140) / 0x1.e000000000000p+5f;
        if (M2C_FIELD(arg0, f32 *, 0x28C) < temp_f1_2) {
            M2C_FIELD(arg0, s32 *, 0xE8) = 4;
        }
        if (M2C_FIELD(arg0, f32 *, 0x290) < temp_f1_2) {
            M2C_FIELD(arg0, s32 *, 0xE8) = 3;
        }
        break;
    case 5:
        temp_v1_3 = M2C_FIELD(arg1, char **, 0x84);
        var_a2 = checkedRaceCast(temp_v1_3);
        temp_v1_4 = M2C_FIELD(var_a2, char **, 0x64) + 0x448;
        if (M2C_FIELD(temp_v1_4, s32 (**)(char *, int), 4)(var_a2 + M2C_FIELD(temp_v1_4, s16 *, 0), M2C_FIELD(arg3, s16 *, 0xC)) == 0) {
            M2C_FIELD(arg0, s32 *, 0xE8) = 3;
        }
        break;
    }
    func_003FC698(arg3, &vec[0]);
    scale_(&vec[0],60.0f);
    scale_(&vec[1],60.0f);
    scale_(&vec[2],60.0f);
    temp_f0 = func_005F5010(&vec[0]);
    M2C_FIELD(arg0, int *, 0x230) = 0;
    temp_f22 = M2C_FIELD(arg0, f32 *, 0x230);
    var_f20 = temp_f0 - 0x1.edd3be0000000p+2f;
    temp_s0 = M2C_FIELD(arg0, s32 *, 0x1B4);
    if (var_f20 <= temp_f22) {
        var_f20 = temp_f22;
    }
    if (var_f20 >= 0x1.edd3be0000000p+8f) {
        var_f20 = 0x1.edd3be0000000p+8f;
    }
    temp_f20_2 = var_f20 / 0x1.edd3be0000000p+8f;
    func_00384A70(arg0 + 0x1B8, temp_s0, temp_f20_2, -0x1.0000000000000p+0f);
    func_00384A70(arg0 + 0x1C4, temp_s0, temp_f20_2, -0x1.0000000000000p+0f);
    if ((temp_s2 == 0) || (temp_s2 == 0x19)) {
        var_f21 = temp_f22;
        var_v0_2 = (char *)temp_s4 + 0x164;
        var_v1 = 3;
        do {
            temp_f0_2 = M2C_FIELD(var_v0_2, f32 *, 0x38);
            var_v1 -= 1;
            var_f21 += abs_(temp_f0_2 * 0x1.3333320000000p-2f);
            temp_f1_3 = M2C_FIELD(var_v0_2, f32 *, 0x34);
            var_v0_2 += 0xEC;
            var_f21 += abs_(temp_f1_3 / 0x1.921fb40000000p+0f);
        } while (var_v1 >= 0);
        if (func_00578598(temp_s0) < 0.5f) {
            func_00384B70(arg0 + 0x1D0, (func_00578598(temp_s0) - 0x1.0000000000000p-1f) * var_f21 * 0x1.f400000000000p+7f);
            func_00384B70(arg0 + 0x1DC, (func_00578598(temp_s0) - 0x1.0000000000000p-1f) * var_f21 * 0x1.f400000000000p+7f);
        } else {
            func_00384B70(arg0 + 0x1D0, 0x0.0p+0f);
            func_00384B70(arg0 + 0x1DC, 0x0.0p+0f);
        }
        var_f0 = root_(temp_f0);
        if (var_f0 <= 0x1.638e380000000p+1f) {
            var_f0 = 0x1.638e380000000p+1f;
        }
        if (var_f0 >= 0x1.0aaaaa0000000p+5f) {
            var_f0 = 0x1.0aaaaa0000000p+5f;
        }
        var_f24 = 0x0.0p+0f;
        var_f25 = 0x0.0p+0f;
        var_f26 = 0x0.0p+0f;
        var_f23 = 0x0.0p+0f;
        M2C_FIELD(arg0, f32 *, 0x230) = (f32) (var_f0 / 0x1.0aaaaa0000000p+5f);
        if (func_0034A8B0(temp_s4, &work.x, &work.y) != 0) {
            work.x *= abs_(work.x);
            work.y *= abs_(work.y);
            var_f23 = root_(abs_(work.x) + abs_(work.y));
            M2C_FIELD(arg0, f32 *, 0x270) = var_f23;
            var_f25 = -work.x * 0x1.4000000000000p+3f;
            temp_f21_2 = func_0037A448(func_00578598(temp_s0), 0x1.9999980000000p-1f, 0x1.9999980000000p-2f);
            float other = func_0037A448(func_00578598(temp_s0), 0.5f, 0.1f);
            var_f24 = abs_(work.y) * 10.0f * temp_f21_2 + abs_(work.x) * 10.0f * other;
            if (work.y > 0.0f) var_f24 = -var_f24;
            var_f26 = var_f23 * 0x1.4000000000000p+2f * func_0037A418(func_00578598(temp_s0), 0x1.9999980000000p-1f, 0x1.9999980000000p-4f);
        }
        temp_f22_2 = var_f23 * func_0037A418(func_00578598(temp_s0), 0x1.9999980000000p-1f, 0x1.9999980000000p-2f);
        temp_f21_3 = var_f23 * func_0037A418(func_00578598(temp_s0), 0x1.9999980000000p-3f, 0x1.9999980000000p-5f);
        temp_f20_3 = var_f23 * func_0037A418(func_00578598(temp_s0), 0x1.3333320000000p-2f, 0x1.eb851e0000000p-6f);
        func_003853A0(arg0 + 0x20C, temp_f22_2);
        func_003853A0(arg0 + 0x218, temp_f21_3);
        func_003853A0(arg0 + 0x224, temp_f20_3);
        func_003853A0(arg0 + 0x1E8, var_f24);
        func_003853A0(arg0 + 0x1F4, var_f25);
        func_003853A0(arg0 + 0x200, var_f26);
    } else {
        func_00384B70(arg0 + 0x1D0, func_00345198(temp_s4) * 0x1.0000000000000p-1f);
        func_00384B70(arg0 + 0x1DC, 0x1.0000000000000p+1f * func_003451A8(temp_s4));
        func_003853A0(arg0 + 0x20C, temp_f22);
        func_003853A0(arg0 + 0x218, temp_f22);
        func_003853A0(arg0 + 0x224, temp_f22);
        func_003853A0(arg0 + 0x1E8, temp_f22);
        func_003853A0(arg0 + 0x1F4, temp_f22);
        func_003853A0(arg0 + 0x200, temp_f22);
    }
    var_f12 = func_003451B0(temp_s4) / 0x1.3999980000000p+3f;
    if (var_f12 <= -0x1.8000000000000p+1f) {
        var_f12 = -0x1.8000000000000p+1f;
    }
    if (var_f12 >= 0x1.8000000000000p+1f) {
        var_f12 = 0x1.8000000000000p+1f;
    }
    func_00385098(arg0 + 0x190, var_f12);
    func_004A0690();
    func_004A53F8();
    func_004A7454();
    if (M2C_FIELD(arg0, u8 *, 0x264) != 0) {
        temp_f3 = 0.0f;
        temp_f2_2 = M2C_FIELD(arg0, f32 *, 0x260);
        var_f12_2 = temp_f3;
        if (temp_f2_2 > temp_f3) {
            var_f12_2 = (f32) M2C_FIELD(arg0, s32 *, 0x140) / (temp_f2_2 * 0x1.e000000000000p+5f);
            if (var_f12_2 <= temp_f3) {
                var_f12_2 = temp_f3;
            }
            if (var_f12_2 >= 0x1.0000000000000p+0f) {
                var_f12_2 = 0x1.0000000000000p+0f;
            }
        }
        func_004A79D8(func_0036F980(arg0 + 0x238, var_f12_2));
    }
    if (temp_s2 < 26U) {
        switch ((int)temp_s2) {
        case 0: case 1: case 25: func_0037B020(arg0); break;
        case 20: func_0037B918(arg0); break;
        default: func_0037B580(arg0); break;
        }
    }
    func_004A7550(arg0 + 0x100);
    func_004A5400();
    func_004A06F0();
    return 1;
}
