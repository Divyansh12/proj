 //---------------------------Header Files --------------------------- 
 #include<iostream.h>
 #include<conio.h>
 #include<dos.h>
 //------------------------------------------------------
 void thank()        // function that creates the thank you screen
 {
  clrscr();
  randomize();
  int  x1=41, y1=2;
  for (int i=0; i<21; i++)
  {
    int g=random(16)+1;
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
    sound((i-1)*30);
    delay(100);
  }
  gotoxy(36,12);
  cout<<" ";
  delay(50);
  cout<<"T";
  delay(50);
  cout<<"H";
  delay(50);
  cout<<"A";
  delay(50);
  cout<<"N";
  delay(50);
  cout<<"K";
  delay(50);
  cout<<" ";
  delay(50);
  cout<<"Y";
  delay(50);
  cout<<"O";
  delay(50);
  cout<<"U";
  delay(50);
  cout<<"!";
  delay(50);
  cout<<"!";
  delay(50);
  cout<<" ";
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
  cprintf("PRESS ANY KEY TO END");
  gotoxy(58,23);
  textcolor(WHITE+BLINK);
  cprintf("PRESS ANY KEY TO END");
  getch();
  textattr(WHITE);
}