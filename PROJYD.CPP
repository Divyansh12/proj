
//----------Header Files-----------------------
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include<stdio.h>
#include<dos.h>
#include<string.h>
#include<graphics.h>
#include"projyd2.cpp"
#include"projyd3.cpp"
#include"projyd4.cpp"
#include"clo.cpp"
#include"clo2.cpp"
#include"cal.cpp"
#include"load.cpp"
#include"thanky.cpp"

/*------------Prototypes----------------------------------*/
void menu();
void passw();
void exit_fun();
void line(int ,char );
void sysdate();
void systime();
void submenu_todo();
void submenu_sch();
void submenu_c();
void submenu_q();
void clockmenu();
int arrowmenu();
int arrowsubmenu_todo();
int arrowsubmenu_sch();
int arrowsubmenu_c();
int arrowsubmenu_q();
int arrowmenucl();
//-----------------PASSWORD----------------------------
class passkept
{
 public:
 char pass[20];

 char* passreturn()
 {
  return pass;
  }
};

//--------------Main------------------------------
void main()
{
clrscr();
load();
passw();
menu();
getch();
}
//___________________________Function Definitions_________________________
  //------------------------ function for the main menu and invoking the arrowmenu ----------------
   //                             and on the basis of choice, invoke the various functions--------------------
