typedef unsigned int u128 __attribute__((mode(TI)));
struct Mat { char pad[0x48]; unsigned short flags; char pad2[0xA16]; u128 rows[4]; };

extern "C" void func_004ABCE0(Mat *m, int unused, unsigned int which, u128 v)
{
    switch (which) {
    case 1:
        m->rows[1] = v;
        break;
    case 2:
        m->rows[1] = v;
    case 0:
        m->rows[0] = v;
        break;
    case 4:
        m->rows[2] = v;
        break;
    case 3:
        m->rows[3] = v;
        break;
    }
    m->flags |= 4;
}
