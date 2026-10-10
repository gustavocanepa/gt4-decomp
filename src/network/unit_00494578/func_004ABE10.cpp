static inline float maxf(float a, float b) { float r; __asm__("max.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }
static inline float minf(float a, float b) { float r; __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(a), "f"(b)); return r; }

struct func_004ABE10_Obj {
    char pad0[0xC];
    int mode;
    char pad10[0xB0 - 0x10];
    float level;
    int levelFlag;
    int padB8;
    float angle;
    float angleValue;
    float c4;
    float c8;
    float cc;
};

extern "C" int func_004A5DA0(float level);
extern "C" float func_004A5ED8(float angle);

extern "C" void func_004ABE10(void *ctx, func_004ABE10_Obj *obj, int param, float value) {
    switch (param) {
    case 6: {
        obj->level = minf(maxf(value, 0.0f), 128.0f);
        obj->levelFlag = 0;
        obj->mode = func_004A5DA0(obj->level);
        break;
    }
    case 7:
        obj->angle = value;
        if (value != 180.0f) obj->angleValue = func_004A5ED8(value);
        break;
    case 8:
        obj->c4 = value;
        break;
    case 9:
        obj->c8 = value;
        break;
    case 10:
        obj->cc = value;
        break;
    }
}
