typedef int s32;
typedef unsigned int u32;

struct Obj_00358468 {
    char pad[0xF898];
    s32 unkF898;
};

extern "C" s32 func_00358468(struct Obj_00358468 *arg0, s32 arg1) {
    u32 x = (u32)(arg0->unkF898 + arg1);
    u32 q = x / 3u;
    return (s32)(x - q * 3u);
}
