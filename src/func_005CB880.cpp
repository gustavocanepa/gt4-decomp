typedef int s32;

/* hObject; its constructor is func_0030A678. The vptr follows its first word. */
struct func_0030A678 {
    s32 m0;
    func_0030A678();
    virtual ~func_0030A678();
};

struct mMemoryCardFile : func_0030A678 {
    s32 m8, mC;
    s32 m10;
    s32 m14;
    mMemoryCardFile(s32 a);
    virtual ~mMemoryCardFile();
};

mMemoryCardFile::mMemoryCardFile(s32 a) : m10(a), m14(0) {
}
