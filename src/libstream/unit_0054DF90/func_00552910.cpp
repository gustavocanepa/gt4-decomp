struct Obj {
    char pad0[0x14];
    int active;
    char pad18[0x5C - 0x18];
    void *sender;
    void *map;
};

extern "C" int func_005657E0(void *map, int key, int *index);
extern "C" void func_00553EF8(void *sender, Obj *self, int index, int type, void *data, int size, int flag);

extern "C" void func_00552910(Obj *self, int value) {
    int index;
    if (self->active && func_005657E0(self->map, 0, &index) == 0)
        func_00553EF8(self->sender, self, index, 6, &value, 4, 1);
}
