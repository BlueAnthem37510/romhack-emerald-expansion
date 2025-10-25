.set LOCALID_MOON, 1
.set LOCALID_VI, 2
.set LOCALID_MIMI, 3


DelusionTown_MoonHouse_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DelusionTown_MoonHouse_OnTransition
	.byte 0

DelusionTown_MoonHouse_OnTransition:
	goto_if_ne VAR_DELUSION_TOWN_STATE, 4, DelusionTown_MoonHouse_EventScript_HideMimiVi
	end

DelusionTown_MoonHouse_EventScript_HideMimiVi::
	setflag FLAG_HIDE_VI_MIMI
	end

DelusionTown_MoonHouse_EventScript_Mimi::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, DelusionTown_MoonHouse_EventScript_MimiRelax
	msgbox DelusionTown_MoonHouse_Text_Mimi 
	release
	end
DelusionTown_MoonHouse_EventScript_MimiRelax::
	msgbox DelusionTown_MoonHouse_Text_MimiTemp 
	release
	end
DelusionTown_MoonHouse_EventScript_Vi::
	lockall
	faceplayer
	goto_if_defeated TRAINER_MOON_1, DelusionTown_MoonHouse_EventScript_ViPostBattle
	goto_if_set FLAG_TEMP_1, DelusionTown_MoonHouse_EventScript_MoonAsk2
	msgbox DelusionTown_MoonHouse_Text_Vi1 
	turnobject LOCALID_MOON, DIR_EAST
	msgbox DelusionTown_MoonHouse_Text_Moon1
	turnobject LOCALID_VI, DIR_WEST
	msgbox DelusionTown_MoonHouse_Text_Vi2
	call_if_eq VAR_FACING, DIR_SOUTH, DelusionTown_MoonHouse_EventScript_FaceNorth
	call_if_eq VAR_FACING, DIR_NORTH, DelusionTown_MoonHouse_EventScript_FaceSouth
	setflag FLAG_TEMP_1
	goto DelusionTown_MoonHouse_EventScript_MoonAsk
	releaseall 
	end

DelusionTown_MoonHouse_EventScript_FaceSouth::
	turnobject LOCALID_MOON, DIR_SOUTH
	turnobject LOCALID_VI, DIR_SOUTH
	return
DelusionTown_MoonHouse_EventScript_FaceNorth::
	turnobject LOCALID_MOON, DIR_NORTH
	turnobject LOCALID_VI, DIR_NORTH
	return
DelusionTown_MoonHouse_EventScript_Moon::
	lockall
	faceplayer
	goto_if_defeated TRAINER_MOON_1, DelusionTown_MoonHouse_EventScript_MoonPostBattle
	goto_if_set FLAG_TEMP_1, DelusionTown_MoonHouse_EventScript_MoonAsk2
	goto_if_ne VAR_DELUSION_TOWN_STATE, 4, DelusionTown_MoonHouse_EventScript_MoonMeet
	msgbox DelusionTown_MoonHouse_Text_MoonFriend
	releaseall
	end
DelusionTown_MoonHouse_EventScript_MoonMeet::
	msgbox DelusionTown_MoonHouse_Text_MoonMeet
	releaseall
	end


DelusionTown_MoonHouse_EventScript_MoonAsk::

	msgbox DelusionTown_MoonHouse_Text_MoonFightMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DelusionTown_MoonHouse_EventScript_MoonBattle
	msgbox DelusionTown_MoonHouse_Text_MoonNo, MSGBOX_DEFAULT
	release
	end

DelusionTown_MoonHouse_EventScript_MoonAsk2::

	msgbox DelusionTown_MoonHouse_Text_MoonFightMe2, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DelusionTown_MoonHouse_EventScript_MoonBattle
	msgbox DelusionTown_MoonHouse_Text_MoonNo, MSGBOX_DEFAULT
	release
	end
