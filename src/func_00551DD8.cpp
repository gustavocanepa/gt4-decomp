/* Real C++ constructor: base constructor, the compiler's own vtable store (_vt$10D_006898A8),
   two member objects, then the body. Classes without known names are named after their
   constructors or vtable so the references resolve (tools/symbols.py). */
class func_0055F4B0 {
public:
    func_0055F4B0();
    virtual void f0();
};

class func_00610AC8 {
public:
    func_00610AC8(void *owner);
    int v[3];
};

class func_00574D78 {
public:
    func_00574D78();
    int v[12];
};

extern "C" void func_00551C98(func_00610AC8 *m);

class D_006898A8 : public func_0055F4B0 {
public:
    D_006898A8(int id);
    virtual void f0();

    func_00610AC8 link;
    func_00574D78 lock;
    int id;
    int pad44[15];
    int count;
    int pad84[4];
    int flags;
};

D_006898A8::D_006898A8(int id_) : link(this)
{
    id = id_;
    count = 0;
    flags = 0;
    func_00551C98(&link);
}
