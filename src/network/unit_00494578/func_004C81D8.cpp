/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef short s16;
typedef unsigned int u32;
struct Item {
    u32 flags;
    union {
        u8 *ptr;
        struct { u8 b4, b5, b6, b7; };
        struct { s16 h4, h6; };
    };
    s16 h8;
    s16 hA;
    s16 hC;
    s16 hE;
};
struct Node {
    Item item;
    u8 extra;
    u8 count;
    s16 pos;
    s16 key;
    char pad16[2];
    int w18;
    Node *next;
};
extern "C" Node *func_004C8C20(int, int);
extern "C" void func_004C4070(void *, const void *, int);
static inline int small_count(Item *it) {
    if (it->flags & 0xC00000) return it->b6;
    return it->ptr[3] & 0xF;
}
static inline s16 base_of(Item *it, int count) {
    int base = count * 40;
    if (!(it->flags & 0xC00000)) return base + (it->ptr[5] & 0x1F) * 2;
    return count * 40;
}
static inline s16 end_of(Item *it, int base) {
    if (it->flags & 0xC00000) {
        int v = base + it->hC;
        return v;
    } else {
        int w = base + it->h8;
        return w;
    }
}
extern "C" int func_004C81D8(int ctx, Node **list, int n, Item *it, u8 *extra) {
    Node *head = *list;
    while (n-- != 0) {
        int count;
        int key;
        int pos;
        Node *node;
        if (it->flags & 0x100000) {
            count = it->b4;
        } else {
            count = small_count(it);
        }
        node = func_004C8C20(ctx, 0x20);
        if (node == 0) return 0x80000300;
        node->count = count;
        node->w18 = 0;
        func_004C4070(node, it, 0x10);
        if (extra) {
            node->extra = *extra;
            node->count += *extra;
        } else {
            node->extra = 0;
        }
        if (it->flags & 0x100000) {
            key = it->h6;
            pos = key;
        } else {
            key = base_of(it, node->count);
            pos = key;
            key = end_of(it, key);
        }
        node->pos = pos;
        it++;
        node->key = key;
        if (head == 0) {
            node->next = 0;
            head = node;
        } else if (head->key < key || (head->key == key && head->extra > node->extra)) {
            node->next = head;
            head = node;
        } else {
            Node *prev;
            Node *cur;
            for (prev = head, cur = prev->next; ; cur = prev->next) {
                if (cur) {
                    if (cur->key < key || (cur->key == key && node->extra < cur->extra)) {
                        node->next = cur;
                        prev->next = node;
                        break;
                    }
                    prev = cur;
                } else {
                    prev->next = node;
                    node->next = 0;
                    break;
                }
            }
        }
    }
    *list = head;
    return 0;
}
