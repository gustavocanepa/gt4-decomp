struct Entry {
    short key;
    int value;
};

struct Table {
    char pad[8];
    Entry e[0x100];
    unsigned char counts[0x1C];
    int n;
};

extern "C" int RaceEventQueue__check(Table *t, int key, int *out, int nth)
{
    if (nth < t->counts[key]) {
        for (int i = 0; i < t->n; i++) {
            if (t->e[i].key == key) {
                if (nth == 0) {
                    if (out)
                        *out = t->e[i].value;
                    return 1;
                }
                nth--;
            }
        }
    }
    return 0;
}
