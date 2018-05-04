//---------------------Header Files------------------
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
//-----------------------------------------------------------
void line(int ,char ); 		//function for displaying lines (definition present in main)

void sysdate();		//function for displaying date (definition present in main)

void systime(); 		//function for displaying time (definition present in main)

//-----------------------------------------------------------
struct Date1
{
 long int dd,mm,yy;
 long int hr, min;
};
//-----------------------------------------------------------
class scheduler
{
 Date1 d1;
 char sch_name[30],job[20],cho,ch,rep;
 public:
 void sgetdata();
 void sdisplaydata();
 int check_dt(Date1 d2)
 {
  if(d1.dd==d2.dd&&d1.mm==d2.mm&&d1.yy==d2.yy)
   return 1;
  else
   return 0;
  }
char *return_name()
{
 return sch_name;
 }
 char *return_job()
{
 return job;
 }
};
//-----------------------------------------------------------
void scheduler::sgetdata()   	//function to get data for the schedule
{
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
 cout<<"\n\n";
 line(78,'+');
 cout<<" Hour:Min : ";
 gets(str);
 sscanf(str,"%ld:%ld",&d1.hr,&d1.min);
 cout<<"\n";
 line(78,'+');
 cout<<"\n Title : ";
 gets(sch_name);
 cout<<"\nDescription :" ;
 gets(job);
}
//-----------------------------------------------------------
void scheduler::sdisplaydata()	//function to display data of the schedule
{
 clrscr();
 systime();
 sysdate();
 cout<<"\n\n";
 line(78,'+');
 cout<<"\n DATE"<<"(Day/Month/Year) : " ;
  printf("%ld/%ld/%ld",d1.dd,d1.mm,d1.yy);
  cout<<"\n";
  line(78,'+');
  cout<<"\n\n";
  line(78,'+');
 cout<<"\n Hour/Time : ";
 printf("%ld:%ld",d1.hr,d1.min);
 cout<<"\n";
 line(78,'+');
 cout<<"\n\t   Title:";
 puts(sch_name);
 cout<<"\n\t   Description :" ;
 puts(job);
 getch();

}
//-----------------------------------------------------------
// scheduler functions -add modify delete display
void sadd()
{
 clrscr();
 fstream file;
 file.open("scheduler.dat",ios::app|ios::binary);
 scheduler sc;
 char rep;
 do
 {
   sc.sgetdata();
   file.write((char*)&sc,sizeof(sc));
   cout<<"\n\n\t Want to add more records (y/n) : ";
   cin>>rep;
 }while(rep=='y'||rep=='Y');
}
//-----------------------------------------------------------
void sdisplayall()
{
 clrscr();
 fstream file;
 file.open("scheduler.dat",ios::in|ios::binary);
 scheduler sc;
 while(file.read((char*)&sc,sizeof(sc)))
 {
  clrscr();
   sc.sdisplaydata();
  }
}
//-----------------------------------------------------------
 void sdelete()
 {
 Date1 d;
 clrscr();
 systime();
 sysdate();
 char rep;
 fstream fin,fout;
 fin.open("scheduler.dat",ios::in|ios::binary);
 fout.open("Nscheduler.dat",ios::out|ios::binary);
 scheduler sc;
 cout<<"\n\n";
 line(78,'+');
 cout<<"Enter the Date of that schedule which you want to delete :"
     <<"\n\t Day = ";
 cin>>d.dd;
 cout<<"\t Month = ";
 cin>>d.mm;
 cout<<"\t Year = ";
 cin>>d.yy;
 cout<<"\n";
 line(78,'+');

 while(fin.read((char*)&sc,sizeof(sc)))
 {
 if(sc.check_dt(d)==1)
 {
  clrscr();
  sc.sdisplaydata();
  cout<<"\n\t  Is this the schedule you want to delete (y/n) : ";
  cin>>rep;
  if(rep=='y'||rep=='Y')
  {
    clrscr();
    systime();
    sysdate();
    line(78,'*');
    cout<<"\t\t     Deleted!! \n ";
    line(78,'*');
   }
  else
  {
   cout<<"\n\t\t  No Problem " ;
   fout.write((char*)&sc,sizeof(sc));
  }
 }
 else
  fout.write((char*)&sc,sizeof(sc));
  fin.close();
  fout.close();
  remove("scheduler.dat");
  rename("Nscheduler.dat","scheduler.dat");
  getch();
 }
}
//-----------------------------------------------------------
void smodify()
{
 int flag;
 clrscr();
 systime();
 sysdate();
 fstream fin,fout;
 fin.open("scheduler.dat",ios::in|ios::binary);
 fout.open("Nscheduler.dat",ios::out|ios::binary);
 scheduler sc;
 Date1 d;
 cout<<"\n\n";
 line(78,'+');
 cout<<"Enter the Date of that schedule which you want to delete :"
     <<"\n\t Day = ";
 cin>>d.dd;
 cout<<"\t Month = ";
 cin>>d.mm;
 cout<<"\t Year = ";
 cin>>d.yy;
 cout<<"\n";
 line(78,'+');
 while(fin.read((char*)&sc,sizeof(sc)))
 {
  if(sc.check_dt(d)==1)
  {
   flag=1;
  }
  else
  {
   fout.write((char*)&sc,sizeof(sc));
   }
  }
  if(flag==1)
  {
    clrscr();
      gotoxy(10,5);
      cout<<" Enter the Data in Schedule to be Modified \n\n: ";
    sc.sgetdata();
    fout.write((char*)&sc,sizeof(sc));
    cout<<"\n\n\t\t    Your record has been modified!! ";
   }
  if(flag==0)
  {
     clrscr();
     systime();
     sysdate();
     cout<<"\n\n\n\n\n\n\n\n";
     line(78,'*');
     cout<<"\t\t\t No such Schedule exist\n";
     line(78,'*');
  }
  fin.close();
  fout.close();
  remove("scheduler.dat");
  rename("Nscheduler.dat","scheduler.dat");
  getch();
}
//-----------------------------------------------------------
void ssview()       //to display selected schedules
{
 scheduler sc;
 clrscr();
 systime();
 sysdate();
 Date1 d;
 int flag=0;
 ifstream fin("scheduler.dat",ios::in|ios::binary);
 cout<<"\n\n";
 line(78,'+');
 cout<<"Enter the Date of that schedule which you want to delete :"
     <<"\n\t Day = ";
 cin>>d.dd;
 cout<<"\t Month = ";
 cin>>d.mm;
 cout<<"\t Year = ";
 cin>>d.yy;
 cout<<"\n";
 line(78,'+');
 while(fin.read((char*)&sc,sizeof(sc)))
 {
  if(sc.check_dt(d)==1)
  {
   clrscr();
   sc.sdisplaydata();
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
     cout<<"\t\t\t No such Schedule exist\n";
     line(78,'*');
 }
  getch();
  fin.close();
}
