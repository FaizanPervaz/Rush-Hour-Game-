//============================================================================
// Name        : Faizan Pervaz
// Author      : FAST CS Department
// Version     : Latest 2021
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include<string>	//for string operations
#include<cmath> // for basic math functions such as cos, sin, sqrt
#include<fstream>
using namespace std;
	
int choice = 0 ;
int t=0;
int p = 0;	//variables for picking passenger up
int q=0;	//variables for dropping first Passenger
int r=0;	//variables for dropping Second Passenger
int w =0;	//variables for dropping Third Passenger

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
 
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}

int xI = 20, yI = 790; //initially the axis of border
bool menu=1;
bool yellow=0; //for displaying yellow colour taxi
bool red=0;	//for displaying red colour taxi
bool start=0;	//for displaying if starting screen
//for passengers
bool disappear=1;	
bool disappear1=1;
bool disappear2=1;
bool disappear3=1;
bool disappear4=1;
bool last_disappear=1;
string playerName;

void drawCar() {
	
	//bool will be 1 for yellow
	if(yellow)
	{
	DrawSquare(xI, yI, 32, colors[YELLOW]);
	}
	else if(red) //bool will be 1 for red displaying first
	{
	DrawSquare(xI, yI, 32, colors[RED]);
	}
	
	glutPostRedisplay();
}

bool flag = false;
void moveCar() {
	
	if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
}
void playerInput()
{

	
	for(int i = 0;i < 1;i++)
	{
	cout<<"Enter player name: ";
	getline(cin,playerName);
	}

}
/*
 * Main Canvas drawing function.
 * */
bool page=1;
bool leaderboard=0;

void Passenger(bool temp,int number)
{
	if(temp)
	{
		DrawLine( 850 , 70 ,  850 , 100 , 6 , colors[BLUE] );
		DrawCircle(850,110,13,colors[RED]); 
		
		if((xI>=870 && xI<= 890)&&(yI >= 90 && yI <= 130))
		{
		DrawString( 500, 500, "Enter SPACE to Pick the Passenger up!", colors[RED]);
		p=3;
		q=3;
		}
	}
	
	if(number==3)
	{
		DrawSquare(150, 780 ,20,colors[GREEN]);  
	}
}

void Passenger1(bool temp1,int number1)
{
	if(temp1)
	 {
		DrawLine( 570 , 670 ,  570 , 700 , 6 , colors[BLUE] );
		DrawCircle(570,710,13,colors[RED]); 
		
		if((xI>=520 && xI<= 560)&&(yI >= 670 && yI <= 700))
		{
		DrawString( 500, 500, "Enter SPACE to Pick the Passenger up!", colors[RED]);
		p = 1;
		q=1;	
		}
	}
		
	 if(number1==1)
		{
			DrawSquare(550, 450 ,20,colors[GREEN]);  
		}
}

void Passenger2(bool temp2, int number2)
{
	  if(temp2)
	  {
	  	DrawLine( 860 , 550 ,  860 , 580 , 6 , colors[BLUE] );
		DrawCircle(860,585,13,colors[RED]); 
	  	
	  	if((xI>=880 && xI<= 900)&&(yI >= 540 && yI <= 590))
		{
		DrawString( 500, 500, "Enter SPACE to Pick the Passenger up!", colors[RED]);
		p = 2;
		q=2;
		}	
	  }
	  
	  if(number2==2)
	  {
	  	DrawSquare(350, 250 ,20,colors[GREEN]);  
	  }
}

void Passenger3(bool temp3)
{
	if(temp3)
	{
		if((xI>=550 && xI<= 550)&&(yI >= 450 && yI <= 450))
		{
			DrawString( 500, 500, "PRESS ENTER to DROP THE Passenger!", colors[RED]);
			r=1;
		}
	}
}

