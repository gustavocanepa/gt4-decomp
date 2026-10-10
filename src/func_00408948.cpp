typedef int s32;

/* The base class (Concourse); its constructor is func_00407FE0. Its vptr sits at 0x10. */
struct func_00407FE0 {
    char pad[0x10];
    func_00407FE0();
    virtual ~func_00407FE0();
};

/* A member object; its constructor is func_00408A28. */
struct func_00408A28 {
    char data[0x3C];
    func_00408A28();
};

struct LicenseConcourse : func_00407FE0 {
    s32 m14;
    s32 m18;
    s32 m1C;
    s32 m20;
    s32 m24;
    s32 m28;
    char pad2C[0xC];
    s32 m38;
    func_00408A28 m3C;
    s32 m78;
    s32 m7C;
    s32 m80;
    LicenseConcourse();
    virtual ~LicenseConcourse();
};

LicenseConcourse::LicenseConcourse() : m14(0), m18(0), m20(0), m24(0), m28(0), m38(0) {
    m78 = 0;
    m7C = 0;
    m80 = 0;
}
