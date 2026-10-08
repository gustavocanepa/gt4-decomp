typedef int s32;
typedef unsigned int u32;

struct Obj {
    char pad[0xF898];
    s32 unkF898;
};

extern "C" u32 func_003584A0(Obj *arg0, s32 arg1) {
    return (u32)(arg0->unkF898 + arg1) / 3u;
}
