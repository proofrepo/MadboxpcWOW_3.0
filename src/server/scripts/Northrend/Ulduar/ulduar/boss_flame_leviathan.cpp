/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

/* ScriptData
Name: Flame Leviathan
Author: 
%Complete: 90
EndScriptData */

#include "ScriptPCH.h"
#include "ulduar.h"
#include "Vehicle.h"

enum Spells
{
    SPELL_PURSUED                               = 62374,
    SPELL_GATHERING_SPEED                       = 62375,
    SPELL_BATTERING_RAM                         = 62376,
    SPELL_FLAME_VENTS                           = 62396,
    SPELL_MISSILE_BARRAGE                       = 62400,
    SPELL_SYSTEMS_SHUTDOWN                      = 62475,
    SPELL_OVERLOAD_CIRCUIT                      = 62399,
    SPELL_START_THE_ENGINE                      = 62472,
    SPELL_SEARING_FLAME                         = 62402,
    SPELL_BLAZE                                 = 62292,
    SPELL_TAR_PASSIVE                           = 62288,
    SPELL_SMOKE_TRAIL                           = 63575,
    SPELL_ELECTROSHOCK                          = 62522,
    SPELL_NAPALM                                = 63666,
    //TOWER Additional SPELLS
    SPELL_THORIM_S_HAMMER                       = 62911, // Tower of Storms
    SPELL_MIMIRON_S_INFERNO                     = 62909, // Tower of Flames
    SPELL_HODIR_S_FURY                          = 62533, // Tower of Frost
    SPELL_FREYA_S_WARD                          = 62906, // Tower of Nature
    SPELL_FREYA_SUMMONS                         = 62947, // Tower of Nature
    //TOWER ap & health spells
    SPELL_BUFF_TOWER_OF_STORMS                  = 65076,
    SPELL_BUFF_TOWER_OF_FLAMES                  = 65075,
    SPELL_BUFF_TOWER_OF_FROST                   = 65077,
    SPELL_BUFF_TOWER_OF_LIFE                    = 64482,
    //Additional Spells
    SPELL_LASH                                  = 65062,
    SPELL_AUTO_REPAIR                           = 62705,
    LIGHTNING_SKYBEAM                           = 63773,
    GREEN_SKYBEAM                               = 63771,
    BLUE_SKYBEAM                                = 63769,
    RED_SKYBEAM                                 = 63772,
    SPELL_LIQUID_PYRITE                         = 62494,
    SPELL_GROUND_SLAM                           = 62625
};

enum Creatures
{
<<<<<<< HEAD
    NPC_ULDUAR_COLOSSUS                         = 33237,
    NPC_TURRET                                  = 33142,
    NPC_DEVICE                                  = 33143,
=======
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
    NPC_SEAT                                    = 33114,
    NPC_MECHANOLIFT                             = 33214,
    NPC_LIQUID                                  = 33189,
    NPC_CONTAINER                               = 33218,
    NPC_THORIM_BEACON                           = 33365,
    NPC_MIMIRON_BEACON                          = 33370,
    NPC_HODIR_BEACON                            = 33212,
    NPC_FREYA_BEACON                            = 33367,
    NPC_THORIM_TARGET_BEACON                    = 33364,
    NPC_MIMIRON_TARGET_BEACON                   = 33369,
    NPC_HODIR_TARGET_BEACON                     = 33108,
    NPC_FREYA_TARGET_BEACON                     = 33366,
    NPC_LOREKEEPER                              = 33686,
    NPC_BRANZ_BRONZBEARD                        = 33579,
    NPC_DELORAH                                 = 33701,
    NPC_ULDUAR_GAUNTLET_GENERATOR               = 33571  // Trigger tied to towers
};

enum Towers
{
<<<<<<< HEAD
    GO_TOWER_OF_STORMS                          = 194377,
    GO_TOWER_OF_FLAMES                          = 194371,
    GO_TOWER_OF_FROST                           = 194370,
    GO_TOWER_OF_LIFE                            = 194375
=======
    GO_TOWER_OF_STORMS  = 194377,
    GO_TOWER_OF_FLAMES  = 194371,
    GO_TOWER_OF_FROST   = 194370,
    GO_TOWER_OF_LIFE    = 194375,
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
};

enum Events
{
<<<<<<< HEAD
    EVENT_NONE,
    EVENT_PURSUE,
    EVENT_MISSILE,
    EVENT_VENT,
    EVENT_SPEED,
    EVENT_SUMMON,
    EVENT_SHUTDOWN,
    EVENT_REPAIR,
    EVENT_THORIM_S_HAMMER,      // Tower of Storms
    EVENT_MIMIRON_S_INFERNO,    // Tower of Flames
    EVENT_HODIR_S_FURY,         // Tower of Frost
    EVENT_FREYA_S_WARD,         // Tower of Life
=======
    EVENT_PURSUE            = 1,
    EVENT_MISSILE           = 2,
    EVENT_VENT              = 3,
    EVENT_SPEED             = 4,
    EVENT_SUMMON            = 5,
    EVENT_SHUTDOWN          = 6,
    EVENT_REPAIR            = 7,
    EVENT_THORIM_S_HAMMER   = 8,    // Tower of Storms
    EVENT_MIMIRON_S_INFERNO = 9,    // Tower of Flames
    EVENT_HODIR_S_FURY      = 10,   // Tower of Frost
    EVENT_FREYA_S_WARD      = 11,   // Tower of Nature
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
};

enum Seats
{
    SEAT_PLAYER                                 = 0,
    SEAT_TURRET                                 = 1,
    SEAT_DEVICE                                 = 2,
    SEAT_CANNON                                 = 7,
};

enum Vehicles
{
    VEHICLE_SIEGE                               = 33060,
    VEHICLE_CHOPPER                             = 33062,
    VEHICLE_DEMOLISHER                          = 33109,
};

<<<<<<< HEAD
#define EMOTE_PURSUE                            "Flame Leviathan pursues $N."
#define EMOTE_OVERLOAD                          "Flame Leviathan's circuits overloaded."
#define EMOTE_REPAIR                            "Automatic repair sequence initiated."

enum Actions
{
    ACTION_NULL                                 = 0,
    ACTION_TOWER_OF_STORMS,
    ACTION_TOWER_OF_FLAMES,
    ACTION_TOWER_OF_FROST,
    ACTION_TOWER_OF_LIFE,
    ACTION_VEHICLE_RESPAWN,
    ACTION_COLOSSUS_COUNT
};
=======
#define EMOTE_PURSUE          "Flame Leviathan pursues $N."
#define EMOTE_OVERLOAD        "Flame Leviathan's circuits overloaded."
#define EMOTE_REPAIR          "Automatic repair sequence initiated."
#define DATA_SHUTOUT          29112912 // 2911, 2912 are achievement IDs
#define DATA_UNBROKEN         29052906 // 2905, 2906 are achievement IDs
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

enum Yells
{
    SAY_AGGRO                                   = -1603060,
    SAY_SLAY                                    = -1603061,
    SAY_DEATH                                   = -1603062,
    SAY_TARGET_1                                = -1603063,
    SAY_TARGET_2                                = -1603064,
    SAY_TARGET_3                                = -1603065,
    SAY_HARDMODE                                = -1603066,
    SAY_TOWER_NONE                              = -1603067,
    SAY_TOWER_FROST                             = -1603068,
    SAY_TOWER_FLAME                             = -1603069,
    SAY_TOWER_NATURE                            = -1603070,
    SAY_TOWER_STORM                             = -1603071,
    SAY_PLAYER_RIDING                           = -1603072,
    SAY_OVERLOAD_1                              = -1603073,
    SAY_OVERLOAD_2                              = -1603074,
    SAY_OVERLOAD_3                              = -1603075,
};

enum AchievementData
{
    ACHIEV_10_NUKED_FROM_ORBIT                  = 2915,
    ACHIEV_25_NUKED_FROM_ORBIT                  = 2917,
    ACHIEV_10_ORBITAL_BOMBARDMENT               = 2913,
    ACHIEV_25_ORBITAL_BOMBARDMENT               = 2918,
    ACHIEV_10_ORBITAL_DEVASTATION               = 2914,
    ACHIEV_25_ORBITAL_DEVASTATION               = 2916,
    ACHIEV_10_ORBIT_UARY                        = 3056,
    ACHIEV_25_ORBIT_UARY                        = 3057,
    ACHIEV_10_SIEGE_OF_ULDUAR                   = 2886,
    ACHIEV_25_SIEGE_OF_ULDUAR                   = 2887,
<<<<<<< HEAD
    ACHIEV_10_THREE_CAR_GARAGE                  = 2907, // no core support for using a vehicle
    ACHIEV_25_THREE_CAR_GARAGE                  = 2908, // no core support for using a vehicle
    ACHIEV_10_UNBROKEN                          = 2905,
    ACHIEV_25_UNBROKEN                          = 2906,
};

const Position PosColossus[2] =
=======
};

enum actions
{
    ACTION_TOWER_OF_STORM_DESTROYED             = 1,
    ACTION_TOWER_OF_FROST_DESTROYED             = 2,
    ACTION_TOWER_OF_FLAMES_DESTROYED            = 3,
    ACTION_TOWER_OF_LIFE_DESTROYED              = 4,
};

