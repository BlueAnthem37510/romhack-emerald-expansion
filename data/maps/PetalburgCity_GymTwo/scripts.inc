.set LOCALID_BONNIE, 14
.set LOCALID_CHICA, 12
.set LOCALID_FOXY, 11
.set LOCALID_FREDDY, 13
.set LOCALID_GOLDENFREDDY, 10
.set LOCALID_SPRINGTRAP, 9

PetalburgCity_GymTwo_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, PetalburgCity_GymTwo_OnLoad
	.byte 0


PetalburgCity_GymTwo_OnLoad:
	goto_if_not_defeated TRAINER_FREDDY, PetalburgCity_GymTwo_HideTrainers
	end

PetalburgCity_GymTwo_HideTrainers::
	setflag FLAG_HIDE_FOXY
	setflag FLAG_HIDE_BONNIE
	setflag FLAG_HIDE_CHICA
	setflag FLAG_HIDE_GOLDENFREDDY
	setflag FLAG_HIDE_SPRINGTRAP
	setflag FLAG_FNAF_BALL
	end






PetalburgCity_GymTwo_EventScript_Freddy::
	trainerbattle_single TRAINER_FREDDY, PetalburgCity_GymTwo_Text_SpiritIntro, PetalburgCity_GymTwo_Text_FreddyDefeat, PetalburgCity_GymTwo_EventScript_ShowBonnie
	msgbox PetalburgCity_GymTwo_Text_SpiritIntro, MSGBOX_AUTOCLOSE
	end

PetalburgCity_GymTwo_EventScript_Bonnie::
	trainerbattle_single TRAINER_BONNIE, PetalburgCity_GymTwo_Text_SpiritIntro, PetalburgCity_GymTwo_Text_BonnieDefeat, PetalburgCity_GymTwo_EventScript_ShowChica
	msgbox PetalburgCity_GymTwo_Text_SpiritIntro, MSGBOX_AUTOCLOSE
	end
PetalburgCity_GymTwo_EventScript_Chica::
	trainerbattle_single TRAINER_CHICA, PetalburgCity_GymTwo_Text_SpiritIntro, PetalburgCity_GymTwo_Text_ChicaDefeat, PetalburgCity_GymTwo_EventScript_ShowFoxy
	msgbox PetalburgCity_GymTwo_Text_SpiritIntro, MSGBOX_AUTOCLOSE
	end
PetalburgCity_GymTwo_EventScript_Foxy::
	trainerbattle_single TRAINER_FOXY, PetalburgCity_GymTwo_Text_SpiritIntro, PetalburgCity_GymTwo_Text_FoxyDefeat, PetalburgCity_GymTwo_EventScript_ShowGoldenFreddy
	msgbox PetalburgCity_GymTwo_Text_SpiritIntro, MSGBOX_AUTOCLOSE
	end

PetalburgCity_GymTwo_EventScript_GoldenFreddy::
	trainerbattle_single TRAINER_GOLDENFREDDY, PetalburgCity_GymTwo_Text_SpiritIntro, PetalburgCity_GymTwo_Text_GoldenFreddyDefeat, PetalburgCity_GymTwo_EventScript_ShowSpringTrap
	msgbox PetalburgCity_GymTwo_Text_SpiritIntro, MSGBOX_AUTOCLOSE
	end


PetalburgCity_GymTwo_EventScript_ShowBonnie::
	msgbox PetalburgCity_GymTwo_Text_SpiritIntro, MSGBOX_AUTOCLOSE
	clearflag FLAG_HIDE_BONNIE
	addobject LOCALID_BONNIE
	special DrawWholeMapView
	end

PetalburgCity_GymTwo_EventScript_ShowChica::
	msgbox PetalburgCity_GymTwo_Text_SpiritIntro, MSGBOX_AUTOCLOSE
	clearflag FLAG_HIDE_CHICA
	addobject LOCALID_CHICA
	special DrawWholeMapView
	end
PetalburgCity_GymTwo_EventScript_ShowFoxy::
	msgbox PetalburgCity_GymTwo_Text_SpiritIntro, MSGBOX_AUTOCLOSE
	clearflag FLAG_HIDE_FOXY
	addobject LOCALID_FOXY
	special DrawWholeMapView
	end
