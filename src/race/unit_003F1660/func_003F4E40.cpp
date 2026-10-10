struct Part { char pad[0x31]; unsigned char kind; char pad2; unsigned char flags; };

extern "C" int func_003F4E40(Part *p)
{
    if (!(p->flags & 2))
        return p->kind;
    int kind = p->kind;
    switch (kind) {
    case 0:
    case 7:
        kind = 0x14;
        break;
    case 1:
    case 10:
    case 11:
    case 12:
        kind = 0x15;
        break;
    case 9:
        kind = 0x16;
        break;
    }
    return kind;
}
