typedef int s32;

struct S00305570 {
    char pad0[0x10];
    s32 unk10;
};

extern "C" s32 HSymID__GetName(s32 arg0);

extern "C" void hModule__getName(struct S00305570 *arg0) {
    HSymID__GetName(arg0->unk10);
}
