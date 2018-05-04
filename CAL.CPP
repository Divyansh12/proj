 //------------------Header Files ---------------------------
 #include<iostream.h>
 #include<conio.h>
 #include "eva_post.cpp"    // evaluates the postfix expression 
 #include "IN_POST.cpp"  // converts the input into a postfix expression 
 //-----------------------------------------------
 char pexp[1000],op1[2];
 //-----------------------------------------------------------
 void sysdate();   //function for displaying date (definition present in main)

 void systime();   //function for displaying time (definition present in main)

 void menu();      // function for returning to main menu (definition present in main)

 void line(int,char);   //function for displaying lines (definition present in main)
 //-----------------------------------------------------------

 void calculator()  // function to take the input, invoke convert function and display answer 
  {
	come_here:	//label to repeat the program
	clrscr();
	systime();
	sysdate();
	cout<<"\n";
	line(78,'*');
	cout<<"\t\t\t     Calculator \n";
	line(78,'*');
	gotoxy(17,11);
	textattr(WHITE+BLINK);
	cprintf("  -> Press any key to start");
	getch();
	textcolor(15);
	inp_convert();                         //inputs the infix expression
	evaluate(pexp); 	//evaluates the infix expression and diplays the result
	textattr(WHITE);
	cout<<"\n\n\n\t\t      "<<"Continue ?? (y/n)      : ";
	gets(op1);
	if(strcmp(op1,"y")==0)
	{
	 goto come_here;
	 }
	else if (strcmp(op1,"n")==0)
	{
	 menu();
	 }
  }