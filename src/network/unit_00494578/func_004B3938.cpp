typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;
struct Obj { s32 f0; u8 *data; };
extern "C" u32 func_004B3938(Obj *o, s32 i) {
    u32 off = i * 4 + 0x40;
    u8 *p = o->data + off;
    return (p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24)) ^ ((i + 1) * 0x14AC327A);
}
