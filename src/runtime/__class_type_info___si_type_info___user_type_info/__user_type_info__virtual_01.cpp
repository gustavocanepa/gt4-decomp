/* compiler: ee-gcc2.96-no-strict-aliasing */
/* GCC runtime (gcc 2000-10-03 snapshot, libgcc.a): __user_type_info::do_upcast (cp/tinfo.cc).
 * licence: gcc-runtime (GPL with the GCC runtime exception, see THIRD_PARTY.md) */
/* gcc 2.96 libstdc++ tinfo.cc __user_type_info::do_upcast: when this type is the target
   (type_info::operator== is func_005BFB00), fill the upcast_result and return contained_p(). */
struct upcast_result {
    void *target_obj;
    int whole2target;
    int base_type; /* nonvirtual_base_type == (const type_info *)8 */
};

extern "C" int func_005BFB00(void *self, void *target);

extern "C" int __user_type_info__virtual_01(void *self, int access_path, void *target, void *obj, upcast_result *result) {
    if (!func_005BFB00(self, target))
        return 0;
    result->target_obj = obj;
    result->base_type = 8;
    result->whole2target = access_path;
    return (access_path & 6) == 4;
}
