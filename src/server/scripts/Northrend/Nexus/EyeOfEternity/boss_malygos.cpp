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

#include "ScriptPCH.h"
#include "eye_of_eternity.h"

enum eYells
{
    // intro
    SAY_INTRO_1                              =  -1616000,
    SAY_INTRO_2                              =  -1616001,
    SAY_INTRO_3                              =  -1616002,
    SAY_INTRO_4                              =  -1616003,
    SAY_INTRO_5                              =  -1616004,
    // phase 1
    SAY_PHASE1_AGGRO                         =  -1616005,
    SAY_MAGIC_BLAST                          =  -1616006, //?
    SAY_SPARK_SUMMON                         =  -1616035,
    SAY_SPARK_BUFFED                         =  -1616007,
    SAY_PHASE1_SLAY_1                        =  -1616008,
    SAY_PHASE1_SLAY_2                        =  -1616009,
    SAY_PHASE1_SLAY_3                        =  -1616010,
    SAY_PHASE1_END                           =  -1616012,
    // phase 2
    SAY_PHASE2_AGGRO                         =  -1616013,
    SAY_BREATH_ATTACK                        =  -1616014,
    SAY_BREATH_ANNOUNCE                      =  -1616015,
    SAY_ANTI_MAGIC_SHELL                     =  -1616016,
    SAY_PHASE2_SLAY_1                        =  -1616020,
    SAY_PHASE2_SLAY_2                        =  -1616021,
    SAY_PHASE2_SLAY_3                        =  -1616022,
    SAY_PHASE2_END                           =  -1616017,
    // phase 3
    SAY_PHASE3_INTRO                         =  -1616018,
    SAY_PHASE3_AGGRO                         =  -1616019,
    SAY_PHASE3_SLAY_1                        =  -1616023,
    SAY_PHASE3_SLAY_2                        =  -1616024,
    SAY_PHASE3_SLAY_3                        =  -1616025,
    SAY_SURGE_OF_POWER                       =  -1616026,
    SAY_PHASE3_CAST_1                        =  -1616027,
    SAY_PHASE3_CAST_2                        =  -1616028,
    SAY_PHASE3_CAST_3                        =  -1616029,
    SAY_DEATH                                =  -1616030,
    SAY_OUTRO_1                              =  -1616031,
    SAY_OUTRO_2                              =  -1616032,
    SAY_OUTRO_3                              =  -1616033,
    SAY_OUTRO_4                              =  -1616034
};

enum eSpells
{
    // phase 1
    SPELL_IRIS_VISUAL                        = 61012,
    SPELL_ARCANE_BREATH_N                    = 56272,
    SPELL_ARCANE_BREATH_H                    = 60072,
    SPELL_ARCANE_STORM_N                     = 61693,
    SPELL_ARCANE_STORM_H                     = 61694,
    SPELL_VORTEX                             = 56105,
    SPELL_VORTEX_VISUAL                      = 55873,
    SPELL_VORTEX_PLAYER                      = 55853,
    SPELL_POWER_SPARK                        = 56152,
    SPELL_POWER_SPARK_VISUAL                 = 55845,
    SPELL_POWER_SPARK_PLAYERS                = 55852,

    // phase 2
    SPELL_ARCANE_BOMB                        = 56430,
    SPELL_ARCANE_BOMB_KNOCKBACK              = 56431,
    SPELL_ARCANE_OVERLOAD                    = 56432,
    SPELL_DEEP_BREATH                        = 56505,

    SPELL_ARCANE_SHOCK_N                     = 57058,
    SPELL_ARCANE_SHOCK_H                     = 60073,
    SPELL_HASTE                              = 57060,
    SPELL_ARCANE_BARRAGE                     = 56397,
    SPELL_ARCANE_BARRAGE_DMG                 = 63934,

    SPELL_DESTROY_PLATFORM_CHANNEL           = 58842,
    SPELL_DESTROY_PLATFORM_BOOM              = 59084,
    SPELL_DESTROY_PLATFORM_EVENT             = 59099,
    //SPELL_SUMMON_RED_DRAGON_BUDDY            = 56070,

    // phase 3
    SPELL_ARCANE_PULSE                       = 57432,
    SPELL_STATIC_FIELD                       = 57428,
    SPELL_STATIC_FIELD_MISSLE                = 57430,
    SPELL_SURGE_OF_POWER_N                   = 57407,
    SPELL_SURGE_OF_POWER_H                   = 60936,

    SPELL_ALEXSTRASZAS_GIFT_VISUAL           = 61023,
    SPELL_ALEXSTRASZAS_GIFT_BEAM             = 61028,
    SPELL_ENRAGE                             = 47008,
    SPELL_ROOT                               = 18373 //hack
};

enum ePhase
{
    PHASE_NONE          = 0, // waiting for someone to use iris
    PHASE_GROUND        = 1, // phase 1 melee / spells
    PHASE_VORTEX        = 2, // phase 1 vortex
    PHASE_ADDS          = 3, // phase 2
    PHASE_DRAGONS       = 4, // phase 3
    PHASE_IDLE          = 5  // used between main phases
};

enum eAction
{
    ACTION_START        = 0,
    ACTION_VORTEX       = 1,
    ACTION_SPARK        = 2,
    ACTION_OVERLOAD     = 3,
    ACTION_DEEP_BREATH  = 4,
    ACTION_SPAWN_ADDS   = 5,
    ACTION_MOUNT_ALL    = 6
};