void menu()   
{
 gotoxy(1,1);
 int op;
 char op1[2];
 systime();
 sysdate();
 do
{
  op=arrowmenu();
switch(op)
{
case 1: clrscr();
	submenu_c() ;
	break;
case 2: clrscr();
	submenu_q();
	break;
case 3: clrscr();
	submenu_sch() ;
	break;
case 4: clrscr();
	submenu_todo() ;
	break;
case 5: clrscr();
	clockmenu()  ;
	break;
case 6: clrscr();
	calculator() ;
	break;
case 7: exit_fun();
	break;
default:clrscr();
	systime();
	sysdate();
	cout<<"\n\n\n\n\n\n\n\n";
	line(78,'*');
	cout<<"\t\t\tPlease choose a correct option\n";
	line(78,'*');
	cout<<"\n\n\n\t\t      "<<"To Continue (y/n)      : ";
	gets(op1);
	if(strcmp(op1,"y")==0)
	{
	 menu();
	 }
	else if (strcmp(op1,"n")==0)
	{
	 exit(0);
	 }

  }
 }while(op!=7);
}
//---------------------------Function for line----------------------------
void line(int b,char a)
{
    for(int i=0;i<b;i++)
    {
    cout<<a;
    }
    cout<<"\n";
}
//--------------------------Function for time-----------------------------
void systime()
{
   struct  time t;
   line(78,'-');
   gettime(&t);
   printf("%2d:%02d", t.ti_hour, t.ti_min);
   cout<<"  \t\t        Digital Dairy By Divyansh         ";
}
//--------------------------Function for date-----------------------------
void sysdate()
{
   struct date d;
   getdate(&d);
   printf("\t    %d/%d/%d ", d.da_day , d.da_mon, d.da_year);
   cout<<"\n";
   line(78,'-');
}
//---------------------------function for exiting the program---------------------------------------------------------
void exit_fun()
{
     char rep[3];
     clrscr();
     exitlabel:
	clrscr();
	systime();
	sysdate();
	cout<<"\n\n\n\t    "<<"Do you want to exit the program ?? (y/n)      : ";
	gets(rep);
	if(strcmp(rep,"y")==0||strcmp(rep,"Y")==0)
	{
	 thank();
	 exit(0);
	 }
	else if (strcmp(rep,"n")==0||strcmp(rep,"N")==0)
	{
	 clrscr();
	 systime();
	 sysdate();
	 cout<<"\n\n\n\n";
	 line(78,'*');
	 cout<<"\t\t\t   Returning to Main Menu !! \n" ;
	 line(78,'*');
	 getch();
	 menu();
	 }
	else
	{
	 cout<<"\n\t\t   You entered a wrong choice!!! ";
	 cout<<"\n\t\t   Please try again!!!";
	 getch();
	 goto exitlabel;
	}
}
//---------------------------function for creating the main menu --------------------------------
int arrowmenu()
{
  clrscr();
  int a,op,x1=26,y1=11;
  textattr(WHITE);
  systime();
  sysdate();
    cout<<"\n\n";
     line(78,'+');
    cout<<"\t\t\t           MAIN MENU \n";
     line(78,'+');
  do
  {
   gotoxy(29,11);
   if(y1==11)
    textattr(WHITE+BLINK);
   else
    textattr(WHITE);
    cprintf("1.CONTACTS");
   gotoxy(29,12);
    if(y1==12)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("2.QUERY");
   gotoxy(29,13);
    if(y1==13)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("3.SCHEDULER");
   gotoxy(29,14);
    if(y1==14)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("4.TO DO LIST");
   gotoxy(29,15);
    if(y1==15)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("5.CLOCK");
   gotoxy(29,16);
    if(y1==16)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("6.CALCULATOR");
   gotoxy(29,17);
    if(y1==17)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("7.EXIT");
   gotoxy(x1,y1);
    a=getch();
    if(a==72)
    {
      y1=wherey()-1;
    }
    else if(a==80)
    {
     y1=wherey()+1;
    }
    x1=wherex();
     if (y1<11)
	 y1=17;
     if (y1>17)
	 y1=11;
     cout<<"\b\b    ";
    gotoxy(x1,y1);
     cout<<"->";
  }while (a!=13);
    op=y1-10;
textattr(WHITE);
return op;

}
//----------------------------function for creating the password menu ------------------------------
//                                and checking the password taken from user-----------------------------
void passw()
{
 passkept p;
 char cha;
 int i,m,j,z,times=0,count=0;
 char passkept[10]="projyd";
 password:
 clrscr();
 systime();
 sysdate();
 i=0;
 cout<<"\n\n\n";
 line(78,'-');
 gotoxy(1,9);
 line(78,'-');
 gotoxy(1,8);
 cout<<"\t\t    ENTER PASSWORD : ";
 for(int k=0;k<1;k++)
  {
   sound(840);
   delay(200);
   sound(340);
   delay(200);
   sound(440);
   delay(200);
   nosound();
   }
do
{
 count=0;
 back:
 cha=getch();
 if(cha==13)
 {
  m=i;
  break;
 }
 else if(cha==8)
 {
  count++;
  if(i>0)
  {
     if(i>count)
     {
       gotoxy(wherex(),wherey());
       cout<<"\b ";
     }
     else
     {
       gotoxy(wherex()-1,wherey());
       cout<<"\b ";
     }
     i--;
   }
    goto back;
  }
  p.pass[i]=cha;
  i++;
  cout<<"*";
}while(1);
 p.pass[m]='\0';
 if(strcmp(p.passreturn(),passkept)==0)
 {
  menu();
  }
 else
 {
  times++;
  if(times==4)
  exit(0);
  else
  {
   cout<<"\n\n\n\n\n";
   line(78,'*');
   cout<<" ("<<p.pass<<") is not the right Password. Try Again !!("
       <<4-times
       <<" out of 4 attempts left)!!!\n";
   line(78,'*');
   getch();
   goto password;
  }
 }
}
//------------------------function for the contact sub-menu and invoking the arrowmenu -------------------------
 //                             and on the basis of choice, invoke the various functions-------------------------------------------
