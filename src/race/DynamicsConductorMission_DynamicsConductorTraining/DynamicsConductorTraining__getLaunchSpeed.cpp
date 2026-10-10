typedef int s32;
typedef unsigned char u8;

struct Obj1 {
    char pad[0xF866];
    u8 unkF866;
};

extern "C" u8 DynamicsConductorTraining__getLaunchSpeed(char *arg0, s32 arg1) {
    arg1 = arg1 + (s32)arg0;
    u8 v = ((struct Obj1 *)arg1)->unkF866;
    arg0 = arg0 + 0xF818;
    if (v == 0) {
        v = *(u8 *)(arg0 + 0x4E);
    }
    return v;
}
