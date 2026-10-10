struct Vec3 { float x, y, z; };
struct SparkParticle {
    int m0, m4;
    unsigned short flags;
    short pad;
    Vec3 pos;
    char pad2[0x2C - 0x18];
    float width;
    char pad3[0x4C - 0x30];
    Vec3 last;
    void Render();
};
extern "C" void func_004A7AA8(Vec3 *, Vec3 *);
extern "C" void func_004A53F8(void);
extern "C" void func_004A7454(void);
extern "C" void func_004A5400(void);
extern "C" int SparkParticle__getColor(SparkParticle *);
extern "C" void ThickLine2(Vec3 *, Vec3 *, int, float);

void SparkParticle::Render()
{
    Vec3 v;
    func_004A7AA8(&v, &pos);
    if (flags & 1) {
        func_004A53F8();
        func_004A7454();
        ThickLine2(&last, &v, SparkParticle__getColor(this), width);
        func_004A5400();
    } else {
        flags |= 1;
    }
    last.x = v.x;
    last.y = v.y;
    last.z = v.z;
}