Position const Center[]=
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
{
    {368.77f, 12.78f,409.89f,3.14f},
    {368.77f,-46.85f,409.89f,3.14f}
};

Position const PosSiege[5] =
{
    {-814.59f,-64.54f,429.92f,5.969f},
    {-784.37f,-33.31f,429.92f,5.096f},
    {-808.99f,-52.10f,429.92f,5.668f},
    {-798.59f,-44.00f,429.92f,5.663f},
    {-812.83f,-77.71f,429.92f,0.046f},
};

Position const PosChopper[5] =
{
    {-717.83f,-106.56f,430.02f,0.122f},
    {-717.83f,-114.23f,430.44f,0.122f},
    {-717.83f,-109.70f,430.22f,0.122f},
    {-718.45f,-118.24f,430.26f,0.052f},
    {-718.45f,-123.58f,430.41f,0.085f},
};

Position const PosDemolisher[5] =
{
    {-724.12f,-176.64f,430.03f,2.543f},
    {-766.70f,-225.03f,430.50f,1.710f},
    {-729.54f,-186.26f,430.12f,1.902f},
    {-756.01f,-219.23f,430.50f,2.369f},
    {-798.01f,-227.24f,429.84f,1.446f},
};

const Position PosFreyasWard[4] =
{
    {374.971f, 66.375f,410.99f,0},
    {374.971f,-129.71f,410.51f,0},
    {160.301f,-129.71f,409.80f,0},
    {160.301f, 60.375f,409.80f,0}
};

class boss_flame_leviathan : public CreatureScript
{
    public:
        boss_flame_leviathan() : CreatureScript("boss_flame_leviathan") { }

<<<<<<< HEAD
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_flame_leviathanAI (pCreature);
    }

    struct boss_flame_leviathanAI : public BossAI
    {
        boss_flame_leviathanAI(Creature* pCreature) : BossAI(pCreature, BOSS_LEVIATHAN), vehicle(pCreature->GetVehicleKit())
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
            me->SetReactState(REACT_PASSIVE);
            
            towerOfStorms = true;
            towerOfLife = true;
            towerOfFlames = true;
            towerOfFrost = true;
            
            // Summon Ulduar Colossus
            if (me->isAlive())
                for (uint32 i = 0; i < 2; ++i)
                    DoSummon(NPC_ULDUAR_COLOSSUS, PosColossus[i], 7000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
        }

        Vehicle* vehicle;
        int32 ShutdownCount;
        int32 towerCount;
        int32 ColossusCount;
        bool towerOfStorms;
        bool towerOfLife;
        bool towerOfFlames;
        bool towerOfFrost;

        void Reset()
        {
            _Reset();
            me->SetReactState(REACT_DEFENSIVE);
            InstallAdds(false);
            me->ResetLootMode();
            ColossusCount = 0;
            towerCount = 0;
            ShutdownCount = 0;
        }

        void EnterCombat(Unit* /*who*/)
        {
            _EnterCombat();
            DoScriptText(SAY_AGGRO, me);
            me->SetReactState(REACT_AGGRESSIVE);
            events.ScheduleEvent(EVENT_PURSUE, 5000);
            events.ScheduleEvent(EVENT_MISSILE, 1500);
            events.ScheduleEvent(EVENT_VENT, 20000);
            events.ScheduleEvent(EVENT_SPEED, 15000);
            events.ScheduleEvent(EVENT_SUMMON, 1500);
            InstallAdds(true);
            ActiveTowers();
        }

        void ActiveTowers()
        {
            if (instance)
=======
        struct boss_flame_leviathanAI : public BossAI
        {
            boss_flame_leviathanAI(Creature* creature) : BossAI(creature, TYPE_LEVIATHAN), vehicle(creature->GetVehicleKit())
            {
            }

            void InitializeAI()
            {
                ASSERT(vehicle);
                Reset();
                ActiveTowersCount = 4;
                Shutdown = 0;
                ActiveTowers = false;
                towerOfStorms = false;
                towerOfLife = false;
                towerOfFlames = false;
                towerOfFrost = false;
                Shutout = true;
                Unbroken = true;

                // need to have correct immunities set in db
                me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
                me->ApplySpellImmune(0, IMMUNITY_ID, 49560, true); //deathgrip
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                me->SetReactState(REACT_PASSIVE);
            }

            Vehicle* vehicle;
            uint8 ActiveTowersCount;
            uint8 Shutdown;
            bool ActiveTowers;
            bool towerOfStorms;
            bool towerOfLife;
            bool towerOfFlames;
            bool towerOfFrost;
            bool Shutout;
            bool Unbroken;

            void Reset()
            {
                _Reset();
                Shutdown = 0;
                me->SetReactState(REACT_DEFENSIVE);
                if (me->GetVehicleKit())
                {
                    me->GetVehicleKit()->Reset();
                    if (me->GetVehicleKit()->GetPassenger(SEAT_CANNON))
                        me->CastSpell(me->GetVehicleKit()->GetPassenger(SEAT_CANNON),AURA_STEALTH_DETECTION,false);
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                me->SetReactState(REACT_AGGRESSIVE);
                events.ScheduleEvent(EVENT_PURSUE, 30*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_MISSILE, urand(1500, 4*IN_MILLISECONDS));
                events.ScheduleEvent(EVENT_VENT, 20*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SHUTDOWN, 150*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SPEED, 15*IN_MILLISECONDS);
                events.ScheduleEvent(EVENT_SUMMON, 1*IN_MILLISECONDS);
                ActiveTower(); //void ActiveTower
            }

            void ActiveTower()
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
            {
                if (towerOfStorms)
                {
                    ++towerCount;
                    me->AddAura(SPELL_BUFF_TOWER_OF_STORMS, me);
                    events.ScheduleEvent(EVENT_THORIM_S_HAMMER, 30000);
                }

                if (towerOfFlames)
                {
                    ++towerCount;
                    me->AddAura(SPELL_BUFF_TOWER_OF_FLAMES, me);
                    events.ScheduleEvent(EVENT_MIMIRON_S_INFERNO, 10000);
                }

                if (towerOfFrost)
                {
                    ++towerCount;
                    me->AddAura(SPELL_BUFF_TOWER_OF_FROST, me);
                    events.ScheduleEvent(EVENT_HODIR_S_FURY, 5000);
                }

                if (towerOfLife)
                {
                    ++towerCount;
                    me->AddAura(SPELL_BUFF_TOWER_OF_LIFE, me);
                    events.ScheduleEvent(EVENT_FREYA_S_WARD, 1000);
                }

                switch (towerCount)
                {
                    case 4:
                        me->AddLootMode(LOOT_MODE_HARD_MODE_4);
                    case 3:
                        me->AddLootMode(LOOT_MODE_HARD_MODE_3);
                    case 2:
                        me->AddLootMode(LOOT_MODE_HARD_MODE_2);
                    case 1:
                        DoScriptText(SAY_HARDMODE, me);
                        me->AddLootMode(LOOT_MODE_HARD_MODE_1);
                        break;
                    default:
                        DoScriptText(SAY_TOWER_NONE, me);
                        me->SetLootMode(LOOT_MODE_DEFAULT);
                        break;
                }
            }

<<<<<<< HEAD
        void InstallAdds(bool apply = true)
        {
            if (apply)
            {
                for (uint8 i = RAID_MODE(2,0); i < 4; ++i)
                {
                    if (vehicle->GetPassenger(i))
                        if (Unit *pSeat = vehicle->GetPassenger(i))
                        {
                            if (Creature* pTurret = (me->SummonCreature(NPC_TURRET, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN)))
                                pTurret->EnterVehicle(pSeat, SEAT_TURRET);

                            if (Creature* pDevice = (me->SummonCreature(NPC_DEVICE, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), 0, TEMPSUMMON_MANUAL_DESPAWN)))
                                pDevice->EnterVehicle(pSeat, SEAT_DEVICE);
                        }
                }
            }
            else
            {
                for (uint8 i = RAID_MODE(2,0); i < 4; ++i)
                {
                    if (vehicle->GetPassenger(i))
                        if (Vehicle *pSeat = vehicle->GetPassenger(i)->GetVehicleKit())
                        {
                            if (Unit* pTurret = (pSeat->GetPassenger(SEAT_TURRET)))
                                pTurret->RemoveFromWorld();

                            if (Unit* pDevice = (pSeat->GetPassenger(SEAT_DEVICE)))
                                pDevice->RemoveFromWorld();
                        }
                }
            }
        }

        void JustDied(Unit* /*victim*/)
        {
            _JustDied();
            DoScriptText(SAY_DEATH, me);

            if (instance)
            {
                Map::PlayerList const& players = me->GetMap()->GetPlayers();
                if (!players.isEmpty())
                {
                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                    {
                        Player* pPlayer = itr->getSource();
                        if (pPlayer)
                            me->GetMap()->ToInstanceMap()->PermBindAllPlayers(pPlayer);
                    }
                }

                switch (towerCount)
                {
                    case 4:
                        instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBIT_UARY, ACHIEV_25_ORBIT_UARY));
                    case 3:
                        instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_NUKED_FROM_ORBIT, ACHIEV_25_NUKED_FROM_ORBIT));
                    case 2:
                        instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBITAL_DEVASTATION, ACHIEV_25_ORBITAL_DEVASTATION));
                    case 1:
                        instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBITAL_BOMBARDMENT, ACHIEV_25_ORBITAL_BOMBARDMENT));
                    default:
                        break;
