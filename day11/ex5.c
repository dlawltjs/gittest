#include <stdio.h>
#include <stdlib.h>
#include "../mapEditor/map.h"

void map_drawTile_trn()
{

}

int main()
{
	_S_MAP_OBJECT screenBuffer;
	map_init(&screenBuffer);

	map_new(&screenBuffer,16,16);

	map_PutTile(&screenBuffer,5,5,4);
	map_PutTile(&screenBuffer,4,5,4);
	map_PutTile(&screenBuffer,3,5,4);




	_S_MAP_OBJECT humanObj;
	map_init(&humanObj);
	map_load(&humanObj,"human.dat");

	puts("----------------");

	//map_drawTile(&humanObj,5,5,&screenBuffer);
	map_dump(&screenBuffer,Default_Tilepalette);



	return 0;
}
