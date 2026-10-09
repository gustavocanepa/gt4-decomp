typedef short s16;
typedef int s32;

struct VEntry001CC8F8 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *);
};

struct Obj001CC8F8 {
    VEntry001CC8F8 *vtbl;
};

extern "C" s32 func_001CC8F8(struct Obj001CC8F8 *arg0) {
    VEntry001CC8F8 *e = (VEntry001CC8F8 *)((char *)arg0->vtbl + 0x50);

    return e->fn((char *)arg0 + e->delta) == 0;
}
