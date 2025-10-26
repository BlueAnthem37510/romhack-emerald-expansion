.set LOCALID_MIMI, 1
.set LOCALID_KATE, 6

DelusionTown_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, DelusionTown_OnLoad
	.byte 0

DelusionTown_OnLoad:
	call_if_set FLAG_USED_STORAGE_KEY, DelusionTown_EventScript_UnlockDoor
	end

DelusionTown_EventScript_PlayerHouseSign::
	msgbox DelusionTown_Text_PlayerHouseSign, MSGBOX_SIGN
	end

DelusionTown_EventScript_ClosedSign::
	msgbox DelusionTown_Text_ClosedSign, MSGBOX_SIGN
	end
DelusionTown_EventScript_CantReadSign::
	msgbox DelusionTown_Text_CantReadSign, MSGBOX_SIGN
	end
DelusionTown_EventScript_Door::
	lockall
	goto_if_set FLAG_USED_STORAGE_KEY, DelusionTown_EventScript_DoorIsUnlocked
	checkitem ITEM_STORAGE_KEY
	goto_if_eq VAR_RESULT, FALSE, DelusionTown_EventScript_LockedDoor
	msgbox DelusionTown_Text_UnlockDoor, MSGBOX_DEFAULT
	playse SE_PIN
	setflag FLAG_USED_STORAGE_KEY
	setflag FLAG_HIDE_VI_WATER_HOUSE
	setflag FLAG_HIDE_MIMI_WATER_HOUSE
	clearflag FLAG_HIDE_VI_MIMI
	setvar VAR_DELUSION_TOWN_STATE, 4
	call DelusionTown_EventScript_UnlockDoor
	special DrawWholeMapView
	releaseall
	end
DelusionTown_EventScript_DoorIsUnlocked::
	msgbox DelusionTown_Text_Unlocked, MSGBOX_SIGN
	end
DelusionTown_EventScript_UnlockDoor::
	setmetatile 12, 5, METATILE_Petalburg_Door_BirchsLab, TRUE
	return
DelusionTown_EventScript_LockedDoor::
	msgbox DelusionTown_Text_LockedDoor, MSGBOX_SIGN
	end

DelusionTown_EventScript_Azumarill::
	lock
	faceplayer
	msgbox DelusionTown_Text_Azumarill, MSGBOX_NPC
	release
	end
DelusionTown_EventScript_Tuber::
	lock
	faceplayer
	msgbox DelusionTown_Text_Tuber, MSGBOX_NPC
	release
	end
DelusionTown_EventScript_Sailor::
	lock
	faceplayer
	msgbox DelusionTown_Text_Sailor, MSGBOX_NPC
	release
	end
DelusionTown_EventScript_Man::
	lock
	faceplayer
	msgbox DelusionTown_Text_Man, MSGBOX_NPC
	release
	end
DelusionTown_EventScript_Mimi::
	lockall
	faceplayer
	goto_if_eq VAR_DELUSION_TOWN_STATE, 0, DelusionTown_EventScript_Mimi0
	goto_if_eq VAR_DELUSION_TOWN_STATE, 1, DelusionTown_EventScript_Mimi1
	releaseall
	end
DelusionTown_EventScript_Mimi0::
	msgbox DelusionTown_Text_Mimi0, MSGBOX_NPC
	releaseall
	end
DelusionTown_EventScript_Mimi1::
	
	msgbox DelusionTown_Text_Mimi1, MSGBOX_NPC
	setvar VAR_DELUSION_TOWN_STATE, 2
	clearflag FLAG_HIDE_MIMI_WATER_HOUSE
	goto_if_eq VAR_FACING, DIR_NORTH, DelusionTown_EventScript_Mimi_MoveLeft
	applymovement LOCALID_MIMI, DelusionTown_Movement_Mimi
	waitmovement 0
	setobjectxy LOCALID_MIMI, -1, -1
	removeobject LOCALID_MIMI	
	setflag FLAG_HIDE_MIMI
	return
	
