typedef int s32;

struct Obj003AAF40 {
    char pad[0x68];
    s32 unk68;
};

extern "C" void RaceRichCountDisplay__make_string(struct Obj003AAF40 *arg0);

extern "C" void RaceRichCountDisplay__setCount(struct Obj003AAF40 *arg0, s32 arg1) {
    s32 old = arg0->unk68;

    if (old != arg1) {
        arg0->unk68 = arg1;
        RaceRichCountDisplay__make_string(arg0);
    }
}
