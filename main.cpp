/*Author: MrUnknown
*/
#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

class Stack{
private:
    //data members
    int Top;
    int MaxSize;
    int* array;

public:

    //consturctor
    Stack(int size) {
        MaxSize = size;
        array = new int[size];
        Top = -1;
    }

    //destructor
    ~Stack() {
        delete []array;
    }

    //function to check if stack is emtpy
    bool isEmpty() {
        if(Top == -1) {
            cout<<"stack is Empty!"<<endl;
            return true;
        }
        return false;
    }

    //function to push value onto stack
    void push(int operand)
    {
        //check if stack is full
        if(Top == MaxSize -1) {
            cout<<"Error: stack is full"<<endl;
            return;
        }
        Top++;
        array[Top] = operand;
    }

    //function to pop value of from stack
    int pop() {
        //check if stack is empty;
        if(isEmpty() == true) {
            return -1;
        }

       return array[Top--];
    }

    //function to print stack
    void PrintStack() {
       for(int i = 0; i < Top; i++) {
            cout<<array[i]<<" ";
       }
    }

    //funccton to do the calculation when operator is encountered
    void calculate(char c, int op_Y, int op_X) {
       //make a switch
       switch (c) {
       case '+':
            push(op_Y + op_X);
            break;
       case '-':
            push(op_Y - op_X);
            break;
       case '*':
            push(op_Y * op_X);
            break;
       case '/':
            push(op_Y / op_X);
            break;
       case '^':
            push(pow(op_Y, op_X));
            break;
       case '%':
            push(op_Y % op_X);
            break;
       default:
            cout<<"Invalid character Expression"<<endl;
            break;
       }
    }

};



//function to evaluate postfix expression
int evaluatePostfixExpression(string& expression) {
    Stack stack(expression.length());

    cout<<"Stack: ";
    for(int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        //check to see if its a digit
        if(c >= '0' && c <= '9') {
            stack.push(c - '0');
        }else {
            int operand_X = stack.pop();
            int operand_Y = stack.pop();
            stack.calculate(c, operand_Y, operand_X);
        }

        //print out the stack as evaluation is carried
        stack.PrintStack();
    }
    cout<<endl;
    //at the end the stack will only have one element in it so
    //pop it and return it since that's the answer
    if(!stack.isEmpty()) {
        return stack.pop();
    }else {
        cout<<"invalid postfix expression"<<endl;
        return -1;
    }
}

int main()
{
    //postfix expression
    string expression = "62+5*84/-";
    int result = evaluatePostfixExpression(expression);
    cout<<"PostFix result is: "<<result<<endl;
    return 0;
}
