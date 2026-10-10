struct Obj {
    void *items[0x18];
    void *map;
};

extern "C" int func_005657E0(void *map, int key, int *index);

extern "C" int func_00565B30(Obj *self, int key, void **out) {
    int index;
    int err = func_005657E0(self->map, key, &index);
    if (err == 0)
        *out = self->items[index];
    return err;
}