void submenu_c()
{
   clrscr();
   char r[3];
   int op1;
   char op2[2];
do
{
  clrscr();
  op1=arrowsubmenu_c();
  switch(op1)
  {
   case 1: clrscr();
	   cadd();
	   break;
   case 2: clrscr();
	   cdisplay();
	   break;
   case 3: clrscr();
	   cdelete();
	   break;
   case 4: clrscr();
	   cmodify() ;
	   break;
   case 5: clrscr();
	   exitlabel:
	   clrscr();
	   systime();
	   sysdate();
	   cout<<"\n\n\n\n\t    "
	       <<"Do you want to exit this menu ?? (y/n) : ";
	   gets(r);
	   if(strcmp(r,"y")==0||strcmp(r,"Y")==0)
	   {
	    menu();
	    }
	   else if(strcmp(r,"n")==0||strcmp(r,"N")==0)
	   {
	    clrscr();
	    systime();
	    sysdate();
	    cout<<"\n\n\n\n" ;
	    line(78,'*');
	    cout<<"\t\t      Returning to Contact Menu !!\n" ;
	    line(78,'*');
	    getch();
	    submenu_c();
	    }
	   else
	   {
	    cout<<"\n\t\t   You entered a wrong choice!!! ";
	    cout<<"\n\t\t   Please try again!!!";
	    getch();
	    goto exitlabel;
	   }
	   break;
   default:clrscr();
	   systime();
	   sysdate();
	   cout<<"\n\n\n\n\n\n\n\n";
	   line(78,'*');
	   cout<<"\t\t\tPlease choose a correct option\n";
	   line(78,'*');
	   cout<<"\n\n\n\t\t      "<<"To Continue (y/n)      : ";
	   gets(op2);
	   if(strcmp(op2,"y")==0)
	   {
	    submenu_c();
	    }
	   else if (strcmp(op2,"n")==0)
	   {
	    exit(0);
	    }
	getch();
     }
 }while(op1!=5);
}
//------------------------function for the scheduler sub-menu and invoking the arrowmenu -------------------------
 //                             and on the basis of choice, invoke the various functions-------------------------------------------
void submenu_sch()
{
 clrscr();
 char r[3];
 int op2;
 char op3[2];
do
{
 clrscr();
 op2=arrowsubmenu_sch();
 switch(op2)
 {
 case 1: clrscr();
	 sadd();
	 break;
 case 2: clrscr();
	 sdisplayall();
	 break;
 case 3: clrscr();
	 ssview();
	 break;
 case 4: clrscr();
	 smodify();
	 break;
 case 5: clrscr();
	 sdelete();
	 break;
 case 6: clrscr();
	 exitlabel:
	   clrscr();
	   systime();
	   sysdate();
	   cout<<"\n\n\n\n\t    "
	       <<"Do you want to exit this menu ?? (y/n) : ";
	   gets(r);
	   if(strcmp(r,"y")==0||strcmp(r,"Y")==0)
	   {
	    menu();
	    }
	   else if (strcmp(r,"n")==0||strcmp(r,"N")==0)
	   {
	    clrscr();
	    systime();
	    sysdate();
	    cout<<"\n\n\n\n";
	    line(78,'*');
	    cout<<"\t\t     Returning to Scheduler Menu !!\n" ;
	    line(78,'*');
	    getch();
	    submenu_sch();
	    }
	   else
	   {
	    cout<<"\n\t\t   You entered a wrong choice!!! ";
	    cout<<"\n\t\t   Please try again!!!";
	    getch();
	    goto exitlabel;
	   }
	 break;
default: clrscr();
	 systime();
	 sysdate();
	 cout<<"\n\n\n\n\n\n\n\n";
	 line(78,'*');
	 cout<<"\t\t\tPlease choose a correct option\n";
	 line(78,'*');
	 cout<<"\n\n\n\t\t      "<<"To Continue (y/n)      : ";
	 gets(op3);
	 if(strcmp(op3,"y")==0)
	 {
	  submenu_sch();
	 }
	 else if (strcmp(op3,"n")==0)
	{
	 exit(0);
	 }
   }
 }while(op2!=6);
}
//------------------------function for the to-do sub-menu and invoking the arrowmenu -------------------------
 //                             and on the basis of choice, invoke the various functions-------------------------------------------
