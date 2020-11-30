#include <iostream>
#include <graphics.h>
#include <stdlib.h>
#include <time.h>
class tPoint{
	public:
		tPoint(){
			xpos = rand() % 550;
			ypos = rand() % 550;
			color = rand() % 15 - 1;
			move_type = 0;
//flag = rand() % 3;
		}
		int menu(){
			draw();
		}
	private:
	int xpos;
	int ypos;
	int color;
	int move_type;
	int flag;
	void draw(){
		setcolor(color);
		circle(xpos,ypos,3);
		this->move_r();
	}


	int randomMove(){
		srand(time(0));
		int a = rand()%2+1;
		return a;
 	}



	int reflective(){
		if(xpos >= 580||xpos <= 20||(ypos >= 580)||ypos <= 20)
			return 0;
		else
			return 1;
	}

	void move_r()
	{

		if(xpos >= 580) move_type = 4;
		if(xpos <= 20) move_type = 5;
		if(ypos >= 580) move_type = 6;
		if(ypos <= 20) move_type = 7;
		switch(move_type)
		{
			case 0: xpos+=3; ypos-=3; break;

			case 4:
			xpos-=3;
			if(randomMove()==1&&reflective())
				ypos+=3;
			else if(randomMove()==2&&reflective())
				ypos-=3;
			break;
			case 5:
			xpos+=3;
			if(randomMove()==1&&reflective())
				ypos+=3;
			else if(randomMove()==2&&reflective())
				ypos-=3;
			break;
			case 6:
			ypos-=3;
			if(randomMove()==1&&reflective())
				xpos+=3;
			else if(randomMove()==2&&reflective())
				xpos-=3;
			break;
			case 7:
			ypos+=3;
			if(randomMove()==1&&reflective())
				xpos+=3;
			else if(randomMove()==2&&reflective())
				xpos-=3;
			break;
		}
	}
};
int main()
{
	int n = 100;
	tPoint *arr[n];
	for(int i = 0; i < n; i++)
	{
		arr[i] = new tPoint();
	}
	initwindow(600,600);
	while(1)
	{
		setfillstyle(0,0);
        bar(0,0,600,600);
        delay(30);
	for(int i = 0; i < n; i++)
	{
		arr[i] -> menu();
	}
	swapbuffers();
}
}
