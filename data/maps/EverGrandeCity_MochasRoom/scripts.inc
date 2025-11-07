EverGrandeCity_MochasRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_MochasRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_MochasRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_MochasRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_MochasRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_MochasRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_MochasRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_MochasRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_MochasRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_MochasRoom_OnLoad:
	call_if_set FLAG_BADGE07_GET, EverGrandeCity_MochasRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_MochasRoom_EventScript_CloseDoor
	end

EverGrandeCity_MochasRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_MochasRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_MochasRoom_EventScript_Mocha::
	lock
	faceplayer
	goto_if_set FLAG_BADGE07_GET, EverGrandeCity_MochasRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_MochasRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MOCHA, EverGrandeCity_MochasRoom_Text_Defeat
	goto EverGrandeCity_MochasRoom_EventScript_Defeated
	end

EverGrandeCity_MochasRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_MochasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_MochasRoom_EventScript_Defeated::
	setflag FLAG_BADGE07_GET
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_MochasRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	msgbox EverGrandeCity_MochasRoom_Text_ReceivedBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	special HealPlayerParty
	release
	end

EverGrandeCity_MochasRoom_Text_IntroSpeech:
	.string "INTRO.$"

EverGrandeCity_MochasRoom_Text_Defeat:
	.string "Ah! I got completely crumpled!$"

EverGrandeCity_MochasRoom_Text_PostBattleSpeech:
	.string "Let's both do our best in all our future\n"
	.string "BATTLES!$"

EverGrandeCity_MochasRoom_Text_ReceivedBadge:
	.string "{PLAYER} received the NORMAL BADGE\n"
	.string "from MOCHA.$"
