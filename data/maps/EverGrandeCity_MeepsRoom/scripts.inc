EverGrandeCity_MeepsRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_MeepsRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_MeepsRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_MeepsRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_MeepsRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_MeepsRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_MeepsRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_MeepsRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_MeepsRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_MeepsRoom_OnLoad:
	call_if_set FLAG_BADGE06_GET, EverGrandeCity_MeepsRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_MeepsRoom_EventScript_CloseDoor
	end

EverGrandeCity_MeepsRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_MeepsRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_MeepsRoom_EventScript_Meep::
	lock
	faceplayer
	goto_if_set FLAG_BADGE06_GET, EverGrandeCity_MeepsRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_MeepsRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_MEEP, EverGrandeCity_MeepsRoom_Text_Defeat
	goto EverGrandeCity_MeepsRoom_EventScript_Defeated
	end

EverGrandeCity_MeepsRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_MeepsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_MeepsRoom_EventScript_Defeated::
	setflag FLAG_BADGE06_GET
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_MeepsRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT	
	msgbox EverGrandeCity_MeepsRoom_Text_ReceivedBadge, MSGBOX_DEFAULT	
	call Common_EventScript_PlayGymBadgeFanfare
	special HealPlayerParty
	release
	end

EverGrandeCity_MeepsRoom_Text_IntroSpeech:
	.string "Hi there! Welcome to my neck of the\n"
	.string "WOODS, hopefully my GREEN team won't\l"
	.string "LEAF you in the dirt.\p"
	.string "Regardless of who wins and loses I'm\n"
	.string "sure this BATTLE will be FRUITFUL for\l"
	.string "the both of us!$"

EverGrandeCity_MeepsRoom_Text_Defeat:
	.string "I hope you learned something from our\n"
	.string "battle, and continue to GROW.$"

EverGrandeCity_MeepsRoom_Text_PostBattleSpeech:
	.string "I'm ROOTING for you to win!$"

EverGrandeCity_MeepsRoom_Text_ReceivedBadge:
	.string "{PLAYER} received the PETAL BADGE\n"
	.string "from MEEP.$"
