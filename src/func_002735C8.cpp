typedef int s32;
typedef float f32;

struct mImage {
    s32 m0;
    mImage() __asm__("mImage__structor_0");
    virtual ~mImage();
};

struct mImagePS2 : mImage {
    s32 m8;
    s32 mC;
    s32 m10;
    s32 m14;
    f32 m18;
    f32 m1C;
    s32 m20;
    mImagePS2();
    virtual ~mImagePS2();
};

mImagePS2::mImagePS2() : m8(0), mC(0), m10(0), m14(0), m18(0x1.000000p+0f), m1C(0x1.000000p+0f), m20(0) {
}