enum eMovePoints
{
    POINT_START         = 1,
    POINT_VORTEX        = 2,
    POINT_FLY_DOWN      = 3,
    POINT_PHASE_2       = 4, // TODO: should move around
    POINT_DESTROY_FLOOR = 5,
    POINT_PHASE_3       = 6
};

static Position Locations[]=
{
    {1178.01f, 1276.01f, 268.2f, 2.3143f},  // p0 - first fly down position
    {1154.20f, 1301.68f, 302.5f, 2.3143f},  // p1 - low room center / vortex
    {1154.20f, 1301.68f, 285.5f, 2.3143f},  // p1 - vortex vehicle position
    {1154.20f, 1301.68f, 320.5f, 2.3143f},  // p2 - higher room center, should fly around
    {1154.20f, 1301.68f, 225.0f, 2.3143f},  // p3 - "inside" destroyed platform
    {1154.35f, 1300.87f, 270.2f, 0.0f}      // alexstraszas gift
};

static Position SparkLocations[]=
{
    // power spark spawn positions
    {1052.417f, 1200.52f, 295.972f, 0.78539f},
    {1247.670f, 1408.05f, 295.972f, 3.97935f},
    {1047.675f, 1403.80f, 295.972f, 5.53269f},
    {1243.182f, 1215.42f, 295.972f, 2.35619f}
};

static Position LordLocations[]=
{
    // nexus lord fly to ground positions
    {1172.396f, 1301.735f, 266.2f, 0.0f},
    {1136.652f, 1301.850f, 266.2f, 0.0f},
    {1154.490f, 1319.730f, 266.2f, 0.0f},
    {1154.160f, 1282.878f, 266.2f, 0.0f}
};

#define FLOOR_Z           268.17f

