struct Key {
    int pad0;
    float time;
    char pad8[0x74];
};

struct Track {
    char pad0[0x20];
    int count;
    Key *keys;
};

extern "C" int func_003DDF88(Track *self, float t)
{
    Key *keys = self->keys;
    if (t < keys[0].time)
        return -1;
    int lo = 0;
    int hi = self->count;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (t < keys[mid].time)
            hi = mid;
        else
            lo = mid + 1;
    }
    return lo - 1;
}
