-- Update Position Npcs.
UPDATE `creature` SET `position_x` = `position_x` + 400  WHERE `map` = 616;
UPDATE `gameobject` SET `position_x` = `position_x` + 400 WHERE `map` = 616;
-- Spawns
DELETE FROM `creature` WHERE `id` IN (30090, 22517);
-- Spawn Focusing Iris (Normal/Heroic)
DELETE FROM `gameobject` WHERE `id` IN (193958, 193960) AND `map` = 616;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`)
VALUES 
(193958, 616, 1, 1, 1154.35, 1300.87, 266.172, 5.34356, 0, 0, 0, 1, 180, 0, 1),
(193960, 616, 2, 1, 1154.35, 1300.87, 266.172, 5.34356, 0, 0, 0, 1, 180, 0, 1);
-- Update Stat Spell Wyrmrest skytalon
UPDATE `creature_template`
SET `spell1` = 56091, -- Flammenstachel
`spell2` = 56092, -- Flammenhuelle
`spell3` = 57090, -- Wiederbeleben
`spell4` = 57143, -- Explosion des Lebens
`spell5` = 57108, -- Flammenschild
`spell6` = 57092  -- Blitztempo
WHERE `entry` IN (30161, 31752);
-- Update Malygos (BOSS)
UPDATE `creature` SET `spawndist` = 0,`MovementType` = 0 WHERE `id` = 28859;
UPDATE `creature_template` SET `difficulty_entry_1` = 31734, `unit_flags` = 770,`ScriptName` = 'boss_malygos' WHERE `entry` = 28859;
UPDATE `creature_template` SET `name` = 'Malygos (1)',`speed_run` = 2.85714, `speed_walk` = 4, `unit_class` = 2, `unit_flags` = 770, `flags_extra` = 1 WHERE `entry` = 31734;
-- Nexus lord
UPDATE `creature_template` SET `ScriptName` = 'npc_nexus_lord' WHERE `entry` = 30245;
-- Scion of eternity
UPDATE `creature_template` SET `ScriptName` = 'npc_scion_of_eternity' WHERE `entry` = 30249;
-- Hover discs
UPDATE `creature_template` SET `ScriptName` = 'npc_hover_disc' WHERE `entry` = 30248;
UPDATE `creature_template` SET `VehicleId` = 283 WHERE `entry` = 31748;
UPDATE `creature_template` SET `VehicleId` = 223 WHERE `entry` = 31749;
-- Portal (malygos)
UPDATE `creature_template` SET `unit_flags` = 770, `flags_extra` = 2 WHERE `entry` = 30118;
-- Ignore threat
UPDATE `creature_template` SET `unit_flags` = 768 WHERE `entry` IN (30234, 31748);
-- Power spark
UPDATE `creature_template` SET `ScriptName` = 'npc_power_spark' WHERE `entry` = 30084;
-- Vortex
UPDATE `creature_template` SET `ScriptName` = 'npc_vortex_vehicle' WHERE `entry` = 30090;
-- Focusing iris
UPDATE `gameobject_template` SET `ScriptName` = 'go_focusing_iris' WHERE `entry` IN (193958, 193960);
-- Can fly
UPDATE `creature_template` SET `InhabitType` = 7 WHERE `entry` IN (28859, 30090, 30118, 30234, 30248, 30592, 31734, 31748, 31749);
-- Immunitys
-- Malygos, Nexus lord, Scion of eternity
UPDATE `creature_template` SET `mechanic_immune_mask` = 650854395 WHERE `entry` IN (28859, 31734, 30245, 31750, 30249, 31751);
-- Instance Script
UPDATE `instance_template` SET `script` = 'instance_eye_of_eternity', `allowMount` = 0 WHERE `map` = 616;
-- Spell targets
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 13 AND `SourceEntry` IN (56505, 56152, 59099);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceEntry`,`ConditionTypeOrReference`,`ConditionValue1`,`ConditionValue2`) 
VALUES 
(13, 56152, 18, 1, 28859), -- power spark (malygos)
(13, 56505, 18, 1, 30334), -- surge of power (deep breath)
(13, 59099, 18, 1, 0); -- destroy platform event
-- Vehicle onclick
DELETE FROM `npc_spellclick_spells` WHERE `npc_entry` IN (30234);
INSERT INTO `npc_spellclick_spells` (`npc_entry`,`spell_id`,`quest_start`,`quest_start_active`,`quest_end`,`cast_flags`,`aura_required`,`aura_forbidden`,`user_type`) VALUES
(30234,46598,0,0,0,1,0,0,0); -- malygos player disc

