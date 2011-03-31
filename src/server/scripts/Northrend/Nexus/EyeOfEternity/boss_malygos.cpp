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

<<<<<<< HEAD
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
    SPELL_ARCANE_BREATH_10                   = 56272,
    SPELL_ARCANE_BREATH_25                   = 60072,
    SPELL_ARCANE_STORM_10                    = 61693,
    SPELL_ARCANE_STORM_25                    = 61694,
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

    SPELL_ARCANE_SHOCK_10                    = 57058,
    SPELL_ARCANE_SHOCK_25                    = 60073,
    SPELL_HASTE                              = 57060,
    SPELL_ARCANE_BARRAGE                     = 56397,
    SPELL_ARCANE_BARRAGE_DMG                 = 63934,

    SPELL_DESTROY_PLATFORM_CHANNEL           = 58842,
    SPELL_DESTROY_PLATFORM_BOOM              = 59084,
    SPELL_DESTROY_PLATFORM_EVENT             = 59099,

    // phase 3
    SPELL_ARCANE_PULSE                       = 57432,
    SPELL_STATIC_FIELD                       = 57428,
    SPELL_STATIC_FIELD_MISSLE                = 57430,
    SPELL_SURGE_OF_POWER_10                  = 57407,
    SPELL_SURGE_OF_POWER_25                  = 60936,
    SPELL_SURGE_OF_POWER_25_MARKER           = 60939,

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
    ACTION_SPAWN_MOUNTS = 6,
    ACTION_MOUNT_ALL    = 7,
    ACTION_CAST_SURGE   = 8,
    ACTION_CLEAR_PLR    = 9
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
#define WHISPER_SURGE     "Malygos fixes his eyes on you!"
=======
/* Script Data Start
SDName: Boss malygos
Script Data End */

// TO-DOs:
// Implement a better pathing for Malygos.
// Find sniffed spawn position for chest
// Implement a better way to disappear the gameobjects
// Implement achievements
// Implement scaling for player's drakes (should be done with aura 66668, it is casted - but it is not working as it should)
// Remove hack that re-adds targets to the aggro list after they enter to a vehicle when it works as expected
// Improve whatever can be improved :)

#include "ScriptPCH.h"
#include "eye_of_eternity.h"
#include "ScriptedEscortAI.h"

// not implemented
enum Achievements
{
    ACHIEV_TIMED_START_EVENT                      = 20387,
};

enum Events
{
    // =========== PHASE ONE ===============
    EVENT_ARCANE_BREATH = 1,
    EVENT_ARCANE_STORM  = 2,
    EVENT_VORTEX        = 3,
    EVENT_POWER_SPARKS  = 4,

    // =========== PHASE TWO ===============
    EVENT_SURGE_POWER   = 5, // wowhead is wrong, Surge of Power is casted instead of Arcane Pulse (source sniffs!)
    EVENT_SUMMON_ARCANE = 6,

    // =========== PHASE TWO ===============
    EVENT_SURGE_POWER_PHASE_3 = 7,
    EVENT_STATIC_FIELD = 8,

    // =============== YELLS ===============
    EVENT_YELL_0 = 9,
    EVENT_YELL_1 = 10,
    EVENT_YELL_2 = 11,
    EVENT_YELL_3 = 12,
    EVENT_YELL_4 = 13,
};

enum Phases
{
    PHASE_ONE = 1,
    PHASE_TWO = 2,
    PHASE_THREE = 3
};

enum Spells
{
    SPELL_ARCANE_BREATH = 56272,
    SPELL_ARCANE_STORM  = 57459,
    SPELL_BERSEKER      = 60670,
    
    SPELL_VORTEX_1 = 56237, // seems that frezze object animation
    SPELL_VORTEX_2 = 55873, // visual effect
    SPELL_VORTEX_3 = 56105, // this spell must handle all the script - casted by the boss and to himself
    //SPELL_VORTEX_4 = 55853, // damage | used to enter to the vehicle - defined in eye_of_eternity.h
    //SPELL_VORTEX_5 = 56263, // damage | used to enter to the vehicle - defined in eye_of_eternity.h
    SPELL_VORTEX_6 = 73040, // teleport - (casted to all raid) | caster 30090 | target player

    SPELL_PORTAL_VISUAL_CLOSED = 55949,
    SPELL_SUMMON_POWER_PARK = 56142,
    SPELL_POWER_SPARK_DEATH = 55852,
    SPELL_POWER_SPARK_MALYGOS = 56152,

    SPELL_SURGE_POWER = 56505, // used in phase 2
    SPELL_SUMMON_ARCANE_BOMB = 56429,
    SPELL_ARCANE_OVERLOAD = 56432,
    SPELL_SUMMOM_RED_DRAGON = 56070,
    SPELL_SURGE_POWER_PHASE_3 = 57407,
    SPELL_STATIC_FIELD = 57430
};

enum Movements
{
    MOVE_VORTEX = 1,
    MOVE_PHASE_TWO,
    MOVE_DEEP_BREATH_ROTATION,
    MOVE_INIT_PHASE_ONE,
    MOVE_CENTER_PLATFORM
};

enum Seats
{
    SEAT_0 = 0,
};

enum Factions
{
    FACTION_FRIENDLY = 35,
    FACTION_HOSTILE = 14
};

enum Actions
{
    ACTION_HOVER_DISK_START_WP_1,
    ACTION_HOVER_DISK_START_WP_2
};

enum MalygosEvents
{
    DATA_SUMMON_DEATHS, // phase 2
    DATA_PHASE
};

#define TEN_MINUTES 600000

enum MalygosSays
{
    SAY_AGGRO_P_ONE,
    SAY_KILLED_PLAYER_P_ONE,
    SAY_END_P_ONE,
    SAY_AGGRO_P_TWO,
    SAY_ANTI_MAGIC_SHELL, // not sure when execute it
    SAY_MAGIC_BLAST,  // not sure when execute it
    SAY_KILLED_PLAYER_P_TWO,
    SAY_END_P_TWO,
    SAY_INTRO_P_THREE,
    SAY_AGGRO_P_THREE,
    SAY_SURGE_POWER,  // not sure when execute it
    SAY_BUFF_SPARK,
    SAY_KILLED_PLAYER_P_THREE,
    SAY_SPELL_CASTING_P_THREE,
    SAY_DEATH
};