PetalburgCity_GymTwo_EventScript_ShowGoldenFreddy::
	msgbox PetalburgCity_GymTwo_Text_SpiritIntro, MSGBOX_AUTOCLOSE
	clearflag FLAG_HIDE_GOLDENFREDDY
	addobject LOCALID_GOLDENFREDDY
	special DrawWholeMapView
	end

PetalburgCity_GymTwo_EventScript_ShowSpringTrap::
	msgbox PetalburgCity_GymTwo_Text_SpiritIntro, MSGBOX_AUTOCLOSE
	clearflag FLAG_HIDE_SPRINGTRAP
	addobject LOCALID_SPRINGTRAP
	special DrawWholeMapView
	end

PetalburgCity_GymTwo_Text_SpiritIntro:
.string "...$"
PetalburgCity_GymTwo_Text_FreddyDefeat:
.string ".. Har, har, har, har.$"
PetalburgCity_GymTwo_Text_BonnieDefeat:
.string "Revenge...$"
PetalburgCity_GymTwo_Text_ChicaDefeat:
.string "... Thanks for playing with me.$"
PetalburgCity_GymTwo_Text_FoxyDefeat:
.string "... Yarr, har, har.$"
PetalburgCity_GymTwo_Text_GoldenFreddyDefeat:
.string "596F752073686F756C64206E6F7420686\n"
.string "7665206B696C6C6564206D652E$"



PetalburgCity_GymTwo_EventScript_SpringTrap::
	lock
	faceplayer
	msgbox PetalburgCity_GymTwo_Text_SpringTrapIntro, MSGBOX_DEFAULT
	setflag B_FLAG_DYNAMAX_BATTLE
	trainerbattle_no_intro TRAINER_SPRINGTRAP, PetalburgCity_GymTwo_Text_SpringTrapDefeat
	clearflag B_FLAG_DYNAMAX_BATTLE
	msgbox PetalburgCity_GymTwo_Text_SpringTrapDefeated 
	closemessage

	setobjectxyperm LOCALID_FREDDY, 3, 19
	setobjectxyperm LOCALID_BONNIE, 15, 23
	setobjectxyperm LOCALID_FOXY, 15, 23
	setobjectxyperm LOCALID_CHICA, 16, 23
	setobjectxyperm LOCALID_GOLDENFREDDY, 10, 22
	delay 40	
	addobject LOCALID_FREDDY
	addobject LOCALID_BONNIE
	addobject LOCALID_FOXY
	addobject LOCALID_CHICA
	addobject LOCALID_GOLDENFREDDY
	clearflag FLAG_FNAF_BALL	
	setobjectxyperm 15, 10, 36
	addobject 15
	applymovement LOCALID_FREDDY, PetalburgCity_GymTwo_Movement_Freddy
	waitmovement 0
	turnobject LOCALID_FREDDY, DIR_NORTH
	delay 20	
	applymovement LOCALID_BONNIE, PetalburgCity_GymTwo_Movement_Bonnie
	waitmovement 0
	turnobject LOCALID_BONNIE, DIR_NORTH
	delay 1
	applymovement LOCALID_FOXY, PetalburgCity_GymTwo_Movement_Foxy
	waitmovement 0
	turnobject LOCALID_FOXY, DIR_NORTH
	delay 1
	applymovement LOCALID_CHICA, PetalburgCity_GymTwo_Movement_Chica
	waitmovement 0
	turnobject LOCALID_CHICA, DIR_NORTH
	delay 40
	msgbox PetalburgCity_GymTwo_Text_SpringTrapScared 
	closemessage
	delay 20	
	applymovement LOCALID_GOLDENFREDDY, PetalburgCity_GymTwo_Movement_GoldenFreddy
	waitmovement 0
	turnobject LOCALID_GOLDENFREDDY, DIR_NORTH
	delay 40	
	msgbox PetalburgCity_GymTwo_Text_SpringTrapRun 
	closemessage
	delay 5
	applymovement LOCALID_SPRINGTRAP, PetalburgCity_GymTwo_Movement_SpringTrap
	waitmovement 0
	removeobject LOCALID_SPRINGTRAP
	turnobject OBJ_EVENT_ID_PLAYER, DIR_SOUTH
	delay 20
	applymovement LOCALID_CHICA, PetalburgCity_GymTwo_Movement_Chica2
	waitmovement 0
	removeobject LOCALID_CHICA
	delay 20
	applymovement LOCALID_BONNIE, PetalburgCity_GymTwo_Movement_Bonnie2
	waitmovement 0
	removeobject LOCALID_BONNIE
	delay 20
	applymovement LOCALID_FREDDY, PetalburgCity_GymTwo_Movement_Freddy2
	waitmovement 0
	removeobject LOCALID_FREDDY
	delay 20
	applymovement LOCALID_FOXY, PetalburgCity_GymTwo_Movement_Foxy2
	waitmovement 0
	removeobject LOCALID_FOXY
	delay 20
	msgbox PetalburgCity_GymTwo_Text_GoldenFreddyThankYou 
	closemessage
	delay 5
	applymovement LOCALID_GOLDENFREDDY, PetalburgCity_GymTwo_Movement_GoldenFreddy2
	waitmovement 0
	removeobject LOCALID_GOLDENFREDDY
	delay 5
	release
	end

