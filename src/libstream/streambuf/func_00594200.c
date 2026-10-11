/* libio (GNU iostream library, gcc 2000-10-03 snapshot): streambuf::get_column.
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
typedef int s32;
typedef unsigned short u16;

typedef struct Self { char pad[0x10]; s32 m10; s32 m14; char pad2[0x30]; u16 m48; } Self;
s32 _IO_adjust_column(s32, s32, s32);

s32 func_00594200(Self *self) {
    if (self->m48 != 0) {
        return _IO_adjust_column(self->m48 - 1, self->m10, self->m14 - self->m10);
    }
    return -1;
}
