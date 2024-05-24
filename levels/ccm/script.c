#include <ultra64.h>
#include "sm64.h"
#include "behavior_data.h"
#include "model_ids.h"
#include "seq_ids.h"
#include "dialog_ids.h"
#include "segment_symbols.h"
#include "level_commands.h"

#include "game/level_update.h"

#include "levels/scripts.h"

#include "actors/common1.h"
#include "actors/group0.h"

/* Fast64 begin persistent block [includes] */
/* Fast64 end persistent block [includes] */

#include "make_const_nonconst.h"
#include "levels/ccm/header.h"

/* Fast64 begin persistent block [scripts] */
/* Fast64 end persistent block [scripts] */

const LevelScript level_ccm_entry[] = {
	INIT_LEVEL(),
	LOAD_YAY0(0x07, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_YAY0_TEXTURE(0x09, _snow_yay0SegmentRomStart, _snow_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0B, _effect_yay0SegmentRomStart, _effect_yay0SegmentRomEnd), 
	LOAD_YAY0(0x0A, _ccm_skybox_yay0SegmentRomStart, _ccm_skybox_yay0SegmentRomEnd), 
	LOAD_YAY0(0x05, _group6_yay0SegmentRomStart, _group6_yay0SegmentRomEnd), 
	LOAD_RAW(0x0C, _group6_geoSegmentRomStart, _group6_geoSegmentRomEnd), 
	LOAD_YAY0(0x06, _group16_yay0SegmentRomStart, _group16_yay0SegmentRomEnd), 
	LOAD_RAW(0x0D, _group16_geoSegmentRomStart, _group16_geoSegmentRomEnd), 
	LOAD_YAY0(0x08, _common0_yay0SegmentRomStart, _common0_yay0SegmentRomEnd), 
	LOAD_RAW(0x0F, _common0_geoSegmentRomStart, _common0_geoSegmentRomEnd), 
	LOAD_MIO0(0x7, _ccm_segment_7SegmentRomStart, _ccm_segment_7SegmentRomEnd), 
	LOAD_MIO0(0xa, _water_skybox_mio0SegmentRomStart, _water_skybox_mio0SegmentRomEnd), 
	ALLOC_LEVEL_POOL(),
	MARIO(MODEL_MARIO, 0x00000001, bhvMario), 
	JUMP_LINK(script_func_global_1), 
	JUMP_LINK(script_func_global_7), 
	JUMP_LINK(script_func_global_17), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_03, ccm_geo_00042C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_04, ccm_geo_00045C), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_05, ccm_geo_000494), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_06, ccm_geo_0004BC), 
	LOAD_MODEL_FROM_GEO(MODEL_LEVEL_GEOMETRY_07, ccm_geo_0004E4), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_CABIN_DOOR, cabin_door_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOW_TREE, snow_tree_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_ROPEWAY_LIFT, ccm_geo_0003D0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_BASE, ccm_geo_0003F0), 
	LOAD_MODEL_FROM_GEO(MODEL_CCM_SNOWMAN_HEAD, ccm_geo_00040C), 
	LOAD_MODEL_FROM_GEO(MODEL_BOIS, bois_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_TURNING_PLATFORM, turning_platform_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_GRILLE, grille_geo), 
	LOAD_MODEL_FROM_GEO(MODEL_WOOD_BOX, wood_box_geo), 

	/* Fast64 begin persistent block [level commands] */
	/* Fast64 end persistent block [level commands] */

	AREA(1, ccm_area_1),
		WARP_NODE(0x0A, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF0, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0xF1, LEVEL_BOB, 0x01, 0x0A, WARP_NO_CHECKPOINT),
		WARP_NODE(0x01, LEVEL_CCM, 0x02, 0x02, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_GRILLE, 1550, 10148, 11174, 0, 0, 0, 0x00000000, breaking_surface),
		OBJECT(MODEL_UKIKI, 2022, 10152, 10871, 0, 0, 0, 0x00000000, bhvMonkeyBreakGrill),
		OBJECT(MODEL_NONE, -3481, 2486, -314, 0, 0, 0, 0x02080000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -1852, 3875, -1110, 0, 0, 0, 0x09980000, bhvPoleGrabbing),
		OBJECT(MODEL_NONE, -333, 4993, -2021, 0, 0, 0, 0x09980000, bhvPoleGrabbing),
		OBJECT(MODEL_WOOD_BOX, 1422, 10020, 8904, 0, 0, 0, 0x00000000, bhvPushableMetalBox),
		OBJECT(MODEL_WOOD_BOX, 2346, 10022, 6610, 0, 0, 0, 0x00000000, bhvPushableMetalBox),
		OBJECT(MODEL_RED_COIN, -3602, 9698, 10452, 0, 0, 0, 0x00000000, bhvCoinsred),
		OBJECT(MODEL_RED_COIN, 3771, 463, 2032, 0, 0, 0, 0x00000000, bhvCoinsred),
		OBJECT(MODEL_RED_COIN, -3567, 8735, 1443, 0, 0, 0, 0x00000000, bhvCoinsred),
		OBJECT(MODEL_RED_COIN, 1848, 4204, 10470, 0, 0, 0, 0x00000000, bhvCoinsred),
		OBJECT(MODEL_RED_COIN, 2825, 10936, 5942, 0, 0, 0, 0x00000000, bhvCoinsred),
		OBJECT(MODEL_RED_COIN, -433, 10217, 9399, 0, 0, 0, 0x00000000, bhvCoinsred),
		OBJECT(MODEL_NONE, 1802, 2946, 9711, 0, 0, 0, (2 << 16), bhvFerrisWheelAxle),
		OBJECT(MODEL_NONE, -523, 3827, 9720, 0, 0, 0, (2 << 16), bhvFerrisWheelAxle),
		OBJECT(MODEL_TURNING_PLATFORM, -566, 10250, 9898, 0, 0, 0, 0x00000000, bhvTurningPlatform),
		OBJECT(MODEL_NONE, 0, 0, 0, 0, 0, 0, 0x000A0000, bhvSpinAirborneWarp),
		MARIO_POS(0x01, 0, 0, 0, 0),
		OBJECT(MODEL_NONE, 1518, 10009, 11174, 0, 0, 0, 0x00010000, bhvWarp),
		TERRAIN(ccm_area_1_collision),
		MACRO_OBJECTS(ccm_area_1_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_LEVEL_GRASS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	AREA(2, ccm_area_2),
		WARP_NODE(0x02, LEVEL_CCM, 0x02, 0x02, WARP_NO_CHECKPOINT),
		OBJECT(MODEL_NONE, -13735, 2536, 1609, 0, 0, 0, 0x00020000, bhvWarp),
		TERRAIN(ccm_area_2_collision),
		MACRO_OBJECTS(ccm_area_2_macro_objs),
		SET_BACKGROUND_MUSIC(0x00, SEQ_EVENT_BOSS),
		TERRAIN_TYPE(TERRAIN_GRASS),
		/* Fast64 begin persistent block [area commands] */
		/* Fast64 end persistent block [area commands] */
	END_AREA(),

	FREE_LEVEL_POOL(),
	MARIO_POS(0x01, 0, 0, 0, 0),
	CALL(0, lvl_init_or_update),
	CALL_LOOP(1, lvl_init_or_update),
	CLEAR_LEVEL(),
	SLEEP_BEFORE_EXIT(1),
	EXIT(),
};
