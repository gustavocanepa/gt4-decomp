typedef float f32;
typedef unsigned char u8;
void func_0035D920(void);
void func_0035DD00(void *a);
f32 func_00350858(char *a, void *b);
void func_003435E8(void *a, f32 b);
void func_00343708(void *a, f32 b);
void func_003439E8(void *a, f32 b);
void func_0035DC08(void *a);
void func_0035D990(void *a);
extern char D_00620320[];
void func_0035DE20(char *arg0) {
    f32 temp_f0;
    f32 temp_f1;
    char *temp_s1;
    char *temp_s2;

    temp_s2 = arg0 + 0x104;
    temp_s1 = arg0 + 0x6DC;
    func_0035D920();
    *(f32 *)(temp_s2 + 0x5C4) = *(f32 *)(temp_s2 + 0x53C);
    func_0035DD00(arg0);
    temp_f1 = *(f32 *)(temp_s2 + 0x5C4);
    if (temp_f1 < 0.0f) {
        *(f32 *)(temp_s2 + 0x5C4) = -temp_f1;
    }
    if (*(u8 *)(temp_s1 + 0x14) == 0) {
        temp_f0 = func_00350858(D_00620320, arg0);
        func_003435E8(temp_s1, temp_f0);
        func_00343708(temp_s1, temp_f0);
        func_003439E8(temp_s1, temp_f0);
    }
    if (*(u8 *)(temp_s2 + 0x4B2) == 0) {
        if (*(f32 *)(arg0 + 0x6CC) < *(f32 *)(arg0 + 0x6C8)) {
            *(f32 *)(arg0 + 0x6CC) = *(f32 *)(arg0 + 0x6C8);
        }
    }
    func_0035DC08(arg0);
    func_0035D990(arg0);
}
