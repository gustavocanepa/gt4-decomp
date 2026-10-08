typedef int s32;

struct Obj_001C7328 {
    char pad[0xAC];
    s32 unkAC;
};

extern "C" s32 func_001C7328(void *arg0) {
    s32 idx = ((Obj_001C7328 *)arg0)->unkAC;
    arg0 = (char *)arg0 + idx * 0x54;
    return *(s32 *)arg0 == 5;
}