PetalburgCity_GymTwo_Text_SpringTrapIntro:
	.string "Welcome, TRESPASSER, to my humble\n"
	.string "workshop.\p"
	.string "Would you like to be part of my next\n"
	.string "PROJECT?$"

PetalburgCity_GymTwo_Text_SpringTrapDefeat:
	.string "You're next...$"
PetalburgCity_GymTwo_Text_SpringTrapDefeated:
	.string "Prepare to join the SPIRITS.$"
PetalburgCity_GymTwo_Text_SpringTrapScared:
	.string "What?\p"
	.string "What is this?\p"
	.string "What did you do?!$"
PetalburgCity_GymTwo_Text_GoldenFreddyThankYou:
	.string "5468616E6B20796F752E$"
PetalburgCity_GymTwo_Text_SpringTrapRun:
	.string "You all listen to me! Leave!\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "...$"


PetalburgCity_GymTwo_Movement_Freddy:
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end


PetalburgCity_GymTwo_Movement_Bonnie:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

PetalburgCity_GymTwo_Movement_Foxy:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

PetalburgCity_GymTwo_Movement_Chica:

	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
PetalburgCity_GymTwo_Movement_GoldenFreddy:
	walk_up
	delay_16
	walk_up
	delay_16
	walk_up
	delay_16
	walk_up
	delay_16
	walk_up
	delay_16
	step_end

PetalburgCity_GymTwo_Movement_SpringTrap:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
PetalburgCity_GymTwo_Movement_Chica2:
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
PetalburgCity_GymTwo_Movement_Bonnie2:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
PetalburgCity_GymTwo_Movement_Freddy2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
PetalburgCity_GymTwo_Movement_Foxy2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	step_end
PetalburgCity_GymTwo_Movement_GoldenFreddy2:
	walk_down
	delay_16
	walk_right
	delay_16
	walk_right
	delay_16
	walk_right
	delay_16
	walk_right
	delay_16
	walk_right
	delay_16
	walk_down
	delay_16
	walk_right
	delay_16
	walk_right
	delay_16
	walk_right
	step_end
PetalburgCity_GymTwo_EventScript_LockedDoor::
	lock
	goto_if_defeated TRAINER_SPRINGTRAP, PetalburgCity_GymTwo_EventScript_LockedDoorDeath
	msgbox PetalburgCity_GymTwo_Text_LockedDoor, MSGBOX_DEFAULT
	releaseall
	end
PetalburgCity_GymTwo_EventScript_LockedDoorDeath::
	lock
	msgbox PetalburgCity_GymTwo_Text_LockedDoorDeath, MSGBOX_DEFAULT
	releaseall
	end
PetalburgCity_GymTwo_EventScript_Pokeball::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_URSALUNA_BLOODMOON
	givemon SPECIES_URSALUNA_BLOODMOON, 50,hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, move1=MOVE_EARTHQUAKE, move2=MOVE_BLOOD_MOON, move3=MOVE_MOONLIGHT, move4=MOVE_SHADOW_CLAW
	call_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, PetalburgCity_GymTwo_EventScript_ReceiveAnorithParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, PetalburgCity_GymTwo_EventScript_ReceiveAnorithPC
	goto Common_EventScript_NoMoreRoomForPokemon

	end
PetalburgCity_GymTwo_EventScript_ReceiveAnorithParty::
	call PetalburgCity_GymTwo_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_GymTwo_EventScript_FinishReceivingUrsaluna
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto PetalburgCity_GymTwo_EventScript_FinishReceivingUrsaluna
	end

