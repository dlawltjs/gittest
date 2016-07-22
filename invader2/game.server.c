#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>
#include <math.h>
#include <pthread.h>

#include <sys/socket.h>
#include <arpa/inet.h>

#include "../engine/engine2d.h"
#include "../mapEditor/map.h"

#include "plane.h"
#include "bullet.h"
#include "alien.h"
#include "packet.h"
#include "plane.h"

pthread_t tid;
struct timespec work_timer;
double acc_tick,last_tick;
double acc_guid_delay_tick;
int bLoop = 1;
int nStep = 1;

int socket_desc;
char read_buffer[2000];

int gnPlayerIndex;

_S_MAP_OBJECT gScreenBuf[2];

_S_MAP_OBJECT gPlayerModel;
_S_MAP_OBJECT gPlasmaModel;
_S_MAP_OBJECT gAlienModel;
_S_MAP_OBJECT gMissileModel;

_S_Plane gPlayerObject[2];
_S_BULLET_OBJECT gBulletObjects[32];
_S_ALIEN_OBJECT gAlienObjects[8];
_S_BULLET_OBJECT gMissileObject[32];


typedef struct _S_PACKET_RECV_POSITIONS {
	unsigned short header; //0
	unsigned short type; //2
	float m_afXpos[2]; //4
	float m_afYpos[2]; //12

} _S_PACKET_RECV_POSITIONS;

void *ListenThread(void *arg)
{
	while(1) {
		if(recv(socket_desc,
			read_buffer,2000,0) < 0) {
			//puts("recv failed");
		}
		_S_PACKET_RECV_POSITIONS *pPacket = (_S_PACKET_RECV_POSITIONS *)read_buffer;
		if(pPacket->header == 1004) {
			gPlayerObject[0].m_fXpos = pPacket->m_afXpos[0];
			gPlayerObject[0].m_fYpos = pPacket->m_afYpos[0];
			gPlayerObject[1].m_fXpos = pPacket->m_afXpos[1];
			gPlayerObject[1].m_fYpos = pPacket->m_afYpos[1];
		}
	}
	return NULL;
}

void *InputThread(void *arg)
{
	float xpos = 30;
	float ypos = 20;

	while(1)
	{
		if(kbhit() != 0 ) {

			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
				puts("bye~ \r");
			}

			switch(ch) {
				case 'w':
					ypos -= 1;
					break;
				case 's':
					ypos += 1;
					break;
				case 'a':
					xpos -= 1;
					break;
				case 'd':
					xpos += 1;
					break;

				case 'j':
					for(int i=0;i<sizeof(gMissileObject)/sizeof(_S_BULLET_OBJECT);i++) {
						double vx,vy,c;
						vx = gAlienObjects[i].m_fXpos - gPlayerObject[0].m_fXpos;
						vy = gAlienObjects[i].m_fYpos - gPlayerObject[0].m_fYpos;
						c = sqrt(vx*vx+vy*vy);
						vx /= c;
						vy /= c;

						_S_BULLET_OBJECT *pObj = &gMissileObject[i];


						if(pObj->m_nFSM == 0) { //슬립상태라면..
							pObj->pfFire(pObj,gPlayerObject[0].m_fXpos,gPlayerObject[0].m_fYpos,5.0,vx,vy,10);
							break;
						}

					}
					break;
	
				case 'k':
					for(int i=0;i<sizeof(gMissileObject)/sizeof(_S_BULLET_OBJECT);i++) {
						double vx,vy,c;
						vx = gAlienObjects[i].m_fXpos - gPlayerObject[1].m_fXpos;
						vy = gAlienObjects[i].m_fYpos - gPlayerObject[1].m_fYpos;
						c = sqrt(vx*vx+vy*vy);
						vx /= c;
						vy /= c;

						_S_BULLET_OBJECT *pObj = &gMissileObject[i];


						if(pObj->m_nFSM == 0) { //슬립상태라면..
							pObj->pfFire(pObj,gPlayerObject[1].m_fXpos,gPlayerObject[1].m_fYpos,5.0,vx,vy,10);
							break;
						}

					}
					break;


			}

			_S_PACKET_REQ_SETPOS packet_setpos = {
				{
					1004,
					200,
				},
				gnPlayerIndex,
				xpos,
				ypos

			};
			if(send(socket_desc,
						&packet_setpos,
						sizeof(packet_setpos),0) < 0) {
				puts("send failed");
			}

		}
		

	}
	return NULL;
}


