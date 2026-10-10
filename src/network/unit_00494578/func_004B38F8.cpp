typedef unsigned char u8;
typedef unsigned int u32;
typedef int s32;

struct Obj {
    s32 a;
    u8 *data;
};

extern "C" u32 func_004B38F8(Obj *self, s32 i) {
    s32 off = i * 4 + 0x40;
    u8 *p = self->data + off;
    return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
}