DelusionTown_MoonHouse_EventScript_MoonDefeated::
	lockall
	settrainerflag TRAINER_MOON_1
	call_if_eq VAR_FACING, DIR_SOUTH, DelusionTown_MoonHouse_EventScript_FaceNorth
	call_if_eq VAR_FACING, DIR_NORTH, DelusionTown_MoonHouse_EventScript_FaceSouth
	msgbox DelusionTown_MoonHouse_Text_MoonDefeated
	turnobject LOCALID_VI, DIR_WEST
	msgbox DelusionTown_MoonHouse_Text_ViDefeated
	call_if_eq VAR_FACING, DIR_SOUTH, DelusionTown_MoonHouse_EventScript_FaceNorth
	call_if_eq VAR_FACING, DIR_NORTH, DelusionTown_MoonHouse_EventScript_FaceSouth
	msgbox DelusionTown_MoonHouse_Text_ViDefeated2
	releaseall
	end
DelusionTown_MoonHouse_EventScript_MoonPostBattle::
	msgbox DelusionTown_MoonHouse_Text_MoonPostBattle
	release
	end
DelusionTown_MoonHouse_EventScript_ViPostBattle::
	msgbox DelusionTown_MoonHouse_Text_ViPostBattle
	releaseall
	end
DelusionTown_MoonHouse_Text_MoonMeet:
	.string "Do you need something?$"
DelusionTown_MoonHouse_Text_MoonFriend:
	.string "A friend of MIMI and VI is a friend of\n"
	.string "mine too!$"
DelusionTown_MoonHouse_Text_Mimi:
	.string "Hello again, welcome to our home.$"

DelusionTown_MoonHouse_Text_Vi1:
	.string "Hi! Nice to see you again, thanks for\n"
	.string "the hand earlier, and getting to have a\p"
	.string "battle with MIMI always makes me\n"
	.string "happy.$"
DelusionTown_MoonHouse_Text_Moon1:
	.string "MOON: You guys BATTLED?! No way! I want\n"
	.string "to too!$"
DelusionTown_MoonHouse_Text_Vi2:
	.string "VI: Of course we can!\n"
	.string  "If our guest would like to.$"
DelusionTown_MoonHouse_Text_MoonFightMe:
	.string "MOON: PLEASE!$"
DelusionTown_MoonHouse_Text_MoonFightMe2:
	.string "MOON: PLEASE!! I wanna fight too!$"

DelusionTown_MoonHouse_Text_MoonIntro:
	.string "MOON: Yes!! Prepare to face defeat!$"

DelusionTown_MoonHouse_Text_MoonDefeat:
	.string "Wow, you're strong!$"
DelusionTown_MoonHouse_Text_MoonNo:
	.string "MOON: Aww...$"
DelusionTown_MoonHouse_Text_MoonDefeated:
	.string "MOON: We were so close! Next time VI and \n"
	.string "I will WIN for sure!$"
DelusionTown_MoonHouse_Text_ViDefeated:
	.string "VI: Hehe, I'm sure we will my love.$"
	
	DelusionTown_MoonHouse_Text_ViDefeated2:
	.string "Thank you for agreeing to battle us.\l"
	.string "I'm sure MOON and MIMI would be happy\n"
	.string "if you visited again.$"
DelusionTown_MoonHouse_Text_MoonPostBattle:
	.string "We should train together some time!$"
DelusionTown_MoonHouse_Text_ViPostBattle:
	.string "Fate has been kind for our paths to\n"
	.string "cross each other.$"
DelusionTown_MoonHouse_Text_MimiTemp:
	.string "Maybe the next time we meet we can do\n"
	.string "something more relaxing.$"

DelusionTown_MoonHouse_EventScript_MoonBattle::
	setflag B_FLAG_DYNAMAX_BATTLE
	msgbox DelusionTown_MoonHouse_Text_MoonIntro, MSGBOX_AUTOCLOSE
	trainerbattle_two_trainers TRAINER_MOON_1, DelusionTown_MoonHouse_Text_MoonDefeat, TRAINER_VI_2, DelusionTown_WaterHouse_Text_ViDefeat
	clearflag B_FLAG_DYNAMAX_BATTLE
	switch VAR_RESULT
	case 1, DelusionTown_MoonHouse_EventScript_MoonDefeated