#define MAX_HOVER_DISK_WAYPOINTS 18

// Sniffed data
const Position HoverDiskWaypoints[MAX_HOVER_DISK_WAYPOINTS] =
{
   {782.9821f,1296.652f,282.1114f},
   {779.5459f,1287.228f,282.1393f},
   {773.0028f,1279.52f,282.4164f},
   {764.3626f,1274.476f,282.4731f},
   {754.3961f,1272.639f,282.4171f},
   {744.4422f,1274.412f,282.222f},
   {735.575f,1279.742f,281.9674f},
   {729.2788f,1287.187f,281.9943f},
   {726.1191f,1296.688f,282.2997f},
   {725.9396f,1306.531f,282.2448f},
   {729.3045f,1316.122f,281.9108f},
   {735.8322f,1323.633f,282.1887f},
   {744.4616f,1328.999f,281.9948f},
   {754.4739f,1330.666f,282.049f},
   {764.074f,1329.053f,281.9949f},
   {772.8409f,1323.951f,282.077f},
   {779.5085f,1316.412f,281.9145f},
   {782.8365f,1306.778f,282.3035f},
};

#define GROUND_Z 268

// Source: Sniffs
#define MALYGOS_MAX_WAYPOINTS 16
const Position MalygosPhaseTwoWaypoints[MALYGOS_MAX_WAYPOINTS] =
{
    {812.7299f,1391.672f,283.2763f},
    {848.2912f,1358.61f,283.2763f},
    {853.9227f,1307.911f,283.2763f},
    {847.1437f,1265.538f,283.2763f},
    {839.9229f,1245.245f,283.2763f},
    {827.3463f,1221.818f,283.2763f},
    {803.2727f,1203.851f,283.2763f},
    {772.9372f,1197.981f,283.2763f},
    {732.1138f,1200.647f,283.2763f},
    {693.8761f,1217.995f,283.2763f},
    {664.5038f,1256.539f,283.2763f},
    {650.1497f,1303.485f,283.2763f},
    {662.9109f,1350.291f,283.2763f},
    {677.6391f,1377.607f,283.2763f},
    {704.8198f,1401.162f,283.2763f},
    {755.2642f,1417.1f,283.2763f},
};

#define MAX_SUMMONS_PHASE_TWO 4

#define MAX_MALYGOS_POS 2
const Position MalygosPositions[MAX_MALYGOS_POS] =
{
    {754.544f,1301.71f,320.0f},
    {754.39f, 1301.27f, 292.91f}
};
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

