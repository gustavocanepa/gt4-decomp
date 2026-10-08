typedef int s32;
typedef unsigned char u8;

struct Obj {
    s32 unk0;
};

extern "C" u8 *func_00359510(s32 arg0);

extern "C" u8 func_00364A78(Obj *arg0) {
    return *func_00359510(arg0->unk0 + 0x600);
}
