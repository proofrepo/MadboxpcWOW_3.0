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

class instance_eye_of_eternity : public InstanceMapScript
{
public:
    instance_eye_of_eternity() : InstanceMapScript("instance_eye_of_eternity", 616) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_eye_of_eternity_InstanceMapScript(pMap);
    }

    struct instance_eye_of_eternity_InstanceMapScript : public InstanceScript
    {
        instance_eye_of_eternity_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {Initialize();};

        uint64 uiMalygosGUID;
        uint64 uiPlatformGUID;
        uint64 uiExitPortalGUID;
        uint64 uiFocusingIrisGUID;

        uint32 auiEncounter[MAX_ENCOUNTER];

        void Initialize()
        {
            memset(&auiEncounter, 0, sizeof(auiEncounter));

            uiMalygosGUID = 0;
            uiPlatformGUID = 0;
            uiExitPortalGUID = 0;
            uiFocusingIrisGUID = 0;
        }

        bool IsEncounterInProgress() const
        {
            for (int i = 0; i < MAX_ENCOUNTER; ++i)
                if (auiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_MALYGOS:
                    uiMalygosGUID = creature->GetGUID();
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch(go->GetEntry())
            {
                case GO_PLATFORM:
                    uiPlatformGUID = go->GetGUID();
                    //if (auiEncounter[0] == DONE)
                    //    go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                    break;
                case GO_EXIT_PORTAL:
                    uiExitPortalGUID = go->GetGUID();
                    break;
                case GO_FOCUSING_IRIS:
                case GO_FOCUSING_IRIS_H:
                    uiFocusingIrisGUID = go->GetGUID();
                    if (auiEncounter[0] == DONE)
                        go->SetPhaseMask(2, true);
                    break;
            }
        }

        void SetData(uint32 uiType, uint32 uiData)
        {
            switch(uiType)
            {
                case TYPE_MALYGOS:
                    auiEncounter[0] = uiData;

                    if (uiData == NOT_STARTED)
                    {
                        if (GameObject* pFocusingIris = instance->GetGameObject(uiFocusingIrisGUID))
                        {
                            pFocusingIris->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_UNK1);
                            pFocusingIris->SetPhaseMask(1, true);
                        }
                        if (GameObject* pExitPortal = instance->GetGameObject(uiExitPortalGUID))
                            pExitPortal->SetPhaseMask(1, true);

                        if (GameObject* pPlatform = instance->GetGameObject(uiPlatformGUID))
                            if (pPlatform->HasFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED))
                                pPlatform->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_DESTROYED);
                    }
                    if (uiData == IN_PROGRESS)
                    {
                        if (GameObject* pFocusingIris = instance->GetGameObject(uiFocusingIrisGUID))
                            pFocusingIris->SetPhaseMask(2, true);

                        if (GameObject* pExitPortal = instance->GetGameObject(uiExitPortalGUID))
                            pExitPortal->SetPhaseMask(2, true);
                    }
                    if (uiData == DONE)
                    {
                        if (GameObject* pExitPortal = instance->GetGameObject(uiExitPortalGUID))
                            pExitPortal->SetPhaseMask(1, true);
                    }
                    break;
            }

            if (uiData == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 uiType)
        {
            switch (uiType)
            {
                case TYPE_MALYGOS: return auiEncounter[0];
            }
            return 0;
        }

        uint64 GetData64(uint32 uiData)
        {
            switch (uiData)
            {
                case DATA_MALYGOS: return uiMalygosGUID;
                case DATA_PLATFORM: return uiPlatformGUID;
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "E E " << auiEncounter[0];

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(const char* data)
        {
            if (!data)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(data);

            char dataHead1, dataHead2;
            uint16 data0;

            std::istringstream loadStream(data);
            loadStream >> dataHead1 >> dataHead2 >> data0;

            if (dataHead1 == 'E' && dataHead2 == 'E')
            {
                auiEncounter[0] = data0;

                if (auiEncounter[0] == IN_PROGRESS)
                    auiEncounter[0] = NOT_STARTED;

            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        void OnPlayerEnter(Player* pPlayer)
        {
            //if (auiEncounter[0] == DONE)
            //{
            //   if (Creature* pMount = pPlayer->SummonCreature(NPC_WYRMREST_SKYTALON, pPlayer->GetPositionX(), pPlayer->GetPositionY(), 260.0f, 0.0f))
            //    {
            //        pMount->SetFlying(true);
            //        pPlayer->EnterVehicle(pMount, 0);
            //    }
            //}
        }
    };
};

void AddSC_instance_eye_of_eternity()
{
    new instance_eye_of_eternity();
}
