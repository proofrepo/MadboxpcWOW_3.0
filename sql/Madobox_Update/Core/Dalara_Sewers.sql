UPDATE `gameobject_template` SET `flags` = '36' WHERE `entry` =192642;
UPDATE `gameobject_template` SET `flags` = '36' WHERE `entry` =192643;
UPDATE `battleground_template` SET `MinPlayersPerTeam` = '0', `MaxPlayersPerTeam` = '2' WHERE `battleground_template`.`id` =10;
DELETE FROM `disables` WHERE `entry` = 10;