/* compiler: ee-gcc2.96-stl */
/* SGI STL __default_alloc_template<...>::_S_refill (stl_alloc.h), spelled out as a plain function:
   _S_chunk_alloc is func_00606020 and _S_free_list is D_00659E30; the non-threaded instance
   (__STL_VOLATILE empty: a volatile free list would not fold the %lo into the store). */
union _Obj {
    union _Obj *_M_free_list_link;
    char _M_client_data[1];
};
enum { _ALIGN = 8 };

extern _Obj *D_00659E30[];
extern "C" char *func_00606020(unsigned int __size, int &__nobjs);

static inline unsigned int _S_freelist_index(unsigned int __bytes)
{
    return (((__bytes) + (unsigned int)_ALIGN - 1) / (unsigned int)_ALIGN - 1);
}

extern "C" void *func_00605EA8(unsigned int __n)
{
    int __nobjs = 20;
    char *__chunk = func_00606020(__n, __nobjs);
    _Obj **__my_free_list;
    _Obj *__result;
    _Obj *__current_obj;
    _Obj *__next_obj;
    int __i;

    if (1 == __nobjs) return (__chunk);
    __my_free_list = D_00659E30 + _S_freelist_index(__n);

    /* Build free list in chunk */
    __result = (_Obj *)__chunk;
    *__my_free_list = __next_obj = (_Obj *)(__chunk + __n);
    for (__i = 1;; __i++) {
        __current_obj = __next_obj;
        __next_obj = (_Obj *)((char *)__next_obj + __n);
        if (__nobjs - 1 == __i) {
            __current_obj->_M_free_list_link = 0;
            break;
        } else {
            __current_obj->_M_free_list_link = __next_obj;
        }
    }
    return (__result);
}