class boss_malygos : public CreatureScript
{
public:
    boss_malygos() : CreatureScript("boss_malygos") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new boss_malygosAI (pCreature);
    }

    struct boss_malygosAI : public ScriptedAI
    {
        boss_malygosAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
        {
            m_pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;
        SummonList Summons;

        std::set<uint64> SparkList;

        bool vortexing;

        uint8 uiStep;
        uint8 uiPhase;
        uint8 uiAddsCount;

        uint32 uiWaitTimer;
        uint32 uiStormTimer;
        uint32 uiSparkTimer;
        uint32 uiThreatTimer;
        uint32 uiEnrageTimer;
        uint32 uiVortexTimer;
        uint32 uiOverloadTimer;
        uint32 uiStaticFieldTimer;
        uint32 uiArcanePulseTimer;
        uint32 uiArcaneBreathTimer;
        uint32 uiSurgeOfPowerTimer;

        void Reset()
        {
            vortexing = false;
            uiPhase = PHASE_NONE;
            uiAddsCount = 0;
            uiStep = 0;

            uiWaitTimer = 10*IN_MILLISECONDS;
            uiStormTimer = 5*IN_MILLISECONDS;
            uiSparkTimer = 20*IN_MILLISECONDS;
            uiThreatTimer = 10*IN_MILLISECONDS;
            uiEnrageTimer = 10*MINUTE*IN_MILLISECONDS;
            uiVortexTimer = 25*IN_MILLISECONDS;
            uiOverloadTimer = 5*IN_MILLISECONDS;
            uiStaticFieldTimer = 20*IN_MILLISECONDS;
            uiArcanePulseTimer = 10*IN_MILLISECONDS;
            uiArcaneBreathTimer = 10*IN_MILLISECONDS;
            uiSurgeOfPowerTimer = 60*IN_MILLISECONDS;

            me->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);

            me->SetFlying(true);
            me->SetSpeed(MOVE_FLIGHT, 2.0f);
            me->SetReactState(REACT_PASSIVE);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_PASSIVE);

            Summons.DespawnAll();
            SparkList.clear();

            if (m_pInstance)
            {
                m_pInstance->SetData(TYPE_MALYGOS, NOT_STARTED);
                m_pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT,  ACHIEV_TIMED_START_EVENT);
            }
        }

        // try to fix bad reset (due to grid issues)?
        void JustReachedHome()
        {
            Reset();
        }

        void JustSummoned(Creature *summon)
        {
            switch (summon->GetEntry())
            {
                case NPC_POWER_SPARK:
                    SparkList.insert(summon->GetGUID());
                    break;
                case NPC_STATIC_FIELD:
                    summon->SetDisplayId(11686);
                    summon->SetFlying(true);
                    summon->SetInCombatWithZone();
                    summon->AddUnitState(UNIT_STAT_ROOT);
                    summon->SetReactState(REACT_PASSIVE);
                    summon->ForcedDespawn(30*IN_MILLISECONDS);
                    summon->CastSpell(summon, SPELL_STATIC_FIELD, true);
                    break;
            }
            Summons.Summon(summon);
        }

        void SummonedCreatureDespawn(Creature *summon)
        {
            switch (summon->GetEntry())
            {
                case NPC_POWER_SPARK:
                    SparkList.erase(summon->GetGUID());
                    break;
                case NPC_NEXUS_LORD:
                case NPC_SCION_OF_ETERNITY:
                    if (Creature* pDisc = me->SummonCreature(NPC_DISC_PLAYER, summon->GetPositionX(), summon->GetPositionY(), FLOOR_Z, 0.0f))
                        pDisc->SetSpeed(MOVE_FLIGHT, 3.0f);
                    uiAddsCount++;
                    break;
            }
            Summons.Despawn(summon);
        }

        void KilledUnit(Unit *pVictim)
        {
            if (pVictim == me)
                return;

            switch (uiPhase)
            {
                case PHASE_GROUND:
                case PHASE_VORTEX:
                    DoScriptText(RAND(SAY_PHASE1_SLAY_1, SAY_PHASE1_SLAY_2, SAY_PHASE1_SLAY_3), me);
                    break;
                case PHASE_ADDS:
                    DoScriptText(RAND(SAY_PHASE2_SLAY_1, SAY_PHASE2_SLAY_2, SAY_PHASE2_SLAY_3), me);
                    break;
                case PHASE_DRAGONS:
                    DoScriptText(RAND(SAY_PHASE3_SLAY_1, SAY_PHASE3_SLAY_2, SAY_PHASE3_SLAY_3), me);
                    break;
                default:
                    break;
            }
        }

        void JustDied(Unit* /*killer*/)
        {
            DoScriptText(SAY_DEATH, me);
            Summons.DespawnAll(); // only static fields left
            me->SummonCreature(NPC_ALEXSTRASZA, Locations[3], TEMPSUMMON_TIMED_DESPAWN, 9*MINUTE*IN_MILLISECONDS);
        }

        void MoveInLineOfSight(Unit* pWho)
        {
            if (uiPhase != PHASE_GROUND || pWho->GetTypeId() != TYPEID_UNIT)
                return;

            if (pWho->GetEntry() == NPC_POWER_SPARK && me->GetDistance(pWho) < 5.0f && !pWho->HasAura(SPELL_POWER_SPARK_PLAYERS))
            {
                DoCast(SPELL_POWER_SPARK);
                DoScriptText(SAY_SPARK_BUFFED, me);
                pWho->ToCreature()->ForcedDespawn(500);
            }
        }

        void DoAction(const int32 param)
        {
            switch (param)
            {
                case ACTION_START:
                {
                    me->SetInCombatWithZone();
                    me->GetMotionMaster()->MovePoint(POINT_START, Locations[0]);

                    while (Creature* pDragon = me->FindNearestCreature(NPC_WYRMREST_SKYTALON, 250.0f))
                        pDragon->ForcedDespawn();

                    break;
                }
                case ACTION_VORTEX:
                {
                    Map* map = me->GetMap();
                    if (!map->IsDungeon())
                        return;

                    Map::PlayerList const &PlayerList = map->GetPlayers();
                    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        Player* i_pl = i->getSource();
                        if (i_pl && !i_pl->isGameMaster() && i_pl->isAlive())
                        {
                            if (Creature* pVortex = me->SummonCreature(NPC_VORTEX, Locations[2], TEMPSUMMON_TIMED_DESPAWN, 10*IN_MILLISECONDS))
                            {
                                pVortex->SetDisplayId(11686);
                                pVortex->SetFlying(true);
                                i_pl->EnterVehicle(pVortex, 0);
                                i_pl->AddAura(SPELL_VORTEX_PLAYER, i_pl);
                            }
                        }
                    }   
                    break;
                }
                case ACTION_SPARK:
                {
                    if (Creature* pSpark = me->SummonCreature(NPC_POWER_SPARK, SparkLocations[urand(0, 3)], TEMPSUMMON_TIMED_DESPAWN, 90*IN_MILLISECONDS))
                    {
                        DoScriptText(SAY_SPARK_SUMMON, me);
                        pSpark->SetFlying(true);
                        pSpark->SetReactState(REACT_PASSIVE);
                        pSpark->SetInCombatWithZone();
                        pSpark->GetMotionMaster()->MoveFollow(me, 0.0f, 0.0f);
                    }
                    break;
                }
                case ACTION_OVERLOAD:
                {
                    float x, y, angle;
                    angle = float(2 * M_PI * rand_norm());
                    x = Locations[1].GetPositionX() + float(urand(10, 28)) * cos(angle);
                    y = Locations[1].GetPositionY() + float(urand(10, 28)) * sin(angle);

                    if (Creature* pOverload = me->SummonCreature(NPC_ARCANE_OVERLOAD, x, y, FLOOR_Z, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 45*IN_MILLISECONDS))
                    {
                        if (!urand(0, 2))
                            DoScriptText(SAY_ANTI_MAGIC_SHELL, me);
                        pOverload->AddUnitState(UNIT_STAT_ROOT);
                        pOverload->SetReactState(REACT_PASSIVE);
                        pOverload->SetInCombatWithZone();
                        DoCast(pOverload, SPELL_ARCANE_BOMB, true);
                    }
                    break;
                }
                case ACTION_DEEP_BREATH:
                {
                    if (Creature* pSurge = me->SummonCreature(NPC_SURGE_OF_POWER, Locations[3], TEMPSUMMON_TIMED_DESPAWN, 10*IN_MILLISECONDS))
                    {
                        DoScriptText(SAY_BREATH_ANNOUNCE, me);
                        DoScriptText(SAY_BREATH_ATTACK, me);
                        pSurge->SetDisplayId(11686);
                        pSurge->SetReactState(REACT_PASSIVE);
                        pSurge->SetInCombatWithZone();
                        DoCast(pSurge, SPELL_DEEP_BREATH);
                    }
                    break;
                }
                case ACTION_SPAWN_ADDS:
                {
                    // nexus lords
                    for (uint8 i = 0; i < RAID_MODE(2, 4); ++i)
                    {
                        if (Creature* pLord = me->SummonCreature(NPC_NEXUS_LORD, Locations[1], TEMPSUMMON_CORPSE_DESPAWN))
                        {
                            pLord->SetReactState(REACT_PASSIVE);
                            if (Creature* pTemp = me->SummonCreature(NPC_DISC_NPC, Locations[1], TEMPSUMMON_CORPSE_DESPAWN))
                            {
                                pLord->EnterVehicle(pTemp, 0);
                                pTemp->SetReactState(REACT_PASSIVE);
                                pTemp->GetMotionMaster()->MovePoint(0, LordLocations[i]);
                            }
                        }
                    }
                    // scions of eternity
                    for (uint8 i = 0; i < RAID_MODE(4, 8); ++i)
                    {
                        if (Creature* pScion = me->SummonCreature(NPC_SCION_OF_ETERNITY, Locations[1], TEMPSUMMON_CORPSE_DESPAWN))
                        {
                            pScion->SetInCombatWithZone();
                            if (Creature* pTemp = me->SummonCreature(NPC_DISC_NPC, Locations[1], TEMPSUMMON_CORPSE_DESPAWN))
                            {
                                pScion->EnterVehicle(pTemp, 0);
                                pTemp->SetFlying(true);
                                pTemp->SetSpeed(MOVE_FLIGHT, 0.7f);
                                pTemp->SetReactState(REACT_PASSIVE);
                                pTemp->GetMotionMaster()->MovePoint(0, Locations[2]);
                                pTemp->AI()->SetData(0, (i + 1) * RAID_MODE(4, 2));
                            }
                        }
                    }
                    break;
                }
                case ACTION_MOUNT_ALL:
                {
                    Map *map = me->GetMap();
                    if (!map->IsDungeon())
                        return;

                    Map::PlayerList const &PlayerList = map->GetPlayers();
                    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        Player* i_pl = i->getSource();
                        if (i_pl && !i_pl->isGameMaster() && i_pl->isAlive())
                        {
                            if (Creature* pMount = i_pl->SummonCreature(NPC_WYRMREST_SKYTALON, i_pl->GetPositionX(), i_pl->GetPositionY(), 220.0f, i_pl->GetOrientation()))
                            {
                                pMount->SetFlying(true);
                                pMount->SetSpeed(MOVE_FLIGHT, 2.0f); //TODO: find value
                                i_pl->EnterVehicle(pMount, 0);
                            }
                        }
                    }
                    me->SetInCombatWithZone();
                    break;
                }
                default:
                    break;
            }
        }

        void SparkMovement(bool move)
        {
            if (SparkList.empty())
                return;

            for (std::set<uint64>::const_iterator itr = SparkList.begin(); itr != SparkList.end(); ++itr)
                if (Unit* pSpark = me->GetUnit(*me, *itr))
                {
                    // spark already "dead"
                    if (pSpark->HasAura(SPELL_POWER_SPARK_PLAYERS))
                        continue;

                    if (move)
                        pSpark->GetMotionMaster()->MoveFollow(me, 0.0f, 0.0f);
                    else
                        pSpark->GetMotionMaster()->Clear();

                    // remove remaining free sparks
                    if (uiPhase == PHASE_ADDS)
                        me->Kill(pSpark);
                }
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
                // landed right after iris got used
                case POINT_START:
                {
                    DoScriptText(SAY_PHASE1_AGGRO, me);
                    if (m_pInstance)
                    {
                        m_pInstance->SetData(DATA_MALYGOS, IN_PROGRESS);
                        m_pInstance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_TIMED_START_EVENT);
                    }
                    me->SetFlying(false);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_OOC_NOT_ATTACKABLE | UNIT_FLAG_PASSIVE);
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetInCombatWithZone();
                    uiPhase = PHASE_GROUND;
                    break;
                }
                // reached vortexing position
                case POINT_VORTEX:
                {
                    // cast visual and give 2 seconds for heal
                    vortexing = false;
                    DoCast(me, SPELL_VORTEX_VISUAL, true);
                    uiWaitTimer = 2*IN_MILLISECONDS;
                    uiPhase = PHASE_VORTEX;
                    break;
                }
                // vortex finished, reached current victim's pos.
                case POINT_FLY_DOWN:
                {
                    SparkMovement(true);
                    me->SetFlying(false);
                    me->GetMotionMaster()->MoveChase(me->getVictim());
                    me->SetReactState(REACT_AGGRESSIVE);
                    // give some time to heal vortex dmg
                    uiStormTimer = urand(7*IN_MILLISECONDS, 10*IN_MILLISECONDS);
                    uiArcaneBreathTimer = RAID_MODE(7*IN_MILLISECONDS, 3*IN_MILLISECONDS);
                    uiVortexTimer = 45*IN_MILLISECONDS;
                    uiPhase = PHASE_GROUND;
                    break;
                }
                // ready to begin phase 2
                case POINT_PHASE_2:
                {
                    DoScriptText(SAY_PHASE2_AGGRO, me);
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    DoAction(ACTION_SPAWN_ADDS);
                    uiPhase = PHASE_ADDS;
                    SparkMovement(false);
                    break;
                }
                case POINT_DESTROY_FLOOR:
                {
                    DoScriptText(SAY_PHASE3_INTRO, me);
                    DoCast(SPELL_DESTROY_PLATFORM_CHANNEL);
                    uiWaitTimer = 6*IN_MILLISECONDS;
                    uiStep = 1;
                    uiPhase = PHASE_IDLE;
                    break;
                }
                // start phase 3
                case POINT_PHASE_3:
                {
                    DoScriptText(SAY_PHASE3_AGGRO, me);
                    me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE);
                    DoCast(me, SPELL_ROOT, true);
                    uiSurgeOfPowerTimer = 10*IN_MILLISECONDS;
                    uiStormTimer = 15*IN_MILLISECONDS;
                    uiPhase = PHASE_DRAGONS;
                    break;
                }
                default:
                    break;
            }
        }

        void SpellHitTarget(Unit* target, const SpellEntry* spell)
        {
            if (spell->Id == SPELL_ARCANE_BOMB)
            {
                target->CastSpell(target, SPELL_ARCANE_BOMB_KNOCKBACK, true);
                target->CastSpell(target, SPELL_ARCANE_OVERLOAD, true);
            }
        }

        Unit* SelectVehicleBaseOrPlayer()
        {
            if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM))
            {
                if (Unit* pVehicle = pTarget->GetVehicleBase())
                    return pVehicle;

                return pTarget;
            }

            return NULL;
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (uiPhase == PHASE_NONE || (uiPhase != PHASE_NONE && !UpdateVictim()))
                return;

            if (uiThreatTimer <= uiDiff)
            {
                DoAttackerAreaInCombat(me, 100.0f);
                uiThreatTimer = 5*IN_MILLISECONDS;
            } else uiThreatTimer -= uiDiff;

            if (!me->HasAura(SPELL_ENRAGE))
            {
                if (uiEnrageTimer <= uiDiff)
                {
                    if (uiPhase == PHASE_GROUND || uiPhase == PHASE_ADDS || uiPhase == PHASE_DRAGONS)
                    {
                        me->InterruptNonMeleeSpells(true);
                        DoCast(me, SPELL_ENRAGE, true);

                        if (uiPhase == PHASE_ADDS)
                        {
                            me->SetFlying(true);
                            me->SetSpeed(MOVE_FLIGHT, 10.0f);
                            me->SetReactState(REACT_AGGRESSIVE);
                            me->GetMotionMaster()->Clear();
                            me->GetMotionMaster()->MoveChase(me->getVictim());
                        }
                    }
                } else uiEnrageTimer -= uiDiff;
            }

            switch (uiPhase)
            {
                case PHASE_GROUND:
                {
                    if (me->HasUnitState(UNIT_STAT_CASTING))
                        return;
 
                    if (uiStormTimer <= uiDiff)
                    {
                        DoCast(me, RAID_MODE(SPELL_ARCANE_STORM_N, SPELL_ARCANE_STORM_H), true);
                        uiStormTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
                    } else uiStormTimer -= uiDiff;

                    if (uiSparkTimer <= uiDiff)
                    {
                        DoAction(ACTION_SPARK);
                        uiSparkTimer = 20*IN_MILLISECONDS;
                    } else uiSparkTimer -= uiDiff;

                    if (uiArcaneBreathTimer <= uiDiff)
                    {
                        DoCast(me->getVictim(), RAID_MODE(SPELL_ARCANE_BREATH_N, SPELL_ARCANE_BREATH_H));
                        uiArcaneBreathTimer = 20*IN_MILLISECONDS;
                    } else uiArcaneBreathTimer -= uiDiff;

                    if (uiVortexTimer <= uiDiff)
                    {
                        SparkMovement(false);
                        // fly up
                        me->SetFlying(true);
                        me->SetReactState(REACT_PASSIVE);
                        me->GetMotionMaster()->MovePoint(POINT_VORTEX, Locations[1]);
                        // set idle phase
                        uiPhase = PHASE_IDLE;
                        uiVortexTimer = 12*IN_MILLISECONDS;
                    } else uiVortexTimer -= uiDiff;

                    // fly up for p2
                    if (HealthBelowPct(50))
                    {
                        if (!me->HasAura(SPELL_ENRAGE))
                        {
                            DoScriptText(SAY_PHASE1_END, me);
                            me->SetFlying(true);
                            me->SetReactState(REACT_PASSIVE);
                            me->GetMotionMaster()->MovePoint(POINT_PHASE_2, Locations[3]);
                            uiPhase = PHASE_IDLE;
                        }
                    }

                    DoMeleeAttackIfReady();
                    break;
                }
                case PHASE_VORTEX:
                {
                    if (vortexing)
                    {
                        if (uiVortexTimer <= uiDiff)
                        {
                            float x, y, z;
                            me->getVictim()->GetPosition(x, y, z);
                            me->GetMotionMaster()->MovePoint(POINT_FLY_DOWN, x, y, z);
                            uiPhase = PHASE_IDLE;
                        } else uiVortexTimer -= uiDiff;
                    }
                    else
                    {
                        if (uiWaitTimer <= uiDiff)
                        {
                            vortexing = true;
                            DoAction(ACTION_VORTEX);
                        } else uiWaitTimer -= uiDiff;
                    }
                    break;
                }
                case PHASE_ADDS:
                {
                    if (me->HasUnitState(UNIT_STAT_CASTING))
                        return;

                    if (uiOverloadTimer <= uiDiff)
                    {
                        DoAction(ACTION_OVERLOAD);
                        uiOverloadTimer = urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS);
                    } else uiOverloadTimer -= uiDiff;

                    if (uiSurgeOfPowerTimer <= uiDiff)
                    {
                        DoAction(ACTION_DEEP_BREATH);
                        uiSurgeOfPowerTimer = 60*IN_MILLISECONDS;
                    } else uiSurgeOfPowerTimer -= uiDiff;

                    if (uiAddsCount == RAID_MODE(6, 12))
                    {
                        DoScriptText(SAY_PHASE2_END, me);
                        me->GetMotionMaster()->MovePoint(POINT_DESTROY_FLOOR, Locations[1]);
                        Summons.DespawnAll(); // remove remaining anti-magic shells and discs
                        uiPhase = PHASE_IDLE;
                    }

                    if (me->HasAura(SPELL_ENRAGE))
                        DoMeleeAttackIfReady();

                    break;
                }
                case PHASE_DRAGONS:
                {
                    if (uiStormTimer <= uiDiff)
                    {
                        if (!me->IsNonMeleeSpellCasted(false))
                        {
                            if (!urand(0, 2))
                                DoScriptText(RAND(SAY_PHASE3_CAST_1, SAY_PHASE3_CAST_2, SAY_PHASE3_CAST_3), me);
                            DoCast(me, RAID_MODE(SPELL_ARCANE_STORM_N, SPELL_ARCANE_STORM_H));
                            uiStormTimer = urand(8*IN_MILLISECONDS, 12*IN_MILLISECONDS);
                        }
                    } else uiStormTimer -= uiDiff;

                    // TODO: check timer
                    if (uiSurgeOfPowerTimer <= uiDiff)
                    {
                        if (Unit* pTarget = SelectVehicleBaseOrPlayer())
                        {
                            if (!urand(0, 2))
                                DoScriptText(SAY_SURGE_OF_POWER, me);
                            DoCast(pTarget, RAID_MODE(SPELL_SURGE_OF_POWER_N, SPELL_SURGE_OF_POWER_H));
                        }
                        uiSurgeOfPowerTimer = urand(12*IN_MILLISECONDS, 16*IN_MILLISECONDS);
                    } else uiSurgeOfPowerTimer -= uiDiff;

                    if (uiArcanePulseTimer <= uiDiff)
                    {
                        DoCast(me, SPELL_ARCANE_PULSE, true);
                        uiArcanePulseTimer = 10*IN_MILLISECONDS;
                    } else uiArcanePulseTimer -= uiDiff;

                    if (uiStaticFieldTimer <= uiDiff)
                    {
                        if (!me->IsNonMeleeSpellCasted(false))
                        {
                            if (Unit* pTarget = SelectVehicleBaseOrPlayer())
                            {
                                if (!urand(0, 2))
                                    DoScriptText(RAND(SAY_PHASE3_CAST_1, SAY_PHASE3_CAST_2, SAY_PHASE3_CAST_3), me);
                                DoCast(pTarget, SPELL_STATIC_FIELD_MISSLE);
                            }
                            uiStaticFieldTimer = 25*IN_MILLISECONDS;
                        }
                    } else uiStaticFieldTimer -= uiDiff;
                    break;
                }
                case PHASE_IDLE:
                {
                    if (uiWaitTimer <= uiDiff)
                    {
                        switch (uiStep)
                        {
                            case 1:
                            {
                                DoCast(me, SPELL_DESTROY_PLATFORM_BOOM, true);
                                DoCast(SPELL_DESTROY_PLATFORM_EVENT);
                                uiWaitTimer = 2*IN_MILLISECONDS;
                                uiStep++;
                                break;
                            }
                            case 2:
                            {
                                if (m_pInstance)
                                {
                                    if (GameObject* platform = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(DATA_PLATFORM)))
                                        platform->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                                }
                                me->GetMotionMaster()->MovePoint(POINT_PHASE_3, Locations[4]);
                                uiWaitTimer = 3*IN_MILLISECONDS;
                                uiStep++;
                                break;
                            }
                            case 3:
                            {
                                DoAction(ACTION_MOUNT_ALL);
                                uiStep++;
                                break;
                            }
                        }
                    } else uiWaitTimer -= uiDiff;
                    break;
                }
                default:
                    return;
            }
        }
    };
};

