/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_getline (iogetline.c; a wrapper glued to _IO_getline_info)?.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;

extern "C" s32 _IO_getline_info(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5);

extern "C" s32 func_00596628(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    return _IO_getline_info(arg0, arg1, arg2, arg3, arg4, 0);
}
