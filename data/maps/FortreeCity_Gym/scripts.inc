FortreeCity_Gym_MapScripts::
	.byte 0

FortreeCity_Gym_EventScript_Winona::
	trainerbattle_single TRAINER_MEEP, FortreeCity_Gym_Text_WinonaIntro, FortreeCity_Gym_Text_WinonaDefeat, FortreeCity_Gym_EventScript_WinonaDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, FortreeCity_Gym_EventScript_WinonaRematch
	goto_if_unset FLAG_RECEIVED_TM_AERIAL_ACE, FortreeCity_Gym_EventScript_GiveAerialAce2
	msgbox FortreeCity_Gym_Text_WinonaPostBattle, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_WinonaDefeated::
	message FortreeCity_Gym_Text_ReceivedPetalBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_FORTREE_GYM
	setflag FLAG_BADGE06_GET
	setvar VAR_0x8008, 6
	call Common_EventScript_SetGymTrainers
	call FortreeCity_Gym_EventScript_GiveAerialAce
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox FortreeCity_Gym_Text_RegisteredWinona, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_WINONA_MATCH_CALL
	setvar VAR_SCOTT_FORTREE_CALL_STEP_COUNTER, 0
	setflag FLAG_SCOTT_CALL_FORTREE_GYM
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce2::
	giveitem ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox FortreeCity_Gym_Text_ExplainGigaDrain, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	release
	end

FortreeCity_Gym_EventScript_GiveAerialAce::
	giveitem ITEM_TM19
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_ExplainGigaDrain, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_AERIAL_ACE
	return

FortreeCity_Gym_EventScript_WinonaRematch::
	trainerbattle_rematch_double TRAINER_MEEP, FortreeCity_Gym_Text_WinonaPreRematch, FortreeCity_Gym_Text_WinonaRematchDefeat, FortreeCity_Gym_Text_WinonaRematchNeedTwoMons
	msgbox FortreeCity_Gym_Text_WinonaPostRematch, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Jane::
	trainerbattle_single TRAINER_JANE, FortreeCity_Gym_Text_JaneIntro, FortreeCity_Gym_Text_JaneDefeat
	msgbox FortreeCity_Gym_Text_JanePostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Edwardo::
	trainerbattle_single TRAINER_EDWARDO, FortreeCity_Gym_Text_EdwardoIntro, FortreeCity_Gym_Text_EdwardoDefeat
	msgbox FortreeCity_Gym_Text_EdwardoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Flint::
	trainerbattle_single TRAINER_FLINT, FortreeCity_Gym_Text_FlintIntro, FortreeCity_Gym_Text_FlintDefeat
	msgbox FortreeCity_Gym_Text_FlintPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Ashley::
	trainerbattle_single TRAINER_ASHLEY, FortreeCity_Gym_Text_AshleyIntro, FortreeCity_Gym_Text_AshleyDefeat
	msgbox FortreeCity_Gym_Text_AshleyPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Humberto::
	trainerbattle_single TRAINER_HUMBERTO, FortreeCity_Gym_Text_HumbertoIntro, FortreeCity_Gym_Text_HumbertoDefeat
	msgbox FortreeCity_Gym_Text_HumbertoPostBattle, MSGBOX_AUTOCLOSE
	end

FortreeCity_Gym_EventScript_Duckie::
	lock
	faceplayer	
	goto_if_not_defeated TRAINER_MELIA, FortreeCity_Gym_EventScript_DuckieAsk
	msgbox FortreeCity_Gym_Text_DuckiePostBattle, MSGBOX_AUTOCLOSE
	release
	end


FortreeCity_Gym_EventScript_DuckieAsk::

	msgbox FortreeCity_Gym_Text_DuckieAskBattle, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, FortreeCity_Gym_EventScript_DuckieBattle
	msgbox FortreeCity_Gym_Text_DuckieNo, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_DuckieDefeated::
	
	msgbox FortreeCity_Gym_Text_DuckieWin, MSGBOX_DEFAULT
	giveitem ITEM_LINKING_CORD
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_BagIsFull
	msgbox FortreeCity_Gym_Text_DuckiePostBattle, MSGBOX_AUTOCLOSE
	release
	end