class boss_malygos : public CreatureScript
{
public:
    boss_malygos() : CreatureScript("boss_malygos") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new boss_malygosAI(creature);
    }

    struct boss_malygosAI : public BossAI
    {
<<<<<<< HEAD
        boss_malygosAI(Creature* pCreature) : ScriptedAI(pCreature), Summons(me)
        {
            m_pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;
        SummonList Summons;

        std::set<uint64> SparkList;
        std::list<std::pair<uint64,uint64> > uiMounts;

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
=======
        boss_malygosAI(Creature* creature) : BossAI(creature, DATA_MALYGOS_EVENT)
        {
            // If we enter in combat when MovePoint generator is active, it overrwrites our homeposition
            homePosition = creature->GetHomePosition();
        }

        void Reset()
        {

            _Reset();
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee

            bersekerTimer = 0;
            currentPos = 0;

            SetPhase(PHASE_ONE,true);

            delayedMovementTimer = 8000;
            delayedMovement = false;

            summonDeaths = 0;

            me->SetFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);

            cannotMove = true;
        }

        uint32 GetData(uint32 data)
        {
<<<<<<< HEAD
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
            uiMounts.clear();

            if (m_pInstance)
            {
                m_pInstance->SetData(TYPE_MALYGOS, NOT_STARTED);
                m_pInstance->DoStopTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT,  ACHIEV_TIMED_START_EVENT);
=======
            if (data == DATA_SUMMON_DEATHS)
                return summonDeaths;
            else if (data == DATA_PHASE)
                return phase;

            return 0;
        }

        void SetData(uint32 data, uint32 value)
        {
            if (data == DATA_SUMMON_DEATHS && phase == PHASE_TWO)
            {
                summonDeaths = value;

                if (summonDeaths >= MAX_SUMMONS_PHASE_TWO)
                    StartPhaseThree();
            }
        }

        void EnterEvadeMode()
        {
            me->SetHomePosition(homePosition);

            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);

            BossAI::EnterEvadeMode();

            if (instance)
                instance->SetBossState(DATA_MALYGOS_EVENT, FAIL);
        }

        void SetPhase(uint8 _phase, bool setEvents = false)
        {
            events.Reset();

            events.SetPhase(_phase);
            phase = _phase;

            if (setEvents)
                SetPhaseEvents(_phase);
        }

        void StartPhaseThree()
        {
            if (!instance)
                return;
            
            SetPhase(PHASE_THREE,true);

            // this despawns Hover Disks
            summons.DespawnAll();
            // players that used Hover Disk are no in the aggro list
            me->SetInCombatWithZone();
            std::list<HostileReference*> &m_threatlist = me->getThreatManager().getThreatList();
            for (std::list<HostileReference*>::const_iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
            {
                if (Unit* target = (*itr)->getTarget())
                {
                    if (target->GetTypeId() != TYPEID_PLAYER)
                        continue;

                    // The rest is handled in the AI of the vehicle.
                    target->CastSpell(target,SPELL_SUMMOM_RED_DRAGON,true);
                }
            }

            if (GameObject* go = GameObject::GetGameObject(*me,instance->GetData64(DATA_PLATFORM)))
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED); // In sniffs it has this flag, but i don't know how is applied. 

            // pos sniffed
            me->GetMotionMaster()->MoveIdle();
            me->GetMotionMaster()->MovePoint(MOVE_CENTER_PLATFORM,MalygosPositions[0].GetPositionX(),MalygosPositions[0].GetPositionY(),MalygosPositions[0].GetPositionZ());
        }

        void SetPhaseEvents(uint8 _phase)
        {
            switch (_phase)
            {
                case PHASE_ONE:
                    events.ScheduleEvent(EVENT_ARCANE_BREATH,urand(15,20)*IN_MILLISECONDS,0,_phase);
                    events.ScheduleEvent(EVENT_ARCANE_STORM,urand(5,10)*IN_MILLISECONDS,0,_phase);
                    events.ScheduleEvent(EVENT_VORTEX,urand(30,40)*IN_MILLISECONDS,0,_phase);
                    events.ScheduleEvent(EVENT_POWER_SPARKS,urand(30,35)*IN_MILLISECONDS,0,_phase);
                    break;
                case PHASE_TWO:
                    events.ScheduleEvent(EVENT_YELL_0,0,0,_phase);
                    events.ScheduleEvent(EVENT_YELL_1,24*IN_MILLISECONDS,0,_phase);
                    events.ScheduleEvent(EVENT_SURGE_POWER,urand(60,70)*IN_MILLISECONDS,0,_phase);
                    events.ScheduleEvent(EVENT_SUMMON_ARCANE,urand(2,5)*IN_MILLISECONDS,0,_phase);
                    break;
                case PHASE_THREE:
                    events.ScheduleEvent(EVENT_YELL_2,0,0,_phase);
                    events.ScheduleEvent(EVENT_YELL_3,8*IN_MILLISECONDS,0,_phase);
                    events.ScheduleEvent(EVENT_YELL_4,16*IN_MILLISECONDS,0,_phase);
                    events.ScheduleEvent(EVENT_SURGE_POWER_PHASE_3,(7,16)*IN_MILLISECONDS,0,_phase);
                    events.ScheduleEvent(EVENT_STATIC_FIELD,(20,30)*IN_MILLISECONDS,0,_phase);
                    break;
                default:
                    break;
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
            }
        }

        void JustReachedHome()
        {
<<<<<<< HEAD
            Reset();
            me->setActive(false);
        }

        void JustSummoned(Creature *summon)
        {
            switch (summon->GetEntry())
            {
                case NPC_POWER_SPARK:
                    summon->setActive(true);
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
                    {
                        pDisc->ApplySpellImmune(0, IMMUNITY_ID, SPELL_ARCANE_BOMB_KNOCKBACK, true);
                        pDisc->SetSpeed(MOVE_FLIGHT, 3.0f);
                    }
                    uiAddsCount++;
                    break;
            }
            Summons.Despawn(summon);
        }

        void KilledUnit(Unit* pVictim)
        {
            if (pVictim == me || (pVictim->GetTypeId() == TYPEID_UNIT && pVictim->GetEntry() == NPC_POWER_SPARK))
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
=======
            _EnterCombat();

            me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);

            Talk(SAY_AGGRO_P_ONE);

            DoCast(SPELL_BERSEKER);
        }

        void KilledUnit(Unit* who)
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            switch (phase)
            {
            case PHASE_ONE:
                Talk(SAY_KILLED_PLAYER_P_ONE);
                break;
            case PHASE_TWO:
                Talk(SAY_KILLED_PLAYER_P_TWO);
                break;
            case PHASE_THREE:
                Talk(SAY_KILLED_PLAYER_P_THREE);
                break;
            }
        }

        void SpellHit(Unit* caster, const SpellEntry* spell)
        {
            if (spell->Id == SPELL_POWER_SPARK_MALYGOS)
            {
                if (Creature* creature = caster->ToCreature())
                    creature->DespawnOrUnsummon();

                Talk(SAY_BUFF_SPARK);
            }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!me->isInCombat())
                return;

            if (who->GetEntry() == NPC_POWER_SPARK)
            {
                // not sure about the distance | I think it is better check this here than in the UpdateAI function...
                if (who->GetDistance(me) <= 2.5f)
                    who->CastSpell(me, SPELL_POWER_SPARK_MALYGOS, true);
                    
            }
        }

        void PrepareForVortex()
        {
            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);

            me->GetMotionMaster()->MovementExpired();
            me->GetMotionMaster()->MovePoint(MOVE_VORTEX,MalygosPositions[1].GetPositionX(), MalygosPositions[1].GetPositionY(), MalygosPositions[1].GetPositionZ());
            // continues in MovementInform function.
        }

        void ExecuteVortex()
        {
            DoCast(me,SPELL_VORTEX_1,true);
            DoCast(me,SPELL_VORTEX_2,true);

            // the vortex execution continues in the dummy effect of this spell (see its script)
            DoCast(me,SPELL_VORTEX_3,true);
        }

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            switch (id)
            {
                case MOVE_VORTEX:
                    me->GetMotionMaster()->MoveIdle();
                    ExecuteVortex();
                    break;
                case MOVE_DEEP_BREATH_ROTATION:
                    currentPos = currentPos == MALYGOS_MAX_WAYPOINTS - 1 ? 0 : currentPos+1;
                    me->GetMotionMaster()->MovementExpired();
                    me->GetMotionMaster()->MovePoint(MOVE_DEEP_BREATH_ROTATION,MalygosPhaseTwoWaypoints[currentPos]);
                    break;
                case MOVE_INIT_PHASE_ONE:
                    me->SetInCombatWithZone();
                    break;
                case MOVE_CENTER_PLATFORM:
                    cannotMove = false;
                    // malygos will move into center of platform and then he does not chase dragons, he just turns to his current target.
                    me->GetMotionMaster()->MoveIdle();
                    break;
            }
        }

        void StartPhaseTwo()
        {
            SetPhase(PHASE_TWO,true);

            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);

            me->GetMotionMaster()->MoveIdle();
            me->GetMotionMaster()->MovePoint(MOVE_DEEP_BREATH_ROTATION,MalygosPhaseTwoWaypoints[0]);
            
            Creature* summon = me->SummonCreature(NPC_HOVER_DISK_CASTER,HoverDiskWaypoints[MAX_HOVER_DISK_WAYPOINTS-1]);
            if (summon && summon->IsAIEnabled)
                summon->AI()->DoAction(ACTION_HOVER_DISK_START_WP_2);
            summon = me->SummonCreature(NPC_HOVER_DISK_CASTER,HoverDiskWaypoints[0]);
            if (summon && summon->IsAIEnabled)
                summon->AI()->DoAction(ACTION_HOVER_DISK_START_WP_1);

            for (uint8 i = 0; i < 2; i++)
            {
                // not sure about its position.
                summon = me->SummonCreature(NPC_HOVER_DISK_MELEE,HoverDiskWaypoints[0]);
                if (summon)
                    summon->SetInCombatWithZone();
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (phase == PHASE_THREE)
            {
                if (!cannotMove)
                {
                    // it can change if the player falls from the vehicle.
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != IDLE_MOTION_TYPE)
                    {
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MoveIdle();
                    }
                } else
                {
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != POINT_MOTION_TYPE)
                    {
                        me->GetMotionMaster()->MovementExpired();
                        me->GetMotionMaster()->MovePoint(MOVE_CENTER_PLATFORM,MalygosPositions[0].GetPositionX(),MalygosPositions[0].GetPositionY(),MalygosPositions[0].GetPositionZ());
                    }
                }
            }

            // we need a better way for pathing
            if (delayedMovement)
            {
                if (delayedMovementTimer <= diff)
                {
                    me->GetMotionMaster()->MovePoint(MOVE_DEEP_BREATH_ROTATION,MalygosPhaseTwoWaypoints[currentPos]);
                    delayedMovementTimer = 8000;
                    delayedMovement = false;
                } delayedMovementTimer -= diff;
            }

            // at 50 % health malygos switch to phase 2
            if (me->GetHealthPct() <= 50.0f && phase == PHASE_ONE)
                StartPhaseTwo();

            // the boss is handling vortex
            if (me->HasAura(SPELL_VORTEX_2))
                return;

            // We can't cast if we are casting already.
            if (me->HasUnitState(UNIT_STAT_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_YELL_2:
                        Talk(SAY_END_P_TWO);
                        break;
                    case EVENT_YELL_3:
                        Talk(SAY_INTRO_P_THREE);
                        break;
                    case EVENT_YELL_4:
                        Talk(SAY_AGGRO_P_THREE);
                        break;
                    case EVENT_YELL_0:
                        Talk(SAY_END_P_ONE);
                        break;
                    case EVENT_YELL_1:
                        Talk(SAY_AGGRO_P_TWO);
                        break;
                    case EVENT_ARCANE_BREATH:
                        DoCast(me->getVictim(),SPELL_ARCANE_BREATH);
                        events.ScheduleEvent(EVENT_ARCANE_BREATH,urand(35,60)*IN_MILLISECONDS,0,PHASE_ONE);
                        break;
                    case EVENT_ARCANE_STORM:
                        DoCast(me->getVictim(),SPELL_ARCANE_STORM);
                        events.ScheduleEvent(EVENT_ARCANE_STORM,urand(5,10)*IN_MILLISECONDS,0,PHASE_ONE);
                        break;
                    case EVENT_VORTEX:
                        PrepareForVortex();
                        events.ScheduleEvent(EVENT_VORTEX,urand(60,80)*IN_MILLISECONDS,0,PHASE_ONE);
                        break;
                    case EVENT_POWER_SPARKS:
                        instance->SetData(DATA_POWER_SPARKS_HANDLING,0);
                        events.ScheduleEvent(EVENT_POWER_SPARKS,urand(30,35)*IN_MILLISECONDS,0,PHASE_ONE);
                        break;
                    case EVENT_SURGE_POWER:
                        me->GetMotionMaster()->MoveIdle();
                        delayedMovement = true;
                        DoCast(SPELL_SURGE_POWER);
                        events.ScheduleEvent(EVENT_SURGE_POWER,urand(60,70)*IN_MILLISECONDS,0,PHASE_TWO);
                        break;
                    case EVENT_SUMMON_ARCANE:
                        DoCast(SPELL_SUMMON_ARCANE_BOMB);
                        events.ScheduleEvent(EVENT_SUMMON_ARCANE,urand(12,15)*IN_MILLISECONDS,0,PHASE_TWO);
                        break;
                    case EVENT_SURGE_POWER_PHASE_3:
                        DoCast(GetTargetPhaseThree(),SPELL_SURGE_POWER_PHASE_3);
                        events.ScheduleEvent(EVENT_SURGE_POWER_PHASE_3,(7,16)*IN_MILLISECONDS,0,PHASE_THREE);
                        break;
                    case EVENT_STATIC_FIELD:
                        DoCast(GetTargetPhaseThree(),SPELL_STATIC_FIELD);
                        events.ScheduleEvent(EVENT_STATIC_FIELD,(20,30)*IN_MILLISECONDS,0,PHASE_THREE);
                        break;
                    default:
                        break;
                }
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
            }
        }

        Unit* GetTargetPhaseThree()
        {
            Unit* target = SelectTarget(SELECT_TARGET_RANDOM,0);
                
            // we are a drake
            if (target->GetVehicleKit())
                return target;

            // we are a player using a drake (or at least you should)
            if (target->GetTypeId() == TYPEID_PLAYER)
            {
                if (Unit* base = target->GetVehicleBase())
                    return base;
            }
            
            // is a player falling from a vehicle? 
            return NULL;
        }

        void JustDied(Unit* /*killer*/)
        {
<<<<<<< HEAD
            DoScriptText(SAY_DEATH, me);
            Summons.DespawnAll(); // only static fields left
            me->SummonCreature(NPC_ALEXSTRASZA, Locations[3], TEMPSUMMON_TIMED_DESPAWN, 9*MINUTE*IN_MILLISECONDS);
        }

        void MoveInLineOfSight(Unit* pWho)
        {
            if (uiPhase != PHASE_GROUND || pWho->GetTypeId() != TYPEID_UNIT)
                return;

            if (pWho->GetEntry() == NPC_POWER_SPARK && pWho->GetExactDist(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ()) < 8.0f
                && !pWho->HasAura(SPELL_POWER_SPARK_PLAYERS))
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
                    me->setActive(true);
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
                        pSpark->SetSpeed(MOVE_FLIGHT, 0.8f);
                        pSpark->SetReactState(REACT_PASSIVE);
                        pSpark->SetInCombatWithZone();
                    }
                    break;
                }
                case ACTION_OVERLOAD:
                {
                    float x, y, angle;
                    angle = float(2 * M_PI * rand_norm());
                    x = Locations[1].GetPositionX() + float(urand(10, 28)) * cos(angle);
                    y = Locations[1].GetPositionY() + float(urand(10, 28)) * sin(angle);

                    if (Creature* pOverload = me->SummonCreature(NPC_ARCANE_OVERLOAD, x, y, FLOOR_Z - 1.8f, 0.0f, TEMPSUMMON_TIMED_DESPAWN, 45*IN_MILLISECONDS))
                    {
                        if (!urand(0, 2))
                            DoScriptText(SAY_ANTI_MAGIC_SHELL, me);
                        pOverload->AddUnitState(UNIT_STAT_ROOT);
                        pOverload->SetReactState(REACT_PASSIVE);
                        pOverload->SetInCombatWithZone();
                        pOverload->GetMotionMaster()->MoveIdle();
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
                case ACTION_SPAWN_MOUNTS:
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
                            if (Creature* mount = i_pl->SummonCreature(NPC_WYRMREST_SKYTALON, i_pl->GetPositionX(), i_pl->GetPositionY(), 220.0f, i_pl->GetOrientation()))
                            {
                                mount->SetFlying(true);
                                mount->SetSpeed(MOVE_FLIGHT, 2.0f);
                                uiMounts.push_back(std::pair<uint64, uint64>(mount->GetGUID(), i_pl->GetGUID()));
                            }
                        }
                    }
                    me->SetInCombatWithZone();
                    break;
                }
                case ACTION_MOUNT_ALL:
                {
                    if (uiMounts.empty())
                        return;

                    for (std::list<std::pair<uint64,uint64> >::iterator iter = uiMounts.begin(); iter != uiMounts.end(); ++iter)
                    {
                        Creature* mount = Unit::GetCreature(*me, (*iter).first);
                        Player* player = Unit::GetPlayer(*me, (*iter).second);
                        
                        if (!mount || !player)
                            continue;

                        if (!player->isAlive())
                            continue;

                        //mount->SetCreatorGUID(player->GetGUID());
                        player->EnterVehicle(mount, 0);
                    }

                    me->SetInCombatWithZone();
                    break;
                }
                case ACTION_CAST_SURGE:
                {
                    if (!urand(0, 2))
                        DoScriptText(SAY_SURGE_OF_POWER, me);

                    if (GetDifficulty() == RAID_DIFFICULTY_10MAN_NORMAL)
                    {
                        if (Unit* target = SelectVehicleBaseOrPlayer())
                        {
                            if (Player* player = target->GetCharmerOrOwnerPlayerOrPlayerItself())
                                me->MonsterWhisper(WHISPER_SURGE, player->GetGUID(), true);
                            DoCast(target, SPELL_SURGE_OF_POWER_10);
                        }
                    }
                    else
                    {
                        // immune whole threatlist
                        std::list<HostileReference *>& ThreatList = me->getThreatManager().getThreatList();
                        for (std::list<HostileReference *>::const_iterator itr = ThreatList.begin(); itr != ThreatList.end(); ++itr)
                        {
                            if (Unit* hostil = Unit::GetUnit(*me, (*itr)->getUnitGuid()))
                                hostil->ApplySpellImmune(0, IMMUNITY_ID, SPELL_SURGE_OF_POWER_25, true);
                        }

                        // select 3 targets, remove immunity on spellhit
                        DoCast(me, SPELL_SURGE_OF_POWER_25_MARKER, true);
                        // spellscript will select not immuned units
                        DoCast(SPELL_SURGE_OF_POWER_25);
                    }
                    break;
                }
                case ACTION_CLEAR_PLR:
                {
                    /* workaround to prevent players from falling through map in alive state (once they got unmounted) */
                    Map *map = me->GetMap();
                    if (!map->IsDungeon())
                        return;

                    Map::PlayerList const &PlayerList = map->GetPlayers();
                    for(Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                    {
                        Player* i_pl = i->getSource();
                        if (i_pl && !i_pl->isGameMaster() && i_pl->isAlive())
                        {
                            if (!i_pl->GetVehicle())
                            {
                                i_pl->SetUnitMovementFlags(0);
                                me->DealDamage(i_pl, i_pl->GetHealth());
                                i_pl->SetMovement(MOVE_ROOT);
                            }
                        }
                    }
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
                if (Creature* pSpark = me->GetCreature(*me, *itr))
                {
                    // spark already "dead"
                    if (pSpark->HasAura(SPELL_POWER_SPARK_PLAYERS))
                        continue;

                    if (move)
                        pSpark->AI()->DoAction(1);
                    else
                        pSpark->AI()->DoAction(0);

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
                    uiWaitTimer = 1*IN_MILLISECONDS;
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
                target->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NON_ATTACKABLE | UNIT_FLAG_NOT_SELECTABLE);
            }
            if (spell->Id == SPELL_SURGE_OF_POWER_25_MARKER)
            {
                target->ApplySpellImmune(0, IMMUNITY_ID, SPELL_SURGE_OF_POWER_25, false);
                if (Player* player = target->GetCharmerOrOwnerPlayerOrPlayerItself())
                    me->MonsterWhisper(WHISPER_SURGE, player->GetGUID(), true);
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
                        DoCast(me, RAID_MODE(SPELL_ARCANE_STORM_10, SPELL_ARCANE_STORM_25), true);
                        uiStormTimer = urand(10*IN_MILLISECONDS, 15*IN_MILLISECONDS);
                    } else uiStormTimer -= uiDiff;

                    if (uiSparkTimer <= uiDiff)
                    {
                        DoAction(ACTION_SPARK);
                        uiSparkTimer = 20*IN_MILLISECONDS;
                    } else uiSparkTimer -= uiDiff;

                    if (uiArcaneBreathTimer <= uiDiff)
                    {
                        DoCast(me->getVictim(), RAID_MODE(SPELL_ARCANE_BREATH_10, SPELL_ARCANE_BREATH_25));
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
                            DoCast(me, RAID_MODE(SPELL_ARCANE_STORM_10, SPELL_ARCANE_STORM_25));
                            uiStormTimer = urand(7*IN_MILLISECONDS, 10*IN_MILLISECONDS);
                        }
                    } else uiStormTimer -= uiDiff;

                    if (uiSurgeOfPowerTimer <= uiDiff)
                    {
                        DoAction(ACTION_CAST_SURGE);
                        uiSurgeOfPowerTimer = 10*IN_MILLISECONDS;
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

                    if (uiWaitTimer <= uiDiff)
                    {
                        DoAction(ACTION_CLEAR_PLR);
                        uiWaitTimer = 1*IN_MILLISECONDS;
                    } else uiWaitTimer -= uiDiff;
                    
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
                                DoAction(ACTION_SPAWN_MOUNTS);
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
                DoCast(me->getVictim(), RAID_MODE(SPELL_ARCANE_SHOCK_10, SPELL_ARCANE_SHOCK_25));
                uiArcaneShockTimer = urand(5*IN_MILLISECONDS, 10*IN_MILLISECONDS);
            } else uiArcaneShockTimer -= uiDiff;

            if (uiHasteTimer <= uiDiff)
            {
                DoCast(me, SPELL_HASTE);
                uiHasteTimer = urand(15*IN_MILLISECONDS, 25*IN_MILLISECONDS);
            } else uiHasteTimer -= uiDiff;

            DoMeleeAttackIfReady();
