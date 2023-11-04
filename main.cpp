#include<graphics.h>
#include<iostream>  
#include<conio.h>  
#include<dos.h>   
#include <windows.h>  
#include <time.h> 

#define carX1 300
#define carX2 340
#define carY1 385
#define carY2 455
#define enemyCarWidth 20

void CreateNMoveEnemyCar();

void Start();

void Intr();

void Play();

void CreateMoveEnemyCar(int x, int y, int moveFactor, colors body, colors head)
{
	/// Body of truck
    setcolor(BLACK);
    rectangle(x, y+moveFactor, x+enemyCarWidth, -30+y+moveFactor);
    setfillstyle(SOLID_FILL, body);
    floodfill(x+1, -30+y+moveFactor+1, BLACK);

	/// Head of truck
    setcolor(BLACK);
    rectangle(x+5, y+moveFactor, x+(enemyCarWidth-5), 5+y+moveFactor);
    setfillstyle(SOLID_FILL, head);
    floodfill(x+6, 5+y+moveFactor-1, BLACK);

}

void LifePoint(int x, int y, int r) // Draw life point
{
	setcolor(WHITE);
    setfillstyle(SOLID_FILL, RED);
    circle(x, y, r);
    floodfill(x+1, y+1, WHITE);
}

void Lines(int x, int y, int leng, int &distance, int move)
{

        ///Draw Lines
        for(int i=0; i<700; i+=105)
        {
        	if(move == 1) //move fromtop to bottom
        	{
	            rectangle(x, y+i+distance, x+20, y+i+distance+leng); 
	            setfillstyle(SOLID_FILL, WHITE);
	            floodfill(x+1, y+i+distance+1, WHITE);
	        }
	        else //move from bottom to top
	        {
            	rectangle(x, y+i-distance, x+20, y+i-distance-leng); 
            	setfillstyle(SOLID_FILL, WHITE);
            	floodfill(x+1, y+i-distance-1, WHITE);
			}
        }
        /// For repeat lines
        distance += 15;
        if(distance > 100) distance = - 100;
}

void Rocket(int x, int y, int move)
{	
	//body of rocket
	setfillstyle(SOLID_FILL, RED);
	rectangle(x, y, x+9, y+20); 
	floodfill(x+1, y+1, BLACK);
	if(move == 1) //move from top to bottom
	{
		setfillstyle(SOLID_FILL, BLACK); 
		pieslice(x+5, y+31, 60, 120, 10);
		floodfill(x+5, y+26, BLACK);
	}
	else //move from bottom to top
	{
		setfillstyle(SOLID_FILL, BLACK); 
		pieslice(x+5, y-10, -135, -45, 10);
		floodfill(x+5, y-9, BLACK);
		setfillstyle(SOLID_FILL, YELLOW);
		pieslice(x+5, y+20, -135, -45, 10);
		floodfill(x+5, y+21, BLACK);
	}
}

void Start()
{	
    int dis =- 300;
	while(1)
	{  
    	setactivepage(0);
        setvisualpage(1);
        cleardevice();
		
        /// Border of menu
        setcolor(WHITE);
		Lines(90, 20, 30, dis, 1);
		Lines(490, -210, 30, dis, -1);
        
		/// Text in menu 
        settextstyle(SANS_SERIF_FONT, 0, 1);
        outtextxy(205, 100," |        Truck Game        | ");
        outtextxy(205, 130,"Press S: Start Game");
        outtextxy(205, 160,"Press I: Instructions");
        outtextxy(205, 190,"Press ESC: Exit");
        delay(400);
        
        /// For choices
        if(GetAsyncKeyState('S'))      
        {
			Play();
        }
        else if(GetAsyncKeyState('I'))
        {
			Intr();
        }
        else if(GetAsyncKeyState(27))
        {
            exit(0);
        }
	}
}

void Intr()
{
	while(1)
	{
	setactivepage(0);
	setvisualpage(1);
	cleardevice();
	
	/// Text in instructions
	settextstyle(SANS_SERIF_FONT, 0, 1);
	outtextxy(20, 40,"This is Avoiding Truck Game! Try to avoid the trucks and get the highest");
	outtextxy(235, 70,"score possible.");
	outtextxy(20, 100,"Sometime you can claim life point or rocket to destroy enemy truck.");
	outtextxy(20, 130,"You only have 3 life points, you will lose one life point if you accidentally");
	outtextxy(175, 160,"crash into a truck. Be careful!");
	outtextxy(240, 210,"---Control---");
	outtextxy(230, 240,"> key: go right     ");
	outtextxy(230, 270,"< key: go left        ");
	outtextxy(205, 350,"I: go back to menu");
	
	delay(300);
	
	/// Back to menu
	if(GetAsyncKeyState('I')) Start();
	}
}

