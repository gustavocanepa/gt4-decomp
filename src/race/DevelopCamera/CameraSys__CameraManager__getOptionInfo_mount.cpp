typedef int s32;

struct Elem {
    char pad[0x194];
    s32 unk194;
};

extern "C" s32 CameraSys__CameraManager__getOptionInfo_mount(char *arg0, s32 arg1) {
    return ((Elem *)(arg0 + arg1 * 0x19C))->unk194;
}
