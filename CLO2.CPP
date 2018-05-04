    #include<iostream.h>
    #include<stdio.h>
    #include<conio.h>
    #include<graphics.h>
    #include<dos.h>
    #include<stdlib.h>
    #define DOTCOLOR 14
    #define DIGCOLOR 4
    void systime();
    void sysdate();
    class DIGITE
    {
     private:
       int X,Y;
       int SIZE;
       int COLOR;
       int HIGHT,WIDTH;
       void *VER,*HOR;
     public:
      int style;
      DIGITE();
      DIGITE(int s,int c,int st);
      void MakeBars();
      void PutDig(int x,int y,int n);
      void DrawDig(int x,int y,int n);
      ~DIGITE();
    };
    DIGITE::DIGITE()
    {
     style=1;
     SIZE=1;
     HIGHT=1;
     WIDTH=12;
     COLOR=15;
     MakeBars();
    }
    DIGITE::DIGITE(int s,int c,int st)
    {
     style=st;
     SIZE=s;
     COLOR=15;
     HIGHT=1;
     WIDTH=6;
     MakeBars();
    }
    void DIGITE::MakeBars()
    {
     int x,y,w,h;
     int area;
     x=10;
     y=getmaxy()/2;
     w=WIDTH*SIZE;
     h=HIGHT*SIZE;
     setfillstyle(style,COLOR);
     bar(x+h,y,x+w-h,y+h);
     setcolor(COLOR);
     line(x,y+h/2,x+h,y);
     line(x,y+h/2,x+h,y+h);
     floodfill(x+h/2,y+h/2,COLOR);
     setcolor(COLOR);
     line(x+w-h,y,x+w+-h+h,y+h/2);
     line(x+w-h,y+h,x+w-h+h,y+h/2);
     floodfill(x+w-h+h/2,y+h/2,COLOR);
     area=imagesize(x,y,x+w,y+h);
     HOR=malloc(area);
     if(HOR==NULL)
     {
      printf("Low Memory(Horizontal)...\nPress Any Key");
      getch();
      exit(0);
     }
     getimage(x,y,x+w,y+h,HOR);
     putimage(x,y,HOR,XOR_PUT);
     x=getmaxx()/2;
     y=10;
     h=SIZE*WIDTH;
     w=HIGHT*SIZE;
     bar(x,y+w,x+w,y+h-w);
     setcolor(COLOR);
     line(x,y+w,x+w/2,y);
     line(x+w,y+w,x+w/2,y);
     floodfill(x+w/2,y+w/2,COLOR);
     setcolor(COLOR);
     line(x,y+h-w,x+w/2,y+h);
     line(x+w,y+h-w,x+w/2,y+h);
     floodfill(x+w/2,y+h-w/2,COLOR);
     area=imagesize(x,y,x+w,y+h);
     VER=malloc(area);
     if(VER==NULL)
     {
      printf("Low Memory(Vertical)...\nPress Any Key");
      getch();
      exit(0);
     }
     getimage(x,y,x+w,y+h,VER);
     putimage(x,y,VER,XOR_PUT);
    }
    void DIGITE::PutDig(int x,int y,int n)
    {
     int num,gap,qu,rem;
     gap=(HIGHT*SIZE);
     num=n;
     if(num>=0&&num<10)
     {
      DrawDig(x,y,0);
      DrawDig(x+WIDTH*SIZE+HIGHT*SIZE+gap,y,n);
     }
     if(num>=10&&num<100)
     {
      qu=num/10;
      rem=num%10;
      DrawDig(x,y,qu);
      DrawDig(x+WIDTH*SIZE+HIGHT*SIZE+gap,y,rem);
     }
    }
    void DIGITE::DrawDig(int x,int y,int n)
    {
     int H[10][3]={1,0,1,
	       0,0,0,
	       1,1,1,
	       1,1,1,
	       0,1,0,
	       1,1,1,
	       1,1,1,
	       1,0,0,
	       1,1,1,
	       1,1,1};
     int V[10][4]={1,1,1,1,
	       0,1,0,1,
	       0,1,1,0,
	       0,1,0,1,
	       1,1,0,1,
	       1,0,0,1,
	       1,0,1,1,
	       0,1,0,1,
	       1,1,1,1,
	       1,1,0,1};
     int HX[3]={x,x,x};
     int HY[3]={y,y+WIDTH*SIZE,y+2*WIDTH*SIZE};
     int VX[4]={x-(HIGHT*SIZE)/2,x+WIDTH*SIZE-(HIGHT*SIZE)/2,x-(HIGHT*SIZE)/2,x+WIDTH*SIZE-(HIGHT*SIZE)/2};
     int VY[4]={y+(HIGHT*SIZE)/2,y+(HIGHT*SIZE)/2,y+WIDTH*SIZE+(HIGHT*SIZE)/2,y+WIDTH*SIZE+(HIGHT*SIZE)/2};
     int i;
     setfillstyle(1,getpixel(x-1,y-1));
     bar(x-(SIZE*HIGHT)/2,y,x+WIDTH*SIZE+(SIZE*HIGHT)/2,y+2*SIZE*WIDTH+HIGHT*SIZE);
     for(i=0;i<3;i++)
     {
      if(H[n][i]==1)
       putimage(HX[i],HY[i],HOR,XOR_PUT);
     }
     for(i=0;i<4;i++)
     {
     if(V[n][i]==1)
      putimage(VX[i],VY[i],VER,XOR_PUT);
     }
    }
    DIGITE::~DIGITE()
    {
     delete VER;
     delete HOR;
    }
    void drawdot();
    void drawdot2();
    int color=DOTCOLOR;
    void clockb()
    {
     int gd=DETECT,gm,i;
     initgraph(&gd,&gm,"");
     systime();
     sysdate();
     struct time t;
     int th=t.ti_hour;
     int tm=t.ti_min;
     int ts=t.ti_sec;
     int tms=t.ti_hund;
     //setbkcolor(15);
     gettime(&t);
     DIGITE h(8,DIGCOLOR,1);
     DIGITE m(8,DIGCOLOR,1);
     DIGITE s(8,DIGCOLOR,1);
     DIGITE ms(2,DIGCOLOR,1);
     int y=200;
     int flag=1;
     h.PutDig(40,y,t.ti_hour);
     m.PutDig(240,y,t.ti_min);
     s.PutDig(420,y,t.ti_sec);
     ms.PutDig(540,y,t.ti_hund);
     while(!kbhit())
     {
      gettime(&t);
      if(th!=t.ti_hour)
      {
       th=t.ti_hour;
       h.PutDig(40,y,t.ti_hour);
      }
      if(tm!=t.ti_min)
      {
       tm=t.ti_min;
       m.PutDig(240,y,t.ti_min);
      }
      if(ts!=t.ti_sec)
      {
       ts=t.ti_sec;
       s.PutDig(420,y,t.ti_sec);
	drawdot();
	s.PutDig(420,y,t.ti_sec);
	drawdot2();
	color=color-DOTCOLOR;
	if(color<0)
	 color=DOTCOLOR;
      }
      if(tms!=t.ti_hund)
      {
	tms=t.ti_hund;
	ms.PutDig(540,y,t.ti_hund);
      }

     }
      closegraph();
      restorecrtmode();
      getch();
     }
    void drawdot()
    {

     int x,y,gap,size;
     gap=10;
     size=15;
     x=180;
     y=200;
     setfillstyle(1,color);
     bar(x+gap,y+gap,x+gap+size,y+gap+size);
     bar(x+gap,y+8*gap,x+gap+size,y+8*gap+size);
     //color=15;
     delay(0);
    }

    void drawdot2()
    {

     int x,y,gap,size;
     gap=10;
     size=15;
     x=380;
     y=200;
     setfillstyle(1,color);
     bar(x+gap,y+gap,x+gap+size,y+gap+size);
     bar(x+gap,y+8*gap,x+gap+size,y+8*gap+size);
     //color=15;
     delay(0);
    }

