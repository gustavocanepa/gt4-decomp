struct Vec3 { float x, y, z; };

struct Shape {
    int unk0;
    Vec3 inertia;
    char pad10[0x84];
    float mass;
    char pad98[8];
};

struct ShapeTable {
    char pad[0x20];
    Shape shapes[1];
};

struct Body {
    char pad[0x1C];
    Vec3 vel;
    Vec3 angVel;
    char pad34[0x10];
    unsigned char shape;
};

extern ShapeTable *D_006D6054;

extern "C" float func_005FE3A0(const Body *b) {
    const Shape &s = D_006D6054->shapes[b->shape];
    return s.inertia.x * b->angVel.x * b->angVel.x + s.inertia.y * b->angVel.y * b->angVel.y +
           s.inertia.z * b->angVel.z * b->angVel.z +
           s.mass * (b->vel.x * b->vel.x + b->vel.y * b->vel.y + b->vel.z * b->vel.z);
}
