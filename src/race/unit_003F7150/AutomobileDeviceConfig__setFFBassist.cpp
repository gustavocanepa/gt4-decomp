typedef short s16;

struct Obj_003F7160 { char pad[0x2]; s16 unk2; };

extern "C" void AutomobileDeviceConfig__setFFBassist(Obj_003F7160 *arg0, s16 arg1) {
    arg0->unk2 = arg1;
}
