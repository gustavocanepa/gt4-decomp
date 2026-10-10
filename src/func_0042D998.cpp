struct Key { int pad[2]; float time; };
struct Track { int pad[3]; Key *keys[1]; };

extern "C" int func_0042D998(Track *t, int lo, int hi, float time)
{
    while (hi - lo >= 2) {
        int mid = (lo + hi) >> 1;
        if (time < t->keys[mid]->time)
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}