int main(int argc,char *argv[])
{
	if(argc < 2) {
		gnPlayerIndex = 0;
	}
	else {
		gnPlayerIndex = atoi(argv[1]);
	}

	printf("ready player %d \r\n",gnPlayerIndex);
	

	//소켓 연결 시도...
	struct sockaddr_in server;

	socket_desc = socket(AF_INET,SOCK_STREAM,0);
	if(socket_desc == -1)
	{
		puts("err create socket");
	}
	
	//server.sin_addr.s_addr = inet_addr("127.0.0.1");
	server.sin_addr.s_addr = inet_addr("192.168.0.26");

	server.sin_family = AF_INET;
	server.sin_port = htons(8080);
	if(connect(socket_desc,(struct sockaddr *)&server,sizeof(server)) < 0) {
		puts("connect error");
		return 1;
	}

	puts("connect ok!");
	
	//쓰레드 기동 ..
	{
		int err = pthread_create(&tid,NULL,&InputThread,NULL);
		if(err != 0) {
			printf("err : %s \r\n",strerror(err));
		}
		else {
			printf("thread create success \r\n");
		}
	}

	{
		int err = pthread_create(&tid,NULL,&ListenThread,NULL);
		if(err != 0) {
			printf("err : %s \r\n",strerror(err));
		}
		else {
			printf("thread create success \r\n");
		}
	}

	puts("system ready!");
	sleep(3);

	//게임 리소스 로딩 
	for(int i=0;i<2;i++)
	{
		map_init(&gScreenBuf[i]);
		map_new(&gScreenBuf[i],60,25);
	}

	map_init(&gPlayerModel);
	map_load(&gPlayerModel,"plane1.dat");

	Plane_init(&gPlayerObject[0],&gPlayerModel,25,20);
	gPlayerObject[0].m_nFSM = 1;

	Plane_init(&gPlayerObject[1],&gPlayerModel,30,20);
	gPlayerObject[1].m_nFSM = 1;

	map_init(&gPlasmaModel);
	map_load(&gPlasmaModel,"plasma.dat");

	map_init(&gAlienModel);
	map_load(&gAlienModel,"alien.dat");

	map_init(&gMissileModel);
	map_load(&gMissileModel,"bullet1.dat");


	for(int i=0;i<sizeof(gMissileObject)/sizeof(_S_BULLET_OBJECT);i++)
	{
		bullet_init(&gMissileObject[i],0,0,0,&gMissileModel);
	}

	for(int i=0;i<10;i++) 
	{
		bullet_init(&gBulletObjects[i],0,0,0,&gPlasmaModel);
	}

	double TablePosition[] = {0,8.0,16.0,24.0};

	for(int i=0;i<4;i++)
	{
		_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
		alien_init(pObj,&gAlienModel);
		pObj->m_fXpos = TablePosition[i];
		pObj->m_fYpos = 2;
		pObj->m_nFSM = 1;
		gAlienObjects[i].m_pBullet = &gBulletObjects[i];

	}



	puts("object setup ok!");
	sleep(1);

	system("clear");

	set_conio_terminal_mode();
	acc_tick=last_tick=0;
	acc_guid_delay_tick = 0;

	while(bLoop) {
		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		for(int i=0;i<sizeof(gMissileObject)/sizeof(_S_BULLET_OBJECT);i++) {
			_S_BULLET_OBJECT *pObj = &gMissileObject[i];
			pObj->pfApply(pObj,delta_tick);

		}

		for(int i=0;i<4;i++ ) 
		{
			_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
			pObj->pfApply(pObj,delta_tick);

		}

		acc_guid_delay_tick += delta_tick;

		if(acc_guid_delay_tick > 1.8) {
			acc_guid_delay_tick = 0;

			for(int i=0;i<4;i+=2) {
				double bullet_pos_x = gBulletObjects[i].m_fXpos;
				double bullet_pos_y = gBulletObjects[i].m_fYpos;

				double target_pos_x = gPlayerObject[0].m_fXpos;
				double target_pos_y = gPlayerObject[0].m_fYpos;

				double vx = target_pos_x - bullet_pos_x;
				double vy = target_pos_y - bullet_pos_y;

				double dist = sqrt(vx*vx+vy*vy);

				vx /= dist;
				vy /= dist;

				gBulletObjects[i].m_fvx = vx;
				gBulletObjects[i].m_fvy = vy;
				
			}
		}

		if(acc_guid_delay_tick > 1.8) {
			acc_guid_delay_tick = 0;

			for(int i=1;i<5;i+=2) {
				double bullet_pos_x2 = gBulletObjects[i].m_fXpos;
				double bullet_pos_y2 = gBulletObjects[i].m_fYpos;

				double target_pos_x2 = gPlayerObject[1].m_fXpos;
				double target_pos_y2 = gPlayerObject[1].m_fYpos;

				double vx2 = target_pos_x2 - bullet_pos_x2;
				double vy2 = target_pos_y2 - bullet_pos_y2;

				double dist2 = sqrt(vx2*vx2+vy2*vy2);

				vx2 /= dist2;
				vy2 /= dist2;

				gBulletObjects[i].m_fvx = vx2;
				gBulletObjects[i].m_fvy = vy2;

			}
		}

		for(int i=0;i<10;i++) {
			if(gBulletObjects[i].m_nFSM != 0) {
				double bullet_pos_x = gBulletObjects[i].m_fXpos;
				double bullet_pos_y = gBulletObjects[i].m_fYpos;

				double target_pos_x = gPlayerObject[0].m_fXpos;
				double target_pos_y = gPlayerObject[0].m_fYpos;

				double vx = target_pos_x - bullet_pos_x;
				double vy = target_pos_y - bullet_pos_y;
				double dist = sqrt(vx*vx+vy*vy);


				double bullet_pos_x2 = gBulletObjects[i].m_fXpos;
				double bullet_pos_y2 = gBulletObjects[i].m_fYpos;

				double target_pos_x2 = gPlayerObject[1].m_fXpos;
				double target_pos_y2 = gPlayerObject[1].m_fYpos;

				double vx2 = target_pos_x2 - bullet_pos_x2;
				double vy2 = target_pos_y2 - bullet_pos_y2;
				double dist2 = sqrt(vx2*vx2+vy2*vy2);


				if(dist < 0.25) {
					gBulletObjects[i].m_nFSM = 0;
					gPlayerObject[0].m_nFSM = 0;

										
					setColor(37,41);
					printf("\n                        game over                           ");
					setColor(37,40);
					gotoxy(0,0);

				}
				
				if(dist2 < 0.25) {
					gBulletObjects[i].m_nFSM = 0;
					gPlayerObject[1].m_nFSM = 0;
				}

			}
		}

		

		for(int i=0;i<4;i++) {
			if(gMissileObject[i].m_nFSM != 0) {
				double bullet_pos_x = gMissileObject[i].m_fXpos;
				double bullet_pos_y = gMissileObject[i].m_fYpos;

				double target_pos_x = gAlienObjects[i].m_fXpos;
				double target_pos_y = gAlienObjects[i].m_fYpos;

				double vx = target_pos_x - bullet_pos_x;
				double vy = target_pos_y - bullet_pos_y;
				double dist = sqrt(vx*vx+vy*vy);

				if(dist < 5.0) {
					gAlienObjects[i].m_nFSM = 0;

				}
			}
		}	

		for(int i=0;i<10;i++) {
			gBulletObjects[i].pfApply(&gBulletObjects[i],delta_tick);

		}




		//타이밍 계산 
		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			gotoxy(0,0);
			map_drawTile(&gScreenBuf[0],0,0,&gScreenBuf[1]);
			
			gPlayerObject[0].pfDraw(&gPlayerObject[0],&gScreenBuf[1]);
			gPlayerObject[1].pfDraw(&gPlayerObject[1],&gScreenBuf[1]);
				for(int i=0;i<4;i++ ) 
			{
				_S_ALIEN_OBJECT *pObj = &gAlienObjects[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);
			}


			for(int i=0;i<10;i++) {
				gBulletObjects[i].pfDraw(&gBulletObjects[i],&gScreenBuf[1]);
			}

			for(int i=0;i<sizeof(gMissileObject)/sizeof(_S_BULLET_OBJECT);i++)
			{
				_S_BULLET_OBJECT *pObj = &gMissileObject[i];
				pObj->pfDraw(pObj,&gScreenBuf[1]);
			}

	
			map_dump(&gScreenBuf[1],Default_Tilepalete);
			acc_tick = 0;
		}

	}

	return 0;

}
