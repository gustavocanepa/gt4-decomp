typedef int s32;
typedef long long s64;
typedef unsigned char u8;
typedef unsigned short u16;

struct Global;
extern Global D_006235A8;

struct Info {
    char pad0[0x25];
    u8 f25;
    char pad26[0xA];
};

struct Obj {
    char pad0[0x48];
    s64 id;
    char pad50[0xC0];
    u16 f110[12];
    char pad128[0x2];
    u8 f12A;
};

extern "C" s32 SPEC_DATABASE__DatabaseStorage__IsExistID(Global *g, s64 id);
extern "C" s32 SPEC_DATABASE__DatabaseStorage__getRow(Global *g, s64 id, Info *info);
extern "C" void func_004413C8(Obj *self, char *buf);
extern "C" void func_00354FF8(char *buf, s32 off, u16 *out, s32 n);

extern "C" s32 func_00443240(Obj *self) {
    s64 id = self->id;
    if (SPEC_DATABASE__DatabaseStorage__IsExistID(&D_006235A8, id) == 0) {
        return 0;
    }
    Info info;
    SPEC_DATABASE__DatabaseStorage__getRow(&D_006235A8, id, &info);
    if (info.f25 == 0) {
        return 1;
    }
    {
        u16 tmp[16];
        char buf[0x600];
        s32 i;
        func_004413C8(self, buf);
        func_00354FF8(buf, self->f12A * 10, tmp, 1);
        for (i = 0; i < 12; i++) {
            self->f110[i] = tmp[i];
        }
    }
    return 1;
}
