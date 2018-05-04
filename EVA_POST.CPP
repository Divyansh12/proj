 //------------------Header Files------------------------------------
 #include <stdio.h>
 #include <iostream.h>
 #include <stdlib.h>
 #include <conio.h>
 #include <string.h>
 //----------------------------------------------------------------------------------------------
 void line (int,char);     //function for displaying lines (definition present in main)
 //-----------------------------------------------------------------------------------------------
 class stack
 {
  long double s[50];
  int top;
  public:
  stack()
 {
  top=-1;
 }
 void push(long double);    // function to push data in the stack 
 long pop();   // function to remove data from the stack
 };
//--------------------------------------------------------------------------------------
 void stack::push(long double l)         //function to push operators into a stack
 {
  if(top+1==50)
  cout<<"\n Overflow";
  else
  {   
    s[++top]=l;
   } 
 }
//--------------------------------------------------------------------------------------
 long stack::pop()
 {
   if(top==-1)
   return -1;
   else
  { 
    long v=s[top--];
    return v; // v contains the value which has been popped
   }
 }

//--------------------------------------------------------------------------------------
long int isOperator(char ch)  // function to check the operator 
{
    if (ch=='+' || ch=='-' || ch=='*' || ch=='/')
	return 1;
    else
	return 0;
}
//--------------------------------------------------------------------------------------
// function to perform the various operations such as addition, subtraction, etc. 
long double performOperation(long double op1, long double op2, char op)  
{
    long double ans;
    switch(op){
    case '+':
	ans = op2 + op1;
	break;
    case '-':
	ans = op2 - op1;
	break;
    case '*':
	ans = op2 * op1;
	break;
    case '/':
	ans = op2 / op1;
	break;
    }
    return ans;
}

//--------------------------------------------------------------------------------------
int evaluate(char pexp[100]) //function to evaluate the given expression
{

    stack s;
    char exp[100], buffer[15];
    int i,j,len;
    long double op1, op2,  x;
    strcpy(exp,pexp);
    len=strlen(exp);
    j = 0;
    for(i=0; i<len;i++)
    {
	if(exp[i]>='0' && exp[i]<='9'){
	    buffer[j++] = exp[i];
	}
	else if(exp[i]==' '){
	    if(j>0){
		buffer[j] = '\0';
		x = atol(buffer);
		s.push(x);
		j = 0;
	    }
	}

	   else if(isOperator(exp[i]))
	{
	    op1 = s.pop();
	    op2 = s.pop();
	    s.push(performOperation(op1, op2, exp[i]));
	}
    }
    line(78,'-');
    printf("\t\t\t\t Answer= %d\n", s.pop());
    line(78,'-');
    getch();
    return 0;
}