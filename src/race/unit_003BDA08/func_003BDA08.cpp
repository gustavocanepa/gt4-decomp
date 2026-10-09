typedef int s32;

struct Obj_003BDA08 {
    char pad[0x90];
    s32 unk90;
};

extern "C" void *func_005720B8(void *arg0);
extern "C" void *func_005A48D8(void *arg0, s32 arg1, s32 arg2);

extern "C" void *func_003BDA08(struct Obj_003BDA08 *arg0) {
    struct Obj_003BDA08 *s0 = arg0;

    func_005720B8(s0);
    s0->unk90 = 0;
    return func_005A48D8((char *)s0 + 0x80, 0, 0x10);
}
