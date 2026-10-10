struct func_005262B0_Obj {
    char pad0[0xE0];
    int (*handler)(int code, unsigned char *data, int size, int user);
    int pad1;
    int user;
};

extern "C" int func_00526438(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_005268F8(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_00526988(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_00526AF0(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_005269E8(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_00526B88(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_00526BB8(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_00526C00(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_00526D28(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_00526DF0(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_00526ED8(func_005262B0_Obj *self, int code, unsigned char *data);
extern "C" int func_00526F40(func_005262B0_Obj *self, int code, unsigned char *data, int size);

extern "C" int func_005262B0(func_005262B0_Obj *self, unsigned short code, unsigned int type, unsigned char *data, int size) {
    int r;
    switch (type) {
    case 0:
        if ((r = func_00526438(self, code, data)) != 0) return r;
        break;
    case 1:
        if ((r = func_005268F8(self, code, data)) != 0) return r;
        break;
    case 2:
        if ((r = func_00526988(self, code, data)) != 0) return r;
        break;
    case 3:
        if ((r = func_00526AF0(self, code, data)) != 0) return r;
        break;
    case 13:
        if ((r = func_005269E8(self, code, data)) != 0) return r;
        break;
    case 4:
        if ((r = func_00526B88(self, code, data)) != 0) return r;
        break;
    case 5:
        if ((r = func_00526BB8(self, code, data)) != 0) return r;
        break;
    case 6:
        if ((r = func_00526C00(self, code, data)) != 0) return r;
        break;
    case 7:
        if ((r = func_00526D28(self, code, data)) != 0) return r;
        break;
    case 8:
        if ((r = func_00526DF0(self, code, data)) != 0) return r;
        break;
    case 9:
        if ((r = func_00526ED8(self, code, data)) != 0) return r;
        break;
    case 10:
        self->handler(code, data + 2, size - 2, self->user);
        return 0;
    case 11:
        if ((r = func_00526F40(self, code, data, size)) != 0) return r;
        break;
    }
    return 0;
}