FortreeCity_Gym_EventScript_DuckieBattle::
	trainerbattle_single TRAINER_MELIA, FortreeCity_Gym_Text_DuckieIntro, FortreeCity_Gym_Text_DuckieDefeat, FortreeCity_Gym_EventScript_DuckieDefeated 
	msgbox FortreeCity_Gym_Text_DuckiePostBattle, MSGBOX_AUTOCLOSE
	release
	end
FortreeCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_FORTREE_GYM, FortreeCity_Gym_EventScript_GymGuidePostVictory
	msgbox FortreeCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_GymGuidePostVictory::
	msgbox FortreeCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

FortreeCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE06_GET, FortreeCity_Gym_EventScript_GymStatueCertified
	goto FortreeCity_Gym_EventScript_GymStatue
	end

FortreeCity_Gym_EventScript_GymStatueCertified::
	msgbox FortreeCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_EventScript_GymStatue::
	msgbox FortreeCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

FortreeCity_Gym_Text_GymGuideAdvice:
	.string "Yo, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "FORTREE GYM LEADER MEEP is\n"
	.string "a master of GRASS-type POKéMON.\p"
	.string "She's waiting at the back of this GYM,\n"
	.string "through the dense greenhouse.\p"
	.string "She's waiting for new challengers\n"
	.string "who are trying to take root!\p"
	.string "Okay, go for it!$"

FortreeCity_Gym_Text_GymGuidePostVictory:
	.string "You did it!\n"
	.string "You've realy sprouted!$"

FortreeCity_Gym_Text_JaneIntro:
	.string "Mushroom, mushroom?\n"
	.string "Mushroom!$"

FortreeCity_Gym_Text_JaneDefeat:
	.string "…$"

FortreeCity_Gym_Text_JanePostBattle:
	.string "Mushroom...$"

FortreeCity_Gym_Text_EdwardoIntro:
	.string "The lovers of GRASS POKéMON aspire\n"
	.string "to join this GYM.\p"
	.string "As a member of the FORTREE GYM,\n"
	.string "I'm not allowed to lose!$"

FortreeCity_Gym_Text_EdwardoDefeat:
	.string "It was too much of a load for me\n"
	.string "to bear…$"

FortreeCity_Gym_Text_EdwardoPostBattle:
	.string "The world is huge, and there are\n"
	.string "countless tough TRAINERS.\p"
	.string "I'm going to keep training and make\n"
	.string "myself even stronger.$"

FortreeCity_Gym_Text_FlintIntro:
	.string "Behold the battle style of\n"
	.string "PLANT POKéMON!$"

FortreeCity_Gym_Text_FlintDefeat:
	.string "You…\n"
	.string "You're strong…$"

FortreeCity_Gym_Text_FlintPostBattle:
	.string "A TRAINER has to be smart to keep\n"
	.string "up with unexpected turns of events.\p"
	.string "Do you have the smarts to get to\n"
	.string "our LEADER?$"

FortreeCity_Gym_Text_AshleyIntro:
	.string "MEEP taught me personally!\n"
	.string "You can't beat me easily!$"

FortreeCity_Gym_Text_AshleyDefeat:
	.string "I was beaten…$"

FortreeCity_Gym_Text_AshleyPostBattle:
	.string "Thanks to MEEP, the people of\n"
	.string "FORTREE can live without fear.$"

FortreeCity_Gym_Text_HumbertoIntro:
	.string "When WINONA takes to battle, her face\n"
	.string "shines with beautiful determination…\p"
	.string "I'm not letting you witness that\n"
	.string "lovely sight!$"

FortreeCity_Gym_Text_HumbertoDefeat:
	.string "Urk!\n"
	.string "I couldn't stop you.$"

FortreeCity_Gym_Text_HumbertoPostBattle:
	.string "You'd better watch it!\n"
	.string "Don't get distracted staring at WINONA\l"
	.string "or you'll go crashing down in a heap!$"

