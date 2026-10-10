/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Range {
    s32 a, b, c;
    s32 lo;
    s32 hi;
    Range() {
        a = 0;
        b = 0;
        c = 0;
        lo = -1;
        hi = 1;
    }
};

struct mData {
    s32 base0;
    mData() __asm__("mData__structor_0");
    virtual ~mData();
};

struct mModelMotion : public mData {
    void *unk8;
    void *unkC;
    Range range;
    mModelMotion() __asm__("mModelMotion__structor_0");
    virtual ~mModelMotion();
};

mModelMotion::mModelMotion() : unk8(0), unkC(0) {
}