void submenu_todo()
{
  clrscr();
  char r[3];
  int op3;
  char op4[2];
do
{
 clrscr();
 op3=arrowsubmenu_todo();
 switch(op3)
 {
  case 1: clrscr();
	  tdadd();
	  break;
  case 2: clrscr();
	  tdsview();
	  break;
  case 3: clrscr();
	  tdmodify();
	   break;
  case 4: clrscr();
	  tddelete() ;
	  break;
  case 5: clrscr();
	  exitlabel:
	   clrscr();
	   systime();
	   sysdate();
	   cout<<"\n\n\n\n\t    "
	       <<"Do you want to exit this menu ?? (y/n) : ";
	   gets(r);
	   if(strcmp(r,"y")==0||strcmp(r,"Y")==0)
	   {
	    menu();
	    }
	   else if (strcmp(r,"n")==0||strcmp(r,"N")==0)
	   {
	    clrscr();
	    systime();
	    sysdate();
	    cout<<"\n\n\n\n";
	    line(78,'*');
	    cout<<"\t\t    Returning to TO DO List !!\n" ;
	    line(78,'*');
	    getch();
	    submenu_todo();
	    }
	   else
	   {
	    cout<<"\n\t\t   You entered a wrong choice!!! ";
	    cout<<"\n\t\t   Please try again!!!";
	    getch();
	    goto exitlabel;
	   }
	  break;
   default: clrscr();
	    systime();
	    sysdate();
	    cout<<"\n\n\n\n\n\n\n\n";
	    line(78,'*');
	    cout<<"\t\t\tPlease choose a correct option\n";
	    line(78,'*');
	    cout<<"\n\n\n\t\t      "<<"To Continue (y/n)      : ";
	    gets(op4);
	    if(strcmp(op4,"y")==0)
	    {
	     submenu_todo();
	    }
	    else if (strcmp(op4,"n")==0)
	    {
	      exit(0);
	    }
	    getch();
     }
 }while(op3!=5);
}
//------------------------function for the query sub-menu and invoking the arrowmenu -------------------------
 //                             and on the basis of choice, invoke the various functions-------------------------------------------
void submenu_q()
{
 clrscr();
 char r[3];
 int op4;
 char op5[2];
do
{
 clrscr();
 op4=arrowsubmenu_q();
 switch(op4)
 {
  case 1: clrscr();
	  cphone_disp();
	  break;
  case 2: clrscr();
	  cname_disp();
	  break;
  case 3: clrscr();
	  caddress_disp() ;
	  break;
  case 4: clrscr();
	  cmobile_disp() ;
	  break;
  case 5: clrscr();
	  ccompany_disp() ;
	  break;
  case 6: clrscr();
	  exitlabel:
	   clrscr();
	   systime();
	   sysdate();
	   cout<<"\n\n\n\n\t    "
	       <<"Do you want to exit this menu ?? (y/n) : ";
	   gets(r);
	   if(strcmp(r,"y")==0||strcmp(r,"Y")==0)
	   {
	    menu();
	    }
	   else if (strcmp(r,"n")==0||strcmp(r,"N")==0)
	   {
	    clrscr();
	    systime();
	    sysdate();
	    cout<<"\n\n\n\n";
	    line(78,'*');
	    cout<<"\t\t    Returning to Contact Query Menu !!\n" ;
	    line(78,'*');
	    getch();
	    submenu_q();
	    }
	   else
	   {
	    cout<<"\n\t\t   You entered a wrong choice!!! ";
	    cout<<"\n\t\t   Please try again!!!";
	    getch();
	    goto exitlabel;
	   }
	   break;
  default: clrscr();
	   systime();
	   sysdate();
	   cout<<"\n\n\n\n\n\n\n\n";
	   line(78,'*');
	   cout<<"\t\t\tPlease choose a correct option\n";
	   line(78,'*');
	   cout<<"\n\n\n\t\t      "<<"To Continue (y/n)      : ";
	   gets(op5);
	    if(strcmp(op5,"y")==0)
	    {
	     submenu_q();
	    }
	    else if (strcmp(op5,"n")==0)
	    {
	      exit(0);
	    }
	    getch();

  }
 }while(op4!=6);
}

//------------------------function for creating the query sub-menu----------------------------------------------------


