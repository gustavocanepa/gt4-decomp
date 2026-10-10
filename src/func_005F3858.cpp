/* Named after their constructors so that the constructor calls resolve. */
struct func_003B08C8 {
    char data[0x6A0];
    func_003B08C8();
};

struct func_003B05A8 {
    char data[0x60];
    func_003B05A8();
};

struct Slot : func_003B08C8 {
    func_003B05A8 sub;
};

/* No known name: named after its vtable (0x006792C0). */
struct Base {
    virtual ~Base();
};

struct D_006792C0 : Base {
    virtual ~D_006792C0();
    int pad4[3];
    Slot slots[2];
    int mE10;
    int mE14;
    D_006792C0();
};

D_006792C0::D_006792C0() {
    mE10 = 0;
    mE14 = 0;
}