class npc_scion_of_eternity : public CreatureScript
{
public:
    npc_scion_of_eternity() : CreatureScript("npc_scion_of_eternity") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_scion_of_eternityAI(pCreature);
    }

    struct npc_scion_of_eternityAI : public ScriptedAI
    {
        npc_scion_of_eternityAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 uiArcaneBarrageTimer;

        void Reset()
        {
            uiArcaneBarrageTimer = urand(10*IN_MILLISECONDS, 20*IN_MILLISECONDS);
        }

        void SpellHitTarget(Unit* target, const SpellEntry* spell)
        {
            if (spell->Id == SPELL_ARCANE_BARRAGE)
                target->CastSpell(target, SPELL_ARCANE_BARRAGE_DMG, true, NULL, NULL, me->GetGUID());
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiArcaneBarrageTimer <= uiDiff)
            {
                if (Unit* pTarget = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, false, -SPELL_ARCANE_BARRAGE_DMG))
                {
                    // try to skip spell fly time
                    SpellEntry const *spellInfo = sSpellStore.LookupEntry(SPELL_ARCANE_BARRAGE_DMG);
                    if (spellInfo)
                        me->AddAura(spellInfo, 2, pTarget);

                    DoCast(pTarget, SPELL_ARCANE_BARRAGE);
                    uiArcaneBarrageTimer = urand(8*IN_MILLISECONDS, 12*IN_MILLISECONDS);
                }
            } else uiArcaneBarrageTimer -= uiDiff;
        }
    };
};

