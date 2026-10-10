typedef long s64;

struct Obj {
    s64 unk0;
    s64 unk8;
    s64 unk10;
    s64 unk18;
    s64 unk20;
};

extern "C" void pgluTexReset(Obj *arg0) {
    arg0->unk0 = (s64)0x8000 << 19;
    arg0->unk8 = 0x60;
    arg0->unk18 = 0;
    arg0->unk20 = 0;
    arg0->unk10 = 0;
}
