EverGrandeCity_Hall1_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_Hall1_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_Hall1_OnWarp
	.byte 0

EverGrandeCity_Hall1_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall1_EventScript_TurnPlayerNorth
	.2byte 0

EverGrandeCity_Hall1_OnLoad:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_Hall1_EventScript_Doors
	.2byte 0

EverGrandeCity_Hall1_EventScript_TurnPlayerNorth::
	
	call EverGrandeCity_Hall1_EventScript_Doors
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end
	

    
EverGrandeCity_Hall1_EventScript_Doors::
	setvar VAR_ELITE_4_STATE, 0
	setvar VAR_TEMP_2, 0
	setflag FLAG_IN_ELITE_FOUR
	call_if_unset FLAG_DEFEATED_ELITE_4_SIDNEY, EverGrandeCity_Hall1_EventScript_Heeb_Door
	call_if_unset FLAG_DEFEATED_ELITE_4_PHOEBE, EverGrandeCity_Hall1_EventScript_Fluffy_Door
	call_if_unset FLAG_DEFEATED_ELITE_4_GLACIA, EverGrandeCity_Hall1_EventScript_Val_Door
	call_if_unset FLAG_DEFEATED_ELITE_4_DRAKE, EverGrandeCity_Hall1_EventScript_Duckie_Door
	call_if_unset FLAG_BADGE05_GET, EverGrandeCity_Hall1_EventScript_Moshi_Door
	call_if_unset FLAG_BADGE06_GET, EverGrandeCity_Hall1_EventScript_Meep_Door
	call_if_unset FLAG_BADGE07_GET, EverGrandeCity_Hall1_EventScript_Mocha_Door
	call_if_unset FLAG_BADGE08_GET, EverGrandeCity_Hall1_EventScript_Latte_Door

	call_if_eq VAR_TEMP_2, 0, EverGrandeCity_Hall1_EventScript_Final_Door

    return

    
EverGrandeCity_Hall1_EventScript_Heeb_Door::
	setmetatile 3, 1 METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 3, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	addvar VAR_TEMP_2, 1
	return
    
EverGrandeCity_Hall1_EventScript_Fluffy_Door::
	setmetatile 8, 1 METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 8, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	addvar VAR_TEMP_2, 1
	return
EverGrandeCity_Hall1_EventScript_Val_Door::
	setmetatile 13, 1 METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 13, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	addvar VAR_TEMP_2, 1
	return
EverGrandeCity_Hall1_EventScript_Duckie_Door::
	setmetatile 18, 1 METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 18, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	addvar VAR_TEMP_2, 1
	return
EverGrandeCity_Hall1_EventScript_Moshi_Door::
	setmetatile 28, 1 METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 28, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	addvar VAR_TEMP_2, 1
	return
EverGrandeCity_Hall1_EventScript_Meep_Door::
	setmetatile 33, 1 METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 33, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	addvar VAR_TEMP_2, 1
	return
EverGrandeCity_Hall1_EventScript_Mocha_Door::
	setmetatile 38, 1 METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 38, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	addvar VAR_TEMP_2, 1
	return
EverGrandeCity_Hall1_EventScript_Latte_Door::
	setmetatile 43, 1 METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 43, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE
	addvar VAR_TEMP_2, 1
	return
EverGrandeCity_Hall1_EventScript_Final_Door::
	setmetatile 23, 1, METATILE_EliteFour_OpenDoor_Frame, FALSE
	setmetatile 23, 2, METATILE_EliteFour_OpenDoor_Opening, FALSE	
	return
