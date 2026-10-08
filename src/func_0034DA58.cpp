typedef int s32;
typedef short s16;

struct Obj { char pad[0xF878]; s16 unkF878; };

extern "C" s32 func_0034DA58(Obj *arg0) {
    return arg0->unkF878 != 0;
}
