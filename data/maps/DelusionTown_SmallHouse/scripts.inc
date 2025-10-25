DelusionTown_SmallHouse_MapScripts::
	.byte 0


DelusionTown_SmallHouse_EventScript_Melia::
	lock
	faceplayer
	goto_if_defeated TRAINER_MELIA, DelusionTown_SmallHouse_EventScript_Melia_PostBattle
	goto_if_set FLAG_TEMP_1, DelusionTown_SmallHouse_EventScript_Melia_Ask2
	msgbox DelusionTown_SmallHouse_Text_MeliaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DelusionTown_SmallHouse_EventScript_Melia_Battle
	setflag FLAG_TEMP_1
	msgbox DelusionTown_SmallHouse_Text_MeliaNo, MSGBOX_DEFAULT
	release
	end

DelusionTown_SmallHouse_EventScript_Melia_Battle::
	trainerbattle_single TRAINER_MELIA, DelusionTown_SmallHouse_Text_MeliaBattleIntro, DelusionTown_SmallHouse_Text_MeliaDefeat, 	DelusionTown_SmallHouse_EventScript_Melia_Defeated
	end
	
DelusionTown_SmallHouse_EventScript_Melia_Defeated:
	msgbox DelusionTown_SmallHouse_Text_MeliaDefeated
	goto DelusionTown_EventScript_GiveWalrein
	release
	end
DelusionTown_SmallHouse_EventScript_Melia_PostBattle:
	msgbox DelusionTown_SmallHouse_Text_MeliaPostBattle
	release
	end
DelusionTown_SmallHouse_EventScript_Melia_Ask2:
	msgbox DelusionTown_SmallHouse_Text_MeliaIntro, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, DelusionTown_SmallHouse_EventScript_Melia_Battle
	msgbox DelusionTown_SmallHouse_Text_MeliaNo, MSGBOX_DEFAULT
	release
	end
DelusionTown_SmallHouse_Text_MeliaIntro:
	.string "Hello, are you from around here?\p"
	.string "I'm on vacation from a far away REGION.\p"
	.string "Decided I needed a small break from it\n"
	.string "all you know?\p"
	.string "Would you care for a BATTLE?\n"
	.string "It would be nice for me to have one\l"
	.string "where the stakes aren't so high.\l"
	.string "Make of that what you will...$"
DelusionTown_SmallHouse_Text_MeliaNo:
	.string "Let me know if you change your mind.$"
DelusionTown_SmallHouse_Text_MeliaShort:
	.string "Changed your mind about the BATTLE?$"
DelusionTown_SmallHouse_Text_MeliaBattleIntro:
	.string "Best of luck!$"
DelusionTown_SmallHouse_Text_MeliaDefeated:
	.string "Thank you for that, my POKéMON enjoyed\n"
	.string "the change of pace as well!\p"
	.string "As a token of appreciation would you\n"
	.string "allow me to give you a POKéMON?\p"
	.string "I have one who I think would appreciate\n"
	.string "being in HOENN much more than home.$"
DelusionTown_SmallHouse_Text_MeliaDefeat:
	.string "You fight well.$"
DelusionTown_SmallHouse_Text_MeliaPostBattle:
	.string "Take good care of WALREIN for me.$"

DelusionTown_EventScript_GiveWalrein::
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_WALREIN
	givemon SPECIES_WALREIN, 50, hpIv=31, atkIv=31, defIv=31, speedIv=31, spAtkIv=31, spDefIv=31, shinyMode=TRUE
	call_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, DelusionTown_EventScript_ReceiveWalreinParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, DelusionTown_EventScript_ReceiveWalreinPC
	goto Common_EventScript_NoMoreRoomForPokemon

	end
DelusionTown_EventScript_ReceiveWalreinParty::
	call DelusionTown_EventScript_ReceivedWalreinFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DelusionTown_EventScript_FinishReceivingWalrein
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto DelusionTown_EventScript_FinishReceivingWalrein
	end

DelusionTown_EventScript_ReceiveWalreinPC::
	call DelusionTown_EventScript_ReceivedWalreinFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, DelusionTown_EventScript_TransferWalreinToPC
	call Common_EventScript_NameReceivedBoxMon
	goto DelusionTown_EventScript_TransferWalreinToPC
	end

DelusionTown_EventScript_TransferWalreinToPC::
	call Common_EventScript_TransferredToPC
	goto DelusionTown_EventScript_FinishReceivingWalrein
	end

DelusionTown_EventScript_ReceivedWalreinFanfare::
	bufferspeciesname STR_VAR_2, SPECIES_WALREIN
	playfanfare MUS_OBTAIN_ITEM
	message DelusionTown_Text_ReceivedMonFromMelia
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_WALREIN
	return
DelusionTown_EventScript_FinishReceivingWalrein::
	release
	end

DelusionTown_Text_ReceivedMonFromMelia:
.string "{PLAYER} received {STR_VAR_2} from\n"
.string "TRAINER MELIA.$"
