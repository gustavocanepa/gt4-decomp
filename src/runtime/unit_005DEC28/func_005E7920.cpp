typedef int s32;

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    char pad[0x154];
    Vec4 unk154;
};

extern "C" void func_002030E8(Vec4 *arg0);

extern "C" void func_005E7920(struct Obj *arg0) {
    func_002030E8(&arg0->unk154);
}
