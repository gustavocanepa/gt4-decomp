struct View {
    char pad0[3];
    unsigned char dirty;
    char pad4[0x268];
    unsigned short ox;
    unsigned short oy;
    char pad270[0x18];
    int w;
    int h;
    int sx;
    int sy;
    char pad298[0xD08];
    float fa0;
    float fa4;
    char pada8[8];
    float fb0;
    float fb4;
};

extern "C" void func_004A2D60(View *v) {
    v->dirty = 0;
    v->fa0 = (float)v->sx * 0.5f;
    v->fa4 = (float)-v->sy * 0.5f;
    v->fb0 = (float)(v->ox + (v->w << 4) + (v->sx << 3)) * 0.0625f;
    v->fb4 = (float)(v->oy + (v->h << 4) + (v->sy << 3)) * 0.0625f;
}
