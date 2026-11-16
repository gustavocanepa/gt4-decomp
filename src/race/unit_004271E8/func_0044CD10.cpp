/* Starts a loaded game-data instance for an object id, or calls back at once when there is no such object. The
 * callback argument points at a pair (function pointer, int argument). func_004AE1F8(0, objectId) looks the object
 * up; when found, __dynamic_cast_2 creates an instance from the table at owner+0xA8 (size at
 * +4, offset at +0), and the instance is filled: the pair {D_0044D540, callback arg} goes to +0xC8 (D_0044D540
 * lies in code, so it is probably a function address, inferred from the address), 1 to +0x60, 0 to +0x74, zeros to
 * +0x64 and a copy of the callback pair to +0x6C; then it is handed to func_004AED20 with D_008463B0. When the
 * object is missing, the callback function is called with its int argument and 0 (if the pointer is not null).
 * Purpose of the instance fields unknown. */
#include "types.h"

struct Blk8 {
    s32 a;
    s32 b;
};

typedef void (*F2)(s32, s32);

extern "C" void *func_004AE1F8(s32, s32);
extern "C" void func_004AED20(void *, void *);
extern "C" void *__dynamic_cast_2(s32, s32, s32, s32, s32, s32);

extern char D_0060B030[];
extern char D_0060AD40[];
extern char D_0044D540[];
extern char D_008463B0[];

extern "C" void func_0044CD10(s32 objectId, void *callback) {
    char *owner;
    char *instance;
    char *info;
    Blk8 pair;
    F2 fn;

    owner = (char *)func_004AE1F8(0, objectId);
    if (owner != 0) {
        info = *(char **)(owner + 0xA8);
        instance = (char *)__dynamic_cast_2(*(s32 *)(info + 4), (s32)D_0060B030, 0,
                                  (s32)(owner + *(s16 *)info), (s32)D_0060AD40, (s32)owner);
        pair.b = *(s32 *)((char *)callback + 4);
        pair.a = (s32)D_0044D540;
        *(Blk8 *)(instance + 0xC8) = pair;
        *(s32 *)(instance + 0x60) = 1;
        *(s32 *)(instance + 0x74) = 0;
        pair.a = 0;
        pair.b = 0;
        *(Blk8 *)(instance + 0x64) = pair;
        *(Blk8 *)(instance + 0x6C) = *(Blk8 *)callback;
        func_004AED20((void *)D_008463B0, instance);
    } else {
        fn = *(F2 *)callback;
        if (fn != 0) {
            fn(*(s32 *)((char *)callback + 4), 0);
        }
    }
}
