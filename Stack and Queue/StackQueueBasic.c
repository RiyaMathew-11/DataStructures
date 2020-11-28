// Implementation of stack and queue with basic functions on insertion and deletion in menu driven format

#include<stdio.h>
#define MAX 7
int Stack[MAX],Queue[MAX],Top,Front,Rear,ele,i;
void push();
void pop();
void enqueue();
void dequeue();
void Sdisp();
void Qdisp();

int main()
{

  Top =  Front = Rear = -1;
  int opt,choice1,choice2;
  printf("1. STACK\n2. QUEUE\n");
  //printf("Enter your choice:");
  scanf("%d",&opt);
  if(opt == 1){
    printf("STACK OPERATIONS: 1. PUSH   2. POP   3. DISPLAY  4.EXIT");
    ;
    do{
      //printf("\nEnter your choice: ");
      scanf("%d",&choice1);
      switch(choice1)
      {
        case(1):
        {
          push();
          break;
        }
        case(2):
        {
          pop();
          break;
        }
        case(3):
        {
          Sdisp();
          break;
        }
        case(4):
        {
          printf("\nExit Operation");
          break;
        }
        default:
          printf("Please enter valid choice:1/2/3/4");
      }
    }while(choice1 != 4);
  }
  else{
    printf("QUEUE OPERATIONS: 1. ENQUEUE   2. DEQUEUE   3. DISPLAY  4.EXIT\n");

    do{
      //printf("Enter your choice: ");
      scanf("%d",&choice2);
      switch(choice2)
      {
        case(1):
        {
          enqueue();
          break;
        }
        case(2):
        {
          dequeue();
          break;
        }
        case(3):
        {
          Qdisp();
          break;
        }
        case(4):
        {
          printf("\nExit Operation");
          break;
        }
        default:
          printf("Please enter valid choice:1/2/3/4");
      }
    }while(choice2!=4);
  }
  return 0;
}

void push(){
  if(Top == MAX - 1)
    printf("\nOverflow");
  else{
    //printf("Enter value to be pushed: ");
    scanf("%d ",&ele);
    Top++;
    Stack[Top]=ele;
  }
}

void pop(){
  if(Top == -1)
    printf("\nUnderflow");
  else{
    ele = Stack[Top];
    Top--;
    printf("\nThe Popped element is %d",ele);
  }
}

void Sdisp(){
  if(Top>=0){
    printf("\nThe elements in Stack are: ");
    for(int i = 0; i<=Top;i++)
      printf("%d ", Stack[i]);
  }
  else
    printf("\nStack is empty !");
}

void enqueue(){
  if(Rear == MAX - 1)
    printf("\nOverflow");
  else{
    if(Front = -1)
      Front+=1;
    //printf("Enter element to be inserted: ");
    scanf("%d ",&ele);
    Rear+=1;
    Queue[Rear] = ele;
    }
}

void dequeue(){
  if(Front == - 1)
    printf("\nUnderflow");
  else{
    ele = Queue[Front];
    printf("\nThe element deleted is:%d ",ele);
    if(Front == Rear)
      Front = Rear = -1;
    else
        Front+=1;
  }
}

void Qdisp(){
  if(Front>=0){
    printf("\nThe elements in Queue are: ");
    for(int i = Front; i<=Rear;i++)
      printf("%d ", Queue[i]);
  }
  else
    printf("\nQueue is empty");
}
