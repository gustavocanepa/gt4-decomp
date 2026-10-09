typedef int s32;
typedef long long s64;

struct B { char pad[0x470]; s64 arr[1]; };

extern "C" s64 func_004409C8(struct B *arg0, s32 arg1) {
    return arg0->arr[arg1];
}