FortreeCity_Gym_Text_DuckieAskBattle:
	.string "Hello, I'm testing\n"
	.string "if this works correctly.\p"
	.string "Would you like to battle me?$"
FortreeCity_Gym_Text_DuckieNo:
	.string "Maybe next time.$"
FortreeCity_Gym_Text_DuckieWin:
	.string "Thank you for the battle.\n"
	.string "Maybe this will be of use to you?$"
FortreeCity_Gym_Text_DuckieIntro:
	.string "You'd better know that there are all\n"
	.string "sorts of FLYING-type POKéMON.\p"
	.string "You do know that, right?$"

FortreeCity_Gym_Text_DuckieDefeat:
	.string "You seem to know your stuff!$"

FortreeCity_Gym_Text_DuckiePostBattle:
	.string "Sure, you beat me all right.\n"
	.string "But you'd better watch it! Our LEADER\l"
	.string "WINONA's POKéMON are all business.$"

FortreeCity_Gym_Text_WinonaIntro:
	.string "Hello! Welcome to the FORTREE POKéMON\n"
	.string "GYM!\p" 
	.string "I hope you enjoyed my beautiful flowers,\n" 
	.string "and tough trainers!\p"
	.string "Now, I look forward to a fruitful battle\n" 
	.string "with you!$" 

FortreeCity_Gym_Text_WinonaDefeat:
	.string "You and your POKéMON were shining!\n"
	.string "I hope you learned something from\l"
	.string "our battle and continue to grow.\p"
	.string "In recognition of your strength,\n"
	.string "I present to you this GYM BADGE.$"

FortreeCity_Gym_Text_ReceivedPetalBadge:
	.string "{PLAYER} received the PETAL BADGE\n"
	.string "from MEEP.$"

FortreeCity_Gym_Text_ExplainFeatherBadgeTakeThis:
	.string "With the PETAL BADGE, all POKéMON up\n"
	.string "to LV 70, and any received through\l"
	.string "trades, will listen to your commands.\p"
	.string "You will also be able to use\n"
	.string "the HM move FLY outside of battle.\p"
	.string "And here! A gift from me.$"

FortreeCity_Gym_Text_ExplainGigaDrain:
	.string "TM19 contains GIGA DRAIN\p"
	.string "It'll keep your POKéMON strong\n"
	.string "while draining your oppenents.$"

FortreeCity_Gym_Text_RegisteredWinona:
	.string "Registered GYM LEADER MEEP\n"
	.string "in the POKéNAV.$"

FortreeCity_Gym_Text_WinonaPostBattle:
	.string "Thank you for the battle\p"
	.string "you are always welcome\n"
	.string "to visit my garden.$"

FortreeCity_Gym_Text_GymStatue:
	.string "FORTREE CITY POKéMON GYM$"

FortreeCity_Gym_Text_GymStatueCertified:
	.string "FORTREE CITY POKéMON GYM\p"
	.string "WINONA'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

FortreeCity_Gym_Text_WinonaPreRematch:
	.string "WINONA: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning CHAMPION.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!$"

FortreeCity_Gym_Text_WinonaRematchDefeat:
	.string "I failed to reach your height again…$"

FortreeCity_Gym_Text_WinonaPostRematch:
	.string "WINONA: Even though I have lost,\n"
	.string "the wings of my heart remain unbroken.\p"
	.string "I can rise and soar again and\n"
	.string "yet again.\p"
	.string "I am convinced of it!$"

FortreeCity_Gym_Text_WinonaRematchNeedTwoMons:
	.string "WINONA: We humans can never escape\n"
	.string "gravity's pull on the ground.\p"
	.string "But by striving for excellence,\n"
	.string "we have the power to soar!\p"
	.string "You have scaled the pinnacle as\n"
	.string "the reigning CHAMPION.\p"
	.string "Please, allow me to see your power\n"
	.string "at full flight!\p"
	.string "Oh, no… Do you have but one\n"
	.string "POKéMON with you?\p"
	.string "Please return with two POKéMON\n"
	.string "at the very least.$"
