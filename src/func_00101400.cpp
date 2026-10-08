typedef int s32;

extern char D_00617CB8[];
extern char D_00617CF8[];

extern "C" void func_00100E40(s32 arg0);
extern "C" void func_00100EA0(void *buf);

extern "C" void func_00101400(void) {
    func_00100E40((s32)D_00617CB8);
    func_00100EA0(D_00617CF8);
}