class npc_nexus_lord : public CreatureScript
{
public:
    npc_nexus_lord() : CreatureScript("npc_nexus_lord") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_nexus_lordAI(pCreature);
    }

    struct npc_nexus_lordAI : public ScriptedAI
    {
        npc_nexus_lordAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 uiArcaneShockTimer;
        uint32 uiHasteTimer;

        void Reset()
        {
            uiHasteTimer = urand(15*IN_MILLISECONDS, 20*IN_MILLISECONDS);
            uiArcaneShockTimer = urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
                return;

            if (uiArcaneShockTimer <= uiDiff)
            {
                DoCast(me->getVictim(), RAID_MODE(SPELL_ARCANE_SHOCK_N, SPELL_ARCANE_SHOCK_H));
                uiArcaneShockTimer = urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS);
            } else uiArcaneShockTimer -= uiDiff;

            if (uiHasteTimer <= uiDiff)
            {
                DoCast(me, SPELL_HASTE);
                uiHasteTimer = urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS);
            } else uiHasteTimer -= uiDiff;

            DoMeleeAttackIfReady();
        }
    };
};

class npc_alexstrasza : public CreatureScript
{
public:
    npc_alexstrasza() : CreatureScript("npc_alexstrasza") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_alexstraszaAI(pCreature);
    }

    struct npc_alexstraszaAI : public ScriptedAI
    {
        npc_alexstraszaAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;
        uint32 uiStepTimer;
        uint8 uiStep;

        void Reset()
        {
            uiStep = 1;
            uiStepTimer = 5*IN_MILLISECONDS;
            me->SetFlying(true);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (uiStepTimer <= uiDiff)
            {
                switch (uiStep)
                {
                    // workaround
                    case 1:
                    {
                        if (m_pInstance)
                        {
                            if (GameObject* platform = m_pInstance->instance->GetGameObject(m_pInstance->GetData64(DATA_PLATFORM)))
                                platform->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                        }

                        Map *map = me->GetMap();
                        if (!map->IsDungeon())
                            return;

                        Map::PlayerList const &PlayerList = map->GetPlayers();
                        for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                        {
                            Player* i_pl = i->getSource();
                            if (i_pl && !i_pl->isGameMaster() && i_pl->isAlive())
                            {
                                if (Unit* pMount = i_pl->GetVehicleBase())
                                {
                                    i_pl->ExitVehicle();
                                    i_pl->JumpTo(me, 10.0f);
                                    pMount->ToCreature()->ForcedDespawn(1*IN_MILLISECONDS);
                                    me->CastSpell(i_pl, VEHICLE_SPELL_PARACHUTE, true);
                                }
                            }
                        }
                        uiStepTimer = 7*IN_MILLISECONDS;
                        break;
                    }
                    case 2:
                    {
                        DoScriptText(SAY_OUTRO_1, me);
                        uiStepTimer = 9*IN_MILLISECONDS;
                        break;
                    }
                    case 3:
                    {
                        DoScriptText(SAY_OUTRO_2, me);
                        if (Creature* pGift = me->SummonCreature(NPC_ALEXSTRASZAS_GIFT, Locations[5], TEMPSUMMON_TIMED_DESPAWN, 90*IN_MILLISECONDS))
                        {
                            pGift->SetFlying(true);
                            pGift->SetDisplayId(11686);
                            pGift->CastSpell(pGift, SPELL_ALEXSTRASZAS_GIFT_VISUAL, true);
                            DoCast(SPELL_ALEXSTRASZAS_GIFT_BEAM);
                        }
                        uiStepTimer = 5*IN_MILLISECONDS;
                        break;
                    }
                    case 4:
                    {
                        DoScriptText(SAY_OUTRO_3, me);
                        me->SummonGameObject(RAID_MODE(GO_ALEXSTRASZAS_GIFT, GO_ALEXSTRASZAS_GIFT_H), Locations[5].GetPositionX(),
                            Locations[5].GetPositionY(), Locations[5].GetPositionZ(), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0);

                        if (m_pInstance)
                            m_pInstance->SetData(TYPE_MALYGOS, DONE);

                        uiStepTimer = 23*IN_MILLISECONDS;
                        break;
                    }
                    case 5:
                    {
                        DoScriptText(SAY_OUTRO_4, me);
                        uiStepTimer = 10*MINUTE*IN_MILLISECONDS;
                        break;
                    }
                }
                uiStep++;
            } else uiStepTimer -= uiDiff;
        }
    };
};

