/* libio (GNU iostream library, gcc 2000-10-03 snapshot): filebuf::overflow.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
extern "C" int _IO_file_overflow(void);

extern "C" int filebuf__virtual_01(void)
{
    return _IO_file_overflow();
}
