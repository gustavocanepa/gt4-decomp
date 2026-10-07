typedef int s32;

struct B { char pad[0xC4]; s32 arr[1]; };

extern "C" void func_00251BF8(struct B *arg0, s32 arg1, s32 arg2) {
    arg0->arr[arg1] = arg2;
}
