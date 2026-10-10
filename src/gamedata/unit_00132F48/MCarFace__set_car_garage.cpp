typedef int s32;

/* Classes named after their constructors (func_00137DB8, func_0013BDC0); their sizes are only
   bounded by the frame (the first takes 0x11-0x20 bytes, the second at most 0x10). */
struct func_00137DB8 {
    void *p;
    char data[0x1C];
    func_00137DB8(void *src);
    ~func_00137DB8() { func_00137D60(this, 2); }
    static void func_00137D60(func_00137DB8 *self, s32 flags);
};

struct func_0013BDC0 {
    void *p;
    char data[0xC];
    func_0013BDC0(void *src);
    ~func_0013BDC0() { func_0013BD68(this, 2); }
    static void func_0013BD68(func_0013BDC0 *self, s32 flags);
};

extern "C" void func_0013A9E0(void *obj, func_0013BDC0 *arg);

extern "C" void MCarFace__set_car_garage(void *self, void *a, void *b, void *c) {
    func_00137DB8 x(a);
    void *obj = x.p;
    func_0013BDC0 y(c);
    func_0013A9E0(obj, &y);
}
