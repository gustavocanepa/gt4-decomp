typedef int s32;
typedef float f32;

struct Query_003EBC88 {
    s32 m0;
    f32 m4;
    f32 m8;
    s32 mC;
    s32 m10;
    s32 m14;
    Query_003EBC88(f32 a = 0.0f, f32 b = 0.0f) : m0(0), m4(a), m8(b), mC(0), m10(0), m14(0) {}
};

struct Key_003EBC88 {
    s32 id;
    f32 t;
};

extern "C" s32 func_00429E10(Query_003EBC88 *q, void *ctx, s32 id, f32 t);

extern "C" s32 func_003EBC88(Key_003EBC88 *k, void *ctx) {
    if (ctx == 0 || k->id < 0) {
        return 0;
    }
    Query_003EBC88 q;
    if (func_00429E10(&q, ctx, k->id, k->t)) {
        return q.mC;
    }
    return 0;
}
