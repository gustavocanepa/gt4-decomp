typedef unsigned int u32;
typedef int s32;
typedef float f32;

struct Out {
    s32 type;
    s32 unk4;
    f32 value;
};

extern "C" void func_003A3778(Out *out, u32 packed) {
    out->type = packed & 0xF;
    out->value = (f32)((packed >> 4) & 0x3FFF) * 0x1.999998p-4f;
}
