typedef long s64;
typedef int s32;

struct Obj003BFD58 {
    char pad0[0x68];
    s64 unk68;
    s32 unk70;
    char pad1[4];
    s64 unk78;
};

extern "C" void func_004470E8(s32 arg0);
extern "C" s64 SPEC_DATABASE__RaceSpec__getCourseCode(s32 arg0);

extern "C" void func_003BFD58(struct Obj003BFD58 *arg0, s64 arg1) {
    struct Obj003BFD58 *s0 = arg0;
    s0->unk68 = arg1;
    func_004470E8(s0->unk70);
    s0->unk78 = SPEC_DATABASE__RaceSpec__getCourseCode(s0->unk70);
}