PetalburgCity_GymTwo_EventScript_ReceiveAnorithPC::
	call PetalburgCity_GymTwo_EventScript_ReceivedAnorithFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, PetalburgCity_GymTwo_EventScript_TransferUrsalunaToPC
	call Common_EventScript_NameReceivedBoxMon
	goto PetalburgCity_GymTwo_EventScript_TransferUrsalunaToPC
	end

PetalburgCity_GymTwo_EventScript_TransferUrsalunaToPC::
	call Common_EventScript_TransferredToPC
	goto PetalburgCity_GymTwo_EventScript_FinishReceivingUrsaluna
	end

PetalburgCity_GymTwo_EventScript_ReceivedAnorithFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_URSALUNA_BLOODMOON
	playfanfare MUS_OBTAIN_ITEM
	message PetalburgCity_GymTwo_Text_ReceivedMonFromResearcher
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_URSALUNA_BLOODMOON
	return

PetalburgCity_GymTwo_EventScript_FinishReceivingUrsaluna::
	setflag FLAG_FNAF_BALL
	removeobject 15
	release
	end

PetalburgCity_GymTwo_Text_ReceivedMonFromResearcher:
.string "There's an {STR_VAR_2} in the POKé BALL.\p"
.string "{PLAYER} received {STR_VAR_2}.$"

























PetalburgCity_GymTwo_EventScript_SecuritySystem::
	lock
	msgbox PetalburgCity_GymTwo_Text_SecuritySystem, MSGBOX_SIGN
	releaseall
	end






PetalburgCity_GymTwo_Text_SecuritySystem:
	.string "It's some sort of security system.\p"
	.string "There's nothing of interest on the\n"
	.string "the cameras.$"



PetalburgCity_GymTwo_Text_LockedDoor:
	.string "The door won't open.$"
PetalburgCity_GymTwo_Text_LockedDoorDeath:
	.string "The door won't open.\p"
	.string "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA\n"
	.string "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA$"

PetalburgCity_GymTwo_Text_GymGuideNewTrainer:
	.string "How's it going new TRAINER?\p"
	.string "You'll need 4 badges if you want\n"
	.string "a chance against LEADER MOSHI.\p"
	.string "Head to RUSTBORO CITY and you\n"
	.string "can challenge LEADER HEEB.$"

PetalburgCity_GymTwo_Text_GymGuideGoToDewford:
	.string "Yo, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "Congrats on beating the\n"
	.string "GYM LEADER in RUSTBORO CITY!\p"
	.string "But there are many more TRAINERS\n"
	.string "who are stronger than you, {PLAYER}.\p"
	.string "Across the sea in DEWFORD TOWN is a\n"
	.string "GYM LEADER named FLUFFY.\p"
	.string "You should go challenge them.$"

PetalburgCity_GymTwo_Text_GymGuideMoreBadges:
	.string "Yo, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "Continue earning badges\n"
	.string "to challenge GYM LEADER MOSHI!$"

PetalburgCity_GymTwo_EventScript_GymGuideNewTrainer::
	msgbox PetalburgCity_GymTwo_Text_GymGuideNewTrainer, MSGBOX_DEFAULT
	release
	end

PetalburgCity_GymTwo_EventScript_GymGuideOneBadge::
	msgbox PetalburgCity_GymTwo_Text_GymGuideGoToDewford, MSGBOX_DEFAULT
	release
	end

PetalburgCity_GymTwo_EventScript_GymGuideMoreBadge::
	msgbox PetalburgCity_GymTwo_Text_GymGuideMoreBadges, MSGBOX_DEFAULT
	release
	end

PetalburgCity_GymTwo_EventScript_GymGuideAdvice::
	msgbox PetalburgCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT 
	release
	end
PetalburgCity_GymTwo_EventScript_GymGuide::
	lock
	faceplayer	
	switch VAR_PETALBURG_GYM_STATE
		case 2, PetalburgCity_GymTwo_EventScript_GymGuideNewTrainer
		case 3, PetalburgCity_GymTwo_EventScript_GymGuideOneBadge
		case 4, PetalburgCity_GymTwo_EventScript_GymGuideMoreBadge
		case 5, PetalburgCity_GymTwo_EventScript_GymGuideMoreBadge
		case 6, PetalburgCity_GymTwo_EventScript_GymGuideAdvice
		case 7, PetalburgCity_Gym_EventScript_GymGuidePostVictory
		case 8, PetalburgCity_Gym_EventScript_NormanRematch	
	release
	end

