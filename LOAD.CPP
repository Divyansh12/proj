//------------------Header Files-----------------------------------------
#include<iostream.h>
#include<conio.h>
#include<dos.h>
//-----------------------------------------------------------
void sysdate();   //function for displaying date (definition present in main)

void systime();   //function for displaying time (definition present in main)

void line(int,char);   //function for displaying lines (definition present in main)
//-----------------------------------------------------------
   void load()  	// function for creating the loading screen
 { 
    clrscr();
    randomize();
    int  x1=41, y1=2;
    for (int i=0; i<21; i++)
   {
    int g=random(13)+1;
    if (i>=0 && i<5)
    {
      x1+=4;
      y1+=2;
     }
     if (i>=5 && i<10)
    {
       x1-=4;
      y1+=2;
     }
    if (i>=10 && i<15)
    {
      x1-=4;
      y1-=2;
     }
    if (i>=15 && i<20)
    { 
      x1+=4;
      y1-=2;
     }
    gotoxy(x1,y1);
    textcolor(g);
    cprintf("\t");
    sound((i+1)*40);
    delay(100);
   }
  gotoxy(36,12);
  cout<<"D";
  delay(50);
  cout<<"i";
  delay(50);
  cout<<"g";
  delay(50);
  cout<<"i";
  delay(50);
  cout<<"t";
  delay(50);
  cout<<"a";
  delay(50);
  cout<<"l";
  delay(50);
  cout<<" ";
  delay(50);
  cout<<"D";
  delay(50);
  cout<<"a";
  delay(50);
  cout<<"i";
  delay(50);
  cout<<"r";
  delay(50);
  cout<<"y";
  delay(50);
  gotoxy(34,wherey()+1);
  for (i=0;i<17;i++)
  {
    cout<<"-";
    sound((i+1)*100);
    delay(50);
    }
  gotoxy(wherex()-1,wherey()-1);
  cout<<"|";
  gotoxy(wherex()+1,wherey()-1);
  int x2=wherex()-2;
  for (i=0;i<17;i++)
  {
    gotoxy(x2,wherey());
    cout<<"-";
    x2--;
    delay(50);
   }
  gotoxy(wherex()-1,wherey()+1);
  cout<<"|";
   gotoxy(1,23);
   nosound();
  textcolor(WHITE+BLINK);
  cprintf("PRESS ANY KEY TO START");
  gotoxy(58,23);
  textcolor(WHITE+BLINK);
  cprintf("PRESS ANY KEY TO START");
  getch();
  textattr(WHITE);
  clrscr();
  systime();
  sysdate();
  gotoxy(1,10);
  line(78,'-');
  gotoxy(1,12);
  line(78,'-');
  gotoxy(27,11);
  cout<<"INITIALIZING ";
  for(int z=1;z<5;z++)
  {
    gotoxy(40,11);
    { for(int f=0;f<5;f++)
     {
      cprintf("\t");
      delay(300);
      {
       gotoxy(40+f,11);
       cout<<"\b  ";
       }
      }
    }
   }
  textattr(WHITE);
 }