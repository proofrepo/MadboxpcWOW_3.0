-- [Faction]Sons_Of_hodir_Quest.sql
-- -------------------------------------------
-- Chains Sons Of Hodir
-- -------------------------------------------
-- Fix Quest http://www.wowhead.com/quest=12851 "Going Bearback"
/* DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` =29598; 
INSERT INTO `npc_spellclick_spells` (`npc_entry`, `spell_id`, `quest_start`, `quest_start_active`, `quest_end`, `cast_flags`, `aura_required`, `aura_forbidden`, `user_type`) VALUES
(29598, 54768, 12851, 1, 12851, 1, 0, 0, 0);-- Icefang Summon.*/
UPDATE `creature_template` SET `spell1` = '54897' , `spell2` =  '54907' WHERE `entry` = 29602; -- Spells Icefang
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` IN (29358,29351); -- Mobs Respawn Rapido (Elites).
UPDATE `creature_template` SET `ScriptName` = 'npc_quest_12851' WHERE `entry` IN (29358,29351); -- Set Scriptname.
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 54798; -- Añadida Condiciones Correspondientes
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) 
VALUES
(13,54798,18,1,29351),
(13,54798,18,1,29358);
-- Fix Quest: "Cold Hearted" (12856) http://www.wowhead.com/quest=12856
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` = 29708;-- Respawn Rapido "Captive Protodrake"
UPDATE `creature_template` SET `spell1` = 55046, `faction_A` = 35, `faction_H` = 35, `InhabitType` = 4 WHERE `entry` = 29709; -- Protodrake Misc updates
-- ScriptNames
UPDATE `creature_template` SET `ScriptName` = 'npc_freed_protodrake' WHERE `entry` = 29709;
UPDATE `creature_template` SET `ScriptName` = 'npc_brunnhildar_prisoner' WHERE `entry` = 29639; 
UPDATE `creature_template` SET `ScriptName` = 'npc_freed_protodrake' WHERE `entry` = 29709;
UPDATE `spell_area` SET `quest_end` = 12983 WHERE `area` = 4437 AND `quest_end` = 13063;
-- Fix 12856 (Cold Hearted)
-- Captive proto-drake
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=29708;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`)
VALUES (29708,55028,12856,1,12856,1,0,0,0);
-- Freed proto-drake
DELETE FROM `creature_template_addon` WHERE `entry`=29709;
INSERT INTO `creature_template_addon` (`entry`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(29709,0,50331648,257,0, NULL);
UPDATE `creature_template` SET `unit_flags`=`unit_flags`|16777216, `ScriptName`='' WHERE `entry`=29708;
UPDATE `creature_template` SET `InhabitType`=7 WHERE `entry`=29709;
-- Fix Quest: Quest: The Drakkensryd (12886)
UPDATE `creature_template` SET `InhabitType` = 4, `ScriptName` = 'npc_hyldsmeet_protodrake' WHERE `entry` = 29679;-- The Warm-Up & Into the Pit & Back to the Pit
-- Spells  WoWWiki - http://www.wowwiki.com/Warbear_Matriarch
UPDATE `creature_template` SET
 `spell4` = 54459, -- Maul
 `spell5` = 54458, -- Smash
 `spell6` = 54460, -- Charge
 `speed_run` = 3   -- old: 1,14286
WHERE `entry` = 29918;
-- The Warm-Up
-- Give KillCredit at 10% HP
REPLACE INTO `creature_ai_scripts` VALUES (
-- id, creature_id
2935201, 29352,
-- event_type EVENT_T_HP, event_inverse_phase_mask, event_chance, event_flags EFLAG_REPEATABLE
2, 0, 100, 1,
-- event_param1 HPMax%, event_param2 HPMin%, event_param3 RepeatMin, event_param4 RepeatMax
10, 1, 1, 1,
-- action1_type ACTION_T_KILLED_MONSTER, action1_param1 Creature-ID, action1_param2 Target-Type TARGET_T_ACTION_INVOKER, action1_param3,
33, 30221, 1, 0,
-- action2_type, action2_param1, action2_param2, action2_param3
24, 0, 0, 0,
-- action3_type, action3_param1, action3_param2, action3_param3
0, 0, 0, 0,
-- comment
'Storm Peaks: The Warm-Up - KillCredit for Kirgaraak at 10% HP');
UPDATE `creature_template` SET `AIName` = 'EventAI' WHERE `entry` = 29352;
-- Prequest  12924
UPDATE `quest_template` SET `NextQuestId` = 12924, `ExclusiveGroup` = -12915 WHERE `entry` IN (12915, 12956);
-- Replace 4 vendor items
UPDATE `npc_vendor` SET `item` = 50335 WHERE `entry` = 32540 AND `item` = 44133;
UPDATE `npc_vendor` SET `item` = 50336 WHERE `entry` = 32540 AND `item` = 44134;
UPDATE `npc_vendor` SET `item` = 50338 WHERE `entry` = 32540 AND `item` = 44135;
UPDATE `npc_vendor` SET `item` = 50337 WHERE `entry` = 32540 AND `item` = 44136;
--  12886 Start Script
UPDATE `quest_template` SET `StartScript` = 12886 WHERE `entry` = 12886;
DELETE FROM `quest_start_scripts` WHERE `id` = 12886;
INSERT INTO `quest_start_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`)
VALUES
(12886,0,15,55253,0,0,0,0,0,0);
-- Fix Quest: The Last of Her Kind (12983)
-- ScriptNames
UPDATE `creature_template` SET `ScriptName` = 'npc_injured_icemaw' WHERE `entry` = 29563;
UPDATE `creature_template` SET `ScriptName` = 'npc_harnessed_icemaw' WHERE `entry` = 30468;
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 29592;
-- Spawn anvil
DELETE FROM `gameobject` WHERE `id` = 192060;
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`)
VALUES
(192060, 571, 1, 1, 7220.96, -3650.65, 819.39, 2.59262, 0, 0, 0.962565, 0.271053, 300, 0, 1);
DELETE FROM `spell_area` WHERE `spell` = 55858 AND `area` = 4438;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`)
VALUES 
(55858, 4438, 12924, 1, 0, 0, 0, 2, 1);
UPDATE `gossip_menu_option` SET `option_id` = 3 WHERE `menu_id` = 10281;
-- Spawn Npc
DELETE FROM `creature` WHERE `id`=29563;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(29563, 571, 1, 1, 0, 0, 7315.48, -2050.65, 761.353, 4.04369, 300, 0, 0, 12600, 0, 0, 0, 0, 0, 0);

-- Item 41556 12915 restriccion uso.
UPDATE `conditions` SET `ConditionTypeOrReference` = 8, `ConditionValue1` = 13064 WHERE `SourceEntry` = 41556 AND `SourceGroup` = 29375;
-- Seteo Faction npc Victorious Challenger - Agnetta Tyrsdottar
UPDATE `creature_template` SET `faction_A` = 2109, `faction_H` = 2109 WHERE `entry` IN (30012, 30154);
-- Llevan Montado un npc. (flag dead Eai cuando lo llamas).
UPDATE `creature_template` SET `flags_extra` = 2, `unit_flags` = `unit_flags`|2|256|512 WHERE `entry` = 30175;
-- Spawntime Update Npcs  Overseer Syra - Captive Vrykul - Exhausted Vrykul - Garhal - Agnetta Tyrsdottar - Victorious Challenger - Hyldsmeet Warbear - Kirgaraak
UPDATE `creature` SET `spawntimesecs` = 60 WHERE `id` = 29518;
UPDATE `creature` SET `spawntimesecs` = 120 WHERE `id` IN (29427, 30146, 30147);
UPDATE `creature` SET `spawntimesecs` = 30 WHERE `id` IN (30012, 30154, 30174, 29352);
-- Seteo  Snorri Spells y vechicleID
UPDATE `creature_template` SET `spell1` = 56750, `spell2` = 56753, `VehicleId` = 181 WHERE `entry` = 30124;
-- Update Seething Revenants Faction (Phase 4)
UPDATE `creature_template` SET `faction_A` = 14, `faction_H` = 14, `flags_extra` = 268435456 WHERE `entry` = 30120;
DELETE FROM `creature_ai_scripts` WHERE `id` = 3012002;
INSERT INTO `creature_ai_scripts` 
VALUES (3012002,30120,6,0,100,1,0,0,0,0,33,30125,6,0,41,5000,0,0,0,0,0,0,'Seething Revenant - Kill Credit');
-- Spell target restriccion
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 17 AND `SourceEntry` = 56753;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) 
VALUES
(17, 56753, 19, 30120, 0);
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 56753;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) 
VALUES (56753, -56750, 0, 'Snorri - Remove Gather Snow');
-- Hacer a Snorri Clickeable
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` = 30123;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) 
VALUES (30123, 55957, 12967, 1, 12967, 3, 0, 55962, 0);
-- Phase anvil (phase 4)
DELETE FROM `spell_area` WHERE `spell` = 55858 AND `area` IN (4439,4495);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`)
VALUES 
(55858, 4439, 12924, 1, 12924, 0, 0, 2, 1),
(55858, 4495, 12924, 1, 12924, 0, 0, 2, 1);
-- Phase anvil and lake area (phase 8)
DELETE FROM `spell_area` WHERE `spell` = 55952 AND `area` IN (4439,4495);
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`)
VALUES 
(55952, 4439, 12924, 0, 0, 0, 0, 2, 1),
(55952, 4495, 12924, 0, 0, 0, 0, 2, 1);
-- Set Tundra Ram phasemask
UPDATE `creature` SET `phaseMask` = 13 WHERE `id` = 29958;
-- spawn njormeld related creatures
DELETE FROM `creature` WHERE `id` IN (30099, 30120, 30123);
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)
VALUES
(30099, 571, 1, 4, 0, 0, 7175.17, -3514.41, 832.257, 6.16378, 30,  0, 0, 50400, 0, 0, 0, 0, 0, 0),
(30120, 571, 1, 4, 0, 0, 7211.01, -3663.32, 822.932, 1.06182, 30, 10, 0, 12600, 0, 0, 1, 0, 0, 0),
(30120, 571, 1, 4, 0, 0, 7234.67, -3649.07, 823.685, 2.62084, 30, 10, 0, 12600, 0, 0, 1, 0, 0, 0),
(30120, 571, 1, 4, 0, 0, 7240.39, -3678.53, 822.731, 1.94933, 30, 10, 0, 12600, 0, 0, 1, 0, 0, 0),
(30120, 571, 1, 4, 0, 0, 7258.67, -3641.53, 823.251, 3.15098, 30, 10, 0, 12600, 0, 0, 1, 0, 0, 0),
(30120, 571, 1, 4, 0, 0, 7215.29, -3623.86, 823.263, 2.5855,  30, 10, 0, 12600, 0, 0, 1, 0, 0, 0),
(30120, 571, 1, 4, 0, 0, 7199.37, -3638.62, 823.401, 4.25839, 30, 10, 0, 12600, 0, 0, 1, 0, 0, 0),
(30123, 571, 1, 4, 0, 0, 7167.15, -3543.37, 827.69,  6.25175, 30,  0, 0, 50400, 0, 0, 0, 0, 0, 0);
-- Spawn  Nifelem Anvil
DELETE FROM `gameobject` WHERE `id` = 192071;
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`)
VALUES
(192071, 571, 1, 4, 7218.02, -2644.12, 809.814, 5.65174, 0, 0, 0.310502, -0.950573, 300, 0, 1);
-- Anvil questrelations
INSERT IGNORE INTO `gameobject_questrelation` VALUES (192071, 12981);
INSERT IGNORE INTO `gameobject_involvedrelation` VALUES (192071, 12981);
-- "Hot and Cold" (daily)
UPDATE `quest_template` SET `PrevQuestId` = 12967, `NextQuestInChain` = 0 WHERE `entry` = 12981;
-- "The Reckoning" prequests
UPDATE `quest_template` SET `NextQuestId` = 13047, `ExclusiveGroup` = -13005 WHERE `entry` IN (13005, 13035);
-- "Diametrically Opposed"
UPDATE `quest_template` SET `PrevQuestId` = 13047, `NextQuestInChain` = 0 WHERE `entry` = 13109;
-- dead iron giant looking dead
INSERT IGNORE INTO `creature_template_addon` VALUES (29914, 0, 0, 7, 0, 0, NULL);
-- spawntime and phasemask
UPDATE `creature` SET `spawntimesecs` = 120, `phaseMask` = 13 WHERE `guid` IN (116761, 116762, 116763);
-- make ignore aggro
UPDATE `creature_template` SET `flags_extra` = 268435458, `unit_flags` = `unit_flags`|2|256|512 WHERE `entry` = 29914;
DELETE FROM `creature` WHERE `id` = 29914 AND `phaseMask` = 12;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)
VALUES 
('29914','571','1','12','0','0','7429.23','-3187.91','837.452','0.19249','120','0','0','50400','0','0','0','0','0','0'),
('29914','571','1','12','0','0','7359.28','-3176.45','837.452','1.31954','120','0','0','50400','0','0','0','0','0','0'),
('29914','571','1','12','0','0','7280.03','-3142.9','837.452','4.41243','120','0','0','50400','0','0','0','0','0','0'),
('29914','571','1','12','0','0','7515.58','-3137.05','837.452','5.47429','120','0','0','50400','0','0','0','0','0','0'),
('29914','571','1','12','0','0','7509.03','-3225.78','837.432','2.03661','120','0','0','50400','0','0','0','0','0','0'),
('29914','571','1','12','0','0','7259.32','-3221.84','837.452','1.06349','120','0','0','50400','0','0','0','0','0','0');
-- Quest: hot and cold
DELETE FROM `spell_scripts` WHERE `id` = 56099;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`)
VALUES (56099, 0, 2, 15, 56101, 1, 0, 0, 0, 0, 0);
DELETE FROM `gameobject` WHERE `id` = 192124;
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`)
VALUES 
('192124','571','1','8','7209.07','-3596.18','825.86','1.74533','0','0','0.766046','0.642786','300','0','1'),
('192124','571','1','8','7157.87','-3556.37','828.47','0.45728','0','0','0.226653','0.973976','300','0','1'),
('192124','571','1','8','7190.29','-3485.87','834.72','0.45728','0','0','0.226653','0.973976','300','0','1'),
('192124','571','1','8','7226.67','-3441.92','837.543','1.91341','0','0','0.817297','0.576217','300','0','1'),
('192124','571','1','8','7199.65','-3553.19','828.189','4.97657','0','0','0.607814','-0.794079','300','0','1');
-- Spawn brittle revenants (phase 8, lake area)
DELETE FROM `creature` WHERE `id` = 30160;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) 
VALUES
('30160','571','1','8','0','1831','7220.05','-3272.88','837.452','0.750886','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7452.03','-3081.92','837.452','5.68555','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7278.57','-3198.8','837.452','1.48602','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7266.87','-3109.61','837.451','3.05446','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7325.03','-3154.05','837.453','2.89895','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7385.27','-3100.49','837.457','4.75406','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7380.8','-3160.7','837.452','2.14418','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7432.12','-3202.25','837.452','2.19209','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7429.5','-3137.99','837.452','2.52197','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7493.77','-3132.1','837.465','4.20979','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7478.17','-3179.73','837.471','1.57163','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7528.51','-3189.26','837.448','2.75237','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7333.29','-3114.06','837.452','3.77953','90','10','0','12600','0','0','1','0','0','0'),
('30160','571','1','8','0','1831','7260.9','-3159.63','837.452','6.06896','90','10','0','12600','0','0','1','0','0','0');
-- Spawn seething revenants (phase 8, anvil area)
DELETE FROM `creature` WHERE `id` = 30387;
INSERT INTO `creature` (`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`)
VALUES
('30387','571','1','8','0','0','7228.41','-3681.01','823.549','1.27883','180','7','0','12600','0','0','1','0','0','0'),
('30387','571','1','8','0','0','7223.79','-3653.33','823.259','2.24487','180','7','0','12600','0','0','1','0','0','0'),
('30387','571','1','8','0','0','7247.47','-3651.63','822.965','3.68215','180','7','0','12600','0','0','1','0','0','0'),
('30387','571','1','8','0','0','7231.88','-3623.4','823.628','5.62444','180','7','0','12600','0','0','1','0','0','0'),
('30387','571','1','8','0','0','7201.15','-3623.22','823.489','5.63229','180','7','0','12600','0','0','1','0','0','0'),
('30387','571','1','8','0','0','7186.92','-3537.98','826.927','1.20658','180','7','0','12600','0','0','1','0','0','0'),
('30387','571','1','8','0','0','7201.47','-3487.47','832.464','4.3843','180','7','0','12600','0','0','1','0','0','0'),
('30387','571','1','8','0','0','7207.03','-3375.13','845.052','4.94489','180','7','0','12600','0','0','1','0','0','0'),
('30387','571','1','8','0','0','7218.05','-3434.39','837.901','1.38016','180','7','0','12600','0','0','1','0','0','0');
-- Quest 12985 "Forging a Head"  http://www.wowhead.com/quest=12985
-- Dead iron giant scriptname
UPDATE `creature_template` SET `unit_flags` = `unit_flags` &~2, `ScriptName` = 'npc_dead_irongiant' WHERE `entry` = 29914;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` = 56227;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) 
VALUES
(13,56227,18,1,29914);
-- Stormforged ambusher basic loot
DELETE FROM `creature_loot_template` WHERE `entry` = 30208;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`)
VALUES
(30208, 42423, -50, 1, 0, 1, 1),
(30208, 42105, -33, 1, 0, 1, 1),
(30208, 42780,  40, 1, 0, 1, 1),
(30208, 33470,  30, 1, 0, 1, 4),
(30208, 43851,  20, 1, 0, 1, 1);
-- Quest 12987  http://www.wowhead.com/quest=12987 "Mounting Hodir's Helm"
-- Give credit
DELETE FROM `spell_scripts` WHERE `id` = 56278;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) 
VALUES
(56278, 0, 3, 8, 30210, 0, 0, 0, 0, 0, 0);
-- "northern ice spike" in phase 4
UPDATE `gameobject` SET `phaseMask` = 4 WHERE `guid` = 99731;
-- Misc spell_area
-- Lokrila buff 
UPDATE `spell_area` SET `quest_end` = 0 WHERE `area` = 4437 AND `quest_end` = 12983;
-- Apply hibernal cavern phase 4 area aura
DELETE FROM `spell_area` WHERE `spell` = 55858 AND `area` = 4455;
INSERT INTO `spell_area` (`spell`,`area`,`quest_start`,`quest_start_active`,`quest_end`,`aura_spell`,`racemask`,`gender`,`autocast`)
VALUES 
(55858, 4455, 12915, 0, 0, 0, 0, 2, 1);
-- Quest 13006 http://www.wowhead.com/quest=13006 "Polishing the Helm"
-- "polishing the helm" prequest condition
UPDATE `quest_template` SET `PrevQuestId` = 12987 WHERE `entry` = 13006;
-- Helm questrelations
INSERT IGNORE INTO `gameobject_questrelation` VALUES (192080, 13006);
INSERT IGNORE INTO `gameobject_involvedrelation` VALUES (192080, 13006);
-- Spawn helm
DELETE FROM `gameobject` WHERE `id` = 192080;
INSERT INTO `gameobject` (`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`)
VALUES (192080, 571, 1, 4, 7389.34, -2726.2, 875.227, 2.82985, 0, 0, 0.987876, 0.155243, 300, 0, 1);
-- Oil faster respawn
UPDATE `creature` SET `phaseMask` = 4, `spawntimesecs` = 60 WHERE `id` = 30325;
-- Oil loot
UPDATE `creature_template` SET `lootid` = 30325 WHERE `entry` = 30325;
DELETE FROM `creature_loot_template` WHERE `entry` = 30325;
INSERT INTO `creature_loot_template` (`entry`,`item`,`ChanceOrQuestChance`,`lootmode`,`groupid`,`mincountOrRef`,`maxcount`)
VALUES
(30325, 42640, -100, 1, 0, 1, 1),
(30325, 39551,   80, 1, 0, 1, 1),
(30325, 39552,   20, 1, 0, 1, 1);
-- Quest 13011 http://www.wowhead.com/quest=13011 "Jormuttar is Soo Fat..."
-- item target restriction
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 18 AND `SourceEntry` = 42732;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceEntry`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`) 
VALUES
(18, 42732, 24, 1, 30292);
-- spell 56562 script
DELETE FROM `spell_scripts` WHERE `id` = 56562;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) 
VALUES
(56562, 0, 0, 18,     0, 0, 0, 0, 0, 0, 0),
(56562, 0, 0, 15, 56566, 1, 0, 0, 0, 0, 0);
-- "Icy crater" in phase 4
UPDATE `gameobject` SET `phaseMask` = 4 WHERE `guid` = 99730;
-- Lure jormuttar bunny
UPDATE `creature_template` SET `AIName` = 'EventAI' WHERE `entry` = 30366;
DELETE FROM `creature_ai_scripts` WHERE `creature_id` = 30366;
INSERT INTO `creature_ai_scripts` (`id`, `creature_id`, `event_type`, `event_inverse_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action1_type`, `action1_param1`, `action1_param2`, `action1_param3`, `action2_type`, `action2_param1`, `action2_param2`, `action2_param3`, `action3_type`, `action3_param1`, `action3_param2`, `action3_param3`, `comment`)
VALUES
('3036601','30366','1','0','100','0','5000','10000','0','0','12','30340','0','120000','41','1000','0','0','0','0','0','0','Lure Jormuttar');

-- Fix Quest http://www.wowhead.com/quest=13061  Prepare for Glory Spawn Npc faltante
DELETE FROM `creature` WHERE `id` = 29975;
INSERT INTO `creature` (`id`, `map`, `spawnMask`, `phaseMask`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `DeathState`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`) VALUES
(29975, 571, 1, 1, 0, 0, 6925.96, -1533.25, 836.426, 4.56475, 300, 0, 0, 12175, 0, 0, 0, 0, 0, 0);

