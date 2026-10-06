typedef int s32;

extern s32 func_00441248(s32 a);
extern s32 func_004459B0(s32 a);

s32 func_00145E30(void *arg0) {
    return func_004459B0(func_00441248(*(s32*)((char*)arg0 + 0x14)));
}
