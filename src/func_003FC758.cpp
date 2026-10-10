extern "C" int func_003FC758(int n, const float *w, float r)
{
    int i; for (i = 0; i < n; i++) { r -= *w++; if (r < 0.0f) break; } if (i < 0) i = 0; if (i >= n) i = n - 1; return i;
}