=======
            // TODO: effect 0 and effect 1 may be on different target
            void SpellHitTarget(Unit* target, SpellEntry* const spell)
            {
                if (spell->Id == SPELL_PURSUED)
                    AttackStart(target);
            }

            void JustDied(Unit* /*victim*/)
            {
                _JustDied();
                DoScriptText(SAY_DEATH, me);

                if (ActiveTowers)
                {
                    switch (ActiveTowersCount)
                    {
                        case 4:
                            instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBIT_UARY, ACHIEV_25_ORBIT_UARY));
                        case 3:
                            instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_NUKED_FROM_ORBIT, ACHIEV_25_NUKED_FROM_ORBIT));
                        case 2:
                            instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBITAL_DEVASTATION, ACHIEV_25_ORBITAL_DEVASTATION));
                        case 1:
                            instance->DoCompleteAchievement(RAID_MODE(ACHIEV_10_ORBITAL_BOMBARDMENT, ACHIEV_25_ORBITAL_BOMBARDMENT));
                    }
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
                }
            }

<<<<<<< HEAD
        void SpellHit(Unit* /*caster*/, const SpellEntry* pSpell)
        {
            if (pSpell->Id == SPELL_START_THE_ENGINE)
                vehicle->InstallAllAccessories();

            if (pSpell->Id == SPELL_ELECTROSHOCK)
                me->InterruptSpell(CURRENT_CHANNELED_SPELL);

            if (pSpell->Id == SPELL_OVERLOAD_CIRCUIT)
            {
                ShutdownCount++;
                
                if (ShutdownCount == RAID_MODE(2,4))
                {
                    ShutdownCount = 0;
                    events.ScheduleEvent(EVENT_SHUTDOWN, 0);
                    events.ScheduleEvent(EVENT_REPAIR, 0);
                    me->RemoveAurasDueToSpell(SPELL_OVERLOAD_CIRCUIT);
                    me->InterruptNonMeleeSpells(true);
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);
            
            if (me->HasUnitState(UNIT_STAT_CASTING) || me->HasAura(SPELL_SYSTEMS_SHUTDOWN))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch(eventId)
                {
                    case EVENT_PURSUE:
                        DoScriptText(RAND(SAY_TARGET_1, SAY_TARGET_2, SAY_TARGET_3), me);
                        {
                            DoZoneInCombat();
                            Unit* pTarget;
                            std::vector<Unit *> target_list;
                            std::list<HostileReference*> ThreatList = me->getThreatManager().getThreatList();
                            for (std::list<HostileReference*>::const_iterator itr = ThreatList.begin(); itr != ThreatList.end(); ++itr)
                            {
                                pTarget = Unit::GetUnit(*me, (*itr)->getUnitGuid());
                                
                                if (!pTarget || pTarget->ToPlayer())
                                    continue;
                                    
                                if (pTarget->GetEntry() == VEHICLE_SIEGE || pTarget->GetEntry() == VEHICLE_DEMOLISHER)
                                    target_list.push_back(pTarget);
                                    
                                pTarget = NULL;
                            }
                            
                            if (!target_list.empty())
                                pTarget = *(target_list.begin()+rand()%target_list.size());
                            else
                                pTarget = me->getVictim();
                                
                            if (pTarget && pTarget->isAlive())
                            {
                                DoResetThreat();
                                me->AddThreat(pTarget, 5000000.0f);
                                me->AddAura(SPELL_PURSUED, pTarget);
                                if (Vehicle* pVehicle = pTarget->GetVehicleKit())
                                {
                                    if (Unit* pDriver = pVehicle->GetPassenger(0))
                                        me->MonsterTextEmote(EMOTE_PURSUE, pDriver->GetGUID(), true);
                                }
                                else me->MonsterTextEmote(EMOTE_PURSUE, pTarget->GetGUID(), true);
                            }
                        }
                        events.RescheduleEvent(EVENT_PURSUE, 35000);
                        break;
                    case EVENT_MISSILE:
                        if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(pTarget, SPELL_MISSILE_BARRAGE);
                        events.RescheduleEvent(EVENT_MISSILE, 3000);
                        break;
                    case EVENT_VENT:
                        DoCastAOE(SPELL_FLAME_VENTS);
                        events.RescheduleEvent(EVENT_VENT, urand(15000, 20000));
                        break;
                    case EVENT_SPEED:
                        DoCastAOE(SPELL_GATHERING_SPEED);
                        events.RescheduleEvent(EVENT_SPEED, 15000);
                        break;
                    case EVENT_SUMMON:
                        if (summons.size() < 15) // 4seat+1turret+10lift
                            if (Creature* pLift = DoSummonFlyer(NPC_MECHANOLIFT, me, 30.0f, 50.0f, 0))
                                pLift->GetMotionMaster()->MoveRandom(100);
                        events.RescheduleEvent(EVENT_SUMMON, 3000);
                        break;
                    case EVENT_SHUTDOWN:
                        DoScriptText(RAND(SAY_OVERLOAD_1, SAY_OVERLOAD_2, SAY_OVERLOAD_3), me);
                        InstallAdds(false);
                        me->MonsterTextEmote(EMOTE_OVERLOAD, 0, true);
                        me->AddAura(SPELL_SYSTEMS_SHUTDOWN, me);
                        me->RemoveAurasDueToSpell(SPELL_GATHERING_SPEED);
                        me->AddUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                        me->SetReactState(REACT_PASSIVE);
                        me->StopMoving();
                        events.CancelEvent(EVENT_SHUTDOWN);
                        return;
                    case EVENT_REPAIR:
                        me->MonsterTextEmote(EMOTE_REPAIR, 0, true);
                        InstallAdds(true);
                        me->ClearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.CancelEvent(EVENT_REPAIR);
                        break;
                    case EVENT_THORIM_S_HAMMER:     // Tower of Storms
                        DoScriptText(SAY_TOWER_STORM, me);
                        DoSummon(NPC_THORIM_BEACON, me, float(urand(40,80)), 6000, TEMPSUMMON_TIMED_DESPAWN);
                        events.RescheduleEvent(EVENT_THORIM_S_HAMMER, urand(4000,10000));
                        break;
                    case EVENT_MIMIRON_S_INFERNO:   // Tower of Flames
                        DoScriptText(SAY_TOWER_FLAME, me);
                        me->SummonCreature(NPC_MIMIRON_BEACON, 280.42f, -19.18f, 409.81f);
                        events.CancelEvent(EVENT_MIMIRON_S_INFERNO);
                        break;
                    case EVENT_HODIR_S_FURY:        // Tower of Frost
                        DoScriptText(SAY_TOWER_FROST, me);
                        for (uint8 i = 0; i < 4; ++i)
                            DoSummon(NPC_HODIR_BEACON, me, 50, 0);
                        events.CancelEvent(EVENT_HODIR_S_FURY);
                        break;
                    case EVENT_FREYA_S_WARD:        // Tower of Life
                        DoScriptText(SAY_TOWER_NATURE, me);
                        for (uint32 i = 0; i < 4; ++i)
                            DoSummon(NPC_FREYA_BEACON, PosFreyasWard[i]);
                        events.CancelEvent(EVENT_FREYA_S_WARD);
                        break;
                }

                if (me->IsWithinMeleeRange(me->getVictim()))
                    DoSpellAttackIfReady(SPELL_BATTERING_RAM);
            }
        }

        void DoAction(const int32 action)
        {
            switch(action)
            {
                case ACTION_TOWER_OF_STORMS:
                    towerOfStorms = false;
                    break;
                case ACTION_TOWER_OF_FLAMES:
                    towerOfFlames = false;
                    break;
                case ACTION_TOWER_OF_FROST:
                    towerOfFrost = false;
                    break;
                case ACTION_TOWER_OF_LIFE:
                    towerOfLife = false;
                    break;
                case ACTION_COLOSSUS_COUNT:
                {
                    ++ColossusCount;
                    if (ColossusCount >= 2)
                    {
                        // Event starts
                        if (instance)
                            instance->SetData(DATA_LEVIATHAN_DOOR, GO_STATE_ACTIVE_ALTERNATIVE);
                            
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->SetHomePosition(318.74f, -13.75f, 409.803f, 3.14f); // new Home Position
                        me->GetMotionMaster()->MoveCharge(354.8771f, -12.90240f, 409.803f);
                    }
                    break;
                }
                default:
                    break;
            }
=======
            void SpellHit(Unit* /*caster*/, SpellEntry* const spell)
            {
                if (spell->Id == SPELL_START_THE_ENGINE)
                    vehicle->InstallAllAccessories();

                if (spell->Id == SPELL_ELECTROSHOCK)
                    me->InterruptSpell(CURRENT_CHANNELED_SPELL);

                if (spell->Id == SPELL_OVERLOAD_CIRCUIT)
                    ++Shutdown;
            }

            uint32 GetData(uint32 type)
            {
                switch (type)
                {
                    case DATA_SHUTOUT:
                        return Shutout ? 1 : 0;
                    case DATA_UNBROKEN:
                        return Unbroken ? 1 : 0;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 id, uint32 data)
            {
                if (id == DATA_UNBROKEN)
                    Unbroken = data ? true : false;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (Shutdown == RAID_MODE(2,4))
                {
                    Shutdown = 0;
                    events.ScheduleEvent(EVENT_SHUTDOWN, 4000);
                    me->RemoveAurasDueToSpell(SPELL_OVERLOAD_CIRCUIT);
                    me->InterruptNonMeleeSpells(true);
                    return;
                }

                if (me->HasAura(SPELL_SYSTEMS_SHUTDOWN))
                {
                    me->SetReactState(REACT_PASSIVE);
                    me->AddUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                    if (Shutout)
                        Shutout = false;
                    return;
                }
                else
                {
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
                }

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                uint32 eventId = events.GetEvent();

                switch(eventId)
                {
                    case 0:
                        break; // this is a must
                    case EVENT_PURSUE:
                        DoScriptText(RAND(SAY_TARGET_1, SAY_TARGET_2, SAY_TARGET_3), me);
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0,75,true))
                        {
                            me->AddAura(SPELL_PURSUED, target);
                            me->MonsterTextEmote(EMOTE_PURSUE, target->GetGUID(), true);
                        }
                        events.RepeatEvent(30*IN_MILLISECONDS);
                        break;
                    case EVENT_MISSILE:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_MISSILE_BARRAGE);
                        events.RepeatEvent(1500);
                        break;
                    case EVENT_VENT:
                        DoCastAOE(SPELL_FLAME_VENTS);
                        events.RepeatEvent(20*IN_MILLISECONDS);
                        break;
                    case EVENT_SPEED:
                        DoCastAOE(SPELL_GATHERING_SPEED);
                        events.RepeatEvent(15*IN_MILLISECONDS);
                        break;
                    case EVENT_SUMMON:
                        if (summons.size() < 15)
                            if (Creature* lift = DoSummonFlyer(NPC_MECHANOLIFT, me, 30.0f, 50.0f, 0))
                                lift->GetMotionMaster()->MoveRandom(100);
                        events.RepeatEvent(2*IN_MILLISECONDS);
                        break;
                    case EVENT_SHUTDOWN:
                        DoScriptText(RAND(SAY_OVERLOAD_1, SAY_OVERLOAD_2, SAY_OVERLOAD_3), me);
                        me->MonsterTextEmote(EMOTE_OVERLOAD, 0, true);
                        me->AddAura(SPELL_SYSTEMS_SHUTDOWN, me);
                        me->RemoveAurasDueToSpell(SPELL_GATHERING_SPEED);
                        events.ScheduleEvent(EVENT_REPAIR, 4000);
                        events.CancelEvent(EVENT_SHUTDOWN);
                        break;
                    case EVENT_REPAIR:
                        me->MonsterTextEmote(EMOTE_REPAIR, 0, true);
                        me->ClearUnitState(UNIT_STAT_STUNNED | UNIT_STAT_ROOT);
                        events.ScheduleEvent(EVENT_SHUTDOWN, 150*IN_MILLISECONDS);
                        events.CancelEvent(EVENT_REPAIR);
                        break;
                    case EVENT_THORIM_S_HAMMER: // Tower of Storms
                        for (uint8 i = 0; i < 7; ++i)
                        {
                            if (Creature* thorim = DoSummon(NPC_THORIM_BEACON, me, float(urand(20,60)), 20000, TEMPSUMMON_TIMED_DESPAWN))
                                thorim->GetMotionMaster()->MoveRandom(100);
                        }
                        DoScriptText(SAY_TOWER_STORM, me);
                        events.CancelEvent(EVENT_THORIM_S_HAMMER);
                        break;
                    case EVENT_MIMIRON_S_INFERNO: // Tower of Flames
                        me->SummonCreature(NPC_MIMIRON_BEACON, 390.93f, -13.91f, 409.81f);
                        DoScriptText(SAY_TOWER_FLAME, me);
                        events.CancelEvent(EVENT_MIMIRON_S_INFERNO);
                        break;
                    case EVENT_HODIR_S_FURY:      // Tower of Frost
                        for (uint8 i = 0; i < 7; ++i)
                        {
                            if (Creature* hodir = DoSummon(NPC_HODIR_BEACON, me, 50, 0))
                                hodir->GetMotionMaster()->MoveRandom(100);
                        }
                        DoScriptText(SAY_TOWER_FROST, me);
                        events.CancelEvent(EVENT_HODIR_S_FURY);
                        break;
                    case EVENT_FREYA_S_WARD:    // Tower of Nature
                        DoScriptText(SAY_TOWER_NATURE, me);
                        StartFreyaEvent();
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM))
                            DoCast(target, SPELL_FREYA_S_WARD);
                        events.CancelEvent(EVENT_FREYA_S_WARD);
                        break;
                    default:
                        events.PopEvent();
                        break;
                }
                /*if (me->IsWithinMeleeRange(me->getVictim())) //bugged spell casts on units that are boarded on leviathan
                DoSpellAttackIfReady(SPELL_BATTERING_RAM);*/
                DoMeleeAttackIfReady();
            }

            void StartFreyaEvent()//summon these 4 on each corner wich wil spawn additional hostile mobs
            {
                me->SummonCreature(NPC_FREYA_BEACON, 377.02f, -119.10f, 409.81f);
                me->SummonCreature(NPC_FREYA_BEACON, 377.02f, 54.78f, 409.81f);
                me->SummonCreature(NPC_FREYA_BEACON, 185.62f, 54.78f, 409.81f);
                me->SummonCreature(NPC_FREYA_BEACON, 185.62f, -119.10f, 409.81f);
            }

            void DoAction(int32 const action)
            {
                // Start encounter
                if (action == 10)
                {
                    if (!me->isDead())
                    {
                        me->SetHomePosition(Center->GetPositionX(), Center->GetPositionY(), Center->GetPositionZ(), 0);
                        me->GetMotionMaster()->MoveCharge(Center->GetPositionX(), Center->GetPositionY(), Center->GetPositionZ()); //position center
                        me->SetReactState(REACT_AGGRESSIVE);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE | UNIT_FLAG_STUNNED);
                        return;
                    }
                }

                if (action && action <= 4) // Tower destruction, debuff leviathan loot and reduce active tower
                {
                    if (me->HasLootMode(31) && ActiveTowersCount == 4)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_4);
                        --ActiveTowersCount;
                    }
                    if (me->HasLootMode(15) && ActiveTowersCount == 3)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_3);
                        --ActiveTowersCount;
                    }
                    if (me->HasLootMode(7) && ActiveTowersCount == 2)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_2);
                        --ActiveTowersCount;
                    }
                    if (me->HasLootMode(3) && ActiveTowersCount == 1)
                    {
                        me->RemoveLootMode(LOOT_MODE_HARD_MODE_1);
                        --ActiveTowersCount;
                    }
                }

                switch (action)
                {
                    case 0:  // Activate hard-mode setting counter to 4 towers, enable all towers apply buffs on levithian
                        ActiveTowers = true;
                        towerOfStorms = true;
                        towerOfLife = true;
                        towerOfFlames = true;
                        towerOfFrost = true;
                        me->SetLootMode(31);
                        break;
                    case ACTION_TOWER_OF_STORM_DESTROYED:  // Tower of Storms destroyed
                        towerOfStorms = false;
                        break;
                    case ACTION_TOWER_OF_FROST_DESTROYED: // Tower of Frost destroyed
                        towerOfFrost = false;
                        break;
                    case ACTION_TOWER_OF_FLAMES_DESTROYED: // Tower of Flames destroyed
                        towerOfFlames = false;
                        break;
                    case ACTION_TOWER_OF_LIFE_DESTROYED: // Tower of Nature destroyed
                        towerOfLife = false;
                        break;
                    default:
                        break;
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathanAI(creature);
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        }
};

