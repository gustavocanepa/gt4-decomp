/* libio (GNU iostream library, gcc 2000-10-03 snapshot): filebuf::setbuf.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
extern int _IO_file_setbuf(void);

int filebuf__virtual_09(void)
{
    return _IO_file_setbuf();
}