int arrowsubmenu_q()
{
 systime();
 sysdate();
 int a,op,x1=26,y1=11;
     cout<<"\n\n";
     line(78,'+');
    cout<<"\t\t\t       CONTACT QUERY MENU \n";
     line(78,'+');
 do
  {
   gotoxy(29,11);
   if(y1==11)
    textattr(WHITE+BLINK);
   else
    textattr(WHITE);
    cprintf("1.VIEW CONTACTS BY PHONE NUMBER");
   gotoxy(29,12);
    if(y1==12)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("2.VIEW CONTACTS BY NAME");
   gotoxy(29,13);
    if(y1==13)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("3.VIEW CONTACTS BY ADDRESS");
   gotoxy(29,14);
    if(y1==14)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("4.VIEW CONTACTS BY MOBILE");
   gotoxy(29,15);
    if(y1==15)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("5.VIEW CONTACTS BY COMPANY");
   gotoxy(29,16);
    if(y1==16)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("6.EXIT TO MAIN MENU");
   gotoxy(x1,y1);
    a=getch();
    if(a==72)
    {
      y1=wherey()-1;
    }
    else if(a==80)
    {
     y1=wherey()+1;
    }
    x1=wherex();
     if (y1<11)
	 y1=16;
     if (y1>16)
	 y1=11;
     cout<<"\b\b    ";
    gotoxy(x1,y1);
     cout<<"->";

  }while (a!=13);
    op=y1-10;
textattr(WHITE);
return op;
}
//-----------------function for creating the to-do sub-menu-----------------------------------------------
int arrowsubmenu_todo()
{
 clrscr();
 systime();
 sysdate();
 int a,op,x1=26,y1=11;
     cout<<"\n\n";
     line(78,'+');
    cout<<"\t\t\t        TO DO LIST \n";
     line(78,'+');
 do
  {
   gotoxy(29,11);
   if(y1==11)
    textattr(WHITE+BLINK);
   else
    textattr(WHITE);
    cprintf("1.ADD Tasks TO-DO");
   gotoxy(29,12);
    if(y1==12)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("2.VIEW Tasks TO-DO");
   gotoxy(29,13);
    if(y1==13)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("3.MODIFY Tasks TO-DO");
   gotoxy(29,14);
    if(y1==14)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("4.DELETE TO-DO");
   gotoxy(29,15);
    if(y1==15)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("5.EXIT TO MAIN MENU");
   gotoxy(x1,y1);
    a=getch();
    if(a==72)
    {
      y1=wherey()-1;
    }
    else if(a==80)
    {
     y1=wherey()+1;
    }
    x1=wherex();
     if (y1<11)
	 y1=15;
     if (y1>15)
	 y1=11;
     cout<<"\b\b    ";
    gotoxy(x1,y1);
     cout<<"->";
  }while (a!=13);
    op=y1-10;
textattr(WHITE);
return op;
}
//---------------------function for creating the scheduler sub-menu--------------------------------------------
int arrowsubmenu_sch()
{
  clrscr();
  systime();
  sysdate();
 int a,op,x1=26,y1=11;
    cout<<"\n\n";
     line(78,'+');
    cout<<"\t\t\t         SCHEDULER MENU \n";
     line(78,'+');
 do
  {
   gotoxy(29,11);
   if(y1==11)
    textattr(WHITE+BLINK);
   else
    textattr(WHITE);
    cprintf("1.ADD A SCHEDULE");
   gotoxy(29,12);
    if(y1==12)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("2.DISPLAY ALL SCHEDULES");
   gotoxy(29,13);
    if(y1==13)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("3.VIEW SCHEDULES BY DATE");
   gotoxy(29,14);
    if(y1==14)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("4.MODIFY SCHEDULE");
   gotoxy(29,15);
    if(y1==15)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("5.DELETE SCHEDULE");
   gotoxy(29,16);
    if(y1==16)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("6.EXIT TO MAIN MENU");
   gotoxy(x1,y1);
    a=getch();
    if(a==72)
    {
      y1=wherey()-1;
    }
    else if(a==80)
    {
     y1=wherey()+1;
    }
    x1=wherex();
     if (y1<11)
	 y1=16;
     if (y1>16)
	 y1=11;
     cout<<"\b\b    ";
    gotoxy(x1,y1);
     cout<<"->";
  }while (a!=13);
    op=y1-10;
textattr(WHITE);
return op;
}
//-------------------------------function for creating the contact sub-menu----------------------------------------
int arrowsubmenu_c()
{
 systime();
 sysdate();
 int a,op,x1=26,y1=11;
    cout<<"\n\n";
     line(78,'+');
    cout<<"\t\t\t       CONTACT MENU \n";
     line(78,'+');
 do
  {
   gotoxy(29,11);
   if(y1==11)
    textattr(WHITE+BLINK);
   else
    textattr(WHITE);
    cprintf("1.ADD CONTACTS");
   gotoxy(29,12);
    if(y1==12)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("2.DISPLAY ALL CONTACTS");
   gotoxy(29,13);
    if(y1==13)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("3.Delete CONTACTS");
   gotoxy(29,14);
    if(y1==14)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("4.Modify CONTACTS");
   gotoxy(29,15);
    if(y1==15)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("5.EXIT TO MAIN MENU");
   gotoxy(x1,y1);
    a=getch();
    if(a==72)
    {
      y1=wherey()-1;
    }
    else if(a==80)
    {
     y1=wherey()+1;
    }
    x1=wherex();
     if (y1<11)
	 y1=15;
     if (y1>15)
	 y1=11;
     cout<<"\b\b    ";
    gotoxy(x1,y1);
     cout<<"->";
  }while (a!=13);
    op=y1-10;
textattr(WHITE);
return op;
}
//------------------------function for the clock sub-menu and invoking the arrowmenu -------------------------
 //                             and on the basis of choice, invoke the various functions-------------------------------------------
