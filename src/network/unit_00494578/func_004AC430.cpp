typedef int s32;

extern "C" void *func_00575E60(s32, s32);
extern "C" void *func_00578CF0(s32, s32);

extern "C" void *func_004AC430(s32 size, s32 flag) {
    void *(*alloc)(s32, s32);
    if (flag) alloc = func_00578CF0;
    else alloc = func_00575E60;
    return alloc(0x80, size);
}
