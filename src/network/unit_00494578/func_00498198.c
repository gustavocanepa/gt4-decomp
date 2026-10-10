#include "types.h"

s32 func_00496C28();
void func_00497F48(s32, s32, f32, f32, f32);
void func_00497F98(s32, s32, f32, f32, f32, f32);
void func_004A1638(s32);
void func_004A2808(s32, f32);
void func_004A29A8(s32);
void func_004A53F8();
void func_004A5400();
void func_004A7454();
void func_004A7844(f32, f32, f32);
void func_004A7890(f32, f32, f32);
void func_004AB040(s32);

void func_00498198(s32 arg0, s32 arg1, f32 *arg2, s32 arg3, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5, f32 fparg6, f32 fparg7) {
    f32 z;
    f32 s;
    s32 shadow;
    s32 lit = arg1 & 1;
    s32 tex;

    shadow = 0;
    z = -arg2[2];
    if (fparg6 > 0.0f && fparg7 > 0.0f && z > 1.0f) {
        shadow = 1;
    }
    s = (z - fparg0) / z;
    tex = arg1 & 2;
    func_004A29A8(0);
    func_004A1638(6);
    func_004A2808(0x48, 0.0f);
    func_004A7454();
    func_004A7844(arg2[0] * s, arg2[1] * s, arg2[2] * s);
    if (lit) {
        func_004A53F8();
        func_004A7890(fparg5, fparg5, fparg5);
        if (tex) {
            func_004A1638(5);
            func_00497F98(arg0, arg3, fparg1, fparg2, fparg3, fparg4);
        } else {
            func_004AB040(5);
            func_00497F48(arg0, arg3, fparg1 * fparg4, fparg2 * fparg4, fparg3 * fparg4);
        }
        func_004A5400();
    }
    if (shadow != 0) {
        func_004A7890(fparg7, fparg7, fparg7);
        func_004A1638(5);
        func_00497F98(arg0, func_00496C28(), fparg1, fparg2, fparg3, fparg6);
    }
    func_004A29A8(1);
}
