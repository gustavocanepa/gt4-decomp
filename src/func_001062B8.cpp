typedef int s32;

struct S;

struct Inner001062B8 {
    char pad78[0x78];
    s32 unk78;
};

extern "C" s32 func_00105818(struct S *arg0);

extern "C" s32 func_001062B8(void *arg0) {
    struct Inner001062B8 *temp_a0;

    temp_a0 = (struct Inner001062B8 *)((char *)arg0 + 0xB8);
    return func_00105818((struct S *)((char *)temp_a0 + temp_a0->unk78 * 0x3C));
}
