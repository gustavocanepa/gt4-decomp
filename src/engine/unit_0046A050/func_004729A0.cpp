struct Units {
    int pad0;
    unsigned int power;
};

extern "C" float func_004729A0(Units *self, float ps)
{
    switch (self->power) {
    case 0:
    case 3:
    case 5:
    case 6:
        return ps;
    case 1:
    case 2:
        return ps * 0x1.f8ede4p-1f;
    case 4:
        return ps * 0x1.789374p-1f;
    }
    return ps;
}
