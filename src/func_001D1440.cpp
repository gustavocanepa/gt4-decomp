typedef int s32;
typedef long s64;

struct Obj001D1440 {
    s64 arr[0x190];
    s32 unkC80;
};

extern "C" void func_001D1440(struct Obj001D1440 *arg0, struct Obj001D1440 *arg1) {
    s32 count;
    s64 *dst;
    s64 *src;
    s64 temp;

    dst = arg0->arr;
    count = 0x18F;
    src = arg1->arr;
    do {
        temp = *src;
        src++;
        count--;
        *dst = temp;
        dst++;
    } while (count != -1);
    arg0->unkC80 = arg1->unkC80;
}