void Passenger4(bool temp4)
{
	if(temp4)
	{
		if((xI>=350 && xI<= 350)&&(yI >= 250 && yI <= 250))
		{
			DrawString( 500, 500, "PRESS ENTER to DROP THE Passenger!", colors[RED]);
			r=2;
		}
	}
}
int time_rem=180;
void GameDisplay()
{
	
	static int score=0;
	ofstream presentScore;// Storing score in a file
	
	if(menu)
	{	
	DrawSquare(1, 20 ,999999999,colors[WHITE]);
	DrawString(310, 730, "WELCOME TO RUSH HOUR GAME", colors[RED]);
	DrawString(310, 530, "ENTER Y FOR YELLOW TAXI", colors[RED]);
	DrawString(310, 450, "ENTER R FOR RED TAXI", colors[RED]);
	DrawString(310, 380, "ENTER X FOR RANDOM COLOUR TAXI", colors[RED]);
	DrawString(310, 300, "ENTER 1 FOR LEADERBOARD", colors[RED]);
	}
	/*
	if(leaderboard==1)
	{
		if.stream 
	}
	*/
	 if(start)
	{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	
	DrawSquare(1, 20 ,999999999,colors[CYAN]);
	//timer 
	
	if(time_rem>0)
	{           /*Timer decrement for counting time which is initialized by 120 sec or 2 min*/
	time_rem--;
	}
	DrawString(560, 800, "Time Left:" + Num2Str(time_rem) + " secs", colors[RED]);
	DrawString(800, 800, "Score:" + Num2Str(score), colors[SIENNA]);
	
	//For Obstacles and Buildings
	int x=8,y;
	//left horizontal line
	DrawSquare(8, 550 ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, 550 ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, 550 ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, 550 ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, 550 ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, 550 ,50,colors[BLACK]);
	
	// middle vertical line
	x=400;
	y=780;
	
	DrawSquare(400, y ,50,colors[BLACK]);
	y-=49;
	DrawSquare(400, y ,50,colors[BLACK]);
	y-=49;
	DrawSquare(400, y ,50,colors[BLACK]);
	y-=49;
	DrawSquare(400, y ,50,colors[BLACK]);
	y-=49;
	DrawSquare(400, y ,50,colors[BLACK]);
	y-=49;
	DrawSquare(400, y ,50,colors[BLACK]);
	y-=49;
	DrawSquare(400, y ,50,colors[BLACK]);
	y-=49;
	DrawSquare(400, y ,50,colors[BLACK]);
	y-=49;
	DrawSquare(400, y ,50,colors[BLACK]);
	
	//blocks with spaces
	x=0;
	x+=449;
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	
	x+=49;
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	
	//Park
	DrawSquare(590, 510 ,250,colors[GREEN]);
	DrawString( 690, 630, "Park", colors[WHITE]);
	
	//The Grey BOX
	DrawSquare(108, 350 ,100,colors[BLACK]);
	
	//The Rush Hour Box
	DrawSquare(800, 180 ,100,colors[BLACK]);
	DrawCircle(850,230,50,colors[CYAN]);
	DrawString(815, 230, "RUSH", colors[RED]);
	DrawString(815, 200, "HOUR", colors[RED]);
	
	//Round about in Start
	DrawCircle(180,715,60,colors[BLACK]);
	DrawCircle(180,715,40,colors[CYAN]);
	//coordinates for Round about crashing
	if((xI>=90 && xI<= 230)&&(yI >= 630 && yI <= 770))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
	 score-=2;
	}
	
	//bottom middle line 
	x=200;
	y=200;//setting coordinates
	
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;
	DrawSquare(x, y ,50,colors[BLACK]);
	x+=49;

 	DrawLine( 8 , 20 ,  8 , 999 , 10 , colors[BLACK] );
	DrawLine( 1012 , 20 ,  1012 , 999 , 10 , colors[BLACK] );
	
	DrawLine( 4 , 27 ,  1012 , 27 , 15 , colors[BLACK] );
	DrawLine( 4 , 833 ,  1012 , 833 , 15 , colors[BLACK] );
	
	//for passenengers

	Passenger(disappear,q);
	Passenger1(disappear1,q);
	Passenger2(disappear2,q);
	Passenger3(disappear3);
	Passenger4(disappear4);
	 
	if(last_disappear)
	{
		if((xI>=150 && xI<= 150)&&(yI >= 780 && yI <= 780))
		{
			DrawString( 500, 500, "PRESS ENTER to DROP THE Passenger!", colors[RED]);
			r=3;
		}
	}
	
	
	if (w == 1)
	 {
	  DrawSquare(550, 450 ,20,colors[CYAN]);
	  score+=10;
	  } 
	if ( w==2 ){  
	  DrawSquare(350, 250 ,20,colors[CYAN]);
	  score+=10;
	  }
	 if(w==3){
	 	DrawSquare(150, 780 ,20,colors[CYAN]);    
	 score+=10;
	 } 
	  
	 //Extra BOX 
	 DrawSquare(400, 330 ,50,colors[BLACK]); 
	 if((xI>=370 && xI<= 440)&&(yI >= 310 && yI <= 380))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
	 score-=2;
	}
	  
	  
	//TREES
	DrawCircle(985,810,15,colors[GREEN]); // top right tree
	//for stand
	DrawSquare(980, 770 ,10,colors[BROWN]);  
	DrawSquare(980, 779 ,10,colors[BROWN]);  
	DrawSquare(980, 788 ,10,colors[BROWN]);  
	
	DrawCircle(100,120,15,colors[GREEN]); //bottom left  tree
	//for stand
	DrawSquare(94, 79 ,10,colors[BROWN]);  
	DrawSquare(94, 88 ,10,colors[BROWN]);  
	DrawSquare(94, 97 ,10,colors[BROWN]);  
	
	//Third Tree
	DrawLine( 240 , 250 ,  240 , 280 , 6 , colors[BROWN] );
	DrawCircle(240,290,20,colors[GREEN]); 
	
	//Starting flag
	DrawSquare(20, 790 ,35,colors[YELLOW]);  //flag box
	//stand
	DrawSquare(20, 740 ,10,colors[BLACK]); 	
	DrawSquare(20, 749 ,10,colors[BLACK]); 
	DrawSquare(20, 758 ,10,colors[BLACK]);  
	DrawSquare(20, 767 ,10,colors[BLACK]);  
	DrawSquare(20, 776 ,10,colors[BLACK]);
	DrawSquare(20, 783 ,10,colors[BLACK]);
	//Initalizing Stating point
	DrawString( 60, 800, "STARTING POINT", colors[RED]);
	
	//x and y coordinates for the car
	cout<<"car's x: "<<xI<<endl;
	cout<<"car's y: "<<yI<<endl;
	
	DrawLine( 425 , 390 ,  425 , 830 , 6 , colors[CYAN] );
	
	//on hitting obstacles we set the coordinates so that msg can be displayed
	if((xI>=190 && xI<= 260)&&(yI >= 210 && yI <= 300))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
	score-=2;
	}
	
	if((xI>=0 && xI<= 300)&&(yI >= 520 && yI <= 590))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
	score-=2;
	}
	if((xI>=80 && xI<= 200)&&(yI >= 320 && yI <= 440))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	if((xI>=170 && xI<= 690)&&(yI >= 170 && yI <= 240))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	if((xI>=770 && xI<= 890)&&(yI >= 150 && yI <= 270))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	if((xI>=60 && xI<= 110)&&(yI >= 50 && yI <= 130))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
	 	score-=2;
	}
	
	if((xI>=370 && xI<= 440)&&(yI >= 360 && yI <= 800))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	
	if((xI>=560 && xI<= 830)&&(yI >= 480 && yI <= 750))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	if((xI>=940 && xI<= 980)&&(yI >= 740 && yI <= 800))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	if((xI>=860 && xI<= 930)&&(yI >= 360 && yI <= 430))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
		
	if((xI>=760 && xI<= 840)&&(yI >= 360 && yI <= 430))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	if((xI>=660 && xI<= 740)&&(yI >= 360 && yI <= 430))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	
	if((xI>=570 && xI<= 640)&&(yI >= 360 && yI <= 430))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	if((xI>=470 && xI<= 540)&&(yI >= 360 && yI <= 430))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	//whole border
	if(!((xI>=10 && xI<= 970)&&(yI >= 30 && yI <= 790)))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	// the bootom bridge
	DrawRoundRect(200,40,50,100,colors[SIENNA],70);
	DrawRoundRect(250,40,50,100,colors[SIENNA],70);
	DrawRoundRect(300,40,50,100,colors[SIENNA],70);
	DrawRoundRect(350,40,50,100,colors[SIENNA],70);
	DrawRoundRect(400,40,50,100,colors[SIENNA],70);
	DrawRoundRect(450,40,50,100,colors[SIENNA],70);
	DrawRoundRect(500,40,50,100,colors[SIENNA],70);
	DrawRoundRect(550,40,50,100,colors[SIENNA],70);
	DrawRoundRect(600,40,50,100,colors[SIENNA],70);
	DrawRoundRect(650,40,50,100,colors[SIENNA],70);
	//bridge's coordinates
	if((xI>=170 && xI<= 700)&&(yI >= 40 && yI <= 140))
	{
	 DrawString( 500, 500, "Taxi Crashed", colors[RED]);
		score-=2;
	}
	
	
	//Storing score in file
	presentScore.open("score.txt");
	presentScore << playerName << ": "<< score<<endl;
	presentScore.close();
	
	
	
