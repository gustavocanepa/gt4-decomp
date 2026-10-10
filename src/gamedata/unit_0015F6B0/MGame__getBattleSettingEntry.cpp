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

extern "C" void func_0015F3E0(void *);
extern "C" s32 func_00575DC8(s32);
extern "C" s32 func_00430878(s32);
extern "C" void func_00200140(void *, s32, s32);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" void func_001FFF30(void *, s32);
extern "C" void func_0015F388(void *, s32);

struct MGame__getBattleSettingEntry_v_s0 {
    char pad0[0x4];
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
};
struct MGame__getBattleSettingEntry_v_s2 {
    char pad0[0x54];
    s32 unk54;
    s32 unk58;
    char pad5C[0x4];
    s32 unk60;
};
struct MGame__getBattleSettingEntry_v_s1 {
    char pad0[0x10F4];
    s32 unk10F4;
    char pad10F8[0x34];
    s32 unk112C;
    char pad1130[0x4];
    s32 unk1134;
    char pad1138[0x4];
    s32 unk113C;
    s32 unk1140;
};

extern "C" void MGame__getBattleSettingEntry(s32 *arg0) {
    s32 buf0[4];
    s32 buf1[4];
    s32 v_s1;
    s32 v_s0;
    s32 v_s2;
    s32 *p_s4;
    s32 t1;
    s32 newVal;
    s32 oldVal;
    func_0015F3E0(buf0);
    v_s1 = *(s32 *)((char *)buf0[0] + 0x10);
    v_s0 = func_00575DC8(0x24);
    v_s2 = v_s1 + 0xd8;
    v_s1 = (0x38cb0 + v_s1);
    t1 = (func_00430878(v_s2) ^ 0x1);
    p_s4 = buf1;
    *(s32 *)(char *)v_s0 = t1;
    ((struct MGame__getBattleSettingEntry_v_s0 *)v_s0)->unk4 = ((struct MGame__getBattleSettingEntry_v_s2 *)v_s2)->unk54;
    ((struct MGame__getBattleSettingEntry_v_s0 *)v_s0)->unk8 = ((struct MGame__getBattleSettingEntry_v_s2 *)v_s2)->unk58;
    ((struct MGame__getBattleSettingEntry_v_s0 *)v_s0)->unkC = ((struct MGame__getBattleSettingEntry_v_s1 *)v_s1)->unk112C;
    ((struct MGame__getBattleSettingEntry_v_s0 *)v_s0)->unk10 = ((struct MGame__getBattleSettingEntry_v_s1 *)v_s1)->unk1134;
    ((struct MGame__getBattleSettingEntry_v_s0 *)v_s0)->unk14 = ((struct MGame__getBattleSettingEntry_v_s2 *)v_s2)->unk60;
    ((struct MGame__getBattleSettingEntry_v_s0 *)v_s0)->unk18 = ((struct MGame__getBattleSettingEntry_v_s1 *)v_s1)->unk10F4;
    ((struct MGame__getBattleSettingEntry_v_s0 *)v_s0)->unk1C = (((struct MGame__getBattleSettingEntry_v_s1 *)v_s1)->unk1140 & 0x1);
    ((struct MGame__getBattleSettingEntry_v_s0 *)v_s0)->unk20 = ((struct MGame__getBattleSettingEntry_v_s1 *)v_s1)->unk113C;
    func_00200140(p_s4, v_s0, 0x1);
    if (arg0 != p_s4) {
        newVal = *p_s4;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_001FFF30(p_s4, 0x2);
    func_0015F388(buf0, 0x2);
}
