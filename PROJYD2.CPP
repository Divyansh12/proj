//---------------------Header Files------------------
#include<fstream.h>
#include<conio.h>
#include<process.h>
#include<ctype.h>
#include<stdio.h>
#include<string.h>
//-----------------------------------------------------------
void line(int ,char );         //function for displaying lines (definition present in main)

void sysdate();               //function for displaying date (definition present in main)

void systime();	     //function for displaying time (definition present in main)

//-------------------------------------------------------------
class contact
{
 char telephone[9],mobile1[15],mobile2[15],email[20];
 char name[30],fathername[20],address[30],pincode[8],job[20],company[30];
 public:
 void cgetdata();
 void cdisplaydata();
 char *return_telephone()
{
 return telephone;
 }
 char *return_name()
{
 return name;
 }
 char *return_address()
{
 return address;
 }
 char *return_mobile1()
{
 return mobile1;
 }
 char *return_mobile2()
{
 return mobile2;
 }
  char *return_company()
{
 return company;
 }

};
//-----------------------------------------------------------
 void contact :: cgetdata()     //function to get data for contact
{
 clrscr();
    systime();
    sysdate();
    cout<< "\n\t\t\t\t Contact:";
    cout<< "\n\nNAME: ";
    gets(name) ;
    cout<< "\nTelephone no.: ";
    gets(telephone) ;
    cout<< "\nMobile No.1:";
    gets(mobile1) ;
    cout<< "\nMobile No.2:";
    gets(mobile2) ;
    cout<< "\nEmail Id:";
    gets(email) ;
    cout<< "\nAddress:";
    gets(address);
    cout<< "\nPincode:";
    gets(pincode) ;
    cout<< "\nJob:";
    gets(job) ;
    cout<< "\nCompany:";
    gets(company) ;

}
//-----------------------------------------------------------
void contact :: cdisplaydata()       //function to display data of contact
{
    clrscr();
    systime();
    sysdate();
    cout<< "\n\t\t\t\t Contact:";
    cout<< "\n\nNAME: ";
    puts(name) ;
    cout<< "\nTelephone no.: ";
    puts(telephone) ;
    cout<< "\nMobile No.1:";
    puts(mobile1) ;
    cout<< "\nMobile No.2:";
    puts(mobile2) ;
    cout<< "\nEmail Id:";
    puts(email) ;
    cout<< "\nAddress:";
    puts(address);
    cout<< "\nPincode:";
    puts(pincode) ;
    cout<< "\nJob:";
    puts(job) ;
    cout<< "\nCompany:";
    puts(company) ;
    getch();
}
//-----------------------------------------------------------
// contact functions -add modify delete display
void cadd()
{
 clrscr();
 fstream file;
 file.open("contact.dat",ios::app|ios::binary);
 contact c;
 char rep;

 do
 {
  c.cgetdata();
  file.write((char*)&c,sizeof(c));
  cout<<"\n  Want to add more records (y/n):";
  cin>>rep;
 }while(rep=='y'||rep=='Y');
}
//-----------------------------------------------------------
void cdisplay()
{
  clrscr();
  fstream file;
  file.open("contact.dat",ios::in|ios::binary);
  contact c;
  while(file.read((char*)&c,sizeof(c)))
  {
   c.cdisplaydata();
  }
}
//-----------------------------------------------------------
void cdelete()
 {
  clrscr();
  systime();
  sysdate();
  fstream file,file2;
  file.open("contact.dat",ios::in|ios::binary);
  file2.open("Ncontact.dat",ios::out|ios::binary);
  contact c;
  char name[20],mobile[10],rep;
  cout<<"\nEnter name and mobile 1 for deletion:"
      <<"\n Name : ";
  gets(name);
  cout<<"\n Mobile 1 :";
  gets(mobile);
  while(file.read((char*)&c,sizeof(c)))
  {
   if(strcmp(c.return_name(),name)!=0 && strcmp(c.return_mobile1 (),mobile)!=0)
  {
   file2.write((char*)&c,sizeof(c));
  }
  else
  {
   clrscr();
   c.cdisplaydata();
   cout<<"\n  Are you sure you want to delete (y/n) :";
   cin>>rep;
   if (rep=='n' || rep=='N')
   file2.write((char *)&c,sizeof(c));
  }
 }
  file.close();
  file2.close();
  remove("contact.dat");
  rename("Ncontact.dat","contact.dat");
  }
