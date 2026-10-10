typedef int s32;

struct Obj003AAF70 {
    char pad[0x6C];
    s32 unk6C;
};

extern "C" void RaceRichCountDisplay__make_string(struct Obj003AAF70 *arg0);

extern "C" void RaceRichCountDisplay__setTotal(struct Obj003AAF70 *arg0, s32 arg1) {
    struct Obj003AAF70 *temp_v1 = arg0;

    if (temp_v1->unk6C != arg1) {
        temp_v1->unk6C = arg1;
        RaceRichCountDisplay__make_string(temp_v1);
    }
}
