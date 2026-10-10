typedef int s32;

struct S_00249FF0;

extern "C" void func_00235E68(struct S_00249FF0 *arg0, s32 arg1);
extern "C" struct S_00249FF0 *mWidget__getRootWindow(void);

extern "C" void func_00249FF0(void) {
    struct S_00249FF0 *temp_v0 = mWidget__getRootWindow();

    if (temp_v0 != 0) {
        func_00235E68(temp_v0, 0);
    }
}
