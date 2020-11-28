#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include <stdlib.h>
#include<math.h>

#define MAX 100

char STACK[MAX];
float StackEv[MAX];
int Top = -1, TopEv = -1;

void push(char ch){
    STACK[++Top] = ch;
}
char pop(){
    if(Top==-1)
        return -1;
    else
        return STACK[Top--];
}
char top(){
    return STACK[Top];
}


int priority(char ch)
{
    if(ch == '(')
        return 0;
    if(ch == '+' || ch == '-')
        return 1;
    if(ch == '*' || ch == '/')
        return 2;
    if(ch == '^')
        return 3;
    //return 0;
}

void pushEv(float val){
    StackEv[++TopEv] = val;
}

float popEv(){
    if(TopEv==-1)
        return -1;
    else
        return StackEv[TopEv--];
}

float operation(float x, float y, char op){
    switch(op){
        case ('+'): return x + y;

        case ('-'): return x - y;

        case ('*'): return (x * y);

        case ('/'): return x / y;

        case ('^'): return pow(x, y);
    }

    return 0.0f;
}


int main(){

    char Infix[MAX];
    char Postfix[MAX];

    char Evaluate[MAX];
    char *in, ch;
    int nOp;

    printf("\nEnter the expression : ");
    scanf("%s",Infix);

    // CONVERSION
    push('(');

    strcat(Infix,")");

    int ln = strlen(Infix), i = 0;// length of character array holding expression and initialising iterating variable "i"
    in = Infix;
    while(*in != '\0' && i < ln){
        if(isalnum(*in)){
            Postfix[i] = *in;
            i++;
        }
        else if(*in == '(' || *in == '^')
            push(*in);
        else if(*in == ')'){
        while((ch=top())!='(')
            Postfix[i++] = pop();
        pop();
        }
        else{
            while(priority(STACK[Top]) >= priority(*in)){
                Postfix[i] = pop();
                i++;
            }
            push(*in);
        }
        in++;
    }

    Postfix[i] = '\0';  // Setting the end value of string as End

    printf("postfix exp: %s\n\n", Postfix);

    //EVALUATION
    char *ev;
    int NumVar[MAX] = { 0 };
    float val, NumVal[MAX];
    ev = Postfix;
    while(*ev != '\0'){
        if(isalnum(*ev)){
            if(NumVar[*ev - 65] != 1){
                printf("Enter equivalent value of %c: ", *ev);
                scanf("%f", &val);
                pushEv(val);
                NumVar[*ev - 65] = 1;
                NumVal[*ev - 65] = val;
            }
            else{
                pushEv(NumVal[*ev - 65]);
            }
        }

        else{
            float y = popEv();
            float x = popEv();
            float res = operation(x,y,*ev);
            pushEv(res);
        }

        ev++;
    }
    //printf("\nCharacter array: %s",NumVar);

    printf("\nValue of expression  =  %0.2f", popEv());

}
