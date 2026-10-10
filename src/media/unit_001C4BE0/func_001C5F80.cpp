struct func_001C5F80_Obj {
    unsigned int state;
    char pad4[0x2C - 0x4];
    int frames;
    int steps;
    int tick;
    int pos;
    int speed;
    int count;
};

extern "C" float func_001C5F60(func_001C5F80_Obj *self);

extern "C" void func_001C5F80(func_001C5F80_Obj *self) {
    if (self->count < 0) self->count = 0;
    self->tick++;
    int pos = self->pos + self->speed;
    if (pos < 0) pos = 0;
    self->pos = pos;
    float fpos = pos;
    if (func_001C5F60(self) < fpos) self->pos = (int)func_001C5F60(self);
    switch (self->state) {
    case 0:
        if (++self->count >= self->steps) {
            self->count = 0;
            self->state = 1;
        }
        break;
    case 1:
        if (self->tick >= self->frames) {
            self->count = 0;
            self->state = 2;
        }
        break;
    case 2:
        break;
    case 3:
        if (++self->count >= self->steps) {
            self->count = 0;
            self->state = 4;
        }
        break;
    case 4:
        if (++self->count >= 4) {
            self->count = 0;
            self->state = 5;
        }
        break;
    }
}
