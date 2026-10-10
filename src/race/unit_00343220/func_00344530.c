typedef int s32;
typedef float f32;
void func_00344040(void *);
void func_00345658(void *);
void func_00345A20(void *);
void func_0034A668(void *);
void func_0034A788(void *);
void func_00350080(void *);
void func_00353EE8(void *);
void func_0035D350(void *);
void func_0035DE20(void *);
void func_00366718(void *);
void func_003668F0(void *);
void func_00367148(void *);
void func_0036A490(void);
void func_0036A758(void *);
void func_0036B0C8(void *);
void func_0036BA88(void *);
void func_0036C9F8(char *, char *, char *, f32, f32, f32);
void func_0036CEE8(void *);

void func_00344530(char *arg0) {
    char *temp_v0;

    func_0036A490();
    func_0036A758(arg0);
    func_0036B0C8(arg0);
    func_0036BA88(arg0);
    func_0036CEE8(arg0);
    func_00353EE8(arg0);
    func_00367148(arg0);
    func_00350080(arg0);
    func_00366718(arg0);
    func_00345658(arg0);
    func_00345A20(arg0);
    temp_v0 = arg0 + 0x104;
    func_0036C9F8(arg0 + 0x110, arg0 + 0x11C, arg0 + 0x128, *(f32 *)(temp_v0 + 0x568), *(f32 *)(temp_v0 + 0x56C), *(f32 *)(temp_v0 + 0x570));
    func_0035D350(arg0);
    func_0035DE20(arg0);
    func_00344040(arg0);
    func_003668F0(arg0);
    func_0034A668(arg0);
    func_0034A788(arg0);
}
