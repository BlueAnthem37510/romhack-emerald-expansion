DisCity_MapScripts::
	.byte 0

DisCity_EventScript_Plumeria::
	lock
	faceplayer
	msgbox DisCity_Text_Plumeria, MSGBOX_NPC
	trainerbattle_single TRAINER_PLUMERIA_1, DisCity_Text_Plumeria, DisCity_Text_Plumeria, DisCity_EventScript_Plumeria_Defeated, NO_MUSIC	
	release
	end
DisCity_EventScript_Plumeria_Defeated:
	release
	end
DisCity_Text_Plumeria:
	.string "Urm. Cheesed to meet you?$"
