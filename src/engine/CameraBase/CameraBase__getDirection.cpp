struct Matrix {
    float m[4][4];
};

struct Vec3 {
    float x, y, z;
};

struct Node {
    virtual void v00(); virtual void v01(); virtual void v02(); virtual void v03();
    virtual void v04(); virtual void v05(); virtual void v06();
    virtual void getMatrix(Matrix *m);
};

extern "C" void CameraBase__getDirection(Node *n, Vec3 *out)
{
    Matrix m;
    n->getMatrix(&m);
    out->x = -m.m[0][2];
    out->y = -m.m[1][2];
    out->z = -m.m[2][2];
}
