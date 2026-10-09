typedef int s32;

struct B { char pad[0xF8A4]; s32 arr[1]; };

s32 func_003658D8(struct B *arg0, s32 arg1) {
    return arg0->arr[arg1];
}
