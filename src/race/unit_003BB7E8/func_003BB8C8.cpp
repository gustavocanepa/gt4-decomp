typedef int s32;
typedef unsigned int u32;

struct Record_003BB8C8 {
    s32 data[16];
    u32 time;
};

extern "C" s32 func_003BB8C8(Record_003BB8C8 *dst, const Record_003BB8C8 *src) {
    if (dst->time == 0x157529FF || src->time < dst->time) {
        s32 i;
        for (i = 0; i < 16; i++) {
            dst->data[i] = src->data[i];
        }
        dst->time = src->time;
        return 1;
    }
    return 0;
}
