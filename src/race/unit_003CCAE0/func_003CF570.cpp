typedef int s32;
typedef float f32;

extern "C" s32 func_003CC840(void);
extern "C" void func_003CBB28(char *a, s32 b, char *c, f32 t, s32 d);

extern "C" void func_003CF570(char *arg0, s32 arg1, f32 t) {
    func_003CBB28(arg0 + 4, func_003CC840(), arg0, t, arg1);
}
