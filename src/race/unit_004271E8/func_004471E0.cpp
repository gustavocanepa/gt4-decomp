extern char D_006235A8[];
extern "C" int func_00443E00(void *db, int key, int type);
extern "C" int SPEC_DATABASE__RaceSpec__setCourse(void *self, int id);

extern "C" int func_004471E0(void *self, int key) {
    int id = func_00443E00(D_006235A8, key, 0x22);
    if (id == -1)
        return 0;
    return SPEC_DATABASE__RaceSpec__setCourse(self, id);
}
