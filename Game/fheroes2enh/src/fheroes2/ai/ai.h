#pragma once

class Castle;

class HeroBase;

class Heroes;

class Kingdom;

namespace Battle
{
    class Arena;

    class Unit;

    class Actions;
}

namespace AI
{
    enum modes_t
    {
        HEROES_MOVED = 0x08000000,
        HEROES_SCOUTER = 0x10000000,
        HEROES_HUNTER = 0x20000000,
        HEROES_WAITING = 0x40000000,
        HEROES_STUPID = 0x80000000
    };

    void Init();

    void KingdomTurn(Kingdom &);

    void BattleTurn(Battle::Arena &, const Battle::Unit &, Battle::Actions &);

    bool BattleMagicTurn(Battle::Arena &, const Battle::Unit &, Battle::Actions &, const Battle::Unit *);

    void HeroesAdd(const Heroes &);

    void HeroesRemove(const Heroes &);

    void HeroesTurn(Heroes &);

    void HeroesMove(Heroes &);

    bool HeroesGetTask(Heroes &);

    void HeroesPreBattle(HeroBase &);

    void HeroesAfterBattle(HeroBase &);

    void HeroesPostLoad(Heroes &);

    bool HeroesValidObject(const Heroes &, s32);

    bool HeroesCanMove(const Heroes &);

    void HeroesAction(Heroes &, s32);

    void HeroesActionComplete(Heroes &, s32);

    void HeroesActionNewPosition(Heroes &);

    void HeroesLevelUp(Heroes &);

    void HeroesClearTask(const Heroes &);

    bool HeroesSkipFog();

    std::string HeroesString(const Heroes &);

    void CastleAdd(const Castle &);

    void CastleRemove(const Castle &);

    void CastleTurn(Castle &);

    void CastlePreBattle(Castle &);

    void CastleAfterBattle(Castle &, bool attacker_wins);

    const char *Type();

    const char *License();
}
