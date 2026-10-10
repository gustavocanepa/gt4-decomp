#include "gt4/FileInstrumentStream.h"
extern "C" void func_004AFCE8(void *arg0, void *arg1);
extern "C" void func_005C1628(void *arg0);

extern void *FileInstrumentStream__vtable;

extern "C" void FileInstrumentStream__structor_1(struct FileInstrumentStream *arg0, int arg1) {
    arg0->unk20 = &FileInstrumentStream__vtable;
    func_004AFCE8(arg0, 0);
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}