class npc_power_spark : public CreatureScript
{
public:
    npc_power_spark() : CreatureScript("npc_power_spark") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_power_sparkAI(pCreature);
    }

    struct npc_power_sparkAI : public ScriptedAI
    {
        npc_power_sparkAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        void Reset()
        {
            DoCast(me, SPELL_POWER_SPARK_VISUAL, true);
        }

        void DamageTaken(Unit * /* DoneBy */, uint32 &uiDamage)
        {
            if (uiDamage >= me->GetHealth())
            {
                me->RemoveAllAuras();
                uiDamage = me->GetHealth() - 1;
                DoCast(me, SPELL_POWER_SPARK_PLAYERS, true);

                me->SetFlying(false);
                me->SetReactState(REACT_PASSIVE);
                me->GetMotionMaster()->Clear();
                me->GetMotionMaster()->MoveFall(FLOOR_Z); // TODO: really remove fly state
                me->ForcedDespawn(60*IN_MILLISECONDS);
                me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }
        }
    };
};

class npc_vortex_vehicle : public CreatureScript
{
public:
    npc_vortex_vehicle() : CreatureScript("npc_vortex_vehicle") { }

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_vortex_vehicleAI(pCreature);
    }

    struct npc_vortex_vehicleAI : public ScriptedAI
    {
        npc_vortex_vehicleAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        uint32 uiTurnTimer;
        float angle;

        void Reset()
        {
            uiTurnTimer = 100;
            me->setFaction(35);

            angle = float(2 * M_PI * rand_norm());
            me->SetOrientation(angle);
        }

        void UpdateAI(const uint32 uiDiff)
        {
            // custom rotation
            if (uiTurnTimer <= uiDiff)
            {
                angle += M_PI * 2 / 7;
                if (angle >= M_PI * 2)
                    angle -= M_PI * 2;

                me->SetOrientation(angle);
                me->SendMovementFlagUpdate();

                uiTurnTimer = 100;
            } else uiTurnTimer -= uiDiff;
        }
    };
};