class boss_flame_leviathan_seat : public CreatureScript
{
    public:
        boss_flame_leviathan_seat() : CreatureScript("boss_flame_leviathan_seat") { }

<<<<<<< HEAD
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_flame_leviathan_seatAI (pCreature);
    }

    struct boss_flame_leviathan_seatAI : public PassiveAI
    {
        boss_flame_leviathan_seatAI(Creature* pCreature) : PassiveAI(pCreature), vehicle(pCreature->GetVehicleKit())
        {
            assert(vehicle);
            me->SetDisplayId(11686);
    #ifdef BOSS_DEBUG
            me->SetReactState(REACT_AGGRESSIVE);
    #endif
        }

        Vehicle* vehicle;

    #ifdef BOSS_DEBUG
        void MoveInLineOfSight(Unit *who)
        {
            if (who->GetTypeId() == TYPEID_PLAYER && CAST_PLR(who)->isGameMaster()
                && !who->GetVehicle() && vehicle->GetPassenger(SEAT_TURRET))
                who->EnterVehicle(vehicle, SEAT_PLAYER);
        }
    #endif
=======
        struct boss_flame_leviathan_seatAI : public ScriptedAI
        {
            boss_flame_leviathan_seatAI(Creature* creature) : ScriptedAI(creature), vehicle(creature->GetVehicleKit())
            {
                ASSERT(vehicle);
                me->SetReactState(REACT_PASSIVE);
                me->SetDisplayId(me->GetCreatureInfo()->Modelid2);
                instance = creature->GetInstanceScript();
            }

            InstanceScript* instance;
            Vehicle* vehicle;
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

            void Reset()
            {
                if (me->GetVehicleKit())
                    me->GetVehicleKit()->Reset();
            }

            void PassengerBoarded(Unit* who, int8 seatId, bool apply)
            {
<<<<<<< HEAD
                if (apply)
                {
                    DoScriptText(SAY_PLAYER_RIDING, me);
                    who->ApplySpellImmune(0, IMMUNITY_ID, SPELL_MISSILE_BARRAGE, true);
                }
                else
                    return;

                if (Creature* pTurret = vehicle->GetPassenger(SEAT_TURRET)->ToCreature())
                {
                    pTurret->setFaction(me->GetVehicleBase()->getFaction());
                    pTurret->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // unselectable
                    pTurret->AI()->AttackStart(who);
                }
                
                if (Unit* pDevice = vehicle->GetPassenger(SEAT_DEVICE)->ToCreature())
                {
                    pDevice->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                    pDevice->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
            }
        }
    };

=======
                if (!me->GetVehicle())
                    return;

                if (seatId == SEAT_PLAYER)
                {
                    if (!apply)
                        return;
                    else
                        DoScriptText(SAY_PLAYER_RIDING, me);

                    if (Creature* turret = me->GetVehicleKit()->GetPassenger(SEAT_TURRET)->ToCreature())
                    {
                        turret->setFaction(me->GetVehicleBase()->getFaction());
                        turret->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // unselectable
                        turret->AI()->AttackStart(who);
                    }
                    if (Creature* device = me->GetVehicleKit()->GetPassenger(SEAT_DEVICE)->ToCreature())
                    {
                        device->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        device->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    }

                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                }
                else if (seatId == SEAT_TURRET)
                {
                    if (apply)
                        return;

                    if (Unit* device = vehicle->GetPassenger(SEAT_DEVICE))
                    {
                        device->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        device->SetUInt32Value(UNIT_FIELD_FLAGS, 0); // unselectable
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_seatAI(creature);
        }
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
};

class boss_flame_leviathan_defense_cannon : public CreatureScript
{
    public:
        boss_flame_leviathan_defense_cannon() : CreatureScript("boss_flame_leviathan_defense_cannon") { }

        struct boss_flame_leviathan_defense_cannonAI : public ScriptedAI
        {
            boss_flame_leviathan_defense_cannonAI(Creature* creature) : ScriptedAI(creature)
            {
            }

<<<<<<< HEAD
    struct boss_flame_leviathan_defense_cannonAI : public ScriptedAI
    {
        boss_flame_leviathan_defense_cannonAI(Creature* pCreature) : ScriptedAI(pCreature) 
        {
            me->ApplySpellImmune(0, IMMUNITY_EFFECT, SPELL_EFFECT_KNOCK_BACK, true);
            me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_GRIP, true);
            NapalmTimer = 5000;
        }

        uint32 NapalmTimer;

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (NapalmTimer <= diff)
            {
                if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    if (!me->IsWithinDist(pTarget, 20))
                        DoCast(pTarget, SPELL_NAPALM);
                NapalmTimer = urand(10000, 15000);
            }
            else NapalmTimer -= diff;
=======
            uint32 NapalmTimer;

            void Reset ()
            {
                NapalmTimer = 5000;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (NapalmTimer <= diff)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0))
                        if(CanAIAttack(target))
                            DoCast(target, SPELL_NAPALM, true);

                    NapalmTimer = 5000;
                }
                else
                    NapalmTimer -= diff;
            }

            bool CanAIAttack(Unit* const who) const
            {
                if (who->GetTypeId() != TYPEID_PLAYER || !who->GetVehicle() || who->GetVehicleBase()->GetEntry() == NPC_SEAT)
                    return false;
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_defense_cannonAI(creature);
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        }
};

