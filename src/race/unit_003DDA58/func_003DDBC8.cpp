/* compiler: ee-gcc2.96-no-strict-aliasing */
/* func_0036F880 without the clamp of x: binary search for the segment, then linear interpolation */
struct Point { float x, y; };
struct Tab { int n; Point points[1]; };
extern "C" float func_003DDBC8(Tab *t, float x) {
    int lo = 0;
    int hi = t->n;
    int n = hi;
    while (lo < hi) {
        int mid = (lo + hi) >> 1;
        if (x < t->points[mid].x) hi = mid;
        else lo = mid + 1;
    }
    hi = n - 1;
    int i = lo - 1;
    if (i >= hi) i = hi - 1;
    /* reusing hi for a's index keeps it live, so it ranks above n (a0/t0 as in retail) */
    hi = i;
    Point *a = &t->points[hi];
    Point *b = &t->points[i + 1];
    return (b->y - a->y) * (x - a->x) / (b->x - a->x) + a->y;
}