class npc_hover_disc : public CreatureScript
{
public:
    npc_hover_disc() : CreatureScript("npc_hover_disc") { }

    struct npc_hover_discAI : public ScriptedAI
    {
        npc_hover_discAI(Creature* pCreature) : ScriptedAI(pCreature) {}

        bool move;

        uint32 count;
        uint32 uiCheckTimer;

        void Reset()
        {
            move = false;
            uiCheckTimer = 1*IN_MILLISECONDS;
            me->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ARCANE_BOMB_KNOCKBACK, true);
        }

        void PassengerBoarded(Unit* pWho, int8 /*seatId*/, bool apply)
        {
            if (!apply)
                me->ForcedDespawn(1*IN_MILLISECONDS);
        }

        void SetData(uint32 /*type*/, uint32 data)
        {
            count = data;
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (Unit* pUnit = me->GetVehicleKit()->GetPassenger(0))
            {
                if (!pUnit->ToCreature())
                    return;

                if (pUnit->GetEntry() == NPC_NEXUS_LORD)
                {
                    pUnit->ToCreature()->SetReactState(REACT_AGGRESSIVE);
                    pUnit->ToCreature()->SetInCombatWithZone();
                    me->SetReactState(REACT_AGGRESSIVE);
                    me->SetInCombatWithZone();
                }
                else
                {
                    move = true;
                }
            }
        }

