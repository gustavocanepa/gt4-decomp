struct C { char pad[0x34]; int f34; };
extern void mWidget__setWindowGeometry(struct C *, int *, float *, float *, int, int);
void mWidget__setWindowX(struct C *c, float y)
{
    mWidget__setWindowGeometry(c, &c->f34, &y, 0, 0, 0);
}
