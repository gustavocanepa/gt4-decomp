typedef int s32;
typedef float f32;

extern "C" void func_003EC5C8(void *arg0, f32 arg1);

extern "C" void func_003A9478(void *arg0, s32 arg1) {
    func_003EC5C8((char *)arg0 + 0xC8, (f32)arg1);
}
