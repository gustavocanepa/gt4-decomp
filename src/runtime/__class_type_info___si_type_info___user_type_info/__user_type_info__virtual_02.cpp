/* compiler: ee-gcc2.96-no-strict-aliasing */
/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __user_type_info::do_dyncast (cp/tinfo.cc).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* gcc 2.96 libstdc++ tinfo.cc __user_type_info::do_dyncast (type_info::operator== is
   func_005BFB00); the sub_kind not_contained is 1. */
struct dyncast_result {
    void *target_obj;
    int whole2target;
    int whole2sub;
    int target2sub;
};

extern "C" int func_005BFB00(const void *self, const void *other);

extern "C" int __user_type_info__virtual_02(const void *self, int boff, int access_path, const void *target, void *objptr,
                             const void *subtype, void *subptr, dyncast_result *result) {
    if (objptr == subptr && func_005BFB00(self, subtype)) {
        result->whole2sub = access_path;
        return 0;
    }
    if (func_005BFB00(self, target)) {
        result->target_obj = objptr;
        result->whole2target = access_path;
        result->target2sub = 1;
        return 0;
    }
    return 0;
}
