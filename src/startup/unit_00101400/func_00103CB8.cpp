extern void func_005A609C(void *arg0, const char *arg1);
extern void func_005A5DC8(void *arg0, const char *arg1);
extern const char *D_00618420;
extern const char D_0068BE70[];
extern const char D_006DE8D8[];

void *func_00103CB8(void *str, const char *name)
{
    func_005A609C(str, D_00618420);
    func_005A5DC8(str, name);
    func_005A5DC8(str, D_0068BE70);
    func_005A5DC8(str, D_006DE8D8);
    return str;
}
