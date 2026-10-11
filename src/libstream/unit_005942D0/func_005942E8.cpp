/* libio (GNU iostream library, gcc 2000-10-03 snapshot): streammarker::~streammarker.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
extern "C" void _IO_remove_marker();
extern "C" void func_005C1628(void *arg0);

extern "C" void func_005942E8(void *arg0, int arg1) {
    _IO_remove_marker();
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
