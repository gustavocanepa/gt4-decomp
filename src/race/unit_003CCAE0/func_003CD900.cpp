typedef int s32;

struct B003CD900 {
    char pad[0x9858];
    s32 arr[1][4];
};

extern "C" s32 func_003CD900(struct B003CD900 *arg0, s32 arg1, s32 arg2) {
    return arg0->arr[arg1][arg2];
}
