typedef int s32;
typedef unsigned char u8;

struct Obj_003F69C8 {
    u8 pad0[0x5B6];
    u8 unk5B6;
};

extern "C" s32 func_00357800(void *arg0, struct Obj_003F69C8 *arg1);
extern "C" s32 func_0035E3F0(struct Obj_003F69C8 *arg0);

extern "C" s32 DynamicsConductorMachineTest__virtual_33(void *arg0, struct Obj_003F69C8 *arg1) {
    if (arg1->unk5B6 != 0) {
        return func_0035E3F0(arg1);
    }
    return func_00357800(arg0, arg1);
}
