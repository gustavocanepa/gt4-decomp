typedef int s32;
typedef unsigned char u8;

extern s32 D_00623A38;

struct Obj003923A0 {
    u8 pad0[0xAF4];
    s32 unkAF4;
};

extern "C" s32 func_00462798(s32 arg0);

extern "C" void func_003923A0(struct Obj003923A0 *arg0) {
    s32 temp_v1 = D_00623A38;
    arg0->unkAF4 = temp_v1;
    func_00462798(temp_v1 + 0x25800);
}
