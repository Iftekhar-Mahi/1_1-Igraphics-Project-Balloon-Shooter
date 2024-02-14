# include "iGraphics.h"
#define screenwidth 1000
#define screenheight 600
#include<stdlib.h>
#include <string.h>
#include<math.h>
#include<time.h>
void ballchange();
void bullet_move();
void draw_balloon();
void colchk();
void colchk_2_0();
void numbergen();
void storeScore();
void leadbrd();///showing in leade
//void levelChk();
void game_saver();
void game_loader();
void new_game();

bool playmusic=true;
bool balloon_present=true;
bool paused=false;
bool music=false;
bool vfx=true;
/*
 function iDraw() is called again and again by the system.
*/
char player_name[100] = {0}; // initializing all characters to null character (as the ASCII value of null character is zero)
char remain[10];
int strIdx = -1;
int lvl=1;
int pageidx=10;
int scored=0;//just integer e score
char score[10];
char level[10];///level r nam
int j=4,k=3,p=0,q=2,m=1;
int shot=0;
int ballradius=60;
int xball=700;
int yball=100;
int yline=0;
int xbullet=30;
int ybox=335;
int xbox=0;
int dx=40;
int dy=5;
int red=255,green=255,blue=0;
int scoreTemp[6];//for score
char scoreName[6][100];//player r nam


typedef struct
{

    int lvl;
    int bltrmn;
    int scr;
} game_state;




typedef struct
{
    char nam[100];
    char point[25];
} leaderboard;
leaderboard show[5];


typedef struct
{
    double x,y;
    int fired=0;
} Bullet;

const int MAX_BULLETS = 15;
int remainbullet=MAX_BULLETS;
Bullet blt[MAX_BULLETS];

typedef struct
{
    double x,y,rad,y2;

    int r,g,b;
    double yc;
    int point;
    bool ball_pres=true;
} Balloon;
Balloon balloo[7]=
{
    {530,80,40,0,190,30,250,7,10},
    {600,50,35,0,85,141,240,6,15},
    {800,40,28,0,250,225,20,3,40},
    {500,60,30,0,125,240,30,5,25},
    {650,50,25,0,255,0,0,6,50},
    {900,80,45,0,250,225,20,8,15},

    {700,70,35,0,255,0,0,5,20}
};

