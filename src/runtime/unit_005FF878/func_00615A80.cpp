/* libio (GNU iostream library, gcc 2000-10-03 snapshot): an out-of-line (linkonce) copy of an inline function or member of libio's classes, from the block of such copies libio's objects brought (0x614068-0x616370, grouped by class around each class's type_info function).
 * licence: libio (GPLv2 with the libio special exception, see THIRD_PARTY.md) */
struct Req {
    void *buf;
    int size;
    int done;
    int pad;
    long long flags;
    short unit;
    char mode;
    char busy;
    int retries;
    int error;
};

extern "C" void func_00615A80(Req *r, void *buf, int size)
{
    if (buf == 0)
        r->mode = 4;
    else
        r->mode = 0;
    r->buf = buf;
    r->size = size;
    r->unit = 0x20;
    r->flags = 0x11;
    r->retries = 6;
    r->busy = 0;
    r->done = 0;
    r->error = 0;
}
