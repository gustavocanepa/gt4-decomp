typedef int s32;

/* The base class; its constructor is hObject__structor_0. Its vptr sits at 0x4. */
struct hObject__structor_0 {
    s32 m0;
    hObject__structor_0();
    virtual ~hObject__structor_0();
};

/* A member object; its constructor is func_002286C0. */
struct func_002286C0 {
    s32 w[2];
    func_002286C0();
};

struct Pair {
    s32 a;
    s32 b;
    Pair() : a(0), b(0) {}
};

/* Named after its vtable so the compiler-made vptr store _vt$10D_0065CE20 resolves. */
struct mMemoryCardManager__vtable : hObject__structor_0 {
    char pad8[8];
    func_002286C0 m10;
    s32 m18;
    s32 m1C;
    s32 m20;
    s32 m24;
    s32 m28;
    Pair m2C;
    mMemoryCardManager__vtable();
    virtual ~mMemoryCardManager__vtable();
};

mMemoryCardManager__vtable::mMemoryCardManager__vtable() : m18(0), m1C(0), m20(0), m24(0) {
    m28 = 0;
}