void Play()
{

    int roadX1 = 200, roadX2 = 400, roadY1 = -1, roadY2 = 500;
    int roadLineY =- 300;

    int carX = 0, carSpeed = 5;
    int enemyNormal = 0, enemyFast = 0, enemySlow = 0, lastEnemy = 0;
    
    int point1 = -400, point2 = -600;

    int point = 0, life = 3;
    char pointBuffer[10] = {'0'};
    
    int speed = 0;
    
    int rock1 = -500, rock2 = -600;
    int fire1 = 0, fire2 = 0;
    
	while(1)
    {
        setactivepage(0);
        setvisualpage(1);
        cleardevice();

        ///For background
        rectangle(0, 0, 1000, 1000);
        setfillstyle(SOLID_FILL, BROWN);
        floodfill(1, 1, BROWN);
		
        ///For road
        setcolor(WHITE);
        rectangle(roadX1, roadY1, roadX2, roadY2);
        setfillstyle(SOLID_FILL, DARKGRAY);  /// Sets the current fill pattern and fill color
        floodfill(roadX1+1, roadY1+1, WHITE);  ///Fill an enclosed area
		    
        ///Lines in road
		Lines(roadX1+90, 10, 40, roadLineY, 1);

        ///For life and points label
        settextstyle(BOLD_FONT, 0, 2);
        outtextxy(10, 10,"LIFE:");
        outtextxy(10, 40,"POINTS:");
        
        ///For control board
        settextstyle(SANS_SERIF_FONT, 0, 1);
        outtextxy(480, 10,"-Control-");
        outtextxy(460, 30,"> key: right     ");
        outtextxy(460, 52,"< key: left        ");
        outtextxy(460, 74,"S: start over");
        outtextxy(445, 120,"Red car: 5 points");
        outtextxy(442, 140,"Blue car: 3 points ");
        outtextxy(437, 160,"Yellow car: 1 points");
        outtextxy(439, 180,"Green car: 3 points");
        
        ///Drawing circle for life
        switch(life)
        {
        case 0:
            //Choices when life is no longer
            while(1)
			{
	        	if(GetAsyncKeyState('Y'))
	        	{
	       		life = 3;
	       		delay(10000);	       	
	       		break;
	        	}
	        	else if(GetAsyncKeyState('N'))
	        	{
	        	    exit(0);
	        	}
	        	else if(GetAsyncKeyState('S'))
	        	{
	        	    Start();
	        	}
	    	}
        case 1:
            LifePoint(90, 20, 6);
            break;
        case 2:
			LifePoint(90, 20, 6);
			LifePoint(110, 20, 6);
            break;
        case 3:
			LifePoint(90, 20, 6);
			LifePoint(110, 20, 6);
			LifePoint(130, 20, 6);
            break;
        }

        ///Display points
        settextstyle(BOLD_FONT, 0, 2);
        outtextxy(100, 40, pointBuffer);
		
		///Draw our car
        //Body of car
        setcolor(BLACK);
        setfillstyle(SOLID_FILL, BROWN);
        rectangle(carX1+carX, carY1+15, carX2+carX, carY2+5);
        floodfill(301+carX, carY1+16, BLACK);

        setfillstyle(SOLID_FILL, RED);
        rectangle(carX1+5+carX, carY1+20, (carX2-5)+carX, carY2);
        floodfill(306+carX, carY1+21, BLACK);

        //Front of car
        setfillstyle(SOLID_FILL, CYAN);
        rectangle(carX1+5+carX, carY1, (carX2-5)+carX, carY2-55);
        floodfill(306+carX, carY1+1, BLACK);

        //Car wheels
        setfillstyle(SOLID_FILL, BLACK);
        pieslice(carX1+5+carX, carY1+7, 90, 270, 6);
        pieslice(carX1+37+carX, carY1+7, 270, 90, 5);
        
        ///Life point on road
        if (speed < 10){
	        LifePoint(220, point1, 6); //point 1
	        if (point1 >= carY1)
	        {
	            switch(carX + carX1)
	            {
	            case ((220 - 6) - (carX2-carX1)) ... (220 + 6):
	                if(life < 3) life++;
	                point1 = -300;
	            }
	        }
	        point1 += (3 + speed);
	        if (point1 > getmaxy()) //repeat point 1
	        {
	            point1 = - 400;
	        }
	    }
        
        LifePoint(335, point2, 6); //point 2
		if (point2 >= carY1)
        {
            switch(carX + carX1)
            {
            case ((335 - 6) - (carX2-carX1)) ... (335 + 6):
                if(life < 3) life++;
                point2 =  -300;
            }
        }
        point2 += (3 + speed);
        if (point2 > getmaxy()) //repeat point 2
        {
            point2 = - 600;
        }
        
        ///Enemy car 1
        CreateMoveEnemyCar(350, -50, enemySlow, YELLOW, GREEN);
        if (enemySlow >= (carY1 + 50))
        {
            switch(carX + carX1)
            {
            case (350 - (carX2-carX1)) ... (350 + enemyCarWidth):
                life--;
                delay(100);
                enemySlow = - 10;
            }
        }
        ///Enemy car 2
        CreateMoveEnemyCar(300, -100, enemyNormal, BLUE, BROWN);
        if (enemyNormal >= (carY1 + 100))
        {
            switch(carX + carX1)
            {
            case (300 - (carX2-carX1)) ... (300 + enemyCarWidth):
                life--;
                if (speed < 20) speed += 1;
                delay(100);
                enemyNormal = - 10;
            }
        }
        ///Enemy car 3
        CreateMoveEnemyCar(250, -30, enemyFast, RED, CYAN);
        if (enemyFast >= (carY1 + 30))
        {
            switch(carX + carX1)
            {
            case (250 - (carX2-carX1)) ... (250 + enemyCarWidth):
                life--;
                delay(100);
                enemyFast = - 10;
            }
        }
		///Last Enemy car
		if (speed >= 10){
			CreateMoveEnemyCar(200, -100, lastEnemy, GREEN, YELLOW);
	        if (lastEnemy >= (carY1 + 100))
	        {
	            switch(carX + carX1)
	            {
	            case (200 - (carX2-carX1)) ... (200 + enemyCarWidth):
	                life--;
	                delay(100);
	                lastEnemy = - 10;
	            }
	        }
	        lastEnemy += (5 + speed);
    	}
		
        enemySlow += (3 + speed);
        enemyNormal += (5 + speed);
        enemyFast += (8 + speed);


        /// For repeat enemy cars
        if (enemyNormal > getmaxy() + 115)
        {
        	if (speed < 20) speed += 1;
            point += 3;
            itoa(point, pointBuffer, 10);
            enemyNormal = - 30;
        }

        if (enemyFast > getmaxy() + 50)
        {
            point += 5;
            itoa(point, pointBuffer, 10);
            enemyFast = - 30;
        }

        if (enemySlow > getmaxy() + 70)
        {
            point += 1;
            itoa(point, pointBuffer, 10);
            enemySlow = - 30;
        }
        
        if (lastEnemy > getmaxy() + 115)
        {
            point += 3;
            itoa(point, pointBuffer, 10);
            lastEnemy = - 30;
        }

		///For rocket 1
		Rocket(255, rock1, 1);
		
		if (rock1 >= (carY1-20))
        {
            switch(carX + carX1)
            {
            case (255 - (carX2-carX1)) ... (255 + 9):
                fire1 = 1;
            }
        }
        
        if(fire1 == 0)  rock1 += (5 + speed);
		else
		{ 
			Rocket(255, rock1, -1);
			rock1 -= (10 + speed);
			if(rock1 <= (enemyFast - 30) ) 
			{	
				fire1 = 0;
				rock1 = -1100;
				enemyFast = -200;
			}
			else if(rock1 < -9) 
			{
				fire1 = 0;
				rock1 = -1100;
			}
		}
		
		if (rock1 > getmaxy()) //repeat rocket 1
        {
            rock1 = -1100;
        }
        
		///For rocket 2
		Rocket(305, rock2, 1);
		
		if (rock2 >= (carY1-20))
        {
            switch(carX + carX1)
            {
            case (305 - (carX2-carX1)) ... (305 + 9):
                fire2 = 1;
            }
        }
        
        if(fire2 == 0)  rock2 += (6 + speed);
		else
		{ 
			Rocket(305, rock2, -1);
			rock2 -= (11 + speed);
			if(rock2 <= (enemyNormal - 100) ) 
			{	
				if (speed < 20) speed += 1;
				fire2 = 0;
				rock2 = -1100;
				enemyNormal = -200;
			}
			else if(rock2 < -9) 
			{
				fire2 = 0;
				rock2 = -1100;
			}
		}
		
		if (rock2 > getmaxy() ) //repeat rocket 1
        {
            rock2 = -1100;
        }
		
        /// For car movement
        if(GetAsyncKeyState(VK_LEFT)) // Go to left
        {
            if ((carX + carX1) >= roadX1)
                if(speed < 13) carX -= (carSpeed + speed);
                else
				{
					int curSpeed = (carSpeed + speed);
					carX -= curSpeed;
				}
        }
        else if(GetAsyncKeyState(VK_RIGHT)) // Go to right
        {
            if ((carX + carX1 + (carX2-carX1)) <= roadX2)
                if(speed < 13) carX += (carSpeed + speed);
                else
				{
                	int curSpeed = (carSpeed + speed);
					carX += curSpeed;
				} 
        }
        else if(GetAsyncKeyState('S')) // Start over
        {
            Start();
        }
        else if(GetAsyncKeyState('P')) // Pause game
        {
            outtextxy(roadX1-10, roadY2-280, "PAUSE");
            delay(200000);
        }

        //Display game over when life is no longer
        if (life == 0)
        {
            setcolor(WHITE);
            settextstyle(BOLD_FONT, 0, 5);
            outtextxy(roadX1-10, roadY2-280, "Game Over");
            outtextxy(roadX1-195, roadY2-230, "Wait 10s and revive (Y/N)");
            outtextxy(roadX1-100, roadY2-180, "Back to menu (S)");
        }

        delay(100);
    }
}

int main()
{
	int gd = DETECT, gm;
    initgraph(&gd, &gm, "");
  
	Start();
    closegraph();

    return 0;
}