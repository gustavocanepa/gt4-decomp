extern "C" int func_00486090(int lo, int hi, const float *keys, float t)
{
    while (hi - lo > 4) {
        int mid = ((lo + hi) >> 1) & ~3;
        if (t < keys[mid])
            hi = mid;
        else
            lo = mid;
    }
    return lo;
}
