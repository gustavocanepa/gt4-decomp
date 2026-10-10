/* __cplus_type_matcher (gcc/cp/exception.cc, old ABI): does the thrown object match this catch? */
struct EhInfo { int pad[2]; void *value; void *type; char pad2[0x18]; void *original_value; };
struct ExceptionTable { int pad; short language; };
typedef void *(*TypeInfoFn)(void);
extern "C" int func_005C08F0(void *catch_type, void *throw_type, void *objptr, void **valp);

extern "C" void *func_005C1758(EhInfo *info, TypeInfoFn match_info, ExceptionTable *table)
{
    if (table != 0 && table->language != 4)
        return 0;
    if (match_info == (TypeInfoFn)-1)
        return (void *)1;
    if (func_005C08F0(match_info(), info->type, info->original_value, &info->value))
        return (void *)1;
    return 0;
}
