#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <math.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"
#include "alien.h"
#include "bullet.h"
#include "alien.h"

struct timespec work_timer;
double acc_tick,last_tick;
int bLoop = 1;

_S_MAP_OBJECT gScreenBuffer[2];
_S_MAP_OBJECT gAlienModel;
_S_MAP_OBJECT gPlasmaModel;
_S_BULLET_OBJECT gTestBulletObject;
_S_ALIEN_OBJECT gTestAlienObject;
_S_MAP_OBJECT gAlienModel;

_S_Plane gPlayerObject;
_S_BULLET_OBJECT gBulletObjects[32];
_S_ALIEN_OBJECT gAlienObjects[8];

int main()
{	
	system("clear");

	for(int i=0;i<2;i++){
		map_init(&gScreenBuffer[i]);
		map_new(&gScreenBuffer[i],35,16);
	}

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	map_init(&gPlasmaModel);
	map_load(&gPlasmaModel,"plasma.dat");

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");
	
	double TablePosition[] = {0,6.0};

	for(int i=0;i<2;i++)
	{
		_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
		alien_init(pObj,&gAlienModel);
		pObj->m_fXpos = 0;:
		pObj->m_fYpos = 2;
		pObj->m_nFSM = 1;
	}

/*	{
		_S_ALIEN_OBJECT *pObj = &gAlienObjects[1];
		alien_init(pObj,&gAlienModel);
		pObj->m_fXpos = 5;
		pObj->m_fYpos = 2;
		pObj->m_nFSM = 1;
	} //for문으로 만들기
*/

	set_conio_terminal_mode();
	acc_tick=last_tick=0;

	while(bLoop) {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		//실시간 입력
		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}
		}

		for(int i=0;i<2;i++)
		{
			_S_ALIEN_OBJECT *pObj = &gAlienObjects[0];
			pObj->pfApply(pObj,delta_tick);
		}

		//타이밍 계산 
		acc_tick += delta_tick;
		gTestAlienObject.pfApply(&gTestAlienObject,delta_tick);
		gTestBulletObject.pfApply(&gTestBulletObject,delta_tick);

		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuffer[0],0,0,&gScreenBuffer[1]);
			
			for(int i=0;i<2;i++) {
				_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
				pObj->pfDraw(pObj,&gScreenBuffer[1]);
			}

			gTestAlienObject.pfDraw(&gTestAlienObject,&gScreenBuffer[1]);
			gTestBulletObject.pfDraw(&gTestBulletObject,&gScreenBuffer[1]);

			map_dump(&gScreenBuffer[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}

