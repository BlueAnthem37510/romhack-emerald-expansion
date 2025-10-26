
EverGrandeCity_PokemonLeague_1F_MapScripts::
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EverGrandeCity_PokemonLeague_1F_OnWarpLoad
	map_script MAP_SCRIPT_ON_LOAD, EverGrandeCity_PokemonLeague_1F_OnWarpLoad
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_PokemonLeague_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

EverGrandeCity_PokemonLeague_1F_OnWarpLoad:
	 
	
	end

EverGrandeCity_PokemonLeague_1F_OnTransition:
	setrespawn HEAL_LOCATION_EVER_GRANDE_CITY_POKEMON_LEAGUE
	setflag FLAG_LANDMARK_POKEMON_LEAGUE
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Stairs::
	setmetatile 0, 6, METATILE_PokemonCenter_Floor_Plain_Alt, FALSE
	setmetatile 0, 7, METATILE_PokemonCenter_Floor_Plain_Alt, FALSE
	setmetatile 0, 8, METATILE_PokemonCenter_Floor_Plain_Alt, FALSE
	setmetatile 1, 6, METATILE_PokemonCenter_Floor_Plain_Alt, FALSE
	setmetatile 1, 7, METATILE_PokemonCenter_Floor_Plain_Alt, FALSE
	setmetatile 1, 8, METATILE_PokemonCenter_Floor_Plain_Alt, FALSE
	setmetatile 1, 9, METATILE_PokemonCenter_Floor_Plain_Alt, FALSE
	return

EverGrandeCity_PokemonLeague_1F_EventScript_Nurse::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart_Megas
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
	.align 2

EverGrandeCity_PokemonLeague_1F_Pokemart_Megas:
	.2byte ITEM_CHARIZARDITE_X
	.2byte ITEM_CHARIZARDITE_Y
	.2byte ITEM_GENGARITE
	.2byte ITEM_SCIZORITE
	.2byte ITEM_HOUNDOOMINITE
	.2byte ITEM_BANETTITE
	.2byte ITEM_LUCARIONITE
	.2byte ITEM_SHARPEDONITE
	.2byte ITEM_NONE
	release
	end

EverGrandeCity_PokemonLeague_1F_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EverGrandeCity_PokemonLeague_1F_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
	.align 2


EverGrandeCity_PokemonLeague_1F_Pokemart:	
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE	
	.2byte ITEM_ASSAULT_VEST
	.2byte ITEM_BIG_ROOT
	.2byte ITEM_BINDING_BAND
	.2byte ITEM_BLACK_BELT
	.2byte ITEM_BLACK_GLASSES
	.2byte ITEM_BLACK_SLUDGE
	.2byte ITEM_BUG_GEM
	.2byte ITEM_CELL_BATTERY
	.2byte ITEM_CHARCOAL
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_CHOICE_SCARF
	.2byte ITEM_CHOICE_SPECS
	.2byte ITEM_CLEAR_AMULET
	.2byte ITEM_DAMP_ROCK
	.2byte ITEM_DARK_GEM
	.2byte ITEM_DRAGON_GEM
	.2byte ITEM_DREAD_PLATE
	.2byte ITEM_EARTH_PLATE
	.2byte ITEM_EJECT_BUTTON
	.2byte ITEM_ELECTRIC_GEM
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_FAIRY_GEM
	.2byte ITEM_FIGHTING_GEM
	.2byte ITEM_FIRE_GEM
	.2byte ITEM_FIST_PLATE
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_FLAME_PLATE
	.2byte ITEM_FLYING_GEM
	.2byte ITEM_FOCUS_BAND
	.2byte ITEM_FULL_INCENSE
	.2byte ITEM_GHOST_GEM
	.2byte ITEM_GRASS_GEM
	.2byte ITEM_GRIP_CLAW
	.2byte ITEM_GROUND_GEM
	.2byte ITEM_HARD_STONE
	.2byte ITEM_HEAT_ROCK
	.2byte ITEM_ICE_GEM
	.2byte ITEM_ICICLE_PLATE
	.2byte ITEM_ICY_ROCK
	.2byte ITEM_INSECT_PLATE
	.2byte ITEM_IRON_BALL
	.2byte ITEM_IRON_PLATE
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_LEFTOVERS
	.2byte ITEM_LIFE_ORB
	.2byte ITEM_LIGHT_CLAY
	.2byte ITEM_LUCK_INCENSE
	.2byte ITEM_MAGNET
	.2byte ITEM_MEADOW_PLATE
	.2byte ITEM_METAL_COAT
	.2byte ITEM_METRONOME
	.2byte ITEM_MIND_PLATE
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_MUSCLE_BAND
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_NEVER_MELT_ICE
	.2byte ITEM_NORMAL_GEM
	.2byte ITEM_ODD_INCENSE
	.2byte ITEM_PIXIE_PLATE
	.2byte ITEM_POISON_BARB
	.2byte ITEM_POISON_GEM
	.2byte ITEM_POWER_HERB
	.2byte ITEM_PROTECTIVE_PADS
	.2byte ITEM_PSYCHIC_GEM
	.2byte ITEM_QUICK_CLAW
	.2byte ITEM_RAZOR_CLAW
	.2byte ITEM_RED_CARD
	.2byte ITEM_RING_TARGET
	.2byte ITEM_ROCK_GEM
	.2byte ITEM_ROCK_INCENSE
	.2byte ITEM_ROCKY_HELMET
	.2byte ITEM_SAFETY_GOGGLES
	.2byte ITEM_SCOPE_LENS
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_SHED_SHELL
	.2byte ITEM_SHELL_BELL
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_SKY_PLATE
	.2byte ITEM_SMOOTH_ROCK
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_SPELL_TAG
	.2byte ITEM_SPLASH_PLATE
	.2byte ITEM_SPOOKY_PLATE
	.2byte ITEM_STEEL_GEM
	.2byte ITEM_STICKY_BARB
	.2byte ITEM_STONE_PLATE
	.2byte ITEM_TERRAIN_EXTENDER
	.2byte ITEM_TOXIC_ORB
	.2byte ITEM_TOXIC_PLATE
	.2byte ITEM_WATER_GEM
	.2byte ITEM_WEAKNESS_POLICY
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_WIDE_LENS
	.2byte ITEM_WISE_GLASSES
	.2byte ITEM_ZAP_PLATE
	.2byte ITEM_ZOOM_LENS
	.2byte ITEM_NONE
	release
	end
