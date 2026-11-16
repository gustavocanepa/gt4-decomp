/* compiler: ee-gcc2.96-no-strict-aliasing */
/* deepCopy of mListBox: copies the base mScrollable state, then the list-box-specific block from the original object.
 * The original (arg1) is converted to mListBox with the compiler's dynamic cast helper (the call taking the type-info objects mListBox__tf and hObject__tf and the object's
 * vtable offset); when the cast fails or arg1 is null nothing more is copied. Otherwise the nine words at +0xEC..+0x10C are copied in order: two ints (+0xEC, +0xF0),
 * five floats (+0xF4..+0x104) and two ints (+0x108, +0x10C). Purpose of the individual members is unknown. */
typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef float f32;

extern "C" void mScrollable__deepCopy(void *self, void *original);
extern "C" int __dynamic_cast_2(s32, s32, s32, void *, s32, void *);

extern char mListBox__tf[];
extern char hObject__tf[];

extern "C" void mListBox__deepCopy(void *self, void *original) {
    char *source;
    char *vtableEntry;

    mScrollable__deepCopy(self, original);
    source = 0;
    if (original != 0) {
        vtableEntry = *(char **)((char *)original + 4);
        source = (char *)__dynamic_cast_2(*(s32 *)(vtableEntry + 4), (s32)mListBox__tf, 0,
                                       (char *)original + *(s16 *)vtableEntry, (s32)hObject__tf, original);
    }
    if (source != 0) {
        *(s32 *)((char *)self + 0xEC) = *(s32 *)(source + 0xEC);
        *(s32 *)((char *)self + 0xF0) = *(s32 *)(source + 0xF0);
        *(f32 *)((char *)self + 0xF4) = *(f32 *)(source + 0xF4);
        *(f32 *)((char *)self + 0xF8) = *(f32 *)(source + 0xF8);
        *(f32 *)((char *)self + 0xFC) = *(f32 *)(source + 0xFC);
        *(f32 *)((char *)self + 0x100) = *(f32 *)(source + 0x100);
        *(f32 *)((char *)self + 0x104) = *(f32 *)(source + 0x104);
        *(s32 *)((char *)self + 0x108) = *(s32 *)(source + 0x108);
        *(s32 *)((char *)self + 0x10C) = *(s32 *)(source + 0x10C);
    }
}
