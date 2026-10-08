typedef int s32;
typedef float f32;

struct Vec4 {
    f32 x, y, z, w;
};

extern "C" Vec4 *func_002030E8(Vec4 *arg0, Vec4 *arg1);

extern "C" void func_005E78F8(void *arg0, Vec4 *arg1) {
    func_002030E8((Vec4 *)((char *)arg0 + 0x144), arg1);
}