=======
            Talk(SAY_DEATH);
            _JustDied();
        }

    private:
        uint8 phase;
        uint32 bersekerTimer;
        uint8 currentPos; // used for phase 2 rotation...
        bool delayedMovement; // used in phase2.
        uint32 delayedMovementTimer; // used in phase 2
        uint8 summonDeaths;
        Position homePosition; // it can get bugged because core thinks we are pathing
        bool mustTalk;
        bool cannotMove;
    };

};

class spell_malygos_vortex_dummy : public SpellScriptLoader
{
public:
    spell_malygos_vortex_dummy() : SpellScriptLoader("spell_malygos_vortex_dummy") {}

    class spell_malygos_vortex_dummy_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_malygos_vortex_dummy_SpellScript)
   
        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            // each player will enter to the trigger vehicle (entry 30090) already spawned (each one can hold up to 5 players, it has 5 seats)
            // the players enter to the vehicles casting SPELL_VORTEX_4 OR SPELL_VORTEX_5
            if (InstanceScript* instance = caster->GetInstanceScript())
                instance->SetData(DATA_VORTEX_HANDLING,0);

            // the rest of the vortex execution continues when SPELL_VORTEX_2 is removed.
        }

        void Register()
        {
            OnEffect += SpellEffectFn(spell_malygos_vortex_dummy_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const
    {
        return new spell_malygos_vortex_dummy_SpellScript();
    }
};

class spell_malygos_vortex_visual : public SpellScriptLoader
{
    public:
        spell_malygos_vortex_visual() : SpellScriptLoader("spell_malygos_vortex_visual") { }

        class spell_malygos_vortex_visual_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_malygos_vortex_visual_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                std::list<HostileReference*> &m_threatlist = GetCaster()->getThreatManager().getThreatList();
                for (std::list<HostileReference*>::const_iterator itr = m_threatlist.begin(); itr!= m_threatlist.end(); ++itr)
                {
                    if (Unit* target = (*itr)->getTarget())
                    {
                        Player* targetPlayer = target->ToPlayer();

                        if (!targetPlayer || targetPlayer->isGameMaster())
                            continue;

                        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                        {
                            // teleport spell - i am not sure but might be it must be casted by each vehicle when its passenger leaves it
                            if (Creature* trigger = GetCaster()->GetMap()->GetCreature(instance->GetData64(DATA_TRIGGER)))
                                trigger->CastSpell(targetPlayer, SPELL_VORTEX_6, true);
                        }
                    }
                }

                if (Creature* malygos = GetCaster()->ToCreature())
                {
                    // This is a hack, we have to re add players to the threat list because when they enter to the vehicles they are removed.
                    // Anyway even with this issue, the boss does not enter in evade mode - this prevents iterate an empty list in the next vortex execution.
                    malygos->SetInCombatWithZone();

                    malygos->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);

                    malygos->GetMotionMaster()->MoveChase(GetCaster()->getVictim());
                    malygos->RemoveAura(SPELL_VORTEX_1);
                }

            }

            void Register()
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_malygos_vortex_visual_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const
        {
            return new spell_malygos_vortex_visual_AuraScript();
        }
};

