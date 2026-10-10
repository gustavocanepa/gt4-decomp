struct P { int pad[6]; int b; int c; char pad2[0x18]; int f; };
float func_001058E8(struct P *p) {
    float w = p->c;
    float h = p->b;
    if (p->f) w = w + w;
    return w / h;
}
