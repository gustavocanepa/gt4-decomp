typedef int s32;

extern s32 tex_LOD_enabled;

extern "C" s32 ModelSet2__texLOD(s32 arg0) {
    s32 temp_v0 = tex_LOD_enabled;
    tex_LOD_enabled = arg0;
    return temp_v0;
}
