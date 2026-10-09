typedef unsigned long long u64;
typedef int s32;

extern "C" s32 func_0042EA58(u64 *arg0, u64 *arg1) {
    u64 temp_v1;
    u64 temp_a0;

    temp_v1 = *arg0;
    temp_a0 = *arg1;
    if (temp_v1 < temp_a0) {
        return -1;
    }
    return temp_a0 < temp_v1;
}
