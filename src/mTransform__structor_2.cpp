/* compiler: ee-gcc2.96-no-strict-aliasing */
struct hObject {
    int m0;
    virtual ~hObject();
    hObject() __asm__("hObject__structor_0");
};

struct Mat3 {
    float m[3][3];
};

struct mTransform : hObject {
    int m8;
    int mC;
    Mat3 mat;
    mTransform(const Mat3 *src);
    virtual ~mTransform();
};

mTransform::mTransform(const Mat3 *src) {
    Mat3 *d = &mat;
    d->m[0][0] = src->m[0][0];
    d->m[1][0] = src->m[1][0];
    d->m[2][0] = src->m[2][0];
    d->m[0][1] = src->m[0][1];
    d->m[1][1] = src->m[1][1];
    d->m[2][1] = src->m[2][1];
    d->m[0][2] = src->m[0][2];
    d->m[1][2] = src->m[1][2];
    d->m[2][2] = src->m[2][2];
}