class npc_portal_eoe: public CreatureScript
{
public:
    npc_portal_eoe() : CreatureScript("npc_portal_eoe") {}

    CreatureAI* GetAI(Creature* pCreature) const
    {
        return new npc_portal_eoeAI(pCreature);
    }

    struct npc_portal_eoeAI : public ScriptedAI
    {
        npc_portal_eoeAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();   
        }

        void Reset()
        {
            summonTimer = urand(5,7)*IN_MILLISECONDS;
        }

        void UpdateAI(const uint32 diff)
        {
            if (!me->HasAura(SPELL_PORTAL_VISUAL_CLOSED) &&
                !me->HasAura(SPELL_PORTAL_OPENED))
                DoCast(me,SPELL_PORTAL_VISUAL_CLOSED,true);

            if (instance)
            {
                if (Creature* malygos = Unit::GetCreature(*me,instance->GetData64(DATA_MALYGOS)))
                {
                    if (malygos->AI()->GetData(DATA_PHASE) != PHASE_ONE)
                    {
                        me->RemoveAura(SPELL_PORTAL_OPENED);
                        DoCast(me,SPELL_PORTAL_VISUAL_CLOSED,true);
                    }
                }
            }

            if (!me->HasAura(SPELL_PORTAL_OPENED))
                return;

            if (summonTimer <= diff)
            {
                DoCast(SPELL_SUMMON_POWER_PARK);
                summonTimer = urand(5,7)*IN_MILLISECONDS;
            } else summonTimer -= diff;
        }

