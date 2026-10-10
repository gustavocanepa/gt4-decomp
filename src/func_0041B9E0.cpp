typedef int u128 __attribute__((mode(TI)));

struct Vec4 {
    union {
        struct {
            float x, y, z, w;
        };
        u128 q;
    };
    Vec4() {}
    Vec4(const Vec4 &o) { q = o.q; }
    Vec4 &operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        return *this;
    }
    Vec4 operator*(float s) const {
        Vec4 r(*this);
        r *= s;
        return r;
    }
};

struct Base {
    char pad[0x20];
    virtual void v0();
    virtual void v1();
    virtual Vec4 getPosition();
};

struct Obj : Base {
    char pad24[0x20];
    float scale;
};

extern "C" Vec4 func_0041B9E0(Obj *o) {
    return o->getPosition() * o->scale;
}
