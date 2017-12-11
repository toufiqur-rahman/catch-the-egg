/*
	author: MD.Toufiqur Rahman
	last modified: 2014
*/
# include "iGraphics.h"
# include<sstream>
# include<string>
using namespace std;
   int pic_x, pic_y;
   int game_over_x = -701, game_over_y = 200;
   int eg1_x = 105, eg1_y = -405;
   int eg2_x = 305, eg2_y = -405;
   int eg3_x = 505, eg3_y = -405;
   int eg4_x = 705, eg4_y = -405;
   int egg_height = 10;
   int fall_per_mil_sec = 5;
   int random = 1;
   int speed_counter = 0;
   int score = 0;
   int t,s;
   char scoreString[100]= "0";

   int life = 10;
   char lifeString[10] = "10";

   string NumberToString(int number);

/*
	function iDraw() is called again and again by the system.
*/
void iDraw()
{
	//place your drawing codes here
	iClear();


	iShowBMP(00, 400, "murgi1.bmp");
	iShowBMP(200, 400, "murgi2.bmp");
	iShowBMP(400, 400, "murgi3.bmp");
	iShowBMP(600, 400, "murgi4.bmp");
	iShowBMP(00, 200, "blue1.bmp");
	iShowBMP(200, 200, "blue2.bmp");
	iShowBMP(400, 200, "blue3.bmp");
	iShowBMP(600, 200, "blue4.bmp");
        iShowBMP(00, 00, "green1.bmp");
	iShowBMP(200, 00, "green2.bmp");
	iShowBMP(400, 00, "green3.bmp");
	iShowBMP(600, 00, "green4.bmp");
        iFilledEllipse(eg1_x, eg1_y, 7, egg_height);
	iFilledEllipse(eg2_x, eg2_y, 7, egg_height);
	iFilledEllipse(eg3_x, eg3_y, 7, egg_height);
	iFilledEllipse(eg4_x, eg4_y, 7, egg_height);
	iShowBMP(pic_x,pic_y, "bus.bmp");
	iText(20, 15, "LIFE", GLUT_BITMAP_HELVETICA_18);
	iText(70, 15, lifeString, GLUT_BITMAP_HELVETICA_18);
	iText(550, 15, "SCORE", GLUT_BITMAP_HELVETICA_18);
	iText(650, 15, scoreString, GLUT_BITMAP_HELVETICA_18);
	iShowBMP(game_over_x, game_over_y, "game_over.bmp");


}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouseMove(int mx, int my)
{
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
*/
void iMouse(int button, int state, int mx, int my)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
	if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		//place your codes here
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
*/
void iKeyboard(unsigned char key)
{
	if(key == 'p')
	{
		iPauseTimer(t);
		iPauseTimer(s);
		//do something with 'q'
	}
	if(key == 'r')
    {
		iResumeTimer(t);
		iResumeTimer(s);
	}
	//place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
*/
void iSpecialKeyboard(unsigned char key)
{

	if(key == GLUT_KEY_END)
	{
		exit(0);
	}
	if(key == GLUT_KEY_LEFT)
	{
		if(pic_x!=60)
			pic_x = pic_x-200;
	}
	if(key == GLUT_KEY_RIGHT)
	{
		if(pic_x!=660)
		 pic_x = pic_x+200;

	}


		//exit(0);

	//place your codes for other keys here
}

void eggOneInit()
{
	eg1_x=105;
	eg1_y=405;
}


void eggTwoInit()
{
	eg2_x=305;
	eg2_y=405;
}

void eggThreeInit()
{
	eg3_x=505;
	eg3_y=405;
}

void eggFourInit()
{
	eg4_x=705;
	eg4_y=405;
}

void scoreUpdate()
{
	if(eg1_y>119 && eg1_y <166)
	{
		if(pic_x>59 && pic_x<161)
		{
			score +=5;
			eg1_y = -10;
			//scoreString = NumberToString(score)
			strcpy(scoreString,NumberToString(score).c_str());

		}
	}
	else if(eg2_y>119 && eg2_y <166)
	{
		if(pic_x>259 && pic_x<361)
		{
			score +=5;
			eg2_y = -10;
			strcpy(scoreString,NumberToString(score).c_str());
			printf("%d",score);

		}
	}
	else if(eg3_y>119 && eg3_y <166)
	{
		if(pic_x>459 && pic_x<561)
		{
			score +=5;
			eg3_y = -10;
			strcpy(scoreString,NumberToString(score).c_str());
			printf("%d",score);
		}
	}
	else if(eg4_y>119 && eg4_y <166)
	{
		if(pic_x>659 && pic_x<761)
		{
			score +=5;
			eg4_y = -10;
			strcpy(scoreString,NumberToString(score).c_str());

			printf("%d",score);
		}
	}



}


void fall()
{


	scoreUpdate();

	eg1_y -= fall_per_mil_sec;
	if(eg1_y<= 120 && eg1_y>=0)
	{
		strcpy(lifeString,NumberToString(life).c_str());
		eg1_y = -10;
		life --;
	}
	eg2_y -= fall_per_mil_sec;
	if(eg2_y<= 120 && eg2_y>=0)
	{
		 strcpy(lifeString,NumberToString(life).c_str());
		 eg2_y = -10;
		 life--;
	}
	eg3_y -= fall_per_mil_sec;
	if(eg3_y<= 120 && eg3_y>=0)
	{
		strcpy(lifeString,NumberToString(life).c_str());
		eg3_y = -10;
		life--;
	}
	eg4_y -= fall_per_mil_sec;
	if(eg4_y<= 120 && eg4_y>=0)
	{
		strcpy(lifeString,NumberToString(life).c_str());
		eg4_y = -10;
		life--;
	}
	if(life == -1)
	{
		iPauseTimer(t);
		iPauseTimer(s);
		game_over_x = 101;
		game_over_y = 200;

	}



}

void positionInitiator()
{
	speed_counter +=1;
	if(speed_counter==10)
	{
		speed_counter = 0;
		fall_per_mil_sec +=5;
	}

	random = rand() % 4+1;
	if(random==1 && eg1_y<0)
		eggOneInit();
	else if(random==2 && eg2_y<0)
		eggTwoInit();
	else if(random==3 && eg3_y<0)
		eggThreeInit();
	else if(random==4 && eg4_y<0)
		eggFourInit();
}

int main()
{

	//place your own initialization codes here.

	pic_x=60;
	pic_y=65;

        s=iSetTimer(1,fall);
	t=iSetTimer(1000,positionInitiator);

	iInitialize(800, 600, "demooo");


	//for(eg1_y=405;eg1_y<=55;eg1_y--)
	//{
	//	iDraw();
	//}

	//iSpecialKeyboard(GLUT_KEY_UP);


	return 0;
}

string NumberToString(int number)
{
	stringstream ss;
	ss<<number;
	return ss.str();
}