        void JustSummoned(Creature* summon)
        {
            summon->SetInCombatWithZone();
        }
        
    private:
        uint32 summonTimer;
        InstanceScript* instance;
    };
};


class npc_power_spark: public CreatureScript
{
public:
    npc_power_spark() : CreatureScript("npc_power_spark") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_power_sparkAI(creature);
    }

    struct npc_power_sparkAI : public ScriptedAI
    {
        npc_power_sparkAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();

            MoveToMalygos();    
        }

        void EnterEvadeMode()
        {
            me->DespawnOrUnsummon();
        }

        void MoveToMalygos()
        {
            me->GetMotionMaster()->MoveIdle();

            if (instance)
            {
                if (Creature* malygos = Unit::GetCreature(*me,instance->GetData64(DATA_MALYGOS)))
                    me->GetMotionMaster()->MoveFollow(malygos,0.0f,0.0f);
            }
        }
        
        void UpdateAI(const uint32 diff)
        {
            if (!instance)
                return;

            if (Creature* malygos = Unit::GetCreature(*me,instance->GetData64(DATA_MALYGOS)))
            {
                if (malygos->AI()->GetData(DATA_PHASE) != PHASE_ONE)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                if (malygos->HasAura(SPELL_VORTEX_1))
                {
                    me->GetMotionMaster()->MoveIdle();
                    return;
                }

                if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != TARGETED_MOTION_TYPE)
                    me->GetMotionMaster()->MoveFollow(malygos,0.0f,0.0f);
            }
        }

        void DamageTaken(Unit* /*done_by*/, uint32& damage)
        {
            if (damage > me->GetMaxHealth())
            {
                damage = 0;
                DoCast(me,SPELL_POWER_SPARK_DEATH,true);
                me->DespawnOrUnsummon(1000);
            }
        }

    private:
        InstanceScript* instance;
    };
};

