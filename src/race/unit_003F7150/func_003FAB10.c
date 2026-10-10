typedef int s32;
typedef float f32;
void func_003630C0(void *a, s32 b, f32 c, f32 d, f32 e);
void func_003455F0(void *a);
void func_00363560(void *a);
void func_003F4B20(void *a);
void func_0045B8C0(void *a, void *b, s32 c);
void func_003455C8(void *a);
void func_003F71A0(void *a, s32 b);
void func_003FAB10(char *arg0, f32 fparg0, f32 fparg1, f32 fparg2) {
    char *temp_s0;
    func_003630C0(arg0, 0, fparg0, -fparg2, fparg1);
    func_003455F0(arg0);
    func_00363560(arg0);
    temp_s0 = *(char **)(arg0 + 4);
    func_003F4B20(temp_s0);
    func_0045B8C0(temp_s0 + 0xDA6C, temp_s0, *(s32 *)(temp_s0 + 0xCBD8));
    func_003455C8(arg0);
    func_003F71A0(arg0, 1);
}
