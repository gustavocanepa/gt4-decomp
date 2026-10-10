struct P { int pad[2]; int b; int c; char pad2[0x28]; int f; };
float func_001058B8(struct P *p) {
    float w = p->c;
    float h = p->b;
    if (p->f) w = w + w;
    return w / h;
}
