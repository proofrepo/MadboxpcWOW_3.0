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
#include "ulduar.h"

const DoorData doorData[] =
{
    {194416,    BOSS_LEVIATHAN, DOOR_TYPE_ROOM,     0},
    {194905,    BOSS_LEVIATHAN, DOOR_TYPE_PASSAGE,  0},
    {194631,    BOSS_XT002,     DOOR_TYPE_ROOM,     0},
    {194554,    BOSS_ASSEMBLY,  DOOR_TYPE_ROOM,     0},
    {194556,    BOSS_ASSEMBLY,  DOOR_TYPE_PASSAGE,  0},
    {194553,    BOSS_KOLOGARN,  DOOR_TYPE_ROOM,     0},
    {194441,    BOSS_HODIR,     DOOR_TYPE_PASSAGE,  0},
    {194634,    BOSS_HODIR,     DOOR_TYPE_PASSAGE,  0},
    {194442,    BOSS_HODIR,     DOOR_TYPE_ROOM,     0},
    {194559,    BOSS_THORIM,    DOOR_TYPE_ROOM,     0},
    {194774,    BOSS_MIMIRON,   DOOR_TYPE_ROOM,     0},
    {194775,    BOSS_MIMIRON,   DOOR_TYPE_ROOM,     0},
    {194776,    BOSS_MIMIRON,   DOOR_TYPE_ROOM,     0},
    {194750,    BOSS_VEZAX,     DOOR_TYPE_PASSAGE,  0},
    {194773,    BOSS_YOGGSARON, DOOR_TYPE_ROOM,     0},
    {0,         0,              DOOR_TYPE_ROOM,     0}
};

enum eGameObjects
{
    GO_LEVIATHAN_DOOR       = 194630,
    GO_KOLOGARN_BRIDGE      = 194232,
    GO_HODIR_RARE_CHEST_10  = 194200,
    GO_HODIR_RARE_CHEST_25  = 194201,
    GO_RUNIC_DOOR           = 194557,
    GO_STONE_DOOR           = 194558,
    GO_THORIM_LEVER         = 194265,
    GO_MIMIRON_TRAM         = 194675,
    GO_MIMIRON_ELEVATOR     = 194749,
    GO_KEEPERS_DOOR         = 194255
};