/*
	static int first=rand()%970+1;
	static int second=rand()%790+1;

	if((((first>=170 && first<= 700)&&(second >= 40 && second <= 140))||((first>=470 && first<= 540)&&(second >= 360 && second <= 430))||((first>=570 && first<= 640)&&(second >= 360 && second <= 430))||((first>=660 && first<= 740)&&(second >= 360 && second <= 430))||((first>=760 && first<= 840)&&(second >= 360 && second <= 430))||((first>=860 && first<= 930)&&(second >= 360 && second <= 430))||((first>=940 && first<= 980)&&(second >= 740 && second<= 800))|| ((first>=560 && first<= 830)&&(second >= 480 && second <= 750))||((first>=370 && first<= 440)&&(second >= 360 && second <= 800))||((first>=60 && first<= 110)&&(second >= 50 && second <= 130))||((first>=770 && first<= 890)&&(second >= 150 && second <= 270))||((first>=170 && first<= 690)&&(second >= 170 && second <= 240))||((first>=80 && first<= 200)&&(second >= 320 && second <= 440))||((first>=0 && first<= 300)&&(second >= 520 && second <= 590))||((first>=90 && first<= 230)&&(second >= 630 && second <= 770))|| (!((first>=10 && first<= 970)&&(second >= 30 && second <= 790)))) != ((xI=first)&&(yI=second)))
		{
			DrawCircle(first,second,15,colors[GREEN]); 
		}

	*/

	drawCar();
	}
	
	glutSwapBuffers(); // do not modify this line..

}