class boss_flame_leviathan_defense_turret : public CreatureScript
{
    public:
        boss_flame_leviathan_defense_turret() : CreatureScript("boss_flame_leviathan_defense_turret") { }

        struct boss_flame_leviathan_defense_turretAI : public TurretAI
        {
            boss_flame_leviathan_defense_turretAI(Creature* creature) : TurretAI(creature) {}

            void DamageTaken(Unit* who, uint32 &damage)
            {
                if (!CanAIAttack(who))
                    damage = 0;
            }

            bool CanAIAttack(Unit* const who) const
            {
                if (who->GetTypeId() != TYPEID_PLAYER || !who->GetVehicle() || who->GetVehicleBase()->GetEntry() != NPC_SEAT)
                    return false;
                return true;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_defense_turretAI(creature);
        }
};

class boss_flame_leviathan_overload_device : public CreatureScript
{
    public:
        boss_flame_leviathan_overload_device() : CreatureScript("boss_flame_leviathan_overload_device") { }

        struct boss_flame_leviathan_overload_deviceAI : public PassiveAI
        {
<<<<<<< HEAD
            instance = pCreature->GetInstanceScript();
            me->SetDisplayId(28469);
        }

        InstanceScript *instance;
=======
            boss_flame_leviathan_overload_deviceAI(Creature* creature) : PassiveAI(creature)
            {
            }
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