-- [Quest][4768].sql
-- DB/Quest Fix for Quest 4768 The Dark Rune Tablet
-- Fix for Quest 4768 The dark Rune Tablet
DELETE FROM `gameobject`WHERE `id` = 175385;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (175385, 229, 1, 1, 65.677, -281.64, 93.8493, 3.02213, 0, 0, 0.998217, 0.0596968, 300, 0, 1); 

-- [Quest][5122]The_Medaillon_Of_Faith.sql
-- DB/Quests Fix Quest 5122 The Medaillon of Faith
-- Fix for Quest 5122 The Medaillon of Faith
UPDATE `gameobject_template` SET `flags`=0 WHERE `entry`=176112;

-- [Quest][9375]The_Road_to_Falcon_Watch.sql
-- DB/Quests Fix Quest 9375 The Road to Falcon Watch
-- Fix for Quest 9375 The Road to Falcon Watch
UPDATE `creature_template` SET `faction_A`=14, `faction_H`=14 WHERE `entry`=16967 LIMIT 1;

-- [Quest][9446].sql
-- DB/Quests Fix Quest 9446 NPC's talking draconic
-- Fix for Quest 9446 NPC talking Draconic
UPDATE `script_texts` SET `language`=7 WHERE `npc_entry`=0 AND `entry`=-1800070 LIMIT 1;
UPDATE `script_texts` SET `language`=7 WHERE `npc_entry`=0 AND `entry`=-1800069 LIMIT 1;
UPDATE `script_texts` SET `language`=7 WHERE `npc_entry`=0 AND `entry`=-1800068 LIMIT 1;
UPDATE `script_texts` SET `language`=7 WHERE `npc_entry`=0 AND `entry`=-1800067 LIMIT 1;
UPDATE `script_texts` SET `language`=7 WHERE `npc_entry`=0 AND `entry`=-1800066 LIMIT 1;
UPDATE `script_texts` SET `language`=7 WHERE `npc_entry`=0 AND `entry`=-1800065 LIMIT 1;
UPDATE `script_texts` SET `language`=7 WHERE `npc_entry`=0 AND `entry`=-1800064 LIMIT 1;

