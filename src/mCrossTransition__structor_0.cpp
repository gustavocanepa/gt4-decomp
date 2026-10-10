struct hObject {
    int m0;
    virtual ~hObject();
};

struct mTransition : hObject {
    int m8;
    int mC;
    int m10;
    int m14;
    int m18;
    int m1C;
    mTransition() __asm__("mTransition__structor_0");
};

struct mCrossTransition : mTransition {
    int m20;
    int m24;
    float m28;
    float m2C;
    float m30;
    int m34;
    int m38;
    int m3C;
    mCrossTransition() __asm__("mCrossTransition__structor_0");
    ~mCrossTransition();
};

mCrossTransition::mCrossTransition() {
    m28 = 0x1.999998p-4f;
    m30 = 0.5f;
    m20 = 1;
    m24 = 0;
    m34 = 0;
    m3C = 0;
    m38 = 1;
    m2C = 0x1.11111p-5f;
}
