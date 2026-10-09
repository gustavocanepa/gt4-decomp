typedef int s32;

struct Obj1 {
    char pad[0x108];
    s32 unk108;
};

extern "C" s32 func_00515F98(s32 *arg0, Obj1 *arg1) {
    s32 result = 0x17;
    if (arg0 != 0) {
        s32 tmp = 0x100;
        *arg0 = tmp;
        if (arg1 != 0) {
            result = 0;
            tmp = arg1->unk108;
            *arg0 = tmp;
        }
    }
    return result;
}
