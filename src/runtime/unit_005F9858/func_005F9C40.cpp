typedef int s32;
typedef float f32;

extern "C" void RaceMessageDisplay__setMessage(s32 arg0, f32 arg1, f32 arg2);

extern "C" void func_005F9C40(s32 arg0) {
    RaceMessageDisplay__setMessage(arg0 + 0x3C, 0.0f, 0.0f);
}
