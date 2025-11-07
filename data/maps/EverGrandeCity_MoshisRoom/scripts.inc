EverGrandeCity_MoshisRoom_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EverGrandeCity_MoshisRoom_OnFrame
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_MoshisRoom_OnLoad
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_SidneysRoom_OnWarp
	.byte 0

@ Unused, Drake uses Sidneys identical OnWarp for some reason
EverGrandeCity_MoshisRoom_OnWarp:
	map_script_2 VAR_TEMP_1, 0, EverGrandeCity_MoshisRoom_EventScript_PlayerTurnNorth
	.2byte 0

EverGrandeCity_MoshisRoom_EventScript_PlayerTurnNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

EverGrandeCity_MoshisRoom_OnFrame:
	map_script_2 VAR_ELITE_4_STATE, 0, EverGrandeCity_MoshisRoom_EventScript_WalkInCloseDoor
	.2byte 0

EverGrandeCity_MoshisRoom_EventScript_WalkInCloseDoor::
	lockall
	call PokemonLeague_EliteFour_EventScript_WalkInCloseDoor
	setvar VAR_ELITE_4_STATE, 1
	releaseall
	end

EverGrandeCity_MoshisRoom_OnLoad:
	call_if_set FLAG_BADGE05_GET, EverGrandeCity_MoshisRoom_EventScript_ResetAdvanceToNextRoom
	call_if_eq VAR_ELITE_4_STATE, 1, EverGrandeCity_MoshisRoom_EventScript_CloseDoor
	end

EverGrandeCity_MoshisRoom_EventScript_ResetAdvanceToNextRoom::
	call PokemonLeague_EliteFour_EventScript_ResetAdvanceToNextRoom
	return

EverGrandeCity_MoshisRoom_EventScript_CloseDoor::
	call PokemonLeague_EliteFour_EventScript_CloseDoor
	return

EverGrandeCity_MoshisRoom_EventScript_Moshi::
	lock
	faceplayer
	goto_if_set FLAG_BADGE05_GET, EverGrandeCity_MoshisRoom_EventScript_PostBattleSpeech
	playbgm MUS_ENCOUNTER_ELITE_FOUR, FALSE
	msgbox EverGrandeCity_MoshisRoom_Text_IntroSpeech, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_DUCKIE, EverGrandeCity_MoshisRoom_Text_Defeat
	goto EverGrandeCity_MoshisRoom_EventScript_Defeated
	end

EverGrandeCity_MoshisRoom_EventScript_PostBattleSpeech::
	msgbox EverGrandeCity_MoshisRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	release
	end

EverGrandeCity_MoshisRoom_EventScript_Defeated::
	setflag FLAG_BADGE05_GET
	call PokemonLeague_EliteFour_SetAdvanceToNextRoomMetatiles
	msgbox EverGrandeCity_MoshisRoom_Text_PostBattleSpeech, MSGBOX_DEFAULT
	msgbox EverGrandeCity_MoshisRoom_Text_ReceivedBadge, MSGBOX_DEFAULT
	call Common_EventScript_PlayGymBadgeFanfare
	special HealPlayerParty
	release
	end

EverGrandeCity_MoshisRoom_Text_IntroSpeech:
	.string "INTRO.$"
EverGrandeCity_MoshisRoom_Text_Defeat:
.string "DEFEAT.$"

EverGrandeCity_MoshisRoom_Text_PostBattleSpeech:
.string "POST BATTLE.$"

EverGrandeCity_MoshisRoom_Text_ReceivedBadge:
	.string "{PLAYER} received the GHOST BADGE\n"
	.string "from MOSHI.$"
