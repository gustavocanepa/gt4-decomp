typedef int s32;

extern "C" s32 RaceOrganization__getLoggerCheckPointCount(s32 arg0);

extern "C" s32 DynamicsConductor__getNumberOfLoggerSections(s32 *arg0) {
    return RaceOrganization__getLoggerCheckPointCount(*arg0) + 1;
}
