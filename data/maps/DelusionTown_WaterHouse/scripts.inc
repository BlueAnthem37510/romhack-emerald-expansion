.set LOCALID_VI, 1
.set LOCALID_MIMI, 2

DelusionTown_WaterHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DelusionTown_WaterHouse_OnTransition
	.byte 0

DelusionTown_WaterHouse_OnTransition: 
	goto_if_eq VAR_DELUSION_TOWN_STATE, 0, DelusionTown_WaterHouse_EventScript_HideMimi
	addobject LOCALID_MIMI 
	setobjectxy LOCALID_MIMI, 5, 4
	end

DelusionTown_WaterHouse_EventScript_HideMimi::
	setflag FLAG_HIDE_MIMI_WATER_HOUSE
	end
DelusionTown_WaterHouse_EventScript_Mimi::
	lock
	faceplayer	
	msgbox DelusionTown_WaterHouse_Text_Mimi, MSGBOX_AUTOCLOSE
	end




DelusionTown_WaterHouse_EventScript_ViAsk::
	lock
	faceplayer	
	goto_if_eq VAR_DELUSION_TOWN_STATE, 0, DelusionTown_WaterHouse_EventScript_ViStuck
	goto_if_eq VAR_DELUSION_TOWN_STATE, 1, DelusionTown_WaterHouse_EventScript_ViWaitForMimi
	goto_if_eq VAR_DELUSION_TOWN_STATE, 2, DelusionTown_WaterHouse_EventScript_ViWithMimi
	goto_if_eq VAR_DELUSION_TOWN_STATE, 3, DelusionTown_WaterHouse_EventScript_AfterBattle
	release
	end

DelusionTown_WaterHouse_EventScript_ViStuck::
	lock
	faceplayer
	msgbox DelusionTown_WaterHouse_Text_ViStuck, MSGBOX_DEFAULT
	setvar VAR_DELUSION_TOWN_STATE, 1
	release
	end

DelusionTown_WaterHouse_EventScript_ViWaitForMimi::
	msgbox DelusionTown_WaterHouse_Text_ViWaitForMimi
	release
	end

DelusionTown_WaterHouse_EventScript_ViDefeated::
	lock
	faceplayer
	msgbox DelusionTown_WaterHouse_Text_ViDefeated, MSGBOX_DEFAULT
	giveitem ITEM_STORAGE_KEY
	setvar VAR_DELUSION_TOWN_STATE, 3
	release
	end

DelusionTown_WaterHouse_EventScript_ViWithMimi::
	msgbox DelusionTown_WaterHouse_Text_ViWithMimi, MSGBOX_DEFAULT
	turnobject LOCALID_MIMI, DIR_WEST
	msgbox DelusionTown_WaterHouse_Text_MimiSuggestBattle, MSGBOX_DEFAULT
	turnobject LOCALID_VI, DIR_EAST
	msgbox DelusionTown_WaterHouse_Text_ViAgreeBattle, MSGBOX_DEFAULT
	
	call_if_eq VAR_FACING, DIR_SOUTH, DelusionTown_WaterHouse_EventScript_TurnSouth
	call_if_eq VAR_FACING, DIR_NORTH, DelusionTown_WaterHouse_EventScript_TurnNorth
	call_if_eq VAR_FACING, DIR_WEST, DelusionTown_WaterHouse_EventScript_TurnWest
	call_if_eq VAR_FACING, DIR_EAST, DelusionTown_WaterHouse_EventScript_TurnEast
	goto DelusionTown_WaterHouse_EventScript_ViBattle
	release
	end

DelusionTown_WaterHouse_EventScript_TurnSouth::
	turnobject LOCALID_VI, DIR_NORTH
	return
DelusionTown_WaterHouse_EventScript_TurnNorth::
	turnobject LOCALID_VI, DIR_SOUTH
	return
DelusionTown_WaterHouse_EventScript_TurnWest::
	turnobject LOCALID_VI, DIR_EAST
	return
DelusionTown_WaterHouse_EventScript_TurnEast::
	turnobject LOCALID_VI, DIR_WEST
	return
DelusionTown_WaterHouse_EventScript_ViBattle::
	trainerbattle_two_trainers TRAINER_MIMI_1, DelusionTown_WaterHouse_Text_MimiDefeat, TRAINER_VI_1, DelusionTown_WaterHouse_Text_ViDefeat
	switch VAR_RESULT
	case 1, DelusionTown_WaterHouse_EventScript_ViDefeated
DelusionTown_WaterHouse_EventScript_AfterBattle::
	msgbox DelusionTown_WaterHouse_Text_ViAfterBattle
	release
	end

DelusionTown_WaterHouse_Text_ViStuck:
	.string "VI: Hi, I'm kinda stuck on this ISLAND.\p"
	.string "Can you let the LIFEGUARD know that\n"
	.string "I'm here?\p"
	.string	"I'll even give you this key I\n"
	.string "found if you do.\p"
	.string "MIMI will definitely be on the BEACH!$"

DelusionTown_WaterHouse_Text_ViWaitForMimi:
	.string "Don't forget to let MIMI know I'm here!$"

DelusionTown_WaterHouse_Text_Mimi:
	.string "MIMI: I'm always happy to help VI when\n"
	.string "they're in trouble.$"

DelusionTown_WaterHouse_Text_ViWithMimi:
	.string "VI: Thank you for getting MIMI, here's\n"
	.string "the key as promised.$"
DelusionTown_WaterHouse_Text_MimiSuggestBattle:
	.string "MIMI: Hold on, how about we all have a\n"
	.string "BATTLE first while we're here?$"
DelusionTown_WaterHouse_Text_ViAgreeBattle:
	.string "VI: That's a fun idea MIMI!$"
	
DelusionTown_WaterHouse_Text_ViIntro:
.string "Prepare to face defeat!$"

DelusionTown_WaterHouse_Text_ViDefeated:
	.string "VI: Well you've definitely earned this\n"
	.string "key, here you go.$"
DelusionTown_WaterHouse_Text_ViAfterBattle:
	.string "It's always fun BATTLING someone new\n"
	.string "thanks again!$"

DelusionTown_WaterHouse_Text_MimiDefeat:
	.string "Thanks for the fight!$"
DelusionTown_WaterHouse_Text_ViDefeat:
	.string "Your BATTLE style is most interesting.$"