        void UpdateAI(const uint32 uiDiff)
        {
            if (move)
            {
                move = false;
                float x, y, angle;
                angle = float(count) * 2 * M_PI / 16;
                x = Locations[1].GetPositionX() + float(urand(20, 28)) * cos(angle);
                y = Locations[1].GetPositionY() + float(urand(20, 28)) * sin(angle);
                me->GetMotionMaster()->MovePoint(1, x, y, FLOOR_Z + 10.0f);

                count--;
                if (count == 0)
                    count = 16;
            }

            if (!UpdateVictim())
                return;

            // TODO: find a better way
            if (me->GetReactState() == REACT_AGGRESSIVE)
            {
                if (uiCheckTimer <= uiDiff)
                {
                    Unit* pUnit = me->GetVehicleKit()->GetPassenger(0);
                    if (pUnit && pUnit->GetTypeId() == TYPEID_UNIT && pUnit->GetEntry() == NPC_NEXUS_LORD)
                    {
                        Unit* pTarget = pUnit->getVictim();
                        if (pTarget && pTarget != me->getVictim())
                        {
                            me->getThreatManager().modifyThreatPercent(me->getVictim(), -100);
                            me->AddThreat(pTarget, 9999999.0f);
                        }
                    }
                    uiCheckTimer = 1*IN_MILLISECONDS;
                } else uiCheckTimer -= uiDiff;
            }
        }
    };

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_hover_discAI(pCreature);
    }
};

class go_focusing_iris : public GameObjectScript
{
public:
    go_focusing_iris() : GameObjectScript("go_focusing_iris") { }

    bool OnGossipHello(Player * /*pPlayer*/, GameObject* pGO)
    {
        InstanceScript* m_pInstance = pGO->GetInstanceScript();

        Creature* pMalygos = Unit::GetCreature(*pGO, m_pInstance ? m_pInstance->GetData64(DATA_MALYGOS) : 0);
        if (pMalygos && pMalygos->isAlive())
        {
            pGO->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
            pMalygos->AI()->DoAction(ACTION_START);

            if (Creature* pTrigger = pGO->SummonCreature(NPC_SURGE_OF_POWER, pGO->GetPositionX(), pGO->GetPositionY(), 277.0f, 0.0f,
                TEMPSUMMON_TIMED_DESPAWN, 6*IN_MILLISECONDS))
            {
                pTrigger->SetDisplayId(11686);
                pTrigger->SetFlying(true);
                pTrigger->SetReactState(REACT_PASSIVE);
                pTrigger->CastSpell(pTrigger, SPELL_IRIS_VISUAL, true);
            }
        }
        return true;
    }
};

void AddSC_boss_malygos()
{
    new boss_malygos();
    new npc_nexus_lord();
    new npc_scion_of_eternity();
    new npc_alexstrasza();
    new npc_power_spark();
    new npc_vortex_vehicle();
    new npc_hover_disc();
    new go_focusing_iris();
}
