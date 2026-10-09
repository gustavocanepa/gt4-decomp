typedef int s32;

struct Obj002BBFA8 {
    char pad0[0x308];
    s32 unk308;
};

struct Buf002BBFA8 {
    struct Obj002BBFA8 *unk0;
    char pad[0xC];
};

extern "C" void func_002BAB38(struct Buf002BBFA8 *arg0);
extern "C" void func_002BAAE0(struct Buf002BBFA8 *arg0, int arg1);

extern "C" void MModelFace__stopRotate(void) {
    struct Buf002BBFA8 buf;
    struct Obj002BBFA8 *p;

    func_002BAB38(&buf);
    p = buf.unk0;
    p->unk308 |= 1;
    func_002BAAE0(&buf, 2);
}
