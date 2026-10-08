typedef int s32;

struct Vec4 {
    float x, y, z, w;
};

struct Obj {
    char pad[0x134];
    Vec4 unk134;
};

extern "C" void func_002030E8(Vec4 *arg0);

extern "C" void func_005E78D0(struct Obj *arg0) {
    func_002030E8(&arg0->unk134);
}
