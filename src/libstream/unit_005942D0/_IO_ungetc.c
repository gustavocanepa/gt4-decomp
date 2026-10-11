/* compiler: ee-gcc2.96-no-strict-aliasing */
/* libio (GNU iostream library, gcc 2000-10-03 snapshot): _IO_ungetc.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
typedef unsigned char u8;

extern s32 _IO_sputbackc(void *fp, s32 c);

s32 _IO_ungetc(s32 c, void *fp) {
    if (c == -1) {
        return -1;
    }
    return _IO_sputbackc(fp, (u8)c);
}
