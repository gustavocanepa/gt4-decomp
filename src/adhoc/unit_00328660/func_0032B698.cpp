/* Appends one character to the string at +0 and returns the object (a game-side text builder's
 * operator<< (char), next to its %p/%d/const char * overloads): basic_string<char>::append(1, c),
 * bastring.h's inline forwarder to replace(length(), 0, 1, c) (func_005CB368). */
typedef unsigned int u32;

struct StringRep { u32 len; u32 res; u32 ref; u32 selfish; };
struct String { char *dat; };

extern "C" struct String *func_005CB368(struct String *str, u32 pos, u32 n1, u32 n2, char c);

static inline struct StringRep *rep(const struct String *str) { return (struct StringRep *)str->dat - 1; }
static inline u32 length(const struct String *str) { return rep(str)->len; }

static inline struct String &append(struct String *str, u32 n, char c) {
    return *func_005CB368(str, length(str), 0, n, c);
}

extern "C" struct String *func_0032B698(struct String *str, char c) {
    append(str, 1, c);
    return str;
}
