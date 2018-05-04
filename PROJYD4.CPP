//------------------Header Files-----------------------------------------
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
//-----------------------------------------------------------
void sysdate();   //function for displaying date (definition present in main)

void systime();   //function for displaying time (definition present in main)

void line(int,char);   //function for displaying lines (definition present in main)
//-----------------------------------------------------------

struct Date2  //structure of date
{
 long int dd,mm,yy;
 long int hr, min;
};
//-----------------------------------------------------------
class to_do_list
{
 Date2 d1;
 int size;
 char job_to_do[20][20];
 public:
 void tgetdata();
 void tdisplaydata();
 int check_dt(Date2 d2)
 {
   if(d1.dd==d2.dd&&d1.mm==d2.mm&&d1.yy==d2.yy)
    return 1;
   else
    return 0;
  }
};
//-----------------------------------------------------------
  void to_do_list::tgetdata()// function to get data for the to-do
 {
  char rep;
  char str[30];
  clrscr();
  systime();
  sysdate();
  cout<<"\n\n";
  line(78,'+');
  cout<<"DATE  "<<" (Day/Month/Year) :  " ;
  gets(str);
  sscanf(str,"%ld/%ld/%ld",&d1.dd,&d1.mm,&d1.yy);
  cout<<"\n";
  line(78,'+');
  for(int i=0 ;i<20;i++)
  {
    clrscr();
    systime();
    sysdate();
    cout<<"\n\n\t\t  Enter the TASK you want to do : \n";
    line(78,'+');
    cout<<"\n\t\t  TASK "<<i+1<<" : " ;
    gets(job_to_do[i]);
    cout<<"\n";
    line(78,'+');
    cout<<"\nWant to ADD More TASK ?? (y/n) : ";
    cin>>rep;
     if(rep=='n'||rep=='N')
    {
    size=i+1;
    break;
     }
    else
     size=i+1;
   }
 }
//-----------------------------------------------------------
 void to_do_list::tdisplaydata()//function to display the data in to-do
 {
  clrscr();
  systime();
  sysdate();
  cout<<"\n\n";
  line(78,'+');
  cout<<" DATE"<<"(Day/Month/Year) : " ;
  printf("%ld/%ld/%ld",d1.dd,d1.mm,d1.yy);
  cout<<"\n";
  line(78,'+');
  cout<<"\n\n";
  for(int i=0 ;i<size;i++)
  {
    gotoxy(4,i+11);
    cout<<i+1<<" : " ;
    gotoxy(10,i+11);
    puts(job_to_do[i]);
   }
 }
//-----------------------------------------------------------
// to do list functions -add modify delete display
//------------------------------------------------------------
void tdadd()
{
 fstream file;
 file.open("to_do.dat",ios::app|ios::binary);
 to_do_list td;
 char rep;
 do
 {
  td.tgetdata();
  file.write((char*)&td,sizeof(td));
  cout<<"\n\n\t  Want to add more records (y/n) : ";
  cin>>rep;
 }while(rep=='y'||rep=='Y');
}
//-----------------------------------------------------------
 void tddelete()
 {
  Date2 d;
  clrscr();
  systime();
  sysdate();
  char rep;
  fstream fin,fout;
  fin.open("to_do.dat",ios::in|ios::binary);
  fout.open("Nto_do.dat",ios::out|ios::binary);
  to_do_list td;
  cout<<"\n";
  line(78,'+');
  cout<<"\Enter the Date of that Task which you want to delete:"
      <<"\n\t Day = ";
  cin>>d.dd;
  cout<<"\t Month =";
  cin>>d.mm;
  cout<<"\t Year =";
  cin>>d.yy;
  cout<<"\n";
  line(78,'+');
  while(fin.read((char*)&td,sizeof(td)))
  { 
   if(td.check_dt(d)==1)
   {
   clrscr();
   td.tdisplaydata();
   cout<<"\n\n Is this the task you want to delete (y/n) : ";
   cin>>rep;
   if(rep=='y'||rep=='Y')
   {
    line(78,'*');
    cout<<"\t\t     Deleted!!";
     line(78,'*');
    }
   else
   {
    cout<<"\n\t  No Problem";
    fout.write((char*)&td,sizeof(td));
    }
  }
  else
   fout.write((char*)&td,sizeof(td));
 
  fin.close();
  fout.close();
  remove("to_do.dat");
  rename("Nto_do.dat","to_do.dat");
  getch();
  } 
 }
//-----------------------------------------------------------
  void tdmodify()
{
  int flag;
  clrscr();
  systime();
  sysdate();
  fstream fin,fout;
  fin.open("to_do.dat",ios::in|ios::binary);
  fout.open("Nto_do.dat",ios::out|ios::binary);
  to_do_list td;
  Date2 d;
  cout<<"\n";
  line(78,'+');
  cout<<"\Enter the Date of that schedule which you want to Modify : "
      <<"\n\t Day = ";
  cin>>d.dd;
  cout<<"\t Month =";
  cin>>d.mm;
  cout<<"\t Year =";
  cin>>d.yy;
  cout<<"\n";
  line(78,'+');
  while(fin.read((char*)&td,sizeof(td)))
  {
   if(td.check_dt(d)==1)
   {
    flag=1;
    }
   else
   {
    fout.write((char*)&td,sizeof(td));
    }
  }
   if(flag==1)
   {
     clrscr();
       gotoxy(10,5);
       cout<<" Enter the Data in Task to be Modified \n\n: ";
     td.tgetdata();
     fout.write((char*)&td,sizeof(td));
     cout<<"\n\n Your record has been modified!! ";
    }
   if(flag==0)
   {
     clrscr();
     systime();
     sysdate();
     cout<<"\n\n\n\n\n\n\n\n";
      line(78,'*');
      cout<<"\t\t\t No such Task exist\n";
      line(78,'*');;
    }
   fin.close();
   fout.close();
   remove("to_do.dat");
   rename("Nto_do.dat","to_do.dat");
  getch();
 }
//-----------------------------------------------------------
void tdsview() 	// to display selected to-dos
{
 to_do_list td;
 Date2 d;
 clrscr();
 systime();
 sysdate();
 int flag=0;
 ifstream fin("to_do.dat",ios::in|ios::binary);
 cout<<"\n";
 line(78,'+');
 cout<<"\nEnter the Date of that task which you want to view : "
     <<"\n\t Day = ";
 cin>>d.dd;
 cout<<"\t Month =";
 cin>>d.mm;
 cout<<"\t Year =";
 cin>>d.yy;
 cout<<"\n";
 line(78,'+');
 while(fin.read((char*)&td,sizeof(td)))
 {
  if(td.check_dt(d)==1)
  {
   clrscr();
   td.tdisplaydata();
   flag=1;
  }
 }
 if(flag!=1)
 {
     clrscr();
     systime();
     sysdate();
     cout<<"\n\n\n\n\n\n\n\n";
     line(78,'*');
     cout<<"\t\t\t No such Task Found\n";
     line(78,'*');;
 }
  getch();
  fin.close();
}