typedef int s32;

extern "C" void func_003A4F00(void *arg0, float arg1);
extern "C" void func_003A68C8(char *arg0);

struct Obj0039CD70 {
    char pad[0x17BC];
};

extern "C" void func_0039CD70(struct Obj0039CD70 *arg0) {
    func_003A4F00((char *)arg0 + 0x17BC, 0.0f);
    func_003A68C8((char *)arg0 + 0x2D14);
}
