/* libio (GNU iostream library, gcc 2000-10-03 snapshot): streambuf::streambuf.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

struct Obj00594120 {
    char pad[0x50];
    void *unk50;
};

extern char streambuf__vtable[];
extern "C" s32 func_00594FB8(Obj00594120 *arg0);

extern "C" s32 streambuf__structor_0(Obj00594120 *arg0) {
    arg0->unk50 = streambuf__vtable;
    return func_00594FB8(arg0);
}
