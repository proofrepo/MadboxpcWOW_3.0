-- DB/Quest Fix Quest 12652 Availability for Horde
-- Quest 12652 Feedin' Da Goolz
UPDATE `quest_template` SET `RequiredRaces = 0` WHERE `entry` = '12652';