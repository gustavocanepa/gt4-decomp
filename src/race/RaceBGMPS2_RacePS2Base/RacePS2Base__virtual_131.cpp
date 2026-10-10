typedef int s32;

extern "C" s32 RaceBGMPS2__getMusicInformation(char *arg0);

extern "C" s32 RacePS2Base__virtual_131(char *arg0) {
    return RaceBGMPS2__getMusicInformation(arg0 + 0xCF88);
}