class npc_hover_disk : public CreatureScript
{
public:
    npc_hover_disk() : CreatureScript("npc_hover_disk") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_hover_diskAI(creature);
    }

    struct npc_hover_diskAI : public npc_escortAI
    {
        npc_hover_diskAI(Creature* creature) : npc_escortAI(creature) 
        { 
            if (me->GetEntry() == NPC_HOVER_DISK_CASTER)
                me->SetReactState(REACT_PASSIVE);
             else
                me->SetInCombatWithZone();

            instance = creature->GetInstanceScript();
        }

        void Reset()
        {
            if (Vehicle* veh = me->GetVehicleKit())
                veh->Reset();
        }

        void PassengerBoarded(Unit* unit, int8 seat, bool apply)
        {
            if (apply)
            {
                if (unit->GetTypeId() == TYPEID_UNIT)
                {
                    me->setFaction(FACTION_HOSTILE);
                    unit->ToCreature()->SetInCombatWithZone();
                }
            }
            else
            {
                // Error found: This is not called if the passenger is a player

                if (unit->GetTypeId() == TYPEID_UNIT)
                {
                    // This will only be called if the passenger dies
                    if (instance)
                    {
                        if (Creature* malygos = Unit::GetCreature(*me,instance->GetData64(DATA_MALYGOS)))
                            malygos->AI()->SetData(DATA_SUMMON_DEATHS,malygos->AI()->GetData(DATA_SUMMON_DEATHS)+1);
                    }

                    me->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_NOT_SELECTABLE);
                }

                me->GetMotionMaster()->MoveIdle();

                if (me->GetEntry() == NPC_HOVER_DISK_MELEE)
                {
                    // Hack: Fall ground function can fail (remember the platform is a gameobject), we will teleport the disk to the ground
                    if (me->GetPositionZ() > GROUND_Z)
                        me->NearTeleportTo(me->GetPositionX(),me->GetPositionY(),GROUND_Z,0);
                    me->SetHomePosition(me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation());
                    me->setFaction(FACTION_FRIENDLY);
                    me->AI()->EnterEvadeMode();
                }
            }
        }

        void EnterEvadeMode()
        {
            // we dont evade
        }

        void DoAction(const int32 action)
        {
            if (me->GetEntry() != NPC_HOVER_DISK_CASTER)
                return;

            switch (action)
            {
                case ACTION_HOVER_DISK_START_WP_1:
                    for (uint8 i = 0; i < MAX_HOVER_DISK_WAYPOINTS; i++)
                        AddWaypoint(i,HoverDiskWaypoints[i].GetPositionX(),HoverDiskWaypoints[i].GetPositionY(),HoverDiskWaypoints[i].GetPositionZ());
                    break;
                case ACTION_HOVER_DISK_START_WP_2:
                    {
                        uint8 count = 0;
                        for (uint8 i = MAX_HOVER_DISK_WAYPOINTS-1; i > 0; i--)
                        {
                            AddWaypoint(count,HoverDiskWaypoints[i].GetPositionX(),HoverDiskWaypoints[i].GetPositionY(),HoverDiskWaypoints[i].GetPositionZ());
                            count++;
                        }
                        break;
                    }
                default:
                    return;
            }

            Start(true,false,0,0,false,true);
        }

        void UpdateEscortAI(const uint32 /*diff*/)
        {
            // we dont do melee damage!
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        }

        void WaypointReached(uint32 i)
        {

        }

    private:
        InstanceScript* instance;
    };
};
<<<<<<< HEAD

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
                        me->SummonGameObject(RAID_MODE(GO_ALEXSTRASZAS_GIFT_10, GO_ALEXSTRASZAS_GIFT_25), Locations[5].GetPositionX(),
                            Locations[5].GetPositionY(), Locations[5].GetPositionZ(), 0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 0);
                        me->SummonGameObject(RAID_MODE(GO_HEART_OF_MAGIC_10, GO_HEART_OF_MAGIC_25), Locations[5].GetPositionX() + 15.0f,
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
=======


// The reason of this AI is to make the creature able to enter in combat otherwise the spell casting of SPELL_ARCANE_OVERLOAD fails.
class npc_arcane_overload : public CreatureScript
{
public:
    npc_arcane_overload() : CreatureScript("npc_arcane_overload") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_arcane_overloadAI (creature);
    }

    struct npc_arcane_overloadAI : public ScriptedAI
    {
        npc_arcane_overloadAI(Creature* creature) : ScriptedAI(creature) {}

        void AttackStart(Unit* who)
        {
            DoStartNoMovement(who);
        }

        void Reset()
        {
            DoCast(me,SPELL_ARCANE_OVERLOAD,false);
        }

        void UpdateAI(const uint32 diff)
        {
            // we dont do melee damage!
        }

    };
};

