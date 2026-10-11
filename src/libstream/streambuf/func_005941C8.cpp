/* libio (GNU iostream library, gcc 2000-10-03 snapshot): streambuf::sputbackc.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
typedef signed char s8;

extern "C" s32 _IO_sputbackc(s32 arg0, s8 arg1);

extern "C" s32 func_005941C8(s32 arg0, s32 arg1) {
    return _IO_sputbackc(arg0, (s8)arg1);
}
