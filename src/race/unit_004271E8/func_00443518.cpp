struct Resource {
    int a;
    int b;
};

struct Resources {
    char dir[0x80];
    Resource *common[0x2B];
    Resource *localized[0x2B];
    int pad;
    Resource *index;
};

struct Loader {
    int f0;
    int language;
    Resources res;
};

extern char *D_00623580[];  /* language suffixes */
extern char *D_006234B0[];  /* resource names */
extern char D_00623798[];   /* localized resource ids, 0x2B terminated */
extern char D_006A6D20[];
extern char D_006A6D28[];
extern char D_006A6D30[];

extern "C" int func_0057F238(const char *, const char *) throw();
extern "C" char *func_005A609C(char *, const char *);
extern "C" char *func_005A5DC8(char *, const char *);
extern "C" int func_00443DC0(Loader *, int);
extern "C" int func_00449070(Resource *, char *, int, int);
extern "C" int func_004498E8(Resource *, char *, int, int);
extern "C" int func_00449C58(Resource *, char *, int, int);

extern "C" void func_00443518(Loader *self, const char *name) {
    char path[0x100];
    int language = -1;

    for (int i = 0; i < 9; i++) {
        if (func_0057F238(name, D_00623580[i]) == 0) {
            language = i;
            break;
        }
    }
    if (language == -1) language = 0;
    if (self->language == language) return;
    self->language = language;

    for (int i = 0; i < 0x2B; i++) {
        if (func_00443DC0(self, i)) {
            func_005A609C(path, self->res.dir);
            func_005A5DC8(path, D_006234B0[i]);
            func_005A5DC8(path, D_00623580[self->language]);
            func_005A5DC8(path, D_006A6D20);
            Resource *r = self->res.localized[i];
            func_00449070(r, path, r->a, r->b);
        }
    }
    for (int n = 0; D_00623798[n] != 0x2B; n++) {
        int id = D_00623798[n];
        if (func_00443DC0(self, id)) {
            func_005A609C(path, self->res.dir);
            func_005A5DC8(path, D_006234B0[id]);
            func_005A5DC8(path, D_00623580[self->language]);
            func_005A5DC8(path, D_006A6D28);
            Resource *r = self->res.common[id];
            func_004498E8(r, path, r->a, r->b);
        }
    }
    func_005A609C(path, self->res.dir);
    func_005A5DC8(path, D_00623580[self->language]);
    func_005A5DC8(path, D_006A6D30);
    Resource *r = self->res.index;
    func_00449C58(r, path, r->a, r->b);
}
