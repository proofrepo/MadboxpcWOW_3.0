-- Fix Exploit Isle Of conquest 
UPDATE `creature_template` SET `ScriptName`='bosses_isle_of_conquest' WHERE `entry` IN (34924,34922);
-- Fix vehicle system.
DELETE FROM npc_spellclick_spells WHERE npc_entry IN (35413, 35419, 35431, 35433); 
INSERT INTO npc_spellclick_spells (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`, `aura_required`, `aura_forbidden`, `user_type`) VALUES 
(35413, 60968, 0, 0, 0, 1, 0, 0, 0), 
(35419, 68503, 0, 0, 0, 1, 0, 0, 0), 
(35431, 46598, 0, 0, 0, 1, 0, 0, 0), 
(35433, 46598, 0, 0, 0, 1, 0, 0, 0);  
