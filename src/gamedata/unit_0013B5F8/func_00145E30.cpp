typedef int s32;

extern s32 func_00441248(s32 a);
extern s32 func_004459B0(s32 a);

struct func_00145E30_arg0 {
    char pad0[0x14];
    s32 unk14;
};

s32 func_00145E30(void *arg0) {
    return func_004459B0(func_00441248(((struct func_00145E30_arg0 *)arg0)->unk14));
}
