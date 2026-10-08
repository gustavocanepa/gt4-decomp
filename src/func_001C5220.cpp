typedef int s32;
typedef long long s64;

struct Obj_001C5220 {
    char pad[0x10];
    s32 unk10;
    char pad2[0x278 - 0x14];
    s32 unk278;
};

extern "C" s64 func_0058C320(s32 arg0);

extern "C" void func_001C5220(Obj_001C5220 *arg0) {
    func_0058C320(arg0->unk10);
    arg0->unk278 = 0;
}
