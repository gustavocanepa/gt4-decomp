/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef float f32;

struct RefCounter {
    s32 count;
    virtual ~RefCounter();
};

struct hObject : RefCounter {
    s32 m8;
    s32 mC;
    hObject() __asm__("hObject__structor_0");
    virtual ~hObject();
};

struct Volume_002C3A88 {
    f32 gain;
    s32 m4;
    s32 m8;
    Volume_002C3A88() : gain(0x1.000000p+0f), m4(0), m8(-1) {}
};

struct mMusic : hObject {
    s32 m10;
    s32 m14;
    Volume_002C3A88 m18;
    mMusic();
    virtual ~mMusic();
};

mMusic::mMusic() : m10(0), m14(0) {
}
