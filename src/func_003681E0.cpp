extern "C" float func_00359568(const void *curve, float u);
extern const char D_00620C80[];
extern const char D_00620C90[];

extern "C" float func_003681E0(float u, float x, float t) {
    if (t <= x)
        return func_00359568(D_00620C80, u) * (x - t) / (1.0f - t);
    return func_00359568(D_00620C90, u) * (x - t) / (0.0f - t);
}
