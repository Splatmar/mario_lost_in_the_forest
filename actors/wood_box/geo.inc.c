#include "src/game/envfx_snow.h"

const GeoLayout wood_box_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, wood_box_Cube_mesh_layer_1),
	GEO_CLOSE_NODE(),
	GEO_END(),
};