class instance_ulduar : public InstanceMapScript
{
public:
    instance_ulduar() : InstanceMapScript("instance_ulduar", 603) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_ulduar_InstanceMapScript(pMap);
    }

    struct instance_ulduar_InstanceMapScript : public InstanceScript
    {
<<<<<<< HEAD
        instance_ulduar_InstanceMapScript(Map* pMap) : InstanceScript(pMap)
=======
        instance_ulduar_InstanceMapScript(InstanceMap* map) : InstanceScript(map) { Initialize(); };

        uint32 uiEncounter[MAX_ENCOUNTER];
        std::string m_strInstData;

        uint64 uiLeviathanGUID;
        uint64 uiIgnisGUID;
        uint64 uiRazorscaleGUID;
        uint64 uiRazorscaleController;
        uint64 uiRazorHarpoonGUIDs[4];
        uint64 uiExpCommanderGUID;
        uint64 uiXT002GUID;
        uint64 uiAssemblyGUIDs[3];
        uint64 uiKologarnGUID;
        uint64 uiLeftArmGUID;
        uint64 uiRightArmGUID;
        uint64 uiAuriayaGUID;
        uint64 uiMimironGUID;
        uint64 uiHodirGUID;
        uint64 uiThorimGUID;
        uint64 uiFreyaGUID;
        uint64 uiVezaxGUID;
        uint64 uiYoggSaronGUID;
        uint64 uiAlgalonGUID;
        uint64 uiLeviathanGateGUID;
        uint64 uiVezaxDoorGUID;

        uint64 uiKologarnChestGUID;
        uint64 uiKologarnBridgeGUID;
        uint64 uiKologarnDoorGUID;
        uint64 uiThorimChestGUID;
        uint64 uiHodirChestGUID;
        uint64 uiFreyaChestGUID;

        std::set<uint64> mRubbleSpawns;

        void Initialize()
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        {
            SetBossNumber(MAX_BOSS_NUMBER);
            LoadDoorData(doorData);
<<<<<<< HEAD
=======
            uiIgnisGUID             = 0;
            uiRazorscaleGUID        = 0;
            uiRazorscaleController  = 0;
            uiExpCommanderGUID      = 0;
            uiXT002GUID             = 0;
            uiKologarnGUID          = 0;
            uiLeftArmGUID           = 0;
            uiRightArmGUID          = 0;
            uiAuriayaGUID           = 0;
            uiMimironGUID           = 0;
            uiHodirGUID             = 0;
            uiThorimGUID            = 0;
            uiFreyaGUID             = 0;
            uiVezaxGUID             = 0;
            uiYoggSaronGUID         = 0;
            uiAlgalonGUID           = 0;
            uiKologarnChestGUID     = 0;
            uiKologarnBridgeGUID    = 0;
            uiKologarnChestGUID     = 0;
            uiThorimChestGUID       = 0;
            uiHodirChestGUID        = 0;
            uiFreyaChestGUID        = 0;
            uiLeviathanGateGUID     = 0;
            uiVezaxDoorGUID         = 0;

            memset(uiEncounter, 0, sizeof(uiEncounter));
            memset(uiAssemblyGUIDs, 0, sizeof(uiAssemblyGUIDs));
            memset(uiRazorHarpoonGUIDs, 0, sizeof(uiRazorHarpoonGUIDs));
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        }

        uint64 uiLeviathan;
        uint64 uiNorgannon;
        uint64 uiIgnis;
        uint64 uiRazorscale;
        uint64 uiExpCommander;
        uint64 uiXT002;
        uint64 uiSteelbreaker;
        uint64 uiMolgeim;
        uint64 uiBrundir;
        uint64 uiKologarn;
        uint64 uiKologarnBridge;
        uint64 uiAuriaya;
        uint64 uiBrightleaf;
        uint64 uiIronbranch;
        uint64 uiStonebark;
        uint64 uiFreya;
        uint64 uiThorim;
        uint64 uiRunicColossus;
        uint64 uiRuneGiant;
        uint64 uiMimiron;
        uint64 uiLeviathanMKII;
        uint64 uiVX001;
        uint64 uiAerialUnit;
        uint64 uiMagneticCore;
        uint64 KeepersGateGUID;
        uint64 uiVezax;
        uint64 uiFreyaImage;
        uint64 uiThorimImage;
        uint64 uiMimironImage;
        uint64 uiHodirImage;
        uint64 uiFreyaYS;
        uint64 uiThorimYS;
        uint64 uiMimironYS;
        uint64 uiHodirYS;
        uint64 uiYoggSaronBrain;
        uint64 uiYoggSaron;
        uint64 LeviathanDoorGUID;
        uint64 HodirRareChestGUID;
        uint64 RunicDoorGUID;
        uint64 StoneDoorGUID;
        uint64 ThorimLeverGUID;
        uint64 MimironTramGUID;
        uint64 MimironElevatorGUID;
        
        void OnGameObjectCreate(GameObject* pGo)
        {
            AddDoor(pGo, true);
            switch(pGo->GetEntry())
            {
                case GO_LEVIATHAN_DOOR:
                    LeviathanDoorGUID = pGo->GetGUID();
                    break;
                case GO_KOLOGARN_BRIDGE:
                    uiKologarnBridge = pGo->GetGUID();
                    HandleGameObject(uiKologarnBridge, true);
                    break;
                case GO_HODIR_RARE_CHEST_10:
                    HodirRareChestGUID = pGo->GetGUID();
                    break;
                case GO_HODIR_RARE_CHEST_25:
                    HodirRareChestGUID = pGo->GetGUID();
                    break;
<<<<<<< HEAD
                case GO_RUNIC_DOOR:
                    RunicDoorGUID = pGo->GetGUID();
=======
                case NPC_RAZORSCALE_CONTROLLER:
                    uiRazorscaleController = creature->GetGUID();
                    break;
                case NPC_EXPEDITION_COMMANDER:
                    uiExpCommanderGUID = creature->GetGUID();
                    return;
                case NPC_XT002:
                    uiXT002GUID = creature->GetGUID();
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
                    break;
                case GO_STONE_DOOR:
                    StoneDoorGUID = pGo->GetGUID();
                    break;
                case GO_THORIM_LEVER:
                    ThorimLeverGUID = pGo->GetGUID();
                    break;
                case GO_MIMIRON_TRAM:
                    MimironTramGUID = pGo->GetGUID();
                    break;
                case GO_MIMIRON_ELEVATOR:
                    MimironElevatorGUID = pGo->GetGUID();
                    break;
                case GO_KEEPERS_DOOR: KeepersGateGUID = pGo->GetGUID();
                {
                    InstanceScript* pInstance = pGo->GetInstanceScript();
                    pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_LOCKED);
                    if (pInstance)
                    {
                        for (uint32 i = BOSS_MIMIRON; i < BOSS_VEZAX; ++i)
                            if (pInstance->GetBossState(i) != DONE)
                                pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_LOCKED);
                    }
                    break;
<<<<<<< HEAD
                }
                default: break;
=======

                case NPC_AURIAYA:
                    uiAuriayaGUID = creature->GetGUID();
                    break;
                case NPC_MIMIRON:
                    uiMimironGUID = creature->GetGUID();
                    break;
                case NPC_HODIR:
                    uiHodirGUID = creature->GetGUID();
                    break;
                case NPC_THORIM:
                    uiThorimGUID = creature->GetGUID();
                    break;
                case NPC_FREYA:
                    uiFreyaGUID = creature->GetGUID();
                    break;
                case NPC_VEZAX:
                    uiVezaxGUID = creature->GetGUID();
                    break;
                case NPC_YOGGSARON:
                    uiYoggSaronGUID = creature->GetGUID();
                    break;
                case NPC_ALGALON:
                    uiAlgalonGUID = creature->GetGUID();
                    break;
            }

         }

        void OnGameObjectCreate(GameObject* go)
        {
            switch(go->GetEntry())
            {
                case GO_KOLOGARN_CHEST_HERO:
                case GO_KOLOGARN_CHEST:
                    uiKologarnChestGUID = go->GetGUID();
                    break;
                case GO_KOLOGARN_BRIDGE:
                    uiKologarnBridgeGUID = go->GetGUID();
                    if (GetBossState(TYPE_KOLOGARN) == DONE)
                        HandleGameObject(0, false, go);
                    break;
                case GO_KOLOGARN_DOOR:
                    uiKologarnDoorGUID = go->GetGUID();
                    break;
                case GO_THORIM_CHEST_HERO:
                case GO_THORIM_CHEST:
                    uiThorimChestGUID =go->GetGUID();
                    break;
                case GO_HODIR_CHEST_HERO:
                case GO_HODIR_CHEST:
                    uiHodirChestGUID = go->GetGUID();
                    break;
                case GO_FREYA_CHEST_HERO:
                case GO_FREYA_CHEST:
                    uiFreyaChestGUID = go->GetGUID();
                    break;
                case GO_LEVIATHAN_DOOR:
                    AddDoor(go, true);
                    break;
                case GO_LEVIATHAN_GATE:
                    uiLeviathanGateGUID = go->GetGUID();
                    if (GetBossState(TYPE_LEVIATHAN) == DONE)
                        go->SetGoState(GO_STATE_ACTIVE_ALTERNATIVE);
                    break;
                case GO_VEZAX_DOOR:
                    uiVezaxDoorGUID = go->GetGUID();
                    HandleGameObject(NULL, false, go);
                    break;
                case GO_RAZOR_HARPOON_1:
                    uiRazorHarpoonGUIDs[0] = go->GetGUID();
                    break;
                case GO_RAZOR_HARPOON_2:
                    uiRazorHarpoonGUIDs[1] = go->GetGUID();
                    break;
                case GO_RAZOR_HARPOON_3:
                    uiRazorHarpoonGUIDs[2] = go->GetGUID();
                    break;
                case GO_RAZOR_HARPOON_4:
                    uiRazorHarpoonGUIDs[3] = go->GetGUID();
                    break;
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
            }
        }
        
        void OnGameObjectRemove(GameObject* go)
        {
            AddDoor(go, false);
        }

        void OnCreatureCreate(Creature* pCreature)
        {
            Map::PlayerList const &players = instance->GetPlayers();
            uint32 TeamInInstance = 0;

            if (!players.isEmpty())
                if (Player* pPlayer = players.begin()->getSource())
                    TeamInInstance = pPlayer->GetTeam();
        
            switch(pCreature->GetEntry())
            {
                case 33113: uiLeviathan = pCreature->GetGUID(); return;
                case 33686: uiNorgannon = pCreature->GetGUID(); return;
                case 33118: uiIgnis = pCreature->GetGUID(); return;
                case 33186: uiRazorscale = pCreature->GetGUID(); return;
                case 33210: uiExpCommander = pCreature->GetGUID(); return;
                case 33293: uiXT002 = pCreature->GetGUID(); return;
                case 32867: uiSteelbreaker = pCreature->GetGUID(); return;
                case 32927: uiMolgeim = pCreature->GetGUID(); return;
                case 32857: uiBrundir = pCreature->GetGUID(); return;
                case 32930: uiKologarn = pCreature->GetGUID(); return;
                case 33515: uiAuriaya = pCreature->GetGUID(); return;
                case 32915: uiBrightleaf = pCreature->GetGUID(); return;
                case 32913: uiIronbranch = pCreature->GetGUID(); return;
                case 32914: uiStonebark = pCreature->GetGUID(); return;
                case 32906: uiFreya = pCreature->GetGUID(); return;
                case 32865: uiThorim = pCreature->GetGUID(); return;
                case 32872: uiRunicColossus = pCreature->GetGUID(); return;
                case 32873: uiRuneGiant = pCreature->GetGUID(); return;
                case 33350: uiMimiron = pCreature->GetGUID(); return;
                case 33432: uiLeviathanMKII = pCreature->GetGUID(); return;
                case 33651: uiVX001 = pCreature->GetGUID(); return;
                case 33670: uiAerialUnit = pCreature->GetGUID(); return;
                case 34068: uiMagneticCore = pCreature->GetGUID(); return;
                case 33271: uiVezax = pCreature->GetGUID(); return;
                case 33410: uiFreyaYS = pCreature->GetGUID(); return;
                case 33413: uiThorimYS = pCreature->GetGUID(); return;
                case 33412: uiMimironYS = pCreature->GetGUID(); return;
                case 33411: uiHodirYS = pCreature->GetGUID(); return;
                case 33890: uiYoggSaronBrain = pCreature->GetGUID(); return;
                case 33288: uiYoggSaron = pCreature->GetGUID(); return;
            
                // Keeper's Images
                case 33241: uiFreyaImage = pCreature->GetGUID();
                {
                    InstanceScript* pInstance = pCreature->GetInstanceScript();
                    pCreature->SetVisible(false);
                    if (pInstance && pInstance->GetBossState(BOSS_VEZAX) == DONE)
                        pCreature->SetVisible(true);
                }
                return;
                case 33242: uiThorimImage = pCreature->GetGUID();
                {
                    InstanceScript* pInstance = pCreature->GetInstanceScript();
                    pCreature->SetVisible(false);
                    if (pInstance && pInstance->GetBossState(BOSS_VEZAX) == DONE)
                        pCreature->SetVisible(true);
                }
                return;
                case 33244: uiMimironImage = pCreature->GetGUID();
                {
                    InstanceScript* pInstance = pCreature->GetInstanceScript();
                    pCreature->SetVisible(false);
                    if (pInstance && pInstance->GetBossState(BOSS_VEZAX) == DONE)
                        pCreature->SetVisible(true);
                }            
                return;
                case 33213: uiHodirImage = pCreature->GetGUID();
                {
                    InstanceScript* pInstance = pCreature->GetInstanceScript();
                    pCreature->SetVisible(false);
                    if (pInstance && pInstance->GetBossState(BOSS_VEZAX) == DONE)
                        pCreature->SetVisible(true);
                }
                return;
            }

            // Some npcs are faction dependent
            if (TeamInInstance == HORDE)
            {
                switch(pCreature->GetEntry())
                {
                    case 33062: pCreature->SetDisplayId(25871); return;
                    case 33325: pCreature->UpdateEntry(32941, HORDE); return;
                    case 32901: pCreature->UpdateEntry(33333, HORDE); return;
                    case 33328: pCreature->UpdateEntry(33332, HORDE); return;
                    case 32900: pCreature->UpdateEntry(32950, HORDE); return;
                    case 32893: pCreature->UpdateEntry(33331, HORDE); return;
                    case 33327: pCreature->UpdateEntry(32946, HORDE); return;
                    case 32897: pCreature->UpdateEntry(32948, HORDE); return;
                    case 33326: pCreature->UpdateEntry(33330, HORDE); return;
                    case 32907: pCreature->UpdateEntry(32908, HORDE); return;
                    case 32885: pCreature->UpdateEntry(32883, HORDE); return;
                }
            }
        }

        uint64 GetData64(uint32 id)
        {
            switch(id)
            {
                case DATA_LEVIATHAN:
                    return uiLeviathan;
                case DATA_NORGANNON:
                    return uiNorgannon;
                case DATA_IGNIS:
                    return uiIgnis;
                case DATA_RAZORSCALE:
                    return uiRazorscale;
                case DATA_EXP_COMMANDER:
                    return uiExpCommander;
                case DATA_XT002:
                    return uiXT002;
                case DATA_STEELBREAKER:
                    return uiSteelbreaker;
                case DATA_MOLGEIM:
                    return uiMolgeim;
                case DATA_BRUNDIR:
                    return uiBrundir;
                case DATA_KOLOGARN:
                    return uiKologarn;
                case DATA_AURIAYA:
                    return uiAuriaya;
                case DATA_BRIGHTLEAF:
                    return uiBrightleaf;
                case DATA_IRONBRANCH:
                    return uiIronbranch;
                case DATA_STONEBARK:
                    return uiStonebark;
                case DATA_FREYA:
                    return uiFreya;
                case DATA_THORIM:
                    return uiThorim;
                case DATA_RUNIC_COLOSSUS:
                    return uiRunicColossus;
                case DATA_RUNE_GIANT:
                    return uiRuneGiant;
                case DATA_MIMIRON:
                    return uiMimiron;
                case DATA_LEVIATHAN_MK_II:
                    return uiLeviathanMKII;
                case DATA_VX_001:
                    return uiVX001;
                case DATA_AERIAL_UNIT:
                    return uiAerialUnit;
                case DATA_MAGNETIC_CORE:
                    return uiMagneticCore;
                case DATA_VEZAX:
                    return uiVezax;
                case DATA_YS_FREYA:
                    return uiFreyaYS;
                case DATA_YS_THORIM:
                    return uiThorimYS;
                case DATA_YS_MIMIRON:
                    return uiMimironYS;
                case DATA_YS_HODIR:
                    return uiHodirYS;
                case DATA_YOGGSARON_BRAIN:
                    return uiYoggSaronBrain;
                case DATA_YOGGSARON:
                    return uiYoggSaron;
            }
            return NULL;
        }
    
        void SetData(uint32 id, uint32 value)
        {
            switch(id)
            {
                case DATA_LEVIATHAN_DOOR:
                    if (GameObject* pLeviathanDoor = instance->GetGameObject(LeviathanDoorGUID))
                        pLeviathanDoor->SetGoState(GOState(value));
                    break;
                case DATA_TOWER_DESTROYED:
                    {
                        if (Creature* pLeviathan = instance->GetCreature(uiLeviathan))
                        {
                            switch(value)
                            {
                                case 1: // Tower of Storms
                                    pLeviathan->AI()->DoAction(1);
                                    break;
                                case 2: // Tower of Flames
                                    pLeviathan->AI()->DoAction(2);
                                    break;
                                case 3: // Tower of Frost
                                    pLeviathan->AI()->DoAction(3);
                                    break;
                                case 4: // Tower of Life
                                    pLeviathan->AI()->DoAction(4);
                                    break;
                                default:
                                    break;
                            }
                        }
                    }
                    break;
                case DATA_RUNIC_DOOR:
                    if (GameObject* pRunicDoor = instance->GetGameObject(RunicDoorGUID))
                        pRunicDoor->SetGoState(GOState(value));
                    break;
                case DATA_STONE_DOOR:
                    if (GameObject* pStoneDoor = instance->GetGameObject(StoneDoorGUID))
                        pStoneDoor->SetGoState(GOState(value));
                    break;
                case DATA_CALL_TRAM:
                    if (GameObject* MimironTram = instance->GetGameObject(MimironTramGUID))
                    {
                        // Load Mimiron Tram (unfortunally only server side)
                        instance->LoadGrid(2307, 284.632f);
                
                        if (value == 0)
                            MimironTram->SetGoState(GO_STATE_READY);
                        if (value == 1)
                            MimironTram->SetGoState(GO_STATE_ACTIVE);
                    
                        // Send movement update to players
                        if (Map* pMap = MimironTram->GetMap())
                        {
                            if (pMap->IsDungeon())
                            {
                                Map::PlayerList const &PlayerList = pMap->GetPlayers();

                                if (!PlayerList.isEmpty())
                                {
                                    for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                    {
                                        if (i->getSource())
                                        {
                                            UpdateData data;
                                            WorldPacket pkt;
                                            MimironTram->BuildValuesUpdateBlockForPlayer(&data, i->getSource());
                                            data.BuildPacket(&pkt);
                                            i->getSource()->GetSession()->SendPacket(&pkt);
                                        }
                                    }
                                }
                            }
                        }
                    }
                    break;
                case DATA_MIMIRON_ELEVATOR:
                    if (GameObject* MimironElevator = instance->GetGameObject(MimironElevatorGUID))
                        MimironElevator->SetGoState(GOState(value));
                    break;
                case DATA_HODIR_RARE_CHEST:
                    if (GameObject* HodirRareChest = instance->GetGameObject(HodirRareChestGUID))
                    {
                        if (value == GO_STATE_READY)
                            HodirRareChest->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                    }
                    break;
            }
        }

        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;
            
            switch (id)
            {
                case BOSS_KOLOGARN:
                    if (state == DONE)
                        HandleGameObject(uiKologarnBridge, false);
                    break;
                case BOSS_HODIR:
                    CheckKeepersState();
                    break;
<<<<<<< HEAD
                case BOSS_THORIM:
                    if (GameObject* pThorimLever = instance->GetGameObject(ThorimLeverGUID))
                    {
                        if (state == IN_PROGRESS)
                            pThorimLever->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_UNK1);
                    }
                    CheckKeepersState();
                    break;
                case BOSS_MIMIRON:
                    CheckKeepersState();
                    break;
                case BOSS_FREYA:
                    CheckKeepersState();
                    break;
                case BOSS_VEZAX:
                    if (state == DONE)
                    {
                        // Keeper's Images
                        if (Creature* pFreya = instance->GetCreature(uiFreyaImage))
                            pFreya->SetVisible(true);
                        if (Creature* pThorim = instance->GetCreature(uiThorimImage))
                            pThorim->SetVisible(true);
                        if (Creature* pMimiron = instance->GetCreature(uiMimironImage))
                            pMimiron->SetVisible(true);
                        if (Creature* pHodir = instance->GetCreature(uiHodirImage))
                            pHodir->SetVisible(true);
                    }
                    break;
            }
        
            return true;
        }
    
        void CheckKeepersState()
