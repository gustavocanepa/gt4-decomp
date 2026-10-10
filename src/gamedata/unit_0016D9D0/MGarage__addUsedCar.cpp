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

extern s32 D_00622F4C;
extern "C" void * func_0013BDC0(void *, void *);
extern "C" s32 func_00147D80(s32);
extern "C" void * func_0016D848(void *, void *);
extern "C" void func_0016D7F0(void *, s32);
extern "C" s32 func_00146598(s32);
extern "C" s32 func_00441280(s32);
extern "C" s32 SPEC_DATABASE__CarEquipments__getVariationOrder(s32);
extern "C" s32 func_00435800(s32, s32, s32, s32, s32);
extern "C" void * func_002FE278(void *, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_002FC870(void *, s32);
extern "C" void func_0013BD68(void *, s32);

struct MGarage__addUsedCar_v_s2 {
    char pad0[0x4A0];
    s32 unk4A0;
};

extern "C" void MGarage__addUsedCar(s32 *arg0, void *arg1, s32 arg2, char **arg3) {
    s32 buf0[4];
    s32 buf1[4];
    s32 *p_s5;
    s32 t1;
    s32 v_s2;
    s32 v_s4;
    s32 v_s3;
    s32 v_s1;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;
    if (arg2 > 0) {
        func_0013BDC0(buf0, arg3);
        t1 = func_00147D80(buf0[0]);
        p_s5 = buf1;
        v_s2 = t1;
        v_s4 = ((struct MGarage__addUsedCar_v_s2 *)v_s2)->unk4A0;
        func_0016D848(p_s5, arg1);
        v_s3 = *(s32 *)((char *)(*p_s5) + 0x10);
        func_0016D7F0(p_s5, 0x2);
        v_s1 = (0x10000 + D_00622F4C);
        v_s1 = *(s32 *)((char *)v_s1 - 0x43d8);
        v_s0 = func_00146598(buf0[0]);
        func_002FE278(p_s5, func_00435800(v_s3, v_s0, SPEC_DATABASE__CarEquipments__getVariationOrder(func_00441280(v_s2)), v_s1, v_s4));
        if (arg0 != p_s5) {
            newVal = *p_s5;
            if (newVal != 0) {
                func_003285A8(newVal);
            }
            oldVal = *arg0;
            if (oldVal != 0) {
                func_003285F8(oldVal);
            }
            *arg0 = newVal;
        }
        func_002FC870(p_s5, 0x2);
        func_0013BD68(buf0, 0x2);
    }
}