//-----------------------------------------------------------
 void cmodify()
 {
  clrscr();
  char rep;
  systime();
  sysdate();
  fstream file,file2;
  file.open("contact.dat",ios::in|ios::binary);
  file2.open("Ncontact.dat",ios::out|ios::binary);
  contact c;
  char name[20],mobile[10];
  cout<<"\nEnter name and mobile 1 for modification:"
      <<"\n Name : ";
  gets(name);
  cout<<"\n Mobile 1 :";
  gets(mobile);
  while(file.read((char*)&c,sizeof(c)))
  {
  if(strcmp(c.return_name(),name)!=0 && strcmp(c.return_mobile1(),mobile)!=0)
  {
   clrscr();
   c.cgetdata();
   file2.write((char*)&c,sizeof(c));
  }
  else
  {
   clrscr();
   c.cdisplaydata();
   cout<<"\n  Are you sure you want to modify(y/n) : " ;
   cin>>rep;
  if (rep=='n' || rep=='N')
   file2.write((char *)&c,sizeof(c));
  else
  {
   clrscr();
   c.cgetdata();
   file2.write((char*)&c,sizeof(c));
 }

  file.close();
  file2.close();
  remove("contact.dat");
  rename("Ncontact.dat","contact.dat");
  }
 }
}
//-----------------------------------------------------------
void cphone_disp()     // searching contact by telephone number
{
  clrscr();
  systime();
  sysdate();
  char tele[9];
  cout<<"Enter The Telephone Number For Serach:";
  gets(tele);
  fstream file;
  file.open("contact.dat",ios::in|ios::binary);
  contact c;
  while(file.read((char*)&c,sizeof(c)))
  {
   if(strcmp(tele,c.return_telephone())==0)
   {
    clrscr();
    line(78,'*');
    cout<<"\t\t\t     Found!!"<<endl;
    line(78,'*');
    c.cdisplaydata();
   }
   else
   {
     clrscr();
     systime();
     sysdate();
     cout<<"\n\n\n\n\n\n\n\n";
     line(78,'*');
     cout<<"\t\t\t No such contact exist\n";
     line(78,'*');
   }
 }
}
//-----------------------------------------------------------
void cname_disp()          // searching contact by name
{
  clrscr();
  systime();
  sysdate();
  char name[30];
  cout<<"Enter The Name For Serach:";
  gets(name);
  fstream file;
  file.open("contact.dat",ios::in|ios::binary);
  contact c;
  while(file.read((char*)&c,sizeof(c)))
  {
   if(strcmp(name,c.return_name())==0)
   {
    clrscr();
    line(78,'*');
    cout<<"\t\t\t     Found!!"<<endl;
    line(78,'*');
    c.cdisplaydata();
   }
   else
   {
     clrscr();
     systime();
     sysdate();
     cout<<"\n\n\n\n\n\n\n\n";
     line(78,'*');
     cout<<"\t\t\t No such contact exist\n";
     line(78,'*');
   }
  }
 }
//-----------------------------------------------------------
void caddress_disp()     	// searching contact by address
{
  clrscr();
  systime();
  sysdate();
  char address[30];
  cout<<"Enter The Address For Serach:";
  gets(address);
  fstream file;
  file.open("contact.dat",ios::in|ios::binary);
  contact c;
  while(file.read((char*)&c,sizeof(c)))
  {
   if(strcmp(address,c.return_address())==0)
   {
    clrscr();
    line(78,'*');
    cout<<"\t\t\t     Found!!"<<endl;
    line(78,'*');
    c.cdisplaydata();
   }
   else
   {
     clrscr();
     systime();
     sysdate();
     cout<<"\n\n\n\n\n\n\n\n";
     line(78,'*');
     cout<<"\t\t\t No such contact exist\n";
     line(78,'*');
   }
  }
}
//-----------------------------------------------------------
void cmobile_disp()            // searching contact by mobile number
{
  clrscr();
  systime();
  sysdate();
  char mobile[15];
  cout<<"Enter The Mobile Number For Serach :";
  gets(mobile);
  fstream file;
  file.open("contact.dat",ios::in|ios::binary);
  contact c;
  while(file.read((char*)&c,sizeof(c)))
  {
   if(strcmp(mobile,c.return_mobile1())==0||strcmp(mobile,c.return_mobile2())==0)
   {
    clrscr();
    line(78,'*');
    cout<<"\t\t\t     Found!!"<<endl;
    line(78,'*');
    c.cdisplaydata();
   }
   else
   {
     clrscr();
     systime();
     sysdate();
     cout<<"\n\n\n\n\n\n\n\n";
     line(78,'*');
     cout<<"\t\t\t No such contact exist\n";
     line(78,'*');
   }
  }
}
//-----------------------------------------------------------
void ccompany_disp()    	// searching contact by company	
{
  clrscr();
  systime();
  sysdate();
  char company[15];
  cout<<"Enter The Company For Serach:";
  gets(company);
  fstream file;
  file.open("contact.dat",ios::in|ios::binary);
  contact c;
  while(file.read((char*)&c,sizeof(c)))
  {
   if(strcmp(company,c.return_company())==0)
   {
    clrscr();
    line(78,'*');
    cout<<"\t\t\t     Found!!"<<endl;
    line(78,'*');
    c.cdisplaydata();
   }
   else
   {
     clrscr();
     systime();
     sysdate();
     cout<<"\n\n\n\n\n\n\n\n";
     line(78,'*');
     cout<<"\t\t\t No such contact exist\n";
     line(78,'*');
   }
 }
}