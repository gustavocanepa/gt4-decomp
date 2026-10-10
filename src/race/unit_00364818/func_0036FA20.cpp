extern "C" float func_0036FA20(int x) {
    float r;
    if (x < 0) {
        r = -x;
        r = 1.0f / r;
    } else if (x == 0) {
        r = 1.0f;
    } else {
        r = x;
        r = r / 100.0f;
    }
    return r;
}
