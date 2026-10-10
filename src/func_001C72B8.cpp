struct Entry {
    int type;
    char pad[0x50];
};

struct Machine {
    Entry e[2];
    int cur;
    int next;
};

extern "C" int func_001C72B8(Machine *m)
{
    int t = m->e[m->cur].type;
    int ok = 0;
    if (t == 2 || t == 5)
        ok = 1;
    t = m->e[m->next].type;
    int r = t == 5;
    return ok ? r : 0;
}
