typedef int s32;

struct B { char pad[0xBC]; s32 arr[1]; };

extern "C" s32 func_00251BD8(struct B *arg0, s32 arg1) {
    return arg0->arr[arg1];
}
