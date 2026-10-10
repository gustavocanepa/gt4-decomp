/* A stack object: constructor (func_00109A78), one call, destructor with in-charge flag 2. */
struct Obj { char data[0xB0]; };

void func_00109A78(struct Obj *self);
void func_00109AB8(struct Obj *self, int flags);
int GranTurismo4__MenuGameObject__startProject(struct Obj *self, int a, int b);

int func_0010B290(int a, int b)
{
    struct Obj obj;
    int result;

    func_00109A78(&obj);
    result = GranTurismo4__MenuGameObject__startProject(&obj, a, b);
    func_00109AB8(&obj, 2);
    return result;
}
