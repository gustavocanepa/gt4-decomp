struct func_00230CF8_Obj {
    char pad0[0x1D14];
    float left;
    float top;
    float right;
    float bottom;
    unsigned int corner;
    int dirty;
    float x;
    float y;
    float angle;
    int pad1D38;
    int pad1D3C;
    int placed;
};

extern "C" int func_0022F0F8(func_00230CF8_Obj *self);
extern "C" void func_00230A50(func_00230CF8_Obj *self, float *x, float *y);

extern "C" void func_00230CF8(func_00230CF8_Obj *self) {
    float x, y;
    if (!func_0022F0F8(self)) return;
    if (!self->dirty) return;
    float left = self->left + 2.0f;
    float top = self->top + 2.0f;
    self->dirty = 0;
    float right = self->right - 2.0f;
    float bottom = self->bottom - 2.0f;
    switch (self->corner) {
    case 0:
        x = left;
        y = (top + bottom) * 0.5f;
        self->angle = 45.0f;
        break;
    case 1:
        x = left;
        y = bottom;
        self->angle = 22.5f;
        break;
    case 2:
        x = (left + right) * 0.5f;
        y = bottom;
        self->angle = 0.0f;
        break;
    case 4:
        x = right;
        y = (top + bottom) * 0.5f;
        self->angle = -45.0f;
        break;
    case 5:
        x = right;
        y = top;
        self->angle = 45.0f;
        break;
    case 6:
        x = (left + right) * 0.5f;
        y = top;
        self->angle = 45.0f;
        break;
    case 7:
        x = left;
        y = top;
        self->angle = 45.0f;
        break;
    case 8:
        x = (left + right) * 0.5f;
        y = (top + bottom) * 0.5f;
        self->angle = -22.5f;
        break;
    case 3:
    default:
        x = right;
        y = bottom;
        self->angle = -22.5f;
        break;
    }
    func_00230A50(self, &x, &y);
    self->x = x;
    self->placed = 1;
    self->y = y;
}
