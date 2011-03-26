-- Fix Explosive shot from spd scaling
DELETE FROM `spell_bonus_data` WHERE `entry`='53352';
INSERT INTO `spell_bonus_data`(`entry`,`direct_bonus`,`dot_bonus`,`ap_bonus`,`ap_dot_bonus`,`comments`) VALUES ( '53352','0','0','0.14','0','Hunter - Explosive Shot (triggered)');