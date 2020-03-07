/*****
��Ŀ���ƣ��ɻ���ս
�����ˣ����2��¬��
����ʱ�䣺2018/6/20
��Ŀ˵�����ɻ���ս��Ϸ�����ͨ�����䲻ͬ�ͺŵĵз��ɻ��÷֣��õ�����̼���������飬
�����򵥣��ڵ÷ִﵽһ���̶�ʱ���з��ɻ������ӵ����ٶȣ�Ƶ�ʶ���������
��Ҷ�ܵл��ӵ����ѶȻ����ӣ�ֻ�з�ӦѸ�ٵ���ң��������浽���
*****/
#include <iostream>
#include <graphics.h>
#include<stdio.h>
using namespace std;
void playinterface();
void playergame();
int updatemouse();
int initmouse();
void getgame();
void delIMG();
void displayMap();
void historyinitialization();
void playergame();
void  prsetrainFace();
void gameDescription();
void soundControl();
void historyReading();
PIMAGE enemy_huge[5];//��ɻ���ͼƬ
PIMAGE load_screen[3];
PIMAGE enemy_small[20];
PIMAGE enemy_mudium[10];
PIMAGE bullets_ordinary[20];
PIMAGE hero[5];
PIMAGE Map2,Map4;
PIMAGE Map1,Map3;
PIMAGE enemy_small_death[4];
PIMAGE enemy_mudium_death[4];
PIMAGE enemy_huge_death[6];
PIMAGE hero_death[4];
PIMAGE Button[2];
PIMAGE history_top;
PIMAGE game_over;
MUSIC mus[2];
PIMAGE contin,suspend;
typedef struct enemysmall
{
    int x;
    int y;
    int life;
    int speed;
    int deathtime;
} Enemysmall;
typedef struct enemymudium
{
    int x;
    int y;
    int life;
    int speed;
    int deathtime;
} Enemymudium;
typedef struct enemyhuge
{
    int x;
    int y;
    int life;
    int speed;
    int deathtime;
} Enemyhuge;
typedef struct bulleTour
{
    int x;
    int y;
    int speed;
    int life;
} Bulletour;
typedef struct herO
{
    int x;
    int y;
    int speed;
    int life;
    int socre;
} Hero;
typedef struct history_hishest
{
    int socre;
    int gametimemin;
    int gametimesec;
} Historyhishest;
int g_y1=0,g_y2=-800,g_speed=5;
int g_music=1;
int G_Mouse_X, G_Mouse_Y;   //���λ��
bool G_Mouse_Up;
bool G_Mouse_Down;
bool G_Mouse_Left;
bool G_Mouse_Right;
//���������Ҽ���Ϣ
int initmouse()//������ݳ�ʼ��
{
    G_Mouse_X = 0;
    G_Mouse_Y = 0;
    G_Mouse_Down = false;
    G_Mouse_Left = false;
    G_Mouse_Right = false;
    G_Mouse_Up = false;
    return 0;
}
int updatemouse()//�������ˢ��
{
    mouse_msg msg = { 0 };
    while (mousemsg())//��⵱ǰ�Ƿ��������Ϣ
    {
        msg = getmouse();//��ȡһ�������Ϣ�������ǰ�����Ϣ������û�У���һֱ�ȴ�
        G_Mouse_X = msg.x;
        G_Mouse_Y = msg.y;
        G_Mouse_Down = msg.is_down();
        G_Mouse_Left = msg.is_left();
        G_Mouse_Right = msg.is_right();
        G_Mouse_Up = msg.is_up();
    }
    return 0;
}
void getgame()//ͼƬ��Դ��ȡ
{
    for(int i=0; i<5; i++)
        enemy_huge[i]=ege::newimage();
    for(int i=0; i<3; i++)
        load_screen[i]=newimage();
    for(int i=0; i<20; i++)
    {
        enemy_small[i]=ege::newimage();
    }
    for(int i=0; i<10; i++)
    {
        enemy_mudium[i]=ege::newimage();
    }
    for(int i=0; i<20; i++)
    {
        bullets_ordinary[i]=newimage();
    }
    for(int i=0; i<5; i++)
        hero[i]=newimage();
    for(int i=0; i<4; i++)
    {
        enemy_small_death[i]=newimage();
    }
    for(int i=0; i<4; i++)
    {
        enemy_mudium_death[i]=newimage();
    }
    for(int i=0; i<6; i++)
    {
        enemy_huge_death[i]=newimage();
    }
    for(int i=0; i<4; i++)
    {
        hero_death[i]=newimage();
    }
    Button[0]=newimage();
    Button[1]=newimage();
    game_over=ege::newimage();
    Map1=ege::newimage();
    Map2=newimage();
    Map3=newimage();
    Map4=newimage();
    history_top=ege::newimage();
    contin=newimage();
    suspend=newimage();
    for(int i=0; i<20; i++)
    {
        getimage(enemy_small[i],"pic\\120.png");
    }
    for(int i=0; i<10; i++)
    {
        getimage(enemy_mudium[i],"pic\\140.png");
    }
    for(int i=0; i<20; i++)
    {
        getimage(bullets_ordinary[i],"pic\\007.png");
    }
    getimage(Button[0],"pic\\017.png");
    getimage(Button[1],"pic\\017.png");
    getimage(enemy_small_death[0],"pic\\121.png");
    getimage(enemy_small_death[1],"pic\\122.png");
    getimage(enemy_small_death[2],"pic\\12.png");
    getimage(enemy_small_death[3],"pic\\124.png");
    getimage(enemy_mudium_death[0],"pic\\141.png");
    getimage(enemy_mudium_death[1],"pic\\142.png");
    getimage(enemy_mudium_death[2],"pic\\143.png");
    getimage(enemy_mudium_death[3],"pic\\144.png");
    getimage(enemy_huge_death[0],"pic\\111.png");
    getimage(enemy_huge_death[1],"pic\\112.png");
    getimage(enemy_huge_death[2],"pic\\113.png");
    getimage(enemy_huge_death[3],"pic\\114.png");
    getimage(enemy_huge_death[4],"pic\\115.png");
    getimage(enemy_huge_death[5],"pic\\116.png");
    getimage(hero_death[0],"pic\\131.png");
    getimage(hero_death[1],"pic\\132.png");
    getimage(hero_death[2],"pic\\133.png");
    getimage(hero_death[3],"pic\\134.png");
    getimage(hero[0],"pic\\130.png");
    getimage(hero[1],"pic\\131.png");
    getimage(hero[2],"pic\\132.png");
    getimage(hero[3],"pic\\133.png");
    getimage(hero[4],"pic\\134.png");
    getimage(load_screen[0],"pic\\002.png");
    getimage(load_screen[1],"pic\\003.png");
    getimage(load_screen[2],"pic\\004.png");
    getimage(enemy_huge[0],"pic\\110.png");
    getimage(enemy_huge[1],"pic\\110.png");
    getimage(enemy_huge[2],"pic\\110.png");
    getimage(enemy_huge[3],"pic\\110.png");
    getimage(enemy_huge[4],"pic\\110.png");
    getimage(Map1,"pic\\000.png");
    getimage(Map2,"pic\\001.png");
    getimage(Map3,"pic\\000.png");
    getimage(Map4,"pic\\016.png");
    getimage(game_over,"pic\\018.png");
    getimage(history_top,"pic\\015.png");
    getimage(contin,"pic\\006.png");
    getimage(suspend,"pic\\005.png");
}
void delIMG()//ͼƬ��Դ�ͷ�
{
    for(int i=0; i<5; i++)
    {
        ege::delimage(enemy_huge[i]);
    }
    for(int i=0; i<20; i++)
    {
        ege::delimage(enemy_small[i]);
    }
    for(int i=0; i<10; i++)
    {
        ege::delimage(enemy_mudium[i]);
    }
    for(int i=0; i<3; i++)
    {
        delimage(load_screen[i]);
    }
    for(int i=0; i<5; i++)
    {
        delimage(hero[i]);
    }
    for(int i=0; i<20; i++)
    {
        delimage(bullets_ordinary[i]);
    }
    for(int i=0; i<4; i++)
    {
        delimage(enemy_small_death[i]);
    }
    for(int i=0; i<4; i++)
    {
        delimage(enemy_mudium_death[i]);
    }
    for(int i=0; i<6; i++)
    {
        delimage(enemy_huge_death[i]);
    }
    for(int i=0; i<4; i++)
    {
        delimage(hero_death[i]);
    }
    delimage(Button[0]);
    delimage(Button[1]);
    ege::delimage(Map1);
    ege::delimage(Map2);
    ege::delimage(Map3);
    ege::delimage(Map4);
    ege::delimage(history_top);
    ege::delimage(contin);
    ege::delimage(suspend);
    ege::delimage(game_over);
}
void displayMap()//��ӡ��ͼ
{
    putimage(0,g_y1,Map1);
    putimage(0,g_y2,Map3);
    g_y1=g_y1+g_speed;
    g_y2=g_y2+g_speed;
    if(g_y1==800)
        g_y1=0;
    if(g_y2==0)
        g_y2=-800;

}
void enemyInitialization(Enemyhuge *enemy_big,Enemymudium *enemy_middle,Enemysmall *enemy_little)//�л���ʼ��
{
    randomize();
    for(int i=0,j=0,k=0; i<20||j<10||k<5; i++,j++,k++)
    {
        if(k<5)
        {
            enemy_big[k].x=random(315*5)/5;
            enemy_big[k].y=-random(800)-400;
            enemy_big[k].speed=1;
            enemy_big[k].life=10;
            enemy_big[k].deathtime=5;
        }
        if(i<20)
        {
            enemy_little[i].x=random(429*7)/7;
            enemy_little[i].y=-random(400)-100;
            enemy_little[i].speed=3;
            enemy_little[i].life=1;
            enemy_little[i].deathtime=3;
        }
        if(j<10)
        {
            enemy_middle[j].x=random(412*6)/8;
            enemy_middle[j].y=-random(700)-200;
            enemy_middle[j].speed=2;
            enemy_middle[j].life=3;
            enemy_middle[j].deathtime=3;
        }

    }
}
void enemyAircraft(Enemyhuge *enemy_big,Enemymudium *enemy_middle,Enemysmall *enemy_little,Hero *plane,int speedincrease)//�л����³���
{
    randomize();
    for(int i=0; i<20; i++)
    {
        if((enemy_little[i].y>800)||(enemy_little[i].life==0&&enemy_little[i].deathtime<=0))
        {
            enemy_little[i].x=random(429*7)/7;
            enemy_little[i].y=-random(400)-100;
            enemy_little[i].speed=3;
            if(plane->socre>100)
                enemy_little[i].speed*=speedincrease;
            enemy_little[i].life=1;
            enemy_little[i].deathtime=3;
        }
    }
    for(int j=0; j<10; j++)
    {
        if((enemy_middle[j].y>800)||(enemy_middle[j].life==0&&enemy_middle[j].deathtime<=0))
        {
            enemy_middle[j].x=random(412*6)/8;
            enemy_middle[j].y=-random(700)-200;
            enemy_middle[j].speed=2;
            if(plane->socre>100)
                enemy_middle[j].speed*=speedincrease;
            enemy_middle[j].life=3;
            enemy_middle[j].deathtime=3;
        }
    }
    for(int k=0; k<5; k++)
    {
        if((enemy_big[k].y>800)||(enemy_big[k].life==0&&enemy_big[k].deathtime<=0))
        {
            enemy_big[k].x=random(315*5)/5;
            enemy_big[k].y=-random(800)-400;
            enemy_big[k].speed=1;
            if(plane->socre>100)
                enemy_big[k].speed*=speedincrease;
            enemy_big[k].life=10;
            enemy_big[k].deathtime=5;
        }
    }
}
int  showhighest()//��ʾ��ʷ���
{
    FILE *fp;
    int score;
    Historyhishest scoreHig;
    fp=fopen("historytop.txt","rb");
    if(fp==NULL)
        printf("not open");
    fread(&scoreHig,sizeof(Historyhishest),1,fp);
    score=scoreHig.socre;
    fclose(fp);
    return score;

}
void gamePause(Hero *plane,Enemyhuge *enemy_big,Enemymudium *enemy_middle,Enemysmall *enemy_little,Bulletour *bullet_our,int difftimemin,int difftimesec)//��Ϸ��ͣ
{
    initmouse();
    char timedisplay[20],scoredisplay[20];
    for(; is_run(); delay_fps(60))
    {
        updatemouse();
        cleardevice();
        putimage(0,g_y1,Map1);
        putimage(0,g_y2,Map3);
        putimage_transparent(NULL,suspend,0,0,0);
        if((G_Mouse_X>=0&&G_Mouse_Y>=0&&G_Mouse_X<=38&&G_Mouse_Y<=41&&G_Mouse_Left==true && G_Mouse_Up==true))
        {
            G_Mouse_Left=false;
            G_Mouse_Up=false;
            return;
        }
        ege::setbkmode(TRANSPARENT);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"����");
        sprintf(scoredisplay,"����:%d",plane->socre);
        ege::outtextxy(380,0,scoredisplay);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"����");
        sprintf(timedisplay,"ʱ��:%02d:%02d",difftimemin,difftimesec);
        ege::outtextxy(380,20,timedisplay);
        putimage_transparent(NULL,hero[0],plane->x,plane->y,0);
        ege::putimage_transparent(NULL,enemy_small[0],enemy_little[0].x,enemy_little[0].y,0);
        ege::putimage_transparent(NULL,enemy_small[1],enemy_little[1].x,enemy_little[1].y,0);
        ege::putimage_transparent(NULL,enemy_mudium[0],enemy_middle[0].x,enemy_middle[0].y,0);
        ege::putimage_transparent(NULL,enemy_huge[0],enemy_big[0].x,enemy_big[0].y,0);
        ege::putimage_transparent(NULL,enemy_small[2],enemy_little[2].x,enemy_little[2].y,0);
        ege::putimage_transparent(NULL,enemy_mudium[1],enemy_middle[1].x,enemy_middle[1].y,0);
        ege::putimage_transparent(NULL,enemy_small[3],enemy_little[3].x,enemy_little[3].y,0);
        for(int i=0; i<20; i++)
        {
            if(bullet_our[i].life==1)
                ege::putimage_transparent(NULL,bullets_ordinary[i],bullet_our[i].x,bullet_our[i].y,0);
        }
    }
}
void historyinitialization()//��Ϸ��ʷ��¼��ʼ��
{
    FILE *fp;
    Historyhishest record[11];
    for(int i=0; i<11; i++)
    {
        record[i].socre=0;
        record[i].gametimemin=0;
        record[i].gametimesec=0;
    }
    fp=fopen("historytop.txt","wb");
    if(fp==NULL)
        printf("not open");
    for(int i=0; i<11; i++)
    {
        fwrite(&record[i],sizeof(Historyhishest),1,fp);
    }
    fclose(fp);

}
void historyHishest(Hero *plane,int gametimemin,int gametimesec)//��Ϸ��ʷ��߼�¼
{
    FILE *fp;
    Historyhishest recordgame[11];
    fp=fopen("historytop.txt","rb");
    if(fp==NULL)
        printf("not open");
    for(int i=0; i<10; i++)
        fread(&recordgame[i],sizeof(Historyhishest),1,fp);
    fclose(fp);
    fp=fopen("historytop.txt","wb");
    if(fp==NULL)
        printf("not open");
    for(int i=0; i<10; i++)//������Ϸ������ʱ��
    {
        if(plane->socre>recordgame[i].socre&&i==0)
        {
            for(int j=9; j>=0; j--)
            {
                recordgame[j+1]=recordgame[j];
            }
            recordgame[0].socre=plane->socre;
            recordgame[0].gametimemin=gametimemin;
            recordgame[0].gametimesec=gametimesec;
            break;
        }
        if(plane->socre>=recordgame[i].socre&&i>0)//����Ϸ��������
        {
            for(int j=9; j>=i; j--)
            {
                recordgame[j+1]=recordgame[j];
            }
            recordgame[i].socre=plane->socre;
            recordgame[i].gametimemin=gametimemin;
            recordgame[i].gametimesec=gametimesec;
            break;
        }
    }
    for(int i=0; i<10; i++)
    {
        fwrite(&recordgame[i],sizeof(Historyhishest),1,fp);
    }
    fclose(fp);

}
void gameOver(Hero *plane,int gametimemin,int gametimesec)//��Ϸ����
{
    historyHishest(plane,gametimemin,gametimesec);
    int score;
    char timedisplay[20],gamesocre[20],returninterface[20]="�������˵�";
    char restart[12]="���¿�ʼ";
    char motivational[20]="��Ҫ����,�ٽ�����";
    char motivationals[20]="��ȡ�´�,����Ի�";
    char showscore[20];
    initmouse();
    score = showhighest();
    for(; is_run(); delay_fps(60))
    {

        updatemouse();
        ege::cleardevice();
        putimage(0,0,Map1);
        ege::setbkmode(TRANSPARENT);
        ege::putimage_transparent(NULL,game_over,5,100,0);
        ege::setcolor(RED);
        ege::setfont(40,0,"����");
        sprintf(showscore,"��ʷ��߷�:%d",score);
        ege::outtextxy(115,325,showscore);
        ege::setcolor(BLACK);
        ege::setfont(30,0,"����");
        sprintf(gamesocre,"��Ϸ����:%d",plane->socre);
        ege::outtextxy(160,400,gamesocre);
        ege::setcolor(BLACK);
        ege::setfont(30,0,"����");
        sprintf(timedisplay,"��Ϸʱ��:%02d:%02d",gametimemin,gametimesec);
        ege::outtextxy(160,440,timedisplay);
        ege::setcolor(RED);
        ege::setfont(50,0,"����");
        ege::outtextxy(20,200,motivational);
        ege::setcolor(RED);
        ege::setfont(50,0,"����");
        ege::outtextxy(20,250,motivationals);
        ege::putimage_transparent(NULL,Button[0],148,480,0);
        ege::putimage_transparent(NULL,Button[0],148,550,0);
        ege::setcolor(WHITE);
        ege::setfont(30,15,"����");
        ege::outtextxy(170,495,returninterface);
        ege::setcolor(WHITE);
        ege::setfont(30,15,"����");
        ege::outtextxy(175,565,restart);
        if(G_Mouse_X>=170&&G_Mouse_Y>=495&&G_Mouse_X<=320&&G_Mouse_Y<=525&&G_Mouse_Left==true && G_Mouse_Up==true)
        {
            G_Mouse_Left=false;
            G_Mouse_Up=false;
            initgraph(320,568);
            playinterface();
        }
        else if(G_Mouse_X>=175&&G_Mouse_Y>=565&&G_Mouse_X<=295&&G_Mouse_Y<=595&&G_Mouse_Left==true && G_Mouse_Up==true)
        {
            G_Mouse_Left=false;
            G_Mouse_Up=false;
            playergame();

        }

    }
}
void heroDeath(Hero *plane,Enemyhuge *enemy_big,Enemymudium *enemy_middle,Enemysmall *enemy_little,int herodeathtime,int gametimemin,int gametimesec)//�ҷ��ɻ������ж�
{
    for(int i=0; i<4; i++)//�ҷ��ɻ���з��ɻ���ײ���
    {
        if(((enemy_little[i].x+36)>(plane->x+30)&&(enemy_little[i].x+14)<(plane->x+70))&&((enemy_little[i].y+32)>=(plane->y)&&(enemy_little[i].y+8<plane->y+90)))
        {
            plane->life=0;
            break;
        }
        else if((enemy_middle[i].x+55>plane->x+30&&enemy_middle[i].x+15<plane->x+70)&&(enemy_middle[i].y+88>=plane->y&&enemy_middle[i].y+24<plane->y+90)&&i<2)
        {
            plane->life=0;
            break;
        }
        else if((enemy_big[0].x+120>plane->x+30&&enemy_big[0].x+45<plane->x+70)&&(enemy_big[0].y+240>=plane->y&&enemy_big[0].y+105<plane->y+90)&&i==0)
        {
            plane->life=0;
            break;
        }
    }
    if(plane->life==0)//�򵥴�ӡ��ը����
    {
        if(herodeathtime<4)
        {
            ege::putimage_transparent(NULL,hero_death[herodeathtime],plane->x,plane->y,0);
        }
        else if(herodeathtime>=4)
        {
            mus[1].Close();
            gameOver(plane,gametimemin,gametimesec);//������Ϸ
        }

    }
}
void playergame()//��Ϸ������
{
    //getgame();
    initgraph(480,800);
    mus[1].OpenFile("pic\\201.mp3");
    if(g_music==0)
        mus[1].SetVolume(0.0f);
    //historyinitialization();
    int intervaltime=0,herodeathtime=0;
    double starttime,endtime;
    int difftimesec,difftimemin=0,speedincrease=2;
    starttime=fclock();//�����Ϸ��ʼʱ��
    int littledeath[4]= {0},middledeath[2]= {0},bigdeath=0;
    Hero plane;//����һ��Ӣ�۷ɻ�
    plane.x=200;//�ɻ�x��
    plane.y=678;//�ɻ�y��
    plane.life=1;//�ɻ�����
    plane.speed=5;//�ɻ��ٶ�
    plane.socre=0;//��Ϸ����
    char scoredisplay[20],timedisplay[20];//����չʾ���ַ�����ʱ��չʾ���ַ���
    Bulletour bullet_our[20];//20���ӵ�
    for(int i=0; i<20; i++)
    {
        bullet_our[i].speed=6;//�ӵ��ٶ�
        bullet_our[i].life=0;//�ӵ�������
    }
    Enemyhuge enemy_big[5];//5����ɻ�
    Enemymudium enemy_middle[10];//10���зɻ�
    Enemysmall enemy_little[20];//20��С�ɻ�
    enemyInitialization(enemy_big,enemy_middle,enemy_little);//�л���ʼ��
    randomize();//�������ʼ��
    initmouse();
    for(; is_run(); delay_fps(60))
    {
        endtime=fclock();//���ÿһ��ѭ����ʱ��
        updatemouse();
        if(mus[1].GetPlayStatus()==MUSIC_MODE_STOP)//ѭ������
        {
            mus[1].Play(0);
        }
        cleardevice();
        displayMap();//��ӡ��������
        if(plane.life)
            putimage_transparent(NULL,hero[0],plane.x,plane.y,0);//��ӡ�ҷ��ɻ�
        putimage_transparent(NULL,contin,0,0,0);
        if((G_Mouse_X>=0&&G_Mouse_Y>=0&&G_Mouse_X<=42&&G_Mouse_Y<=45&&G_Mouse_Left==true && G_Mouse_Up==true)||keystate(VK_SPACE))//��Ϸ��ͣ
        {
            G_Mouse_Left=false;
            G_Mouse_Up=false;
            gamePause(&plane,enemy_big,enemy_middle,enemy_little,bullet_our,difftimemin,difftimesec);
            initmouse();
        }//endif
        if((keystate(VK_UP)||keystate(87))&&plane.y>0)//�ҷ��ɻ������ƶ�
            plane.y-=plane.speed;
        else if((keystate(VK_DOWN)||keystate(83))&&plane.y<700)//�ҷ��ɻ������ƶ�
            plane.y+=plane.speed;
        else if((keystate(VK_LEFT)||keystate(65))&&plane.x>0)//�ҷ��ɻ������ƶ�
            plane.x-=plane.speed;
        else if((keystate(VK_RIGHT)||keystate(68))&&plane.x<380)//�ҷ��ɻ������ƶ�
            plane.x+=plane.speed;
        if(intervaltime>400)//��ѭ��400�κ����¼���
            intervaltime=0;
        for(int i=0; i<20; i++)//���´�ӡ�ɻ��ӵ�
        {
            if(bullet_our[i].life==0&&((intervaltime/20)-1==i)&&plane.life>0)
            {
                bullet_our[i].x=plane.x+45;
                bullet_our[i].y=plane.y-21;
                bullet_our[i].life=1;
            }//endif
        }

        for(int i=0; i<20; i++)//�ɻ��ӵ��Ĵ�ӡ���ƶ�
        {
            if(bullet_our[i].life>0&&plane.life>0)
            {
                ege::putimage_transparent(NULL,bullets_ordinary[i],bullet_our[i].x,bullet_our[i].y,0);
                bullet_our[i].y-=bullet_our[i].speed;
            }
            if(bullet_our[i].y<-21)
            {
                bullet_our[i].life=0;
            }
        }
        for(int i=0; i<4; i++)//�з��ɻ�����ʱ���ж�
        {
            if(littledeath[i]>3)
            {
                littledeath[i]=0;
            }
            if(middledeath[i]>3&&i<2)
            {
                middledeath[i]=0;
            }
            if(bigdeath>5&&i<1)
            {
                bigdeath=0;
            }
        }
        if(enemy_little[0].life==1)//ÿ���з��ɻ�����ӡ�ͱ�ը��ӡ
            ege::putimage_transparent(NULL,enemy_small[0],enemy_little[0].x,enemy_little[0].y,0);
        else  if(enemy_little[0].life==0)
        {
            ege::putimage_transparent(NULL,enemy_small_death[littledeath[0]],enemy_little[0].x,enemy_little[0].y,0);
            littledeath[0]++;
            enemy_little[0].deathtime--;
        }
        if(enemy_little[1].life==1)
            ege::putimage_transparent(NULL,enemy_small[1],enemy_little[1].x,enemy_little[1].y,0);
        else if(enemy_little[1].life==0)
        {
            ege::putimage_transparent(NULL,enemy_small_death[littledeath[1]],enemy_little[1].x,enemy_little[1].y,0);
            littledeath[1]++;
            enemy_little[1].deathtime--;
        }

        if(enemy_middle[0].life>=1)
            ege::putimage_transparent(NULL,enemy_mudium[0],enemy_middle[0].x,enemy_middle[0].y,0);
        else if(enemy_middle[0].life==0)
        {
            ege::putimage_transparent(NULL,enemy_mudium_death[middledeath[0]],enemy_middle[0].x,enemy_middle[0].y,0);
            middledeath[0]++;
            enemy_middle[0].deathtime--;
        }
        if(enemy_big[0].life>=1)
            ege::putimage_transparent(NULL,enemy_huge[0],enemy_big[0].x,enemy_big[0].y,0);
        else if(enemy_big[0].life==0)
        {
            ege::putimage_transparent(NULL,enemy_huge_death[bigdeath],enemy_big[0].x,enemy_big[0].y,0);
            bigdeath++;
            enemy_big[0].deathtime--;
        }
        if(enemy_little[2].life==1)
            ege::putimage_transparent(NULL,enemy_small[2],enemy_little[2].x,enemy_little[2].y,0);
        else if(enemy_little[2].life==0)
        {
            ege::putimage_transparent(NULL,enemy_small_death[littledeath[2]],enemy_little[2].x,enemy_little[2].y,0);
            littledeath[2]++;
            enemy_little[2].deathtime--;
        }
        if(enemy_middle[1].life>=1)
            ege::putimage_transparent(NULL,enemy_mudium[1],enemy_middle[1].x,enemy_middle[1].y,0);
        else if(enemy_middle[1].life==0)
        {
            ege::putimage_transparent(NULL,enemy_mudium_death[middledeath[1]],enemy_middle[1].x,enemy_middle[1].y,0);
            middledeath[1]++;
            enemy_middle[1].deathtime--;
        }
        if(enemy_little[3].life==1)
            ege::putimage_transparent(NULL,enemy_small[3],enemy_little[3].x,enemy_little[3].y,0);
        else if(enemy_little[3].life==0)
        {
            ege::putimage_transparent(NULL,enemy_small_death[littledeath[3]],enemy_little[3].x,enemy_little[3].y,0);
            littledeath[3]++;
            enemy_little[3].deathtime--;
        }
        heroDeath(&plane,enemy_big,enemy_middle,enemy_little,herodeathtime,difftimemin,difftimesec);//�ҷ��ɻ�����
        for(int i=0; i<20; i++)
        {
            if(plane.life==0)
                bullet_our[i].life=0;
        }
        enemyAircraft(enemy_big,enemy_middle,enemy_little,&plane,speedincrease);//�л����³���
        for(int i=0; i<20; i++)//��Ϸ��������͵з������ж�
        {
            if(bullet_our[i].x>enemy_little[0].x&&bullet_our[i].x<enemy_little[0].x+51&&bullet_our[i].y<=enemy_little[0].y+39&&bullet_our[i].y>=enemy_little[0].y&&enemy_little[0].life==1&&bullet_our[i].life==1)
            {
                enemy_little[0].life=0;
                plane.socre+=1;
                bullet_our[i].life=0;
            }
            else if(bullet_our[i].x>enemy_little[1].x&&bullet_our[i].x<enemy_little[1].x+51&&bullet_our[i].y<=enemy_little[1].y+39&&bullet_our[i].y>=enemy_little[1].y&&enemy_little[1].life==1&&bullet_our[i].life==1)
            {
                enemy_little[1].life=0;
                plane.socre+=1;
                bullet_our[i].life=0;
            }
            else if(bullet_our[i].x>enemy_little[2].x&&bullet_our[i].x<enemy_little[2].x+51&&bullet_our[i].y<=enemy_little[2].y+39&&bullet_our[i].y>=enemy_little[2].y&&enemy_little[2].life==1&&bullet_our[i].life==1)
            {
                enemy_little[2].life=0;
                plane.socre+=1;
                bullet_our[i].life=0;
            }
            else if(bullet_our[i].x>enemy_little[3].x&&bullet_our[i].x<enemy_little[3].x+51&&bullet_our[i].y<=enemy_little[3].y+39&&bullet_our[i].y>=enemy_little[3].y&&enemy_little[3].life==1&&bullet_our[i].life==1)
            {
                enemy_little[3].life=0;
                plane.socre+=1;
                bullet_our[i].life=0;
            }
            else if(bullet_our[i].x>enemy_middle[0].x&&bullet_our[i].x<enemy_middle[0].x+69&&bullet_our[i].y<=enemy_middle[0].y+89&&bullet_our[i].y>=enemy_middle[0].y&&enemy_middle[0].life>=1&&bullet_our[i].life==1)
            {
                enemy_middle[0].life--;
                if(enemy_middle[0].life==0)
                    plane.socre+=3;
                bullet_our[i].life=0;
            }
            else if(bullet_our[i].x>enemy_middle[1].x&&bullet_our[i].x<enemy_middle[1].x+69&&bullet_our[i].y<=enemy_middle[1].y+89&&bullet_our[i].y>=enemy_middle[1].y&&enemy_middle[1].life>=1&&bullet_our[i].life==1)
            {
                enemy_middle[1].life--;
                if(enemy_middle[1].life==0)
                    plane.socre+=3;
                bullet_our[i].life=0;
            }
            else if(bullet_our[i].x>enemy_big[0].x&&bullet_our[i].x<enemy_big[0].x+165&&bullet_our[i].y<=enemy_big[0].y+246&&bullet_our[i].y>=enemy_big[0].y&&enemy_big[0].life>=1&&bullet_our[i].life==1)
            {
                enemy_big[0].life--;
                if(enemy_big[0].life==0)
                    plane.socre+=5;
                bullet_our[i].life=0;
            }
        }
        //��ȡ��Ϸʱ��
        endtime=fclock();
        ege::setbkmode(TRANSPARENT);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"����");
        sprintf(scoredisplay,"����:%d",plane.socre);//��ӡ��Ϸ����
        ege::outtextxy(380,0,scoredisplay);
        difftimesec=(int) endtime-starttime;
        if(difftimesec>=60)
        {
            difftimemin=difftimesec/60;
            difftimesec=difftimesec%60;
        }
        ege::setbkmode(TRANSPARENT);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"����");
        sprintf(timedisplay,"ʱ��:%02d:%02d",difftimemin,difftimesec);
        ege::outtextxy(380,20,timedisplay);//��ӡ��Ϸʱ��
        for(int i=0; i<4; i++)
        {
            enemy_little[i].y+=enemy_little[i].speed;
        }
        for(int i=0; i<2; i++)
        {
            enemy_middle[i].y+=enemy_middle[i].speed;
        }
        enemy_big[0].y+=enemy_big[0].speed;
        intervaltime++;
        if(plane.life==0)
            herodeathtime++;
    }
    mus[1].Close();
    //delIMG();
}
void  prsetrainFace()//��Ϸ���ؽ���
{

    for(int i=0; i<3; i++)
    {
        cleardevice();
        putimage(0,0,Map1);
        putimage_transparent(NULL,load_screen[i],95,250,0);
        Sleep(500);
    }

    playergame();

}
void gameDescription()//��Ϸ˵��
{
    char text1[50]="�����ƶ�:����W��������������";
    char text2[50]="�����ƶ�:����S��������������";
    char text3[50]="�����ƶ�:����A��������������";
    char text4[50]="�����ƶ�:����D��������������";
    char text7[50]="ͨ���ƶ��ɻ������л������";
    char text8[50]="����,ֱ���ɻ�������";
    char text5[50]="��Ϸ����";
    char text6[12]="�������˵�";
    initmouse();
    for(; is_run(); delay_fps(60))
    {
        updatemouse();
        ege::cleardevice();
        ege::putimage(0,0,Map1);
        ege::setbkmode(TRANSPARENT);
        ege::setcolor(BLACK);
        ege::setfont(40,0,"������κ");
        ege::outtextxy(85,50,text5);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"Courier New");
        ege::outtextxy(40,100,text1);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"Courier New");
        ege::outtextxy(40,130,text2);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"Courier New");
        ege::outtextxy(40,160,text3);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"Courier New");
        ege::outtextxy(40,190,text4);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"Courier New");
        ege::outtextxy(40,210,text7);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"Courier New");
        ege::outtextxy(40,240,text8);
        ege::setcolor(RED);
        ege::setfont(30,0,"������κ");
        ege::outtextxy(95,400,text6);
        if(G_Mouse_X>=95&&G_Mouse_Y>=395&&G_Mouse_X<=220&&G_Mouse_Y<=430)//if
        {
            ege::setcolor(BLUE);
            ege::setfont(30,0,"������κ");
            ege::outtextxy(95,400,text6);
            if(G_Mouse_Left==true && G_Mouse_Up==true)
            {
                G_Mouse_Left=false;
                G_Mouse_Up=false;
                return;
            }

        }//endif


    }

}
void soundControl()//��Ч����
{
    initmouse();
    char soundswitch[10]="��Ч����";
    char soundopen[5]="��";
    char soundshut[5]="��";
    char text6[12]="�������˵�";

    for(; is_run(); delay_fps(60))
    {
        updatemouse();
        ege::cleardevice();
        ege::putimage(0,0,Map2);//��ӡ����
        ege::setbkmode(TRANSPARENT);
        ege::setcolor(BLACK);
        ege::setfont(40,0,"������κ");
        ege::outtextxy(90,250,soundswitch);//��ӡ��Ч��������
        if(g_music==1)
            ege::setcolor(BLUE);
        else  ege::setcolor(BLACK);
        ege::setfont(40,0,"������κ");
        ege::outtextxy(140,300,soundopen);//��ӡ��������
        if(G_Mouse_X>=140&&G_Mouse_Y>=300&&G_Mouse_X<=175&&G_Mouse_Y<=340&&G_Mouse_Left==true&&G_Mouse_Up==true)//if
        {
            g_music=1;
            mus[0].SetVolume(1.0f);//������Ч��
            mus[1].SetVolume(1.0f);//������Ч��
            ege::setcolor(BLUE);
            ege::setfont(40,0,"������κ");
            ege::outtextxy(140,300,soundopen);
        }//endif
        if(g_music==0)
            ege::setcolor(BLUE);
        else ege::setcolor(BLACK);
        ege::setfont(40,0,"������κ");
        ege::outtextxy(140,340,soundshut);
        if(G_Mouse_X>=140&&G_Mouse_Y>=340&&G_Mouse_X<=175&&G_Mouse_Y<=380&&G_Mouse_Left==true&&G_Mouse_Up==true)//if
        {
            g_music=0;
            mus[0].SetVolume(0.0f);//�ر���Ч
            mus[1].SetVolume(0.0f);//�ر���Ч
            ege::setcolor(BLUE);
            ege::setfont(40,0,"������κ");
            ege::outtextxy(140,340,soundshut);//��ӡ�ص�����
        }//endif
        ege::setcolor(RED);
        ege::setfont(30,0,"������κ");
        ege::outtextxy(95,400,text6);
        if(G_Mouse_X>=95&&G_Mouse_Y>=395&&G_Mouse_X<=220&&G_Mouse_Y<=430)//if
        {
            ege::setcolor(BLUE);
            ege::setfont(30,0,"������κ");
            ege::outtextxy(95,400,text6);
            if(G_Mouse_Left==true && G_Mouse_Up==true)
            {
                G_Mouse_Left=false ;
                G_Mouse_Up=false;
                return;
            }

        }//endif


    }
}
void historyReading()//���а�
{
    FILE *fp;
    Historyhishest record[11]= {0};//��ʱ�洢��ʷ����
    char ranking[11][50]= {0};//�洢�ַ�����ʽ����ʷ����
    char text6[12]="�������˵�";
    char text5[12]="��Ϸ����";
    char text4[12]="��Ϸʱ��";
    fp=fopen("historytop.txt","rb");//���ļ��Զ��ķ�ʽ
    if(fp==NULL)//�ж��Ƿ��
        printf("not open");
    for(int i=0; i<11; i++)//�����ļ�����
    {
        fread(&record[i],sizeof(Historyhishest),1,fp);
    }
    fclose(fp);//�ر��ļ�
    fp=fopen("historytop.txt","wb");//���´��ļ���д�ķ�ʽ
    if(fp==NULL)
        printf("not open");
    for(int i=0; i<11; i++)//����������д��ȥ
    {
        fwrite(&record[i],sizeof(Historyhishest),1,fp);
    }
    fclose(fp);
    initmouse();
    for(; ege::is_run(); delay_fps(60))
    {
        ege::cleardevice();
        ege::putimage(0,0,Map4);//��ӡ����
        ege::putimage_transparent(NULL,history_top,0,20,0);//��ӡ��ʷ��ߵ�ͼƬ
        //ege::putimage_transparent(NULL,)
        ege::setbkmode(TRANSPARENT);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"������κ");
        ege::outtextxy(110,100,text5);
        ege::setcolor(BLACK);
        ege::setfont(20,0,"������κ");
        ege::outtextxy(210,100,text4);
        updatemouse();
        for(int i=0; i<10; i++)//��ӡ��Ϸ��ʷ����
            sprintf(ranking[i],"top%3d:%7d%7d:%02d",i+1,record[i].socre,record[i].gametimemin,record[i].gametimesec);
        for(int i=0; i<10; i++)//��ӡ����
        {
            ege::setcolor(BLACK);
            ege::setfont(20,0,"Courier New");
            ege::outtextxy(20,120+20*i,ranking[i]);
        }
        ege::setcolor(BLACK);
        ege::setfont(40,0,"������κ");
        ege::outtextxy(60,395,text6);
        if(G_Mouse_X>=60&&G_Mouse_Y>=395&&G_Mouse_X<=260&&G_Mouse_Y<=435)//if
        {
            ege::setcolor(BLUE);
            ege::setfont(40,0,"������κ");
            ege::outtextxy(60,395,text6);
            if(G_Mouse_Left==true && G_Mouse_Up==true)//�������˵�
            {
                G_Mouse_Left=false;
                G_Mouse_Up=false;
                return;
            }

        }//endif

    }
}
void playinterface()//���˵�����
{
    char text[10]="��ʼ��Ϸ";
    char text1[10]="�뿪��Ϸ";
    char text2[10]="��ʷ���";
    char text3[10]="ϵͳ����";
    char text4[10]="��Ϸ˵��";
    setcaption("�ɻ���ս");
    //historyinitialization();
    initmouse();
    getgame();//��ȡͼƬ
    mus[0].OpenFile("pic\\200.mp3");//�������ļ�
    if(g_music==0)//�ж��Ƿ�ر�����
        mus[0].SetVolume(0.0f);
    for(; is_run(); delay_fps(60))//������û�رվͼ���ѭ��
    {
        if(mus[0].GetPlayStatus()==MUSIC_MODE_STOP)//ѭ������
        {
            mus[0].Play(0);
        }

        ege::cleardevice();//����
        ege::putimage(0,0,Map2);//��ӡ���˵�����
        ege::setbkmode(TRANSPARENT);//���ֱ���͸����
        updatemouse();//��������Ϣ
        if(G_Mouse_X>=90&&G_Mouse_Y>=245&&G_Mouse_X<=220&&G_Mouse_Y<=280)//����������λ����������ɫ�ı� if
        {

            ege::setcolor(BLUE);//����������ɫ
            ege::setfont(30,0,"�����п�");//�������ִ�С�ͷ��
            ege::outtextxy(95,250,text);//��ӡ����
            if(G_Mouse_Left==true && G_Mouse_Up==true)//�ж��Ƿ������
            {
                G_Mouse_Left=false;//����������ʼ��
                G_Mouse_Up=false;//����갴�³�ʼ��
                mus[0].Close();//�ر�����
                prsetrainFace();//������Ϸ������
            }
        }
        else
        {
            ege::setcolor(RED);
            ege::setfont(30,0,"�����п�");
            ege::outtextxy(95,250,text);
        }//endif
        if(G_Mouse_X>=90&&G_Mouse_Y>=295&&G_Mouse_X<=220&&G_Mouse_Y<=330)//if
        {
            ege::setcolor(BLUE);
            ege::setfont(30,0,"�����п�");
            ege::outtextxy(95,300,text2);
            if(G_Mouse_Left==true && G_Mouse_Up==true)
            {
                G_Mouse_Left=false;
                G_Mouse_Up=false;
                historyReading();//��Ϸ��Ϸ���а�
            }
        }
        else
        {
            ege::setcolor(RED);
            ege::setfont(30,0,"�����п�");
            ege::outtextxy(95,300,text2);
        }//endif
        if(G_Mouse_X>=90&&G_Mouse_Y>=345&&G_Mouse_X<=220&&G_Mouse_Y<=380)//if
        {
            ege::setcolor(BLUE);
            ege::setfont(30,0,"�����п�");
            ege::outtextxy(95,350,text3);
            if(G_Mouse_Left==true && G_Mouse_Up==true)
            {
                G_Mouse_Left=false;
                G_Mouse_Up=false;
                soundControl();
            }
        }
        else
        {
            ege::setcolor(RED);
            ege::setfont(30,0,"�����п�");
            ege::outtextxy(95,350,text3);
        }//endif
        if(G_Mouse_X>=90&&G_Mouse_Y>=395&&G_Mouse_X<=220&&G_Mouse_Y<=430)//if
        {
            ege::setcolor(BLUE);
            ege::setfont(30,0,"�����п�");
            ege::outtextxy(95,400,text1);
            if(G_Mouse_Left==true && G_Mouse_Up==true)
            {
                delIMG();
                closegraph();//�رմ���
                exit(0);//�˳�����
            }
        }
        else
        {
            ege::setcolor(BLACK);
            ege::setfont(30,0,"�����п�");
            ege::outtextxy(95,400,text1);
        }//endif
        if(G_Mouse_X>=90&&G_Mouse_Y>=445&&G_Mouse_X<=220&&G_Mouse_Y<=480)//if
        {
            ege::setcolor(BLUE);
            ege::setfont(30,0,"�����п�");
            ege::outtextxy(95,450,text4);
            if(G_Mouse_Left==true && G_Mouse_Up==true)
            {
                G_Mouse_Left=false;
                G_Mouse_Up=false;
                gameDescription();//������Ϸ˵��
            }
        }
        else
        {
            ege::setcolor(RED);
            ege::setfont(30,0,"�����п�");
            ege::outtextxy(95,450,text4);
        }//endif
        if(keystate(VK_ESCAPE))//����esc���˳���Ϸ
        {
            delIMG();
            closegraph();
            exit(0);
        }
    }
    mus[0].Close();//�ر�����
    delIMG();//�ͷ���ϷͼƬ��Դ

}
int main()
{
    ege::setinitmode(0);
    initgraph(320,568);//��һ������
    playinterface();//������Ϸ���˵�
    getch();
    closegraph();//�رմ���
    return 0;
}
