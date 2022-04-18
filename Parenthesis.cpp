#include<iostream>
#include<conio.h>
using namespace std;
#include<string>
string expression;
int top = -1 ;
char stack[100];

void push(char element);
void pop();
void Parenthesis_Checker();

int main()
{
    cout << "Enter an expression to check";
    getline(cin, expression, '\n');
    Parenthesis_Checker();
 
}

void Parenthesis_Checker()
{
    int i;
    
    pair<string, string> pair_1("(", ")"); 
    pair<string, string> pair_2("{", "}");
    pair<string, string> pair_3("[", "]");  

    for(i=0;i<=expression.length();i++)
    {
        if(expression[i] == '(' ||  expression[i] == '{' || expression[i] == '[' )
        {
                 push(expression[i]);
        }
        else if(expression[i] == ')' ||  expression[i] == '}' || expression[i] == ']')
        {

              pair<string , string> pair_4;

              pair_4.first =  stack[top];
              pair_4.second = expression[i];

              if(pair_4 == pair_1 || pair_4 == pair_2 || pair_4 == pair_3 )
              {
                 pop();
              }
              else
              {
                  cout << "Expression not balanced" << endl;
                  return;
              }

        }

    }

    if(top == -1)
    {
        cout << "Expression balanced" << endl;
    }
    else if(top > -1)
    {
        cout << "Expression not balanced" << endl;
    }
}

void push(char element)
{

           top++;
           stack[top] = element;
        
}

void pop()
{

           top--;
}