typedef float f32;

struct Obj005FD900 {
    char pad[0x1E660];
    f32 unk1E660;
    f32 unk1E664;
};

extern "C" void func_005FD900(struct Obj005FD900 *arg0, f32 fparg0, f32 fparg1) {
    arg0->unk1E660 = fparg0;
    arg0->unk1E664 = fparg1;
}
