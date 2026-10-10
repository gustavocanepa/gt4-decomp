struct Car { char pad[0x18]; int id; };
struct Entry { Car *car; };
struct Grid { char pad[8]; Entry *entry; };
struct Race { char pad[0x60]; Grid *grid; char pad2[0x90]; char hud[4]; };
struct RaceFreePractice { char pad[0x6C]; Race *race; };

extern "C" void RaceSinglePlayer__updatePlay(RaceFreePractice *self);
extern "C" int GetPitStopStatus(int id);
extern "C" void func_003B76F0(void *hud, int a, int b, int c);

extern "C" void RaceFreePractice__updatePlay(RaceFreePractice *self)
{
    RaceSinglePlayer__updatePlay(self);
    if (GetPitStopStatus(self->race->grid->entry->car->id) == 1)
        func_003B76F0(self->race->hud, 1, 0, 0);
}
