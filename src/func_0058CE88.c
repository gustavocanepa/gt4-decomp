/* compiler: ee-gcc2.9-991111 */
struct OsdParam {
    unsigned int spdifMode : 1;
    unsigned int screenType : 2;
    unsigned int videoOutput : 1;
    unsigned int japLanguage : 1;
    unsigned int ps1drvConfig : 8;
    unsigned int version : 3;
    unsigned int language : 5;
    unsigned int timezoneOffset : 11;
};
extern unsigned char D_00657ACC;
void func_005ADD50(struct OsdParam *p);
int func_0058CE48(void);

int func_0058CE88(void)
{
    struct OsdParam p;
    int lang;

    func_005ADD50(&p);
    if (func_0058CE48()) {
        lang = D_00657ACC;
    } else {
        func_005ADD50(&p);
        if (p.version == 0)
            lang = p.japLanguage;
        else
            lang = p.language;
    }
    return lang;
}