            void DoAction(const int32 param)
            {
                if (param == EVENT_SPELLCLICK)
                {
                    if (me->GetVehicle())
                    {
<<<<<<< HEAD
                        me->GetVehicleBase()->CastSpell(pPlayer, SPELL_SMOKE_TRAIL, true);
                        pPlayer->ApplySpellImmune(0, IMMUNITY_ID, SPELL_MISSILE_BARRAGE, false);
                        pPlayer->ExitVehicle();
                        pPlayer->GetMotionMaster()->MoveJumpTo(30, 60, 30);
=======
                        me->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        if (Unit* player = me->GetVehicle()->GetPassenger(SEAT_PLAYER))
                        {
                            me->GetVehicleBase()->CastSpell(player, SPELL_SMOKE_TRAIL, true);
                            player->GetMotionMaster()->MoveKnockbackFrom(me->GetVehicleBase()->GetPositionX(), me->GetVehicleBase()->GetPositionY(), 30, 30);
                            player->ExitVehicle();
                        }
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_overload_deviceAI(creature);
        }
};

class boss_flame_leviathan_safety_container : public CreatureScript
{
    public:
        boss_flame_leviathan_safety_container() : CreatureScript("boss_flame_leviathan_safety_container") { }

        struct boss_flame_leviathan_safety_containerAI : public PassiveAI
        {
            boss_flame_leviathan_safety_containerAI(Creature* creature) : PassiveAI(creature)
            {
            }

<<<<<<< HEAD
        void JustDied()
        {
            float x,y,z;
            me->GetPosition(x,y,z);
            z = me->GetMap()->GetHeight(x, y, z);
            me->GetMotionMaster()->MovePoint(0,x,y,z);
            me->GetMap()->CreatureRelocation(me, x,y,z,0);
        }
=======
            void JustDied(Unit* /*killer*/)
            {
                float x,y,z;
                me->GetPosition(x, y, z);
                z = me->GetMap()->GetHeight(x, y, z);
                me->GetMotionMaster()->MovePoint(0, x, y, z);
                me->GetMap()->CreatureRelocation(me, x, y, z, 0);
            }
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

            void UpdateAI(uint32 const /*diff*/)
            {
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new boss_flame_leviathan_safety_containerAI(creature);
        }
};

class npc_mechanolift : public CreatureScript
{
    public:
        npc_mechanolift() : CreatureScript("npc_mechanolift") { }

        struct npc_mechanoliftAI : public PassiveAI
        {
            npc_mechanoliftAI(Creature* creature) : PassiveAI(creature)
            {
                ASSERT(me->GetVehicleKit());
            }

            uint32 MoveTimer;

<<<<<<< HEAD
        void JustDied(Unit* pKiller)
        {
            me->GetMotionMaster()->MoveTargetedHome();
            Creature* pLiquid = DoSummon(NPC_LIQUID, me, 0);
            if (pLiquid)
            {
                pLiquid->CastSpell(pLiquid, SPELL_LIQUID_PYRITE, true);
                pLiquid->GetMotionMaster()->MoveFall(pKiller->GetPositionZ());
            }
        }
=======
            void Reset()
            {
                MoveTimer = 0;
                me->GetMotionMaster()->MoveRandom(50);
            }

            void JustDied(Unit* /*killer*/)
            {
                me->GetMotionMaster()->MoveTargetedHome();
                DoCast(SPELL_DUSTY_EXPLOSION);
                Creature* liquid = DoSummon(NPC_LIQUID, me, 0);
                if (liquid)
                {
                    liquid->CastSpell(liquid, SPELL_LIQUID_PYRITE, true);
                    liquid->CastSpell(liquid, SPELL_DUST_CLOUD_IMPACT, true);
                }
            }
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

            void MovementInform(uint32 type, uint32 id)
            {
<<<<<<< HEAD
                Creature* pContainer = me->FindNearestCreature(NPC_CONTAINER, 5, true);
                if (pContainer)
                    pContainer->EnterVehicle(me);
=======
                if (type == POINT_MOTION_TYPE && id == 1)
                    if (Creature* container = me->FindNearestCreature(NPC_CONTAINER, 5, true))
                        container->EnterVehicle(me);
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
            }

            void UpdateAI(const uint32 diff)
            {
                if (MoveTimer <= diff)
                {
<<<<<<< HEAD
                    Creature* pContainer = me->FindNearestCreature(NPC_CONTAINER, 50, true);
                    if (pContainer && !pContainer->GetVehicle())
                        me->GetMotionMaster()->MovePoint(1,pContainer->GetPositionX(),pContainer->GetPositionY(),pContainer->GetPositionZ());
=======
                    if (me->GetVehicleKit()->HasEmptySeat(-1))
                    {
                        Creature* container = me->FindNearestCreature(NPC_CONTAINER, 50, true);
                        if (container && !container->GetVehicle())
                            me->GetMotionMaster()->MovePoint(1, container->GetPositionX(), container->GetPositionY(), container->GetPositionZ());
                    }

                    MoveTimer = 30000; //check next 30 seconds
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
                }
                else
                    MoveTimer -= diff;
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_mechanoliftAI(creature);
        }
};

<<<<<<< HEAD

=======
// WHY IS THIS CALLED spell_???
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
class spell_pool_of_tar : public CreatureScript
{
    public:
        spell_pool_of_tar() : CreatureScript("spell_pool_of_tar") { }

        struct spell_pool_of_tarAI : public PassiveAI
        {
            spell_pool_of_tarAI(Creature* creature) : PassiveAI(creature)
            {
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->AddAura(SPELL_TAR_PASSIVE, me);
            }

            void DamageTaken(Unit* /*who*/, uint32& damage)
            {
                damage = 0;
            }

            void SpellHit(Unit* /*caster*/, SpellEntry const* spell)
            {
                if (spell->SchoolMask & SPELL_SCHOOL_MASK_FIRE && !me->HasAura(SPELL_BLAZE))
                    me->CastSpell(me, SPELL_BLAZE, true);
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new spell_pool_of_tarAI(creature);
        }
};

class npc_colossus : public CreatureScript
{
    public:
        npc_colossus() : CreatureScript("npc_colossus") { }

        struct npc_colossusAI : public ScriptedAI
        {
            npc_colossusAI(Creature* creature) : ScriptedAI(creature)
            {
                instance = creature->GetInstanceScript();
            }

<<<<<<< HEAD
        InstanceScript *instance;
        uint32 GroundSlamTimer;
        
        void Reset()
        {
            GroundSlamTimer = 10000;
        }

        void JustDied(Unit* /*Who*/)
        {
            if (me->isSummon())
            {
                if (Creature* pLeviathan = me->GetCreature(*me, instance->GetData64(DATA_LEVIATHAN)))
                    pLeviathan->AI()->DoAction(ACTION_COLOSSUS_COUNT);
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            if (GroundSlamTimer <= diff)
            {
                DoCast(me->getVictim(), SPELL_GROUND_SLAM);
                GroundSlamTimer = 10000;
            }
            else GroundSlamTimer -= diff;

            DoMeleeAttackIfReady() ;
=======
            InstanceScript *instance;

            void JustDied(Unit* /*Who*/)
            {
                if (me->GetHomePosition().IsInDist(Center, 50.f))
                    instance->SetData(TYPE_COLOSSUS, instance->GetData(TYPE_COLOSSUS)+1);
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!UpdateVictim())
                    return;

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_colossusAI(creature);
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        }
};

class npc_thorims_hammer : public CreatureScript
{
    public:
        npc_thorims_hammer() : CreatureScript("npc_thorims_hammer") { }

<<<<<<< HEAD
    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new  npc_thorims_hammerAI(pCreature);
    }

    struct npc_thorims_hammerAI : public Scripted_NoMovementAI
    {
        npc_thorims_hammerAI(Creature* pCreature) : Scripted_NoMovementAI (pCreature)
        {
            me->AddAura(LIGHTNING_SKYBEAM, me);
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(11686);
            hammerTimer = 3000;
            done = false;
        }
        
        uint32 hammerTimer;
        bool done;

        void UpdateAI(const uint32 diff)
        {
            if (hammerTimer <= diff && !done)
            {
                if (Creature* pTrigger = DoSummonFlyer(NPC_THORIM_TARGET_BEACON, me, 80, 0, 4000, TEMPSUMMON_TIMED_DESPAWN))
                    pTrigger->CastSpell(me, SPELL_THORIM_S_HAMMER, true);

                done = true;
            }
            else hammerTimer -= diff;
=======
        struct npc_thorims_hammerAI : public ScriptedAI
        {
            npc_thorims_hammerAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->AddAura(AURA_DUMMY_BLUE, me);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER && who->IsVehicle() && me->IsInRange(who, 0, 10, false))
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_THORIM_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                        trigger->CastSpell(who, SPELL_THORIM_S_HAMMER, true);
                }
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!me->HasAura(AURA_DUMMY_BLUE))
                    me->AddAura(AURA_DUMMY_BLUE, me);

                UpdateVictim();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_thorims_hammerAI(creature);
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        }
};

class npc_mimirons_inferno : public CreatureScript
{
public:
    npc_mimirons_inferno() : CreatureScript("npc_mimirons_inferno") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_mimirons_infernoAI(creature);
    }

    struct npc_mimirons_infernoAI : public ScriptedAI
    {
<<<<<<< HEAD
        npc_mimirons_infernoAI(Creature* pCreature) : ScriptedAI(pCreature)
=======
        npc_mimirons_infernoAI(Creature* creature) : npc_escortAI(creature)
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        {
            me->AddAura(RED_SKYBEAM, me);
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(11686);
            me->GetMotionMaster()->MoveRandom(100);
            infernoTimer = 2000;
            pause = false;
            infernoCount = 0;
        }

        bool pause;
        uint8 infernoCount;
        uint32 pauseTimer;
        uint32 infernoTimer;

        void UpdateAI(uint32 const diff)
        {
<<<<<<< HEAD
            if (pauseTimer <= diff && pause)
            {
                pause = false;
                infernoTimer = 0;
                infernoCount = 0;
            }
            else pauseTimer -= diff;
        
            if (infernoTimer <= diff && !pause)
            {
                if (Creature* pTrigger = DoSummonFlyer(NPC_MIMIRON_TARGET_BEACON, me, 80, 0, 20000, TEMPSUMMON_TIMED_DESPAWN))
                    pTrigger->CastSpell(me, SPELL_MIMIRON_S_INFERNO, true);

                infernoTimer = 2000;
                
                infernoCount++;
                if (infernoCount == 3)
                {
                    pause = true;
                    pauseTimer = 6000;
=======
            npc_escortAI::UpdateAI(diff);

            if (!HasEscortState(STATE_ESCORT_ESCORTING))
                Start(false, true, 0, NULL, false, true);
            else
            {
                if (infernoTimer <= diff)
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_MIMIRON_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                    {
                        trigger->CastSpell(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), SPELL_MIMIRON_S_INFERNO, true);
                        infernoTimer = 2000;
                    }
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
                }
            }
            else infernoTimer -= diff;
        }
    };

};


class npc_hodirs_fury : public CreatureScript
{
    public:
        npc_hodirs_fury() : CreatureScript("npc_hodirs_fury") { }

        struct npc_hodirs_furyAI : public ScriptedAI
        {
<<<<<<< HEAD
            me->AddAura(BLUE_SKYBEAM, me);
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(11686);
            me->GetMotionMaster()->MoveRandom(100);
            chaseTimer = 1000;
            freezeTimer = 5000;
            pause = false;
        }
        
        uint32 pauseTimer;
        uint32 freezeTimer;
        uint32 chaseTimer;
        bool pause;

        void UpdateAI(const uint32 diff)
        {
            if (pause)
            {
                if (freezeTimer <= diff)
                {
                    me->GetMotionMaster()->Initialize();
                    pause = false;
                    chaseTimer = 20000;
                    freezeTimer = 5000;
                    pauseTimer = 4000;
                
                    if (Creature* pTrigger = DoSummonFlyer(NPC_HODIR_TARGET_BEACON, me, 80, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                          pTrigger->CastSpell(me, SPELL_HODIR_S_FURY, true);
                }
                else freezeTimer -= diff;
                    
            }
            else
            {
                if (chaseTimer <= diff)
                {
                    if (Unit* pTarget = me->SelectNearestTarget(20))
                    {
                        pause = true;
                        freezeTimer = 6000;
                        me->GetMotionMaster()->MoveFollow(pTarget, 0, 0);
                    }
                    chaseTimer = 1000;
                }
                else chaseTimer -= diff;
                
                if (pauseTimer <= diff)
                {
                    me->GetMotionMaster()->MoveRandom(100);
                    pauseTimer = 60000;
                }
                else pauseTimer -= diff;
            }
=======
            npc_hodirs_furyAI(Creature* creature) : ScriptedAI(creature)
            {
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->AddAura(AURA_DUMMY_GREEN, me);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (who->GetTypeId() == TYPEID_PLAYER && who->IsVehicle() && me->IsInRange(who,0,5,false))
                {
                    if (Creature* trigger = DoSummonFlyer(NPC_HODIR_TARGET_BEACON, me, 20, 0, 1000, TEMPSUMMON_TIMED_DESPAWN))
                        trigger->CastSpell(who, SPELL_HODIR_S_FURY, true);
                }
            }

            void UpdateAI(uint32 const /*diff*/)
            {
                if (!me->HasAura(AURA_DUMMY_GREEN))
                    me->AddAura(AURA_DUMMY_GREEN, me);

                UpdateVictim();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_hodirs_furyAI(creature);
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        }
};

class npc_freyas_ward : public CreatureScript
{
    public:
        npc_freyas_ward() : CreatureScript("npc_freyas_ward") { }

        struct npc_freyas_wardAI : public ScriptedAI
        {
<<<<<<< HEAD
            me->AddAura(GREEN_SKYBEAM, me);
            me->SetReactState(REACT_PASSIVE);
            me->SetDisplayId(11686);
            summonTimer = urand(15000, 20000);
        }

        uint32 summonTimer ;

        void UpdateAI(const uint32 diff)
        {
            if (summonTimer <= diff)
            {
                if (Creature* pTrigger = DoSummonFlyer(NPC_FREYA_TARGET_BEACON, me, 80, 0, 3000, TEMPSUMMON_TIMED_DESPAWN))
                    pTrigger->CastSpell(me, SPELL_FREYA_S_WARD, true);

                summonTimer = urand(25000, 35000);
            }
            else summonTimer -= diff ;
        }
    };
=======
            npc_freyas_wardAI(Creature* creature) : ScriptedAI(creature)
            {
                me->AddAura(AURA_DUMMY_GREEN, me);
            }

            uint32 summonTimer;

            void Reset()
            {
                summonTimer = 5000;
            }

            void UpdateAI(uint32 const diff)
            {
                if (summonTimer <= diff)
                {
                    DoCast(SPELL_FREYA_S_WARD_EFFECT_1);
                    DoCast(SPELL_FREYA_S_WARD_EFFECT_2);
                    summonTimer = 20000;
                }
                else
                    summonTimer -= diff;

                if (!me->HasAura(AURA_DUMMY_GREEN))
                    me->AddAura(AURA_DUMMY_GREEN, me);
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

                UpdateVictim();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_freyas_wardAI(creature);
        }
};

class npc_freya_ward_summon : public CreatureScript
{
    public:
        npc_freya_ward_summon() : CreatureScript("npc_freya_ward_summon") { }

        struct npc_freya_ward_summonAI : public ScriptedAI
        {
<<<<<<< HEAD
            //for (uint32 i = 0; i < 4; ++i)
                //DoCast(me, SPELL_FREYA_SUMMONS, true);
            pInstance = pCreature->GetInstanceScript();
            me->GetMotionMaster()->MovePoint(0, 259.56f, -17.45f, 409.65f);
            lashTimer = 5000 ;
        }

        InstanceScript* pInstance;
        uint32 lashTimer ;

        void UpdateAI(const uint32 diff)
        {
            if (pInstance && pInstance->GetBossState(BOSS_LEVIATHAN) != IN_PROGRESS)
                me->DespawnOrUnsummon();
        
            if (!UpdateVictim())
                return;

            if (lashTimer <= diff)
            {
                DoCast(SPELL_LASH);
                lashTimer = 5000;
            }
            else lashTimer -= diff;
=======
            npc_freya_ward_summonAI(Creature* creature) : ScriptedAI(creature)
            {
                creature->GetMotionMaster()->MoveRandom(100);
            }

            uint32 lashTimer;

            void Reset()
            {
                lashTimer = 5000;
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim())
                    return;

                if (lashTimer <= diff)
                {
                    DoCast(SPELL_LASH);
                    lashTimer = 20000;
                }
                else
                    lashTimer -= diff;

                DoMeleeAttackIfReady();
            }
        };
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_freya_ward_summonAI(creature);
        }
};

//npc lore keeper
#define GOSSIP_ITEM_1  "Activate secondary defensive systems"
#define GOSSIP_ITEM_2  "Confirmed"
class npc_lorekeeper : public CreatureScript
{
    public:
        npc_lorekeeper() : CreatureScript("npc_lorekeeper") { }

<<<<<<< HEAD
    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        if (!pPlayer)
            return false;

        InstanceScript* instance = pCreature->GetInstanceScript();
        switch(uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                pPlayer->PrepareGossipMenu(pCreature);
                instance->instance->LoadGrid(364,-16); // make sure leviathan is loaded
                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_2,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                pPlayer->CLOSE_GOSSIP_MENU();
                if (Creature* pLeviathan = instance->instance->GetCreature(instance->GetData64(DATA_LEVIATHAN)))
                {
                    pLeviathan->AI()->DoAction(0);  // enable hard mode activating the 4 additional events spawning additional vehicles
                    pCreature->AI()->DoAction(0);   // spawn the vehicles
                    instance->SetBossState(BOSS_LEVIATHAN, SPECIAL);
                    if (Creature* Delorah = pCreature->FindNearestCreature(NPC_DELORAH, 30, true))
                    {
                        if (Creature* Branz = pCreature->FindNearestCreature(NPC_BRANZ_BRONZBEARD, 120, true))
                        {
                            Delorah->GetMotionMaster()->MovePoint(0, Branz->GetPositionX()-4, Branz->GetPositionY(), Branz->GetPositionZ());
                            // TODO DoScriptText(xxxx, Delorah, Branz); when reached at branz
                        }
                    }
                }
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        InstanceScript* instance = pCreature->GetInstanceScript();
        if ((pPlayer && instance && instance->GetBossState(BOSS_LEVIATHAN) != DONE && 
            instance->GetBossState(BOSS_LEVIATHAN) != SPECIAL) || pPlayer->isGameMaster())
        {
            pPlayer->PrepareGossipMenu(pCreature);
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
            pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        }
        return true;
    }
=======
        struct npc_lorekeeperAI : public ScriptedAI
        {
            npc_lorekeeperAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void DoAction(int32 const action)
            {
                // Start encounter
                if (action == 0)
                {
                    for (int32 i = 0; i < RAID_MODE(2, 5); ++i)
                        DoSummon(VEHICLE_SIEGE, PosSiege[i], 3000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    for (int32 i = 0; i < RAID_MODE(2, 5); ++i)
                        DoSummon(VEHICLE_CHOPPER, PosChopper[i], 3000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    for (int32 i = 0; i < RAID_MODE(2, 5); ++i)
                        DoSummon(VEHICLE_DEMOLISHER, PosDemolisher[i], 3000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                    return;
                }
            }
        };

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            InstanceScript* instance = creature->GetInstanceScript();
            if (!instance)
                return true;

            switch (action)
            {
                case GOSSIP_ACTION_INFO_DEF+1:
                    if (player)
                    {
                        player->PrepareGossipMenu(creature);
                        instance->instance->LoadGrid(364,-16); //make sure leviathan is loaded
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_2,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
                        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
                    }
                    break;
                case GOSSIP_ACTION_INFO_DEF+2:
                    if (player)
                        player->CLOSE_GOSSIP_MENU();

<<<<<<< HEAD
    struct npc_lorekeeperAI : public ScriptedAI
    {
        npc_lorekeeperAI(Creature* pCreature) : ScriptedAI(pCreature), summons(me)
        {
            instance = pCreature->GetInstanceScript();
        }

        InstanceScript* instance;
        SummonList summons;

        void JustSummoned(Creature *summon)
        {
            summons.Summon(summon);
=======
                    if (Creature* leviathan = instance->instance->GetCreature(instance->GetData64(TYPE_LEVIATHAN)))
                    {
                        CAST_AI(boss_flame_leviathan::boss_flame_leviathanAI, (leviathan->AI()))->DoAction(0); //enable hard mode activating the 4 additional events spawning additional vehicles
                        creature->SetVisible(false);
                        creature->AI()->DoAction(0); // spawn the vehicles
                        if (Creature* Delorah = creature->FindNearestCreature(NPC_DELORAH, 1000, true))
                        {
                            if (Creature* Branz = creature->FindNearestCreature(NPC_BRANZ_BRONZBEARD, 1000, true))
                            {
                                Delorah->GetMotionMaster()->MovePoint(0, Branz->GetPositionX()-4, Branz->GetPositionY(), Branz->GetPositionZ());
                                //TODO DoScriptText(xxxx, Delorah, Branz); when reached at branz
                            }
                        }
                    }
                    break;
            }

            return true;
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
<<<<<<< HEAD
            if (uiAction == 0)
            {
                summons.DespawnAll();
                for (int32 i = 0; i < RAID_MODE(2, 5); ++i)
                    DoSummon(VEHICLE_SIEGE, PosSiege[i], 3000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                for (int32 i = 0; i < RAID_MODE(2, 5); ++i)
                    DoSummon(VEHICLE_CHOPPER, PosChopper[i], 3000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                for (int32 i = 0; i < RAID_MODE(2, 5); ++i)
                    DoSummon(VEHICLE_DEMOLISHER, PosDemolisher[i], 3000, TEMPSUMMON_CORPSE_TIMED_DESPAWN);
                return;
=======
            InstanceScript* instance = creature->GetInstanceScript();
            if (instance && instance->GetData(TYPE_LEVIATHAN) !=DONE && player)
            {
                player->PrepareGossipMenu(creature);

                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
                player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
            }
            return true;
        }

        CreatureAI* GetAI(Creature* creature) const
        {
            return new npc_lorekeeperAI(creature);
        }
};

<<<<<<< HEAD
=======
//enable hardmode
////npc_brann_bronzebeard this requires more work involving area triggers. if reached this guy speaks through his radio..
//#define GOSSIP_ITEM_1  "xxxxx"
//#define GOSSIP_ITEM_2  "xxxxx"
//
/*
class npc_brann_bronzebeard : public CreatureScript
{
public:
    npc_brann_bronzebeard() : CreatureScript("npc_brann_bronzebeard") { }

    //bool OnGossipSelect(Player* pPlayer, Creature* creature, uint32 uiSender, uint32 uiAction)
    //{
    //    pPlayer->PlayerTalkClass->ClearMenus();
    //    switch(uiAction)
    //    {
    //        case GOSSIP_ACTION_INFO_DEF+1:
    //            if (pPlayer)
    //            {
    //                pPlayer->PrepareGossipMenu(creature);
    //
    //                pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_2,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+2);
    //                pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(creature), creature->GetGUID());
    //            }
    //            break;
    //        case GOSSIP_ACTION_INFO_DEF+2:
    //            if (pPlayer)
    //                pPlayer->CLOSE_GOSSIP_MENU();
    //            if (Creature* Lorekeeper = creature->FindNearestCreature(NPC_LOREKEEPER, 1000, true)) //lore keeper of lorgannon
    //                Lorekeeper->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
    //            break;
    //    }
    //    return true;
    //}
    //bool OnGossipHello(Player* pPlayer, Creature* creature)
    //{
    //    InstanceScript* instance = creature->GetInstanceScript();
    //    if (instance && instance->GetData(TYPE_LEVIATHAN) !=DONE)
    //    {
    //        pPlayer->PrepareGossipMenu(creature);
    //
    //        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT,GOSSIP_ITEM_1,GOSSIP_SENDER_MAIN,GOSSIP_ACTION_INFO_DEF+1);
    //        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(creature), creature->GetGUID());
    //    }
    //    return true;
    //}
    //
}
*/
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

class go_ulduar_tower : public GameObjectScript
{
    public:
        go_ulduar_tower() : GameObjectScript("go_ulduar_tower") { }

<<<<<<< HEAD
    void OnDestroyed(Player* /*pPlayer*/, GameObject* pGO, uint32 /*value*/)
    {
        InstanceScript* instance = pGO->GetInstanceScript();
        if (!instance)
            return;
            
        switch(pGO->GetEntry())
        {
            case GO_TOWER_OF_STORMS:
                instance->SetData(DATA_TOWER_DESTROYED, 1);
                break;
            case GO_TOWER_OF_FLAMES:
                instance->SetData(DATA_TOWER_DESTROYED, 2);
                break;
            case GO_TOWER_OF_FROST:
                instance->SetData(DATA_TOWER_DESTROYED, 3);
                break;
            case GO_TOWER_OF_LIFE:
                instance->SetData(DATA_TOWER_DESTROYED, 4);
                break;
        }
=======
        void OnDestroyed(Player* /*pPlayer*/, GameObject* go, uint32 /*value*/)
        {
            InstanceScript* instance = go->GetInstanceScript();
            if (!instance)
                return;
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

            switch (go->GetEntry())
            {
                case GO_TOWER_OF_STORMS:
                    instance->ProcessEvent(go, EVENT_TOWER_OF_STORM_DESTROYED);
                    break;
                case GO_TOWER_OF_FLAMES:
                    instance->ProcessEvent(go, EVENT_TOWER_OF_FLAMES_DESTROYED);
                    break;
                case GO_TOWER_OF_FROST:
                    instance->ProcessEvent(go, EVENT_TOWER_OF_FROST_DESTROYED);
                    break;
                case GO_TOWER_OF_LIFE:
                    instance->ProcessEvent(go, EVENT_TOWER_OF_LIFE_DESTROYED);
                    break;
            }

            Creature* trigger = go->FindNearestCreature(NPC_ULDUAR_GAUNTLET_GENERATOR, 15.0f, true);
            if (trigger)
                trigger->DisappearAndDie();
        }
};

class at_RX_214_repair_o_matic_station : public AreaTriggerScript
{
    public:
        at_RX_214_repair_o_matic_station() : AreaTriggerScript("at_RX_214_repair_o_matic_station") { }

        bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/)
        {
<<<<<<< HEAD
            if (!vehicle->HasAura(SPELL_AUTO_REPAIR) && !pPlayer->isInCombat())
            {
                vehicle->SetFullHealth();
                pPlayer->CastSpell(vehicle, SPELL_AUTO_REPAIR, true);
=======
            InstanceScript* instance = player->GetInstanceScript();
            if (Creature* vehicle = player->GetVehicleCreatureBase())
            {
                if (!vehicle->HasAura(SPELL_AUTO_REPAIR))
                {
                    player->MonsterTextEmote(EMOTE_REPAIR, player->GetGUID(), true);
                    player->CastSpell(vehicle, SPELL_AUTO_REPAIR, true);
                    if (Creature* leviathan = ObjectAccessor::GetCreature(*player, instance ? instance->GetData64(TYPE_LEVIATHAN) : 0))
                        leviathan->AI()->SetData(DATA_UNBROKEN, 0); // set bool to false thats checked in leviathan getdata
                }
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
            }
            return true;
        }
};

class achievement_three_car_garage_demolisher : public AchievementCriteriaScript
{
    public:
        achievement_three_car_garage_demolisher() : AchievementCriteriaScript("achievement_three_car_garage_demolisher") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == VEHICLE_DEMOLISHER)
                    return true;
            }

            return false;
        }
};

class achievement_three_car_garage_chopper : public AchievementCriteriaScript
{
    public:
        achievement_three_car_garage_chopper() : AchievementCriteriaScript("achievement_three_car_garage_chopper") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == VEHICLE_CHOPPER)
                    return true;
            }

            return false;
        }
};

class achievement_three_car_garage_siege : public AchievementCriteriaScript
{
    public:
        achievement_three_car_garage_siege() : AchievementCriteriaScript("achievement_three_car_garage_siege") { }

        bool OnCheck(Player* source, Unit* /*target*/)
        {
            if (Creature* vehicle = source->GetVehicleCreatureBase())
            {
                if (vehicle->GetEntry() == VEHICLE_SIEGE)
                    return true;
            }

            return false;
        }
};

class achievement_shutout : public AchievementCriteriaScript
{
    public:
        achievement_shutout() : AchievementCriteriaScript("achievement_shutout") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target)
                if (Creature* leviathan = target->ToCreature())
                    if (leviathan->AI()->GetData(DATA_SHUTOUT))
                        return true;

            return false;
        }
};

class achievement_unbroken : public AchievementCriteriaScript
{
    public:
        achievement_unbroken() : AchievementCriteriaScript("achievement_unbroken") { }

        bool OnCheck(Player* /*source*/, Unit* target)
        {
            if (target)
                if (Creature* leviathan = target->ToCreature())
                    if (leviathan->AI()->GetData(DATA_UNBROKEN))
                        return true;

            return false;
        }
};

void AddSC_boss_flame_leviathan()
{
    new boss_flame_leviathan();
    new boss_flame_leviathan_seat();
    new boss_flame_leviathan_defense_cannon();
    new boss_flame_leviathan_defense_turret();
    new boss_flame_leviathan_overload_device();
    new boss_flame_leviathan_safety_container();
    new npc_mechanolift();
    new spell_pool_of_tar();
    new npc_colossus();
    new npc_thorims_hammer();
    new npc_mimirons_inferno();
    new npc_hodirs_fury();
    new npc_freyas_ward();
    new npc_freya_ward_summon();
    new npc_lorekeeper();
    new go_ulduar_tower();
    new at_RX_214_repair_o_matic_station();
    new achievement_three_car_garage_demolisher();
    new achievement_three_car_garage_chopper();
    new achievement_three_car_garage_siege();
    new achievement_shutout();
    new achievement_unbroken();
}