void iDraw()
{
//place your drawing codes here
    iClear();
    if(pageidx==10)
    {

        iShowBMP(0,0,"start.bmp");
        iShowBMP2(210,420,"nam.bmp",0);
        iSetColor(0,0,0);
        iText(450,255,player_name,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(pageidx==11)
    {

        iShowBMP(0,0,"homepageresume.bmp");
        iShowBMP2(30,30,"settings.bmp",0);
    }
    if(pageidx==12)
    {

        iShowBMP(0,0,"sett1.bmp");
        iShowBMP2(900,500,"home.bmp",0);
        if(music){
        iShowBMP2(540,290,"soundon.bmp",0);}
        else
            {iShowBMP2(540,290,"soundoff.bmp",0);}
        if(vfx){
        iShowBMP2(540,190,"soundon.bmp",0);}
        else
            {iShowBMP2(540,190,"soundoff.bmp",0);}


    }



    if(pageidx==0)
    {

        iShowBMP(0,0,"go.bmp");
        iShowBMP2(900,500,"home.bmp",0);
        iText(445,398,player_name,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(608,325,score,GLUT_BITMAP_TIMES_ROMAN_24);

    }
    if(pageidx==1)
    {


        iShowBMP(0,0,"homepage.bmp");//draw_balloon();
        iShowBMP2(900,30,"exit.bmp",0);
        iShowBMP2(30,30,"settings.bmp",0);
    }
    //iSetColor(255,255,255);
    if(pageidx==2)
    {
        if(lvl==1){
        iShowBMP(0,0,"bg2.bmp");}
        else if(lvl==2){
        iShowBMP(0,0,"ice.bmp");}
        else if(lvl==3){
        iShowBMP(0,0,"desert.bmp");}

        iShowBMP2(0,500,"scoreboard.bmp",0);
        //iShowBMP2(0,510,"scrbrd.bmp",16777215);
        iShowBMP2(900,500,"home.bmp",0);
        iShowBMP2(425,500,"level.bmp",0);
        sprintf(level,"%d",lvl);
        iText(535,527,level,GLUT_BITMAP_HELVETICA_18);
        if(paused)
        {
            iShowBMP2(810,500,"play.bmp",0);
        }
        if(!paused)
        {
            iShowBMP2(810,500,"pause.bmp",0);
        }




        iSetColor(balloo[j].r,balloo[j].g,balloo[j].b);
        iFilledCircle(balloo[j].x,balloo[j].y,balloo[j].rad,1000);
        iLine(balloo[j].x,balloo[j].y,balloo[j].x,balloo[j].y2);

        iSetColor(balloo[k].r,balloo[k].g,balloo[k].b);
        iFilledCircle(balloo[k].x,balloo[k].y,balloo[k].rad,1000);
        iLine(balloo[k].x,balloo[k].y,balloo[k].x,balloo[k].y2);

        iSetColor(balloo[p].r,balloo[p].g,balloo[p].b);
        iFilledCircle(balloo[p].x,balloo[p].y,balloo[p].rad,1000);
        iLine(balloo[p].x,balloo[p].y,balloo[p].x,balloo[p].y2);

        iSetColor(balloo[q].r,balloo[q].g,balloo[q].b);
        iFilledCircle(balloo[q].x,balloo[q].y,balloo[q].rad,1000);
        iLine(balloo[q].x,balloo[q].y,balloo[q].x,balloo[q].y2);

        iSetColor(balloo[m].r,balloo[m].g,balloo[m].b);
        iFilledCircle(balloo[m].x,balloo[m].y,balloo[m].rad,1000);
        iLine(balloo[m].x,balloo[m].y,balloo[m].x,balloo[m].y2);

        iShowBMP2(0,ybox,"shooter.bmp",16777215);
        iSetColor(0,0,0);
        colchk_2_0();
        bullet_move();
        sprintf(remain,"%d",remainbullet);
        sprintf(score,"%d",scored);

        iText(200,526,score);

        if(remainbullet>0)
        {
            iText(200,560,remain);
        }
        else
        {
            iText(200,560,"empty");
        }


    }
    if(pageidx==3)
    {
        iShowBMP(0,0,"instructions.bmp");
        iShowBMP2(900,500,"home.bmp",0);

    }
    if(pageidx==4)
    {
        iShowBMP(0,0,"hiscore.bmp");
        iShowBMP2(900,500,"home.bmp",0);
        iSetColor(0,0,0);
        iText(393,300,show[0].nam,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(393,270,show[1].nam,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(393,240,show[2].nam,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(393,210,show[3].nam,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(393,180,show[4].nam,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(575,300,show[0].point,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(575,270,show[1].point,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(575,240,show[2].point,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(575,210,show[3].point,GLUT_BITMAP_TIMES_ROMAN_24);
        iText(575,180,show[4].point,GLUT_BITMAP_TIMES_ROMAN_24);
    }
    if(pageidx==5)
    {
        iShowBMP(0,0,"credits.bmp");
        iShowBMP2(900,500,"home.bmp",0);
    }

    /*iSetColor(20, 200, 0);
    iText(40, 40, player_name);*/

}


/*
 function iMouseMove() is called when the user presses and drags the mouse.
 (mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
    printf("%d %d \n",mx,my);
}
/*
 function iMouse() is called when the user presses/releases the mouse.
 (mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
    if(pageidx==0)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&365<=mx&&mx<=640&&58<=my&&my<=140)
        {
            scoreTemp[5]=scored;
            strcpy(scoreName[5],player_name);
            storeScore();



            new_game();




            pageidx=2;
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&900<=mx&&mx<=970&&500<=my&&my<=570)
        {
            scoreTemp[5]=scored;
            strcpy(scoreName[5],player_name);
            storeScore();
            pageidx=1;
        }
    }

    if(pageidx==11)///resume page
    {


        ///PlaySound("chill.WAV",NULL,SND_ASYNC|SND_LOOP);
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&347<=mx&&mx<=650&&391<=my&&my<=447)
        {
            pageidx=2;

        }

        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&347<=mx&&mx<=650&&324<=my&&my<=377)
        {
            pageidx=3;
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&347<=mx&&mx<=650&&255<=my&&my<=309)
        {
            pageidx=4;
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&347<=mx&&mx<=650&&187<=my&&my<=240)
        {
            pageidx=5;
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&30<=mx&&mx<=100&&30<=my&&my<=100)
        {
            pageidx=12;
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&347<=mx&&mx<=650&&117<=my&&my<=174)
        {
            game_saver();
            exit(0);
        }
    }
    if(pageidx==12){///settings page

        if(paused&&button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&900<=mx&&mx<=970&&500<=my&&my<=570)
        {
            pageidx=11;

        }
        else if(!paused&&button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&900<=mx&&mx<=970&&500<=my&&my<=570)
        {
            pageidx=1;

        }

        if(music&&button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&540<=mx&&mx<=610&&290<=my&&my<=360)
        {
            music=false;
            if(!music)
                PlaySound(0,0,0);

        }
        else if(!music&&button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&540<=mx&&mx<=610&&290<=my&&my<=360)
        {
            music=true;
            if(music)
            PlaySound("chill.WAV",NULL,SND_ASYNC|SND_LOOP);
        }

        if(vfx &&button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&540<=mx&&mx<=610&&190<=my&&my<=260)
        {
            vfx=false;
        }
        else if(!vfx &&button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&540<=mx&&mx<=610&&190<=my&&my<=260)
        {
            vfx=true;
        }

    }

    if(pageidx==1)
    {

        new_game();


        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&900<=mx&&mx<=970&&30<=my&&my<=100)
        {
            exit(0);
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&30<=mx&&mx<=100&&30<=my&&my<=100)
        {
            pageidx=12;
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&347<=mx&&mx<=650&&391<=my&&my<=447)
        {
            pageidx=2;
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&347<=mx&&mx<=650&&324<=my&&my<=377)
        {
            pageidx=3;
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&347<=mx&&mx<=650&&255<=my&&my<=309)
        {
            pageidx=4;
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&347<=mx&&mx<=650&&187<=my&&my<=240)
        {
            pageidx=5;
        }
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&347<=mx&&mx<=650&&117<=my&&my<=174)
        {
            paused=true;
            iPauseTimer(0);
            game_loader();
            pageidx=2;

        }

    }
    if(pageidx==2)
    {


        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&900<=mx&&mx<=970&&500<=my&&my<=570)
        {
            if(!paused)
            {
                scored=0,lvl=1,balloo[0].yc=7,balloo[1].yc=6,balloo[2].yc=3,balloo[3].yc=5,balloo[4].yc=6;//home e back krle abr new game

                remainbullet=MAX_BULLETS;//same
                pageidx=1;
            }
            else if(paused)
            {
                pageidx=11;
            }
        }
        if(!paused&&button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&810<=mx&&mx<=880&&500<=my&&my<=570)
        {
            paused=true;
            iPauseTimer(0);
        }
        else if(paused&&button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&810<=mx&&mx<=880&&500<=my&&my<=570)
        {
            paused=false;
            iResumeTimer(0);
        }

    }
    if(pageidx==3)
    {
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&900<=mx&&mx<=970&&500<=my&&my<=570)
        {
            if(paused)
            {
                pageidx=11;
            }
            else
            {
                pageidx=1;
            }
        }
    }
    if(pageidx==4)
    {

        leadbrd();
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&900<=mx&&mx<=970&&500<=my&&my<=570)
        {
            if(paused)
            {
                pageidx=11;
            }
            else
            {
                pageidx=1;
            }
        }
    }
    if(pageidx==5)
    {

        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN&&900<=mx&&mx<=970&&500<=my&&my<=570)
        {
            if(paused)
            {
                pageidx=11;
            }
            else
            {
                pageidx=1;
            }
        }
    }

    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN&&pageidx==2)
    {
        //xbullet=0;
    }
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
    {
//place your codes here
    }
}

/*function iKeyboard() is called whenever the user hits a key in keyboard.
key- holds the ASCII value of the key pressed.
*/

void iKeyboard(unsigned char key)
{
    if(pageidx==2&&!paused)///*_*
    {
        if(key == 119)
        {
            if(ybox<screenheight-100)
            {
                ybox+=15;
            }
        }
        if(key == 115)
        {
            if(ybox>0)
            {
                ybox-=15;
            }
        }
    }
    if(pageidx==10)///starting page
    {
        if (key == 'q')
        {
            exit(0);
        }
        if(key==13)
        {

            PlaySound("select.WAV",NULL,SND_ASYNC);
            pageidx=1;
        }

        //place your codes for other keys here

        else if(key == 8)   // if the user has pressed on backspace
        {
            if(strIdx >= 0)   // if there is still some character in the string
            {
                player_name[strIdx] = '\0';
                strIdx--;
            }

        }
        else
        {
            PlaySound("click.WAV",NULL,SND_ASYNC);
            strIdx++;
            player_name[strIdx] = key;
        }
    }
}

/*
function iSpecialKeyboard() is called whenver user hits special keys likefunction keys, home, end, pg up, pg down, arraows etc. you have to use
appropriate constants to detect them. A list is:
GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11,
GLUT_KEY_F12, GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN,
GLUT_KEY_PAGE UP, GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END,
GLUT_KEY_INSERT */
void iSpecialKeyboard(unsigned char key)
{
    if(pageidx==2&&!paused && key == GLUT_KEY_RIGHT)///*_*
    {
        if(remainbullet && vfx)
            PlaySound("pistol.WAV",NULL,SND_ASYNC);
        blt[MAX_BULLETS-remainbullet].y=ybox+30;
        blt[MAX_BULLETS-remainbullet].fired=1;
        remainbullet--;
        if(remainbullet==-1&&lvl==1 && scored>=250)                                       //level cng
        {

            lvl++;
            if(vfx)
            PlaySound("lvlup.WAV",NULL,SND_ASYNC);
            remainbullet+=16;
            for(int i=0; i<MAX_BULLETS; i++)
            {
                blt[i].fired=0;
                blt[i].x=0;
                blt[i].y=0;
            }
            balloo[0].yc+=3;
            balloo[1].yc+=3;
            balloo[2].yc+=3;
            balloo[3].yc+=3;
            balloo[4].yc+=3;
        }
        else if(remainbullet==-1&&lvl==2 && scored >=500)
        {
            lvl++;
            if(vfx)
            PlaySound("lvlup.WAV",NULL,SND_ASYNC);
            remainbullet+=16;
            for(int i=0; i<MAX_BULLETS; i++)
            {
                blt[i].fired=0;
                blt[i].x=0;
                blt[i].y=0;
            }
            balloo[0].yc+=6;
            balloo[1].yc+=6;
            balloo[2].yc+=6;
            balloo[3].yc+=6;
            balloo[4].yc+=6;
        }
        //level cng
        else if(remainbullet==-1)
        {
            pageidx=0;
        }
    }

    if(key == GLUT_KEY_END)
    {
        exit(0);
    }

}
//place your codes for other keys here

void draw_balloon()
{

    if(balloo[j].ball_pres)
    {

        balloo[j].y+=balloo[j].yc;
        balloo[j].y2+=balloo[j].yc;
        if(balloo[j].y-80>=screenheight)
        {
            balloo[j].y=0;
            balloo[j].y2=-100;
            balloo[j].x=rand()%500+500;
        }

    }
    if(balloo[k].ball_pres)
    {

        balloo[k].y+=balloo[k].yc;
        balloo[k].y2+=balloo[k].yc;
        if(balloo[k].y-80>=screenheight)
        {
            balloo[k].y=0;
            balloo[k].y2=-100;
            balloo[k].x=rand()%500+500;
        }
    }
    if(balloo[p].ball_pres)
    {

        balloo[p].y+=balloo[p].yc;
        balloo[p].y2+=balloo[p].yc;
        if(balloo[p].y-80>=screenheight)
        {
            balloo[p].y=0;
            balloo[p].y2=-100;
            balloo[p].x=rand()%500+500;
        }
    }
    if(balloo[q].ball_pres)
    {

        balloo[q].y+=balloo[p].yc;
        balloo[q].y2+=balloo[p].yc;
        if(balloo[q].y-80>=screenheight)
        {
            balloo[q].y=0;
            balloo[q].y2=-100;
            balloo[q].x=rand()%500+500;
        }
    }
    if(balloo[m].ball_pres)
    {

        balloo[m].y+=balloo[p].yc;
        balloo[m].y2+=balloo[p].yc;
        if(balloo[m].y-80>=screenheight)
        {
            balloo[m].y=0;
            balloo[m].y2=-100;
            balloo[m].x=rand()%500+500;
        }
    }
}

void bullet_move()
{
    for(int i=0; i<MAX_BULLETS; i++)
    {
        if(blt[i].fired)
        {

            iFilledCircle(blt[i].x,blt[i].y,5);

            blt[i].x+=dx;
        }
        if(blt[i].x>screenwidth)
        {
            blt[i].fired=0;
        }

    }
}

void colchk_2_0()
{
    for(int j=0; j<MAX_BULLETS; j++)
    {
        for(int l=0; l<5; l++)
        {
            double ch=(blt[j].x-balloo[l].x)*(blt[j].x-balloo[l].x)+(blt[j].y-balloo[l].y)*(blt[j].y-balloo[l].y);
            if(sqrt(ch)<balloo[l].rad)
            {
                if(vfx)
                PlaySound("pop.WAV",NULL,SND_ASYNC);
                balloo[l].ball_pres=false;

                balloo[l].y=0,balloo[l].y2=-100,balloo[l].x=rand()%500+500;

                balloo[l].ball_pres=true;

                scored+=balloo[l].point;
            }


        }
    }
}

void storeScore()
{
    FILE *scoreptr = fopen ("score.txt", "r");
    FILE *name = fopen("names.txt", "r");

//
//    fputs(score, scoreptr);
//    fputc('\n', scoreptr);
//
//    fputs(player_name, name);
//    fputc('\n', name);
//

    /***checking if input is correct**/
    for(int i=0; i<5; i++)
    {
        fscanf(name,"%s",scoreName[i]);
        //fgets(scoreName[i],100,name);
        fscanf(scoreptr,"%d",&scoreTemp[i]);
//        fscanf(scoreptr,"%d",&scoreTemp[i]);

    }
//    for(int i=0;i<6;i++){
//            printf("%s %d\n",scoreName[i],scoreTemp[i]);
//
//
//    }
    for(int i=0; i<6; i++)
        for(int j=i+1; j<6; j++)
        {
            if(scoreTemp[i]<scoreTemp[j])
            {
                char tempc[25];
                int temp=scoreTemp[i];
                scoreTemp[i]=scoreTemp[j];
                scoreTemp[j]=temp;

                strcpy(tempc,scoreName[i]);
                strcpy(scoreName[i],scoreName[j]);
                strcpy(scoreName[j],tempc);
            }
        }

    for(int i=0; i<5; i++)
    {
        printf("%s %d\n",scoreName[i],scoreTemp[i]);
    }





    fclose(scoreptr);
    fclose(name);

    scoreptr = fopen ("score.txt", "w");
    name = fopen("names.txt", "w");
    for(int i=0; i<5; i++)
    {
        fputs(scoreName[i],name);
        fputc('\n', name);
        fprintf(scoreptr,"%d\n",scoreTemp[i]);

    }

    fclose(scoreptr);
    fclose(name);
}
void leadbrd()
{
    FILE *scoreptr = fopen ("score.txt", "r");
    FILE *name = fopen("names.txt", "r");

    for(int i=0; i<5; i++)
    {
        fscanf(name,"%s",show[i].nam);
        fscanf(scoreptr,"%s",show[i].point);
    }
}

//void levelChk()
//{
//    if(pageidx==2&&lvl==1&&remainbullet>0&&scored>=10)
//    {
//        remainbullet=MAX_BULLETS;
//        lvl++;
//        for(int i=0; i<7; i++)
//        {
//            balloo[i].yc+=4;
//        }
//    }
//    if(pageidx==2&&lvl==2&&remainbullet>0&&scored>=20)
//    {
//        remainbullet=MAX_BULLETS;
//        lvl++;
//        for(int i=0; i<7; i++)
//        {
//            balloo[i].yc+=7;
//        }
//    }
//}
void game_saver()
{



    FILE *f = fopen("gamestate.txt", "w");

    fprintf(f,"%s %d %d %d %d ",player_name, lvl, remainbullet, scored,ybox);
    for(int i=0; i<5; i++)
    {
        fprintf(f,"%lf %lf %lf %lf ",balloo[i].x,balloo[i].y,balloo[i].y2,balloo[i].yc);
    }
    fclose(f);
}
void game_loader()
{
    FILE *f = fopen("gamestate.txt", "r");

    fscanf(f,"%s%d%d%d%d",player_name,&lvl,&remainbullet, &scored,&ybox);
    for(int i=0; i<5; i++)
    {
        fscanf(f,"%lf%lf%lf%lf",&balloo[i].x,&balloo[i].y,&balloo[i].y2,&balloo[i].yc);
    }
    fclose(f);

}
void new_game()
{
    scored=0,ybox=335,lvl=1,remainbullet=MAX_BULLETS;
    balloo[0].yc=7,balloo[1].yc=6,balloo[2].yc=3,balloo[3].yc=5,balloo[4].yc=6;
    for(int i=0; i<MAX_BULLETS; i++)
    {
        blt[i].fired=0;
        blt[i].x=0;
        blt[i].y=0;
    }
}


int main()
{
    iSetTimer(5,draw_balloon);
    srand(time(NULL));
    iInitialize(screenwidth,screenheight, "demooo");


    return 0;
}
