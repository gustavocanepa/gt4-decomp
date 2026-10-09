typedef int s32;

struct S_00249FF0;

extern "C" void func_00235E68(struct S_00249FF0 *arg0, s32 arg1);
extern "C" struct S_00249FF0 *func_0025C1E8(void);

extern "C" void func_00249FF0(void) {
    struct S_00249FF0 *temp_v0 = func_0025C1E8();

    if (temp_v0 != 0) {
        func_00235E68(temp_v0, 0);
    }
}
