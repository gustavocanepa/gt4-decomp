/* The callees are declared throw(): the original translation unit defined them above this
 * function, which marks them nothrow for g++ 2.96 and lets reorg fill the branch delay slots
 * across their calls (knowledge/ee-gcc-2.96.md, "throw() on the declarations"). */
typedef signed char s8; typedef unsigned char u8; typedef int s32; typedef float f32;
#define M2C_FIELD(expr, type_ptr, offset) (*(type_ptr)((s8 *)(expr) + (offset)))

extern "C" void func_001056A0(s32) throw();
extern "C" void RaceDigitalSpeedmeter__virtual_04(void *) throw();
extern "C" void RaceTexturePanel__virtual_04(void *) throw();
extern "C" void RaceABMonitor__virtual_04(void *) throw();
extern "C" void RaceFuelMeter__virtual_05(void *, s32) throw();
extern "C" void RaceTireWearDisplay__virtual_05(void *, s32) throw();
extern "C" void RaceIndicator__virtual_04(void *) throw();
extern "C" void RaceShiftPositionDisplay__virtual_04(void *) throw();
extern "C" void RaceSuggestedGearDisplay__virtual_04(void *) throw();
extern "C" void RaceShiftTimingLampDisplay__virtual_04(void *) throw();
extern "C" void func_003A8290(void) throw();
extern "C" void RaceSideGravityMeter__virtual_04(void *) throw();
extern "C" void RaceBattleTachometer__virtual_05(void *, s32) throw();
struct RaceSimplePanel__virtual_05_temp_s2 {
    char pad0[0xC];
    f32 unkC;
    s32 unk10;
};
struct RaceSimplePanel__virtual_05_arg0 {
    char pad0[0xC];
    f32 unkC;
    char pad10[0x8];
    u8 unk18;
    u8 unk19;
    char pad1A[0x1];
    u8 unk1B;
    u8 unk1C;
    char pad1D[0x15F];
    u8 unk17C;
    char pad17D[0x113];
    u8 unk290;
    char pad291[0xF7];
    u8 unk388;
};
struct RaceSimplePanel__virtual_05_temp_s0 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s3 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s4 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_v0 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_a0 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s0_2 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s2_2 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s4_2 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s6 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s3_2 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_s7 {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_fp {
    char pad0[0xC];
    f32 unkC;
};
struct RaceSimplePanel__virtual_05_temp_v0_2 {
    char pad0[0xC];
    f32 unkC;
};

extern "C" void RaceSimplePanel__virtual_05(char *arg0, s32 arg1) {
    char *sp0;
    char *sp4;
    char *temp_a0;
    char *temp_fp;
    char *temp_s0;
    char *temp_s0_2;
    char *temp_s2;
    char *temp_s2_2;
    char *temp_s3;
    char *temp_s3_2;
    char *temp_s4;
    char *temp_s4_2;
    char *temp_s6;
    char *temp_s7;
    char *temp_v0;
    char *temp_v0_2;
    temp_s2 = arg0 + 0x2C;
    if (((struct RaceSimplePanel__virtual_05_temp_s2 *)temp_s2)->unk10 == 0) {
        func_003A8290();
    }
    temp_s0 = arg0 + 0x48;
    func_001056A0(arg1);
    temp_s3 = arg0 + 0x80;
    temp_s4 = arg0 + 0xD0;
    ((struct RaceSimplePanel__virtual_05_temp_s2 *)temp_s2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
    ((struct RaceSimplePanel__virtual_05_temp_s0 *)temp_s0)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
    ((struct RaceSimplePanel__virtual_05_temp_s3 *)temp_s3)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
    ((struct RaceSimplePanel__virtual_05_temp_s4 *)temp_s4)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
    RaceTexturePanel__virtual_04(temp_s2);
    RaceDigitalSpeedmeter__virtual_04(temp_s0);
    if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk19 != 0) {
        if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk1B != 0) {
            RaceFuelMeter__virtual_05(temp_s3, arg1);
        }
        RaceTireWearDisplay__virtual_05(temp_s4, arg1);
    }
    if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk18 == 0) {
        temp_v0 = arg0 + 0xA8;
        sp0 = temp_v0;
        temp_a0 = arg0 + 0x100;
        ((struct RaceSimplePanel__virtual_05_temp_v0 *)temp_v0)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        temp_v0_2 = arg0 + 0x344;
        temp_s0_2 = arg0 + 0x124;
        temp_s2_2 = arg0 + 0x17C;
        temp_s4_2 = arg0 + 0x1D4;
        temp_s6 = arg0 + 0x210;
        temp_s3_2 = arg0 + 0x290;
        ((struct RaceSimplePanel__virtual_05_temp_a0 *)temp_a0)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        temp_s7 = arg0 + 0x2BC;
        sp4 = temp_v0_2;
        temp_fp = arg0 + 0x300;
        ((struct RaceSimplePanel__virtual_05_temp_s0_2 *)temp_s0_2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_s2_2 *)temp_s2_2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_s4_2 *)temp_s4_2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_s6 *)temp_s6)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_s3_2 *)temp_s3_2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_s7 *)temp_s7)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_fp *)temp_fp)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        ((struct RaceSimplePanel__virtual_05_temp_v0_2 *)temp_v0_2)->unkC = (f32) ((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unkC;
        RaceBattleTachometer__virtual_05(temp_a0, arg1);
        RaceShiftPositionDisplay__virtual_04(temp_s0_2);
        if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk17C != 0) {
            RaceSuggestedGearDisplay__virtual_04(temp_s2_2);
        }
        RaceShiftTimingLampDisplay__virtual_04(temp_s4_2);
        RaceABMonitor__virtual_04(temp_s6);
        if ((((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk290) && (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk388 == 0)) {
            RaceSideGravityMeter__virtual_04(temp_s3_2);
        }
        if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk19 != 0) {
            if (((struct RaceSimplePanel__virtual_05_arg0 *)arg0)->unk1C != 0) {
                RaceFuelMeter__virtual_05(sp0, arg1);
            }
            RaceIndicator__virtual_04(temp_s7);
            RaceIndicator__virtual_04(temp_fp);
            RaceIndicator__virtual_04(sp4);
        }
    }
}
