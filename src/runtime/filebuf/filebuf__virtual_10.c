/* libio (GNU iostream library, gcc 2000-10-03 snapshot): filebuf::sync.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
extern void _IO_file_sync(void);
void filebuf__virtual_10(void)
{
    _IO_file_sync();
}
