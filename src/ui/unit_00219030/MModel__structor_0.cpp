/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Vec3 {
    float x, y, z;
    Vec3() : x(0.0f), y(0.0f), z(0.0f) {}
};

struct Vec4 {
    float x, y, z, w;
    Vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
};

struct MModel {
    Vec4 m0;
    s32 m10, m14, m18, m1C, m20;
    float scale;
    s32 m28;
    s32 m2C;
    Vec3 v30;
    Vec3 v3C;
    MModel();
    virtual ~MModel();
};

MModel::MModel()
    : m10(0), m14(0), m18(0), m1C(0), m20(0),
      scale(1.0f), m28(0), m2C(1) {
}