void clockmenu()
{
 clrscr();
 gotoxy(1,1);
 int op;
 char r[3];
 char op1[2];
 do
{
  op=arrowmenucl();
switch(op)
{
case 1: clrscr();
	clocka() ;
	break;
case 2: clrscr();
	clockb();
	break;
case 3:   clrscr();
	  exitlabel:
	   clrscr();
	   systime();
	   sysdate();
	   cout<<"\n\n\n\n\t    "
	       <<"Do you want to exit this menu ?? (y/n) : ";
	   gets(r);
	   if(strcmp(r,"y")==0||strcmp(r,"Y")==0)
	   {
	    menu();
	    }
	   else if (strcmp(r,"n")==0||strcmp(r,"N")==0)
	   {
	    clrscr();
	    systime();
	    sysdate();
	    cout<<"\n\n\n\n";
	    line(78,'*');
	    cout<<"\t\t    Returning to Clock !!\n" ;
	    line(78,'*');
	    getch();
	    clockmenu();
	    }
	   else
	   {
	    cout<<"\n\t\t   You entered a wrong choice!!! ";
	    cout<<"\n\t\t   Please try again!!!";
	    getch();
	    goto exitlabel;
	   }
	   break;
default:clrscr();
	systime();
	sysdate();
	cout<<"\n\n\n\n\n\n\n\n";
	line(78,'*');
	cout<<"\t\t\tPlease choose a correct option\n";
	line(78,'*');
	cout<<"\n\n\n\t\t      "<<"To Continue (y/n)      : ";
	gets(op1);
	if(strcmp(op1,"y")==0)
	{
	 menu();
	 }
	else if (strcmp(op1,"n")==0)
	{
	 exit(0);
	 }

  }
 }while(op!=7);
}
// -------------------------------function for creating the clock sub-menu-------------------
int arrowmenucl()
{
 clrscr();
 systime();
 sysdate();
 int a,op,x1=26,y1=11;
    cout<<"\n\n";
     line(78,'+');
    cout<<"\t\t\t              CLOCK \n";
     line(78,'+');
 do
  {
   gotoxy(29,11);
   if(y1==11)
    textattr(WHITE+BLINK);
   else
    textattr(WHITE);
    cprintf("1.ANALOG CLOCK");
   gotoxy(29,12);
    if(y1==12)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("2.DIGITAL CLOCK");
   gotoxy(29,13);
     if(y1==13)
     textattr(WHITE+BLINK);
    else
     textattr(WHITE);
    cprintf("3.EXIT TO MAIN MENU");
   gotoxy(x1,y1);
    a=getch();
    if(a==72)
    {
      y1=wherey()-1;
    }
    else if(a==80)
    {
     y1=wherey()+1;
    }
    x1=wherex();
     if (y1<11)
	 y1=13;
     if (y1>13)
	 y1=11;
     cout<<"\b\b    ";
    gotoxy(x1,y1);
     cout<<"->";
  }while (a!=13);
    op=y1-10;
textattr(WHITE);
return op;
}

//--------------------END OF PROGRAM-----------------------------


