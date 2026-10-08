typedef int s32;

struct Obj0038A098 {
    char pad[0xCE4];
    char pad2[0xD18 - 0xCE4];
    s32 unkD18;
};

extern "C" void func_00574F90(void *arg0);
extern "C" void func_001012C8(struct Obj0038A098 *arg0);

extern "C" void func_0038A098(struct Obj0038A098 *arg0, s32 arg1) {
    arg0->unkD18 = arg1;
    func_00574F90((char *)arg0 + 0xCE4);
    func_001012C8(arg0);
}
