typedef int s32;

/* hObject; its constructor is hObject__structor_0. The vptr follows its first word. */
struct hObject__structor_0 {
    s32 m0;
    hObject__structor_0();
    virtual ~hObject__structor_0();
};

struct mMemoryCardPlayList : hObject__structor_0 {
    s32 m8, mC;
    s32 m10;
    s32 m14;
    mMemoryCardPlayList(s32 a);
    virtual ~mMemoryCardPlayList();
};

mMemoryCardPlayList::mMemoryCardPlayList(s32 a) : m10(a), m14(0) {
}
