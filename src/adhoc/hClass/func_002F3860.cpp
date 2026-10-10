/* Registers a native with two callbacks: interns the name, then hands it to func_002F3730. */
struct Obj;
struct Str;

extern "C" int HSymID__GetID(Str *name);
extern "C" void func_002F3730(Obj *obj, int *name, void (*cb1)(void), void (*cb2)(void));

extern "C" void func_002F3860(Obj *obj, Str *name, void (*cb1)(void), void (*cb2)(void))
{
    int id = HSymID__GetID(name);
    func_002F3730(obj, &id, cb1, cb2);
}
