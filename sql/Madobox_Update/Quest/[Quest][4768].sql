-- DB/Quest Fix for Quest 4768 The Dark Rune Tablet
-- Fix for Quest 4768 The dark Rune Tablet
DELETE FROM `gameobject`WHERE `id` = 175385;
INSERT INTO `gameobject` (`id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES (175385, 229, 1, 1, 65.677, -281.64, 93.8493, 3.02213, 0, 0, 0.998217, 0.0596968, 300, 0, 1); 