DelusionTown_EventScript_Mimi_MoveLeft::
	applymovement LOCALID_MIMI, DelusionTown_Movement_Mimi_Left
	waitmovement 0
	setobjectxy LOCALID_MIMI, -1, -1
	removeobject LOCALID_MIMI	
	setflag FLAG_HIDE_MIMI
	return
DelusionTown_Movement_Mimi_Left:
	walk_left
DelusionTown_Movement_Mimi:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
DelusionTown_Text_Mimi0:
	.string "MIMI: Hi there, be careful if you\n"
	.string "go out in the SURF.\p"
	.string "Oh, did you want to BATTLE?\n" 
	.string "I'd be happy to, when I'm off duty.$"
DelusionTown_Text_Mimi1:
	.string "MIMI: VI's stuck on the ISLAND?\n"
	.string "Again...?\l"
	.string "Uh, thanks for letting me know!\p" 
	.string "I'll go get them now.$"
DelusionTown_EventScript_Kate_Trigger::
	lockall
	turnobject LOCALID_KATE, DIR_SOUTH
	call DelusionTown_EventScript_Kate0
	applymovement LOCALID_PLAYER, DelusionTown_Movement_Player_Right
	waitmovement 0
	release
	end
DelusionTown_EventScript_Kate_Talk::
	lockall
	faceplayer
	call DelusionTown_EventScript_Kate0
	release
	end
DelusionTown_EventScript_Kate0::
	goto_if_set FLAG_IS_CHAMPION, DelusionTown_EventScript_Kate_Fight
	msgbox DelusionTown_Text_Kate0, MSGBOX_NPC
	return
DelusionTown_EventScript_Kate_Fight::
	trainerbattle_single TRAINER_KATE_1, DelusionTown_Text_Kate_Intro, DelusionTown_Text_Kate_Defeat, DelusionTown_EventScript_Kate_Defeated, NO_MUSIC	
	release
	end
DelusionTown_EventScript_Kate_Defeated::
	lockall
	msgbox DelusionTown_Text_Kate_Defeated, MSGBOX_NPC
	applymovement LOCALID_KATE, DelusionTown_Movement_Kate
	waitmovement 0
	setobjectxy LOCALID_KATE, -2, -2
	removeobject LOCALID_KATE 
	setflag FLAG_HIDE_KATE

	release
	end
DelusionTown_Text_PlayerHouseSign:
	.string "{PLAYER}'s House.$"

DelusionTown_Text_ClosedSign:
	.string "CLOSED, DO NOT ENTER!$"

DelusionTown_Text_CantReadSign:
	.string "The text is illegible.$"

DelusionTown_Text_LockedDoor:
	.string "The door is locked.\n"
	.string "Maybe someone has a key?$"
DelusionTown_Text_UnlockDoor:
	.string "{PLAYER} inserted and turned the\n"
	.string "BUILDING KEY.\p"
	.string "The door unlocked!$"

DelusionTown_Text_Unlocked:
	.string "The door is unlocked, good thing VI had\n"
	.string "found the key!$"


DelusionTown_Text_Azumarill:
	.string "Azu! Azu!$"

DelusionTown_Text_Tuber:
	.string "I can't swim!$"

DelusionTown_Text_Sailor:
	.string "When you're out at sea most days\n"
	.string "you appreciate the land much more.$"

DelusionTown_Text_Man:
	.string "The BEACH has always been a\n"
	.string "centerpiece of this TOWN. $"

DelusionTown_Text_Kate0:
	.string "I'll fight you.\p"
	.string "When you're a CHAMPION.$"

DelusionTown_Text_Kate_Intro:
	.string "You and me?\n"
	.string "Let's find out who's STRONGEST!$"

DelusionTown_Text_Kate_Defeat:
	.string "It wasn't me after all?$"

DelusionTown_Text_Kate_Defeated:
	.string "We should go to the gym\n"
	.string "together sometime!\p"
	.string "See ya!$"

DelusionTown_Movement_Kate:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

DelusionTown_Movement_Kate_Down:
	walk_down
	step_end

DelusionTown_Movement_Player_Right:
	walk_right
	step_end
