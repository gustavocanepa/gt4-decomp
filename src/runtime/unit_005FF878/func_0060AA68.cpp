struct Job { char pad[0x3C]; char node[0x44]; int queued; };
struct Queue { char pad[0x4C]; char list[0x18]; char event[4]; };
extern "C" void func_00576788(Job *lock);
extern "C" void func_005767C0(Job *lock);
extern "C" void func_0057CB00(void *list, void *node);
extern "C" void func_00574EE8(void *event);

extern "C" void func_0060AA68(Queue *q, Job *job)
{
    func_00576788(job);
    job->queued = 1;
    func_0057CB00(q->list, job->node);
    func_005767C0(job);
    func_00574EE8(q->event);
}
