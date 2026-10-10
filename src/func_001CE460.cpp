struct Obj { char pad[0x24]; char name[1]; };
extern "C" char *func_005A609C(char *, const char *); /* strcpy */
extern "C" char *func_005A5DC8(char *, const char *); /* strcat */
extern "C" int func_0057F260(const char *);          /* strlen */
extern const char D_00694D60[];
extern const char D_00694E68[];

extern "C" char *func_001CE460(Obj *o, char *buf)
{
    buf[0] = '/';
    func_005A609C(buf + 1, o->name);
    func_005A5DC8(buf + 1, D_00694D60);
    char *p = buf + func_0057F260(buf);
    for (int i = 5; i >= 0; i--) *p++ = D_00694E68[i];
    *p = 0;
    return buf;
}