=======
            }
        }

        uint64 GetData64(uint32 data)
        {
            switch(data)
            {
                case TYPE_LEVIATHAN:            return uiLeviathanGUID;
                case TYPE_IGNIS:                return uiIgnisGUID;
                case TYPE_RAZORSCALE:           return uiRazorscaleGUID;
                case DATA_RAZORSCALE_CONTROL:   return uiRazorscaleController;
                case TYPE_XT002:                return uiXT002GUID;
                case TYPE_KOLOGARN:             return uiKologarnGUID;
                case DATA_LEFT_ARM:             return uiLeftArmGUID;
                case DATA_RIGHT_ARM:            return uiRightArmGUID;
                case TYPE_AURIAYA:              return uiAuriayaGUID;
                case TYPE_MIMIRON:              return uiMimironGUID;
                case TYPE_HODIR:                return uiHodirGUID;
                case TYPE_THORIM:               return uiThorimGUID;
                case TYPE_FREYA:                return uiFreyaGUID;
                case TYPE_VEZAX:                return uiVezaxGUID;
                case TYPE_YOGGSARON:            return uiYoggSaronGUID;
                case TYPE_ALGALON:              return uiAlgalonGUID;

                // razorscale expedition commander
                case DATA_EXP_COMMANDER:        return uiExpCommanderGUID;
                case GO_RAZOR_HARPOON_1:        return uiRazorHarpoonGUIDs[0];
                case GO_RAZOR_HARPOON_2:        return uiRazorHarpoonGUIDs[1];
                case GO_RAZOR_HARPOON_3:        return uiRazorHarpoonGUIDs[2];
                case GO_RAZOR_HARPOON_4:        return uiRazorHarpoonGUIDs[3];
                // Assembly of Iron
                case DATA_STEELBREAKER:         return uiAssemblyGUIDs[0];
                case DATA_MOLGEIM:              return uiAssemblyGUIDs[1];
                case DATA_BRUNDIR:              return uiAssemblyGUIDs[2];
            }

            return 0;
        }

        uint32 GetData(uint32 type)
