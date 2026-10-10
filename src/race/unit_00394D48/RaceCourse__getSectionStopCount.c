typedef int s32;
typedef unsigned short u16;
char *CourseData__getRunway(s32 a);
u16 RaceCourse__getSectionStopCount(char *arg0) {
    if (*(s32 *)(arg0 + 0xB0) < 0) return 0;
    return *(u16 *)(*(char **)(CourseData__getRunway(*(s32 *)(arg0 + 4)) + 0x9C) + (*(s32 *)(arg0 + 0xB0) << 5) + 0xE);
}