/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		xI -= 10;

	} else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		xI += 10;
	} else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
		yI += 10;
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		yI -= 10;
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	
	int first_comp = 20, second_comp = 790;	
		
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;
	}
	
	if(key==49 && t==1)
	page=0;
	
	if(key == 32   && p == 3)
	{
		disappear=0;
	}
	
	if(key == 32   && p == 1)
	{
		disappear1=0;
	}
	
	if(key == 32 && p == 2 )
	{
		disappear2=0;
	}
	
	if(key == 13 && r == 3)
	{
		w=3;
	}
	
	if(key == 13 && r == 1)
	{
		w=1;
	}
	
	if(key == 13  && r == 2 )
	{
		w=2;
	}
	
	if(key == 49)
	{
		choice = 1;
	}
	
	
	if(key == 50 )
	{
		choice = 2;
	}
	
	if(key== 0)
	{
		leaderboard=1;
	}
	
	if(key == 'y')
	{
	yellow=true;
	start=1;
	menu=0;
	}
	else if(key == 'r')
	{
	red=true;
	start=1;
	menu=0;
	}
	
	glutPostRedisplay();
}


/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	//implement your functionality here
	//moveCar();

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(500000.0, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Naveed Ahmad"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(10000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse
	
	playerInput();
	
	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
