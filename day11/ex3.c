#include <stdio.h>
#include <stdlib.h>

#include "map.h"

int main()
{

	char tile_pallette[] = {'.','#','@'};
		
	_S_MAP_OBJECT test_map;
	map_init(&test_map);

	map_load(&test_map,"car.dat");
	
	puts("----load complete----");

	map_dump(&test_map,tile_pallette);



	return 0;
}
