struct GameObject { int m0, m4; GameObject *next; int mC; int priority; };
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
namespace GranTurismo4 {
struct GameObjectManager {
    GameObject *head;
    int m4, m8;
    int mutex[1];
    void append(GameObject *obj);
};
}
extern "C" void func_005790B0(GranTurismo4::GameObjectManager *, GameObject *, GameObject *);

void GranTurismo4::GameObjectManager::append(GameObject *obj)
{
    func_00576788(mutex);
    GameObject *n;
    for (n = head; n; n = n->next)
        if (obj->priority < n->priority) break;
    func_005790B0(this, n, obj);
    func_005767C0(mutex);
}