-- [Quest][11061].sql
-- DB/Quest Fix Quest 11061 The Plight of a Father
-- Fix Quest 11061 - The Plight of a Father
UPDATE gameobject SET position_x=4020.290039, position_y=5895.250000, position_z=267.871002, orientation=3.860500 WHERE guid=13355;

-- [Quest][11291].sql
-- Fix Taxi from Quest 'To Westguard Keep!' #11291 
SET @Emilune    = 27930; -- Emilune Winterwind
SET @Gossip     = 9618;   -- gossip_menu_id
SET @Quest      = 11291; -- Quest
SET @Spell      = 50028; -- Gryphon Taxi to Westguard Keep
-- Update creature_template
UPDATE `creature_template` SET `AIName` = 'SmartAI', `npcflag` = `npcflag` | 1 WHERE `entry` = @Emilune;
-- gossip_menu_option
DELETE FROM `gossip_menu_option` WHERE `menu_id` = @Gossip;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `action_script_id`, `box_coded`, `box_money`, `box_text`) VALUES 
(@Gossip,0,0,'Please, Take me to Westguard Keep!',1,1,0,0,0,0,0,'');
-- SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` = @Emilune;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(@Emilune,0,0,0,62,0,100,0,@Gossip,0,0,0,11,@Spell,0x02,0,0,0,0,7,0,0,0,0,0,0,0,'on gossip select - cast taxi');
-- conditions
DELETE FROM `conditions` WHERE `SourceGroup` = @Gossip AND `SourceTypeOrReferenceId` = 15;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(15,@Gossip,0,0,28,@Quest,0,0,0,'','show gossip menu option if player has completed 11291');

-- [Quest][11324-11326].sql
-- Quest 11324, 11326 "Alpha Worg"
UPDATE `creature_template` SET `AIName`='SmartAI', `faction_H`=14, `faction_A`=14 WHERE `entry`=24277;
UPDATE `creature` SET `spawndist`=0, `MovementType`=0 WHERE `id`=24210; -- Riven Widow Cocoons disable random movement

DELETE FROM `creature_addon` WHERE `guid`=199999;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES
(199999,1999990,0,0,0,0,'49415 0'); -- Invisibility and waypoint asignment

DELETE FROM `creature` WHERE `id`=24277;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(199999,24277,571,1,1,22233,0,2461.043,-3099.657,141.533,5.812,300,0,0,13936,0,0,2,0,0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=24277;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(24277,0,0,0,0,0,100,0,2000,4000,10000,12000,11,50046,0,0,0,0,0,2,0,0,0,0,0,0,0,'Use Gnaw Bone'),
(24277,0,1,0,0,0,100,0,1000,3000,15000,18000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,'Use Rend'),
(24277,0,2,0,0,0,100,0,1500,2500,4000,6000,11,31279,0,0,0,0,0,2,0,0,0,0,0,0,0,'Use Swipe'),
(24277,0,3,0,0,0,100,0,10000,12000,20000,25000,11,6749,0,0,0,0,0,2,0,0,0,0,0,0,0,'Use Wide Swipe'),
(24277,0,4,5,2,0,100,0x01,0,50,0,0,3,0,26791,0,0,0,0,1,0,0,0,0,0,0,0,'Below 50% transform to worgen model'),
(24277,0,5,0,61,0,100,0,0,0,0,0,1,0,0,0,0,0,0,7,0,0,0,0,0,0,0,'Say text Garwal');

DELETE FROM `waypoint_data` WHERE `id`=1999990;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(1999990,1,2461.043,-3099.657,141.533,0,0,0,100,0),
(1999990,2,2502.133,-3097.822,134.418,0,0,0,100,0),
(1999990,3,2559.702,-3097.267,121.556,0,0,0,100,0),
(1999990,4,2622.817,-3088.243,120.314,0,0,0,100,0),
(1999990,5,2638.738,-3096.804,121.635,0,0,0,100,0),
(1999990,6,2696.031,-3118.550,110.453,0,0,0,100,0),
(1999990,7,2744.101,-3110.267,115.296,0,0,0,100,0),
(1999990,8,2774.326,-3109.235,111.222,0,0,0,100,0),
(1999990,9,2797.473,-3106.683,110.129,0,0,0,100,0),
(1999990,10,2831.518,-3105.365,100.868,0,0,0,100,0),
(1999990,11,2847.851,-3089.628,91.186,0,0,0,100,0),
(1999990,12,2874.736,-3063.742,85.386,0,0,0,100,0),
(1999990,13,2872.254,-3045.130,82.085,0,0,0,100,0),
(1999990,14,2867.529,-3020.512,84.268,0,0,0,100,0),
(1999990,15,2811.413,-3018.185,88.837,0,0,0,100,0),
(1999990,16,2772.952,-3014.391,92.935,0,0,0,100,0),
(1999990,17,2700.462,-2996.456,92.247,0,0,0,100,0),
(1999990,18,2666.411,-2986.375,96.447,0,0,0,100,0),
(1999990,19,2649.578,-2979.369,95.366,0,0,0,100,0),
(1999990,20,2598.768,-2987.893,109.434,0,0,0,100,0),
(1999990,21,2560.210,-2988.716,111.262,0,0,0,100,0),
(1999990,22,2526.068,-3031.698,121.382,0,0,0,100,0),
(1999990,23,2501.948,-3041.872,126.281,0,0,0,100,0),
(1999990,24,2477.311,-3053.944,138.013,0,0,0,100,0),
(1999990,25,2467.604,-3071.109,141.345,0,0,0,100,0);

DELETE FROM `creature_text` WHERE `entry`=24277;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(24277,0,0,'Enough of this charade!',1,0,100,0,0,0,'Garwal morph text');

DELETE FROM `spell_scripts` WHERE `id`=50103;
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(50103,0,0,14,43060,1,0,0,0,0,0); -- Remove Eyes of the Eagle on quest turn in


DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (43682,50104);
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(43682,43060,1,'Apply Eyes of the Eagle'),
(50104,50103,1,'Remove Eyes of the Eagle');

UPDATE `quest_template` SET `SrcSpell`=43682 WHERE `entry` IN (11324,11326);

-- [Quest][11895-11896-11907-11788].sql
-- Quest 11895 "Master the Storm", 
-- Quest 11896 "Weakness to Lightning", 
-- Quest 11907 "The Sub-Chieftains" 
-- Quest 11788 "Lefty Loosey, Righty Tighty"
DELETE FROM `creature` WHERE `id`=26048;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`DeathState`,`MovementType`,`npcflag`,`unit_flags`,`dynamicflags`) VALUES
(107478,26048,571,1,1,16988,0,3410.110,4128.981,18.054,5.699,60,0,0,8982,3155,0,0,0,0,0);

DELETE FROM `gameobject` WHERE `id` IN (188109,187987);
INSERT INTO `gameobject` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`position_x`,`position_y`,`position_z`,`orientation`,`rotation0`,`rotation1`,`rotation2`,`rotation3`,`spawntimesecs`,`animprogress`,`state`) VALUES
(188898,187987,571,1,1,3793.746,4805.559,-12.185,5.667,0,0,0,1,300,100,1),
(188899,188109,571,1,1,3791.950,4804.803,-12.158,4.571,0,0,0,1,300,100,1);

UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=26048;
UPDATE `creature_template` SET `unit_flags`=4, `AIName`='SmartAI' WHERE `entry`=26045;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25752;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25753;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25758;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=25792;

DELETE FROM `npc_spellclick_spells` WHERE `npc_entry`=26048;
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(26048,74772,11895,1,0,0,0,0,0);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (26048,2604800,26045,25752,25753,25758,25792);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(26048,0,0,0,8,0,100,0,74772,0,0,0,80,2604800,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spellhit start script'),
(2604800,9,0,0,60,0,100,0,0,0,0,0,12,26045,1,60000,0,1,0,8,0,0,0,3399.917,4135.566,18.054,5.699, 'Summon Storm Tempest'),
(2604800,9,1,0,60,0,100,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Despawn'),
(26045,0,0,0,25,0,100,0,0,0,0,0,11,35487,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On summon Storm Tempest cast Lightning Cloud'),
(26045,0,1,0,4,0,100,0,0,0,60000,60000,1,0,0,0,0,0,0,2,0,0,0,0,0,0,0, 'On aggro Storm Tempest say text'),
(26045,0,2,0,0,0,100,0,0,0,4000,5000,11,15659,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Storm Tempest cast Chain Lightning'),
(26045,0,3,0,0,0,50,0,0,0,3000,4000,11,31272,0,0,0,0,0,2,0,0,0,0,0,0,0, 'Storm Tempest cast Wind Shock'),
(26045,0,4,0,6,0,100,0,0,0,0,0,85,46424,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On death apply Master the Storm'),
(25752,0,0,0,8,0,100,0,46432,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spellhit set phase 1'),
(25752,0,1,0,6,1,100,0,0,0,0,0,33,26082,0,0,0,0,0,1,0,0,0,0,0,0,0, 'If killed in phase 1 give quest credit'),
(25752,0,2,0,25,0,100,0,0,0,0,0,28,46432,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On respawn remove aura'),
(25753,0,0,0,8,0,100,0,46432,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spellhit set phase 1'),
(25753,0,1,0,6,1,100,0,0,0,0,0,33,26082,0,0,0,0,0,1,0,0,0,0,0,0,0, 'If killed in phase 1 give quest credit'),
(25753,0,2,0,25,0,100,0,0,0,0,0,28,46432,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On respawn remove aura'),
(25758,0,0,0,8,0,100,0,46432,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spellhit set phase 1'),
(25758,0,1,0,6,1,100,0,0,0,0,0,33,26082,0,0,0,0,0,1,0,0,0,0,0,0,0, 'If killed in phase 1 give quest credit'),
(25758,0,2,0,25,0,100,0,0,0,0,0,28,46432,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On respawn remove aura'),
(25792,0,0,0,8,0,100,0,46432,0,0,0,22,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On spellhit set phase 1'),
(25792,0,1,0,6,1,100,0,0,0,0,0,33,26082,0,0,0,0,0,1,0,0,0,0,0,0,0, 'If killed in phase 1 give quest credit'),
(25792,0,2,0,25,0,100,0,0,0,0,0,28,46432,0,0,0,0,0,1,0,0,0,0,0,0,0, 'On respawn remove aura');

DELETE FROM `creature_text` WHERE `entry`=26045;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(26045,0,0,'You will not defeat me, puny $R!',0,0,100,0,0,0, 'Storm Tempest text');

DELETE FROM `spell_scripts` WHERE `id` IN (46550);
INSERT INTO `spell_scripts` (`id`,`effIndex`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(46550,0,0,14,46424,0,0,0,0,0,0);

-- [Quest][12548][12797].sql
-- Fix Teleport between Sholazar Basin and Un'Goro Crater
-- in conection with quests 'The Etymidian' (12548) and 'Back Through the Waygate' (12797)
DELETE FROM `areatrigger_teleport` WHERE `id` IN (5046,5047);
INSERT INTO `areatrigger_teleport` VALUES
(5046,'Teleport from Sholazar to Un`Goro',1,-6164.0117,-1329.0784,-170.5762,2.378), -- Sholazar Waygate
(5047,'Teleport from Un`Goro to Sholazar',571,4892.8154,5179.8438,-88.5301,0.376); -- Un`Goro Waygate 

-- [Quest][12652].sql
-- DB/Quest Fix Quest 12652 Availability for Horde
-- Quest 12652 Feedin' Da Goolz
UPDATE `quest_template` SET `RequiredRaces = 0` WHERE `entry` = '12652';

-- [Quest][12998].sql
-- QUEST 12998 "The Heart of the Storm"
UPDATE `gameobject_template` SET `AIName`='SmartGameObjectAI' WHERE `entry`=192181;
UPDATE `creature_template` SET `AIName`='SmartAI', `faction_H`=1954, `faction_A`=1954, `unit_flags`=768, `equipment_id`=749, `flags_extra`=2 WHERE `entry`=30299;

-- Spawn GO
DELETE FROM `gameobject` WHERE `id` = 192181;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(192181,571,1,1,7308.97,-727.868,791.609,1.56851,0,0,0.706299,0.707914,300,0,1);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (30299,3029900,192181,19218100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
-- Overseer Narvir script
(30299,0,0,0,25,0,100,0,0,0,0,0,80,3029900,0,2,0,0,0,1,0,0,0,0,0,0,0, 'On summon Overseer Narvir start script'),
(3029900,9,0,0,0,0,100,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Set react passive'),
(3029900,9,1,0,0,0,100,0,500,500,0,0,69,0,0,0,0,0,0,8,0,0,0,7313.045,-726.853,791.610,0, 'Walk to the Heart of the Storm'),
(3029900,9,2,0,0,0,100,0,6500,6500,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,2.437, 'Set orientation'),
(3029900,9,3,0,0,0,100,0,2000,2000,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Overseer Narvir say text 0'),
(3029900,9,4,0,0,0,100,0,5000,5000,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Overseer Narvir say text 1'),
(3029900,9,5,0,0,0,100,0,6000,6000,0,0,66,0,0,0,0,0,0,8,0,0,0,0,0,0,3.334, 'Set orientation'),
(3029900,9,6,0,0,0,100,0,500,500,0,0,17,133,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Loot the heart'),
(3029900,9,7,0,0,0,100,0,5000,5000,0,0,17,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Stop looting'),
(3029900,9,8,0,0,0,100,0,1500,1500,0,0,5,463,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Disappear emote'),
(3029900,9,9,0,0,0,100,0,500,500,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Despawn'),
-- Heart of the Storm script
(192181,1,0,0,64,0,100,0x01,0,0,0,0,80,19218100,0,2,0,0,0,1,0,0,0,0,0,0,0, 'On use start script'),
(19218100,9,0,0,0,0,100,0,1000,1000,0,0,12,30299,1,60000,0,0,0,8,0,0,0,7312.130,-710.919,791.610,4.643, 'Summon Overseer Narvir'),
(19218100,9,1,0,0,0,100,0,0,0,0,0,75,56485,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Cyclone the invoker'),
(19218100,9,2,0,0,0,100,0,27000,27000,0,0,33,30299,0,0,0,0,0,7,0,0,0,0,0,0,0, 'Give quest credit');

DELETE FROM `creature_text` WHERE `entry`=30299;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(30299,0,0,'You didn\'t think that I was going to let you walk in here and take the Heart of the Storm, did you?',0,0,100,6,0,0,'Narvir text 0'),
(30299,1,0,'You may have killed Valduran, but that will not stop me from completing the colossus.',0,0,100,274,0,0,'Narvir text 1');

-- [Quest]Argent_Tournament.sql
DELETE FROM `spell_script_names` WHERE `spell_id` IN (62960,62575,62544,62863);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
('62960', 'spell_tournament_charge'),
('62575', 'spell_tournament_shield'),
('62544', 'spell_tournament_melee'),
('62863', 'spell_tournament_duel');




