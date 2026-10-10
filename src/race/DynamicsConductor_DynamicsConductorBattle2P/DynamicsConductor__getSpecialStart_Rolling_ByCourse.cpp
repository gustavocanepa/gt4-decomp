struct Item {
    char pad[0x19];
    unsigned char w;
    unsigned char h;
};

extern "C" int DynamicsConductor__getCourseType(void *o, int id);
extern "C" Item *GetADPsource(void *o, int index, int flags);

extern "C" int DynamicsConductor__getSpecialStart_Rolling_ByCourse(void *o, int id, int *kind, int *x, int *y) {
    Item *it = GetADPsource(o, DynamicsConductor__getCourseType(o, id), 0);
    int dx = -(it->w * 10);
    int dy = it->h * 5;
    if (dx < 0 && dy > 0) {
        *kind = 3;
        *x = dx;
        *y = dy;
        return 1;
    }
    return 0;
}
