typedef struct { float x, y, w, h; } Rect;
Rect *func_002314A8(void);
void func_00230A50(void *self, float *x, float *y) {
    Rect *r = func_002314A8();
    if (*x < r->x) *x = r->x;
    if (*y < r->y) *y = r->y;
    if (r->x + r->w < *x) *x = r->x + r->w;
    if (r->y + r->h < *y) *y = r->y + r->h;
}
