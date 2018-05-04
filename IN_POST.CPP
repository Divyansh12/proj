//------------------Header Files ---------------------------------------------
# include <iostream.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <conio.h>
//-----------------------------------------------------------------------------------------
void systime();       //function for displaying time (definition present in main)

void sysdate();       //function for displaying date (definition present in main)

void line(int,char);    //function for displaying lines (definition present in main)
//------------------------------------------------------------------------------------------------
extern char pexp[1000]; // this contains the input string
//--------------------------------------------------------------------------------------
 class istack
 {
 int top;
 public:
 char Stack[100],Iexp[100],Pexp[100];

 istack()// constructor to assign initial null value to variables
 {
 top=-1;
 Stack[0]=NULL;
 Iexp[0]=NULL;
 Pexp[0]=NULL;
 }
 void getdata()  // function to take the input expression from user
 {
   cout<<"\n\n";
   line(78,'-');
   cout<<"\t\t Enter the Expression : ";
   gets(Iexp);
   line(78,'-');
   cout<<"\n\n";
  }
 void push(char);  // function to push data in the stack
 char pop();  // function to remove data from the stack

 void infix_to_postfix();    // function to convert input infix expression to postfix expression 

};
//--------------------------------------------------------------------------------------
void inp_convert()   // function to invoke infix to postfix function
    {
       clrscr();
       systime();
       sysdate();
       istack s;
       s.getdata();
       s.infix_to_postfix();

       getch();
       strcpy(pexp,s.Pexp);
      } 

//--------------------------------------------------------------------------------------
    void istack::push(char Symbol)
  {

       if(top==99)
      cout<<"Error : Stack is full."<<endl;

       else
      {
	 top++;
	 Stack[top]=Symbol;
      }
    }

 /*************************************************************************///--------------------------------  pop( )  -----------------------------///*************************************************************************/constchar pop( )
 char istack::pop()
    {
       char Symbol=NULL;

       if(top==-1)
      cout<<"Error : Stack is empty."<<endl;

       else
      {
	 Symbol=Stack[top];
	 Stack[top]=NULL;
	 top--;
      }

       return Symbol;
    }

 /*************************************************************************///---------------------  infix_to_postfix(const char *)  ----------------///*************************************************************************/void infix_to_postfix(constchar *Infix)
 void istack::infix_to_postfix()
    {


       char Symbol[5]={NULL};
       char Temp[5]={NULL};
       int f=0;
       for(int count=0;count<strlen(Iexp);count++)
      {

	 Symbol[0]=Iexp[count];
	 if(!isalnum(Iexp[count]) && f==0)
	 {
	 strcat(Pexp," ");
	 f=1;
	 }
	 else
	 f=0;
	 if(Symbol[0]=='(')
	push(Symbol[0]);

	 else if(Symbol[0]==')')
	{
	      Symbol[0]=pop();

	   while(Symbol[0]!='(')
	      {
	       strcat(Pexp,Symbol);
	       Symbol[0]=pop();
	      }
	      f=0;
	}
	 else if(Symbol[0]=='^' || Symbol[0]=='*' || Symbol[0]=='/'
		    || Symbol[0]=='+' || Symbol[0]=='-')
	{

	   if((Symbol[0]=='*' || Symbol[0]=='/') && top!=-1)
	      {

	     Temp[0]=pop();

	     while((Temp[0]=='^' || Temp[0]=='*' || Temp[0]=='/') && top!=-1)
		{

		   strcat(Pexp,Temp);

		   Temp[0]=pop( );
		}
		     push(Temp[0]);
	      }

	   else if((Symbol[0]=='+' || Symbol[0]=='-') && top !=-1)
	      {
	     Temp[0]=pop();

	     while(Temp[0]!='(' || top!=-1)
		{

		   strcat(Pexp,Temp);

		   Temp[0]=pop();
		}

	     push(Temp[0]);
	      }

	   push(Symbol[0]);
	}

	 else
	 {
	  strcat(Pexp,Symbol);
	  }
   }
      while(top!=-1)
      {
      Temp[0]=pop();
      strcat(Pexp," ");
      strcat(Pexp,Temp);
      }
    }