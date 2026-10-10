struct Counts {
    char pad0[0x20];
    unsigned short n[6];
};

extern "C" int func_004475A8(Counts *c, unsigned int kind)
{
    unsigned int v = 0;
    switch (kind) {
    case 0:
        v = c->n[0];
        break;
    case 1:
        v = c->n[1];
        break;
    case 2:
        v = c->n[2];
        break;
    case 3:
        v = c->n[3];
        break;
    case 4:
        v = c->n[4];
        break;
    case 5:
        v = c->n[5];
        break;
    }
    return v * 100;
}