>>>>>>> 24dae7dd9a782145783f68769dd7f7a9a61fbeee
        {
            if (GameObject* pGo = instance->GetGameObject(KeepersGateGUID))
            {
                InstanceScript* pInstance = pGo->GetInstanceScript();
                pGo->RemoveFlag(GAMEOBJECT_FLAGS,GO_FLAG_LOCKED);
                if (pInstance)
                {
                    for (uint32 i = BOSS_MIMIRON; i < BOSS_VEZAX; ++i)
                        if (pInstance->GetBossState(i) != DONE)
                            pGo->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_LOCKED);
                }
            }
        }
    };

};

class go_call_tram : public GameObjectScript
{
public:
    go_call_tram() : GameObjectScript("go_call_tram") { }

    bool OnGossipHello(Player* /*pPlayer*/, GameObject* pGo)
    {
        InstanceScript* pInstance = pGo->GetInstanceScript();

        if (!pInstance)
            return false;

        switch(pGo->GetEntry())
        {
            case 194914:
            case 194438:
                pInstance->SetData(DATA_CALL_TRAM, 0);
                break;
            case 194912:
            case 194437:
                pInstance->SetData(DATA_CALL_TRAM, 1);
                break;
        }
        return true;
    }
};


void AddSC_instance_ulduar()
{
    new instance_ulduar();
    new go_call_tram();
}

