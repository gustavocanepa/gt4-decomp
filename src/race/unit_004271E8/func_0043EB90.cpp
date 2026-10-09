typedef int s32;
typedef unsigned short u16;

struct Elem0043EB90 {
    char pad[0x130];
    u16 unk130;
};

struct Obj0043EB90 {
    char pad[0x490];
    s32 unk490;
};

extern "C" u16 func_0043EB90(Obj0043EB90 *arg0) {
    return ((Elem0043EB90 *)((char *)arg0 + arg0->unk490 * 0x178))->unk130;
}
