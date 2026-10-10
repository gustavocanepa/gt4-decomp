typedef int s32;

extern s32 tex_level;

extern "C" s32 ModelSet2__texLevel(s32 arg0) {
    s32 temp_v0 = tex_level;
    tex_level = arg0;
    return temp_v0;
}
