typedef float f32;

struct Obj {
    char pad0[0x9C0];
    f32 unk9C0;
    char pad1[0x9D4 - 0x9C0 - 4];
    f32 unk9D4;
};

extern "C" void DevelopCamera__virtual_24(struct Obj *arg0);
extern "C" void func_0036FD88(void *arg0, f32 fparg0, f32 fparg1);

extern "C" void RacePhotoModeCameraManager__virtual_24(struct Obj *arg0) {
    DevelopCamera__virtual_24(arg0);
    func_0036FD88((char *)arg0 + 0xE28, arg0->unk9C0, arg0->unk9D4);
}
