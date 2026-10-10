extern void func_005A609C(void *arg0, const char *arg1);
extern void func_005A5DC8(void *arg0, void *arg1);

void *GT4Model__CarModel__getTireFileName(void *arg0, void *arg1, int arg2)
{
    const char *path;

    if (arg2 != 0) {
        path = "wheel/menu/";
    } else {
        path = "wheel/lod/";
    }
    func_005A609C(arg1, path);
    func_005A5DC8(arg1, arg0);
    return arg1;
}
