typedef short s16;
typedef int s32;

struct Obj_003F7160;

extern "C" void AutomobileDeviceConfig__setFFBlevel(s16 *arg0, s16 arg1);
extern "C" s32 AutomobileDeviceConfig__setFFBassist(struct Obj_003F7160 *arg0, s16 arg1);

extern "C" s32 AutomobileDeviceConfig__setDefault(struct Obj_003F7160 *arg0) {
    struct Obj_003F7160 *s0 = arg0;

    AutomobileDeviceConfig__setFFBlevel((s16 *)s0, 1);
    return AutomobileDeviceConfig__setFFBassist(s0, 1);
}