// SmartAI does not work correctly for this (vehicles)
class npc_wyrmrest_skytalon : public CreatureScript
{
public:
    npc_wyrmrest_skytalon() : CreatureScript("npc_wyrmrest_skytalon") {}

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_wyrmrest_skytalonAI (creature);
    }

    struct npc_wyrmrest_skytalonAI : public NullCreatureAI
    {
        npc_wyrmrest_skytalonAI(Creature* creature) : NullCreatureAI(creature)
        {
            instance = creature->GetInstanceScript();

            timer = 1000;
            entered = false;
        }

        // we can't call this in reset function, it fails.
        void MakePlayerEnter()
        {
            if (!instance)
                return;

            if (Creature* malygos = Unit::GetCreature(*me,instance->GetData64(DATA_MALYGOS)))
            {
                if (Unit* summoner = me->ToTempSummon()->GetSummoner())
                {
                    summoner->CastSpell(me,SPELL_RIDE_RED_DRAGON,true);
                    if (Creature* malygos = Unit::GetCreature(*me,instance->GetData64(DATA_MALYGOS)))
                    {
                        float victim_threat = malygos->getThreatManager().getThreat(summoner);
                        malygos->getThreatManager().resetAllAggro();
                        malygos->AI()->AttackStart(me);
                        malygos->AddThreat(me, victim_threat);
                    }
                }
            }
        }

        void UpdateAI(const uint32 diff)
        {
            if (!entered)
            {
                if (timer <= diff)
                {
                    MakePlayerEnter();
                    entered = true;
                } else timer -= diff;
            }
        }

    private:
        InstanceScript* instance;
        uint32 timer;
        bool entered;
    };
};

enum AlexstraszaYells
{
    SAY_ONE,
    SAY_TWO,
    SAY_THREE,
    SAY_FOUR
};

class npc_alexstrasza_eoe : public CreatureScript
{
public:
    npc_alexstrasza_eoe() : CreatureScript("npc_alexstrasza_eoe") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_alexstrasza_eoeAI (creature);
    }

    struct npc_alexstrasza_eoeAI : public ScriptedAI
    {
        npc_alexstrasza_eoeAI(Creature* creature) : ScriptedAI(creature) {}

        void Reset()
        {
            events.Reset();

            events.ScheduleEvent(EVENT_YELL_1,0);
        }

        void UpdateAI(const uint32 diff)
        {
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_YELL_1:
                        Talk(SAY_ONE);
                        events.ScheduleEvent(EVENT_YELL_2,4*IN_MILLISECONDS);
                        break;
                    case EVENT_YELL_2:
                        Talk(SAY_TWO);
                        events.ScheduleEvent(EVENT_YELL_3,4*IN_MILLISECONDS);
                        break;
                    case EVENT_YELL_3:
                        Talk(SAY_THREE);
                        events.ScheduleEvent(EVENT_YELL_4,7*IN_MILLISECONDS);
                        break;
                    case EVENT_YELL_4:
                        Talk(SAY_FOUR);
                        break;
                }
            }
        }
    private:
        EventMap events;
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
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
        npc_power_sparkAI(Creature* pCreature) : ScriptedAI(pCreature)
        {
            m_pInstance = pCreature->GetInstanceScript();
        }

        InstanceScript* m_pInstance;

        uint32 uiTimer;
        bool canMove;

        void Reset()
        {
            canMove = true;
            uiTimer = 1*IN_MILLISECONDS;
            DoCast(me, SPELL_POWER_SPARK_VISUAL, true);
        }

        void DoAction(const int32 param)
        {
            if (param == 1)
            {
                canMove = true;
            }
            else
            {
                me->SetSpeed(MOVE_FLIGHT, 1.2f);
                me->GetMotionMaster()->Clear();
                canMove = false;
            }
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

        void UpdateAI(const uint32 uiDiff)
        {
            if (canMove && me->CanFreeMove() && !me->HasAura(SPELL_POWER_SPARK_PLAYERS))
            {
                if (uiTimer <= uiDiff)
                {
                    if (Creature* pMalygos = Unit::GetCreature(*me, m_pInstance ? m_pInstance->GetData64(DATA_MALYGOS) : 0))
                        me->GetMotionMaster()->MovePoint(0, pMalygos->GetPositionX(), pMalygos->GetPositionY(), pMalygos->GetPositionZ());
                    
                    uiTimer = 1*IN_MILLISECONDS;
                } else uiTimer -= uiDiff;
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

class IsBadTargetForSpell
{
    public:
        IsBadTargetForSpell() { }

        bool operator() (Unit* unit)
        {
            SpellEntry* sSurge;
            sSurge = GET_SPELL(SPELL_SURGE_OF_POWER_25);
            if (sSurge)
                return unit->IsImmunedToSpell(sSurge);

            return true;
        }
};

class spell_surge_of_power_targeting : public SpellScriptLoader
{
    public:
        spell_surge_of_power_targeting() : SpellScriptLoader("spell_surge_of_power_targeting") { }

        class spell_surge_of_power_targeting_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_surge_of_power_targeting_SpellScript)

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if(IsBadTargetForSpell());
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_surge_of_power_targeting_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_AREA_ENEMY_SRC);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_surge_of_power_targeting_SpellScript();
        }
};
void AddSC_boss_malygos()
{
    new boss_malygos();
<<<<<<< HEAD
    new npc_nexus_lord();
    new npc_scion_of_eternity();
    new npc_alexstrasza();
    new npc_power_spark();
    new npc_vortex_vehicle();
    new npc_hover_disc();
    new go_focusing_iris();
    new spell_surge_of_power_targeting();
=======
    new npc_portal_eoe();
    new npc_power_spark();
    new npc_hover_disk();
    new npc_arcane_overload();
    new npc_wyrmrest_skytalon();
    new spell_malygos_vortex_dummy();
    new spell_malygos_vortex_visual();
    new npc_alexstrasza_eoe();
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
}
