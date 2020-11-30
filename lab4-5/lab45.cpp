#include <iostream>
#include <graphics.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
class Point{
	protected:
		int xpos;
		int ypos;
		int color;
		int move_type;
		
	public:
		Point()
		{
			xpos = rand () % 550;
			ypos = rand () % 550;
			move_type = 1;
			color = rand() %10+1;
		}
		
		void move_()
		{	
			if(xpos >= 598)  {move_type = 1;}
			if(xpos <= 30) {move_type = 2;}
			switch(move_type)
			{
				case 0: xpos+=3; break;
				case 1: xpos-=3; break;
				case 2: xpos+=3; break;
			}
	}

				 virtual void drawPoint(){
	};

};

class Cut : public Point
{
	private:
		int angle;
		int Line_Size;
	public:

		Cut(int angle = 90, int Line_Size = 25)
		{	
			this->angle = angle;
			this->Line_Size = Line_Size;
			move_type = 0;
		}
			
		void drawPoint() 
		{
			setcolor(color);
			int s = sin(angle)*Line_Size;
			int c = cos(angle)*Line_Size;
			line(xpos-s,ypos-c,xpos+s,ypos+c);
			this->move_();
			this->angle+=3;
		}
};

class Rec : public Point
{
	private:
		int angle;
		int angle_2;
		int Line_Size;
	public:
		Rec(int Line_Size = 25)
		{
			 xpos = rand () % 450;
			 ypos = rand () % 450;
			this->Line_Size = Line_Size;
			angle = 90;
			angle_2 = angle + 10;
			move_type = 0;
		}
		void drawPoint()
		{
			setcolor(color);
			line(xpos+(sin(angle)*Line_Size),ypos+(cos(angle)*Line_Size),xpos-(sin(angle_2)*Line_Size),ypos-(cos(angle_2)*Line_Size));
			line(xpos-(sin(angle)*Line_Size),ypos-(cos(angle)*Line_Size),xpos+(sin(angle_2)*Line_Size),ypos+(cos(angle_2)*Line_Size));
			line(xpos+(sin(angle)*Line_Size),ypos+(cos(angle)*Line_Size),xpos+(sin(angle_2)*Line_Size),ypos+(cos(angle_2)*Line_Size));
			line(xpos-(sin(angle)*Line_Size),ypos-(cos(angle)*Line_Size),xpos-(sin(angle_2)*Line_Size),ypos-(cos(angle_2)*Line_Size));
			this->move_();
			this->angle+=3;
			this->angle_2+=3;

		}

};

class Circle : public Point
{
	private:
		int r;
	public:
		Circle()
		{
			 xpos = rand() % 550;
			 ypos = rand() % 550;
			r = 20;
			move_type = 0;
		}
		void drawPoint()
		{
			setcolor(color);
			circle(xpos,ypos,r);
			this->move_();
		}
};

class Rhomb : public Point
{
	private:
		int linesize;
		int linesize1;
		int angle;
		int angle_;
	public:
		Rhomb(int linesizeqq = 15,int linesizeq = 10)
		{
			 xpos = rand()%550;
			 ypos = rand()%550;
			this->linesize = linesizeqq;
			this->linesize1 = linesizeq;
			angle =  90;
			angle_ = 3;
			move_type = 0;
		}
		void drawPoint()
		{
	setcolor(color);
	line(xpos+(sin(angle)*linesize),ypos+(cos(angle)*linesize),xpos-(sin(angle+11)*linesize1),ypos-(cos(angle+11)*linesize1));
    line(xpos-(sin(angle)*linesize),ypos-(cos(angle)*linesize),xpos+(sin(angle+11)*linesize1),ypos+(cos(angle+11)*linesize1));
    line(xpos+(sin(angle)*linesize),ypos+(cos(angle)*linesize),xpos+(sin(angle+11)*linesize1),ypos+(cos(angle+11)*linesize1));
    line(xpos-(sin(angle)*linesize),ypos-(cos(angle)*linesize),xpos-(sin(angle+11)*linesize1),ypos-(cos(angle+11)*linesize1));
	this->move_();
	angle+=angle_;
		}
};

class Tria : public Point
{
	private:
	float angle;
	int linesize;
	public:
		Tria(int linesize = 35)
		{
			 xpos = rand()%450;
			 ypos = rand()%450;
			this->linesize = linesize;
			angle = 60;
			move_type = 1;
		}
		void drawPoint()
		{	setcolor(color);
			line(xpos+(sin(angle)*linesize),ypos-(cos(angle)*linesize),xpos+(sin(angle - 4)*linesize),ypos-(cos(angle-4)*linesize));
			line(xpos+(sin(angle)*linesize),ypos-(cos(angle)*linesize),xpos+(sin(angle + 4)*linesize),ypos-(cos(angle+4)*linesize));
			line(xpos+(sin(angle - 4)*linesize),ypos-(cos(angle - 4)*linesize),xpos+(sin(angle + 4)*linesize),ypos-(cos(angle + 4)*linesize));
			this->move_();
			angle+=2.4;
	}
};

class Ellip : public Point
{
	private:
		int r_x;
		int r_y;
	public:
		Ellip()
		{
			 xpos = rand() % 599;
			 ypos = rand() % 599;
			r_x = 25;
			r_y = 10;
			move_type = 1;
			color = rand() % 10;
		}
		
		void drawPoint()
		{
			setcolor(color);
			fillellipse(xpos,ypos,r_x,r_y);
			this->move_();
			int temp=r_x;
			r_x=r_y;
			r_y=temp;
		
		}

};


int main(){
	srand(time(NULL));

	Point **arr = new Point *[6];
	arr[0] =  new Cut;
	arr[1] = new Rec;
	arr[2] = new Circle;
	arr[3] = new Rhomb;
	arr[4] = new Tria;
	arr[5] = new Ellip; 
	
	 initwindow(600,600);
	 while(1)
	 {
	 	setfillstyle(0,0);
        bar(0,0,600,600);
        delay(50);
		for(int i = 0; i < 1; i++)
        {
        	arr[0]->drawPoint();
        	arr[1]->drawPoint();
        	arr[2]->drawPoint();
        	arr[3]->drawPoint();
        	arr[4]->drawPoint();
			arr[5]->drawPoint(); 
       }
       
		swapbuffers();
	 }
	return 0;
}
