struct Slot {
    int count;
    char pad4[0x2AC];
    int id;
    unsigned int flags;
    void clear() { flags &= ~0xFF; }
    void reset() { count = 0; id = -1; clear(); }
};

struct Player {
    int cur;
    int pending;
    int active;
    char padC[0x640];
    Slot slots[2];
    char padBBC_pad[0xBBC - 0x64C - 2 * 0x2B8];
    int bbc;
    int bc0;
    int bc4;
    int bc8;
    int bcc;
    int bd0;
    int bd4;
};

extern "C" void func_001C6B78(Player *p)
{
    p->active = 1;
    p->cur = -1;
    p->pending = -1;
    for (int i = 0; i < 2; i++)
        p->slots[i].reset();
    p->bd4 = 0;
    p->bbc = 0;
    p->bc0 = 0;
    p->bc4 = 0;
    p->bc8 = -1;
    p->bd0 = 0;
    p->bcc = -1;
}
