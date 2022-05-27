#include <stdio.h>
#include <stdlib.h>
struct stack{                    //Array implementation of the stack
    char arr[10000];
    int top;
};
typedef struct stack stack;


void create(stack *s);
void push(stack *s,unsigned int num);
unsigned int pop(stack *s);
unsigned int min_num(stack *s);

int top(){

}


int main()
{unsigned int Q,E,counter=0;     //Q -> number of operations , E -> element to push in the stack , counter -> to count number of minimum numbers in the stack
int select,i;
                  //select -> to select which operation to be done
stack st1;


create(st1);

                    //Creating an empty stack
scanf("%u",&Q);
unsigned int value[Q];           //An array to store the minimum numbers in the stack
while(Q>0){
    scanf("%u",&select);
    switch(select){
        case 1:                  //When select = 1 ...we push an element in the stack
            scanf("%u",&E);
            push(&st1,E);
            break;
        case 2:                 //When select = 2 ...we pop an element from the stack
            pop(&st1);
            break;
        case 3:                 //When select = 3 ...we find the min number in the stack
            value[counter++] = min_num(&st1);
            break;
      }
    Q--;
}
unsigned int t;
for(i=0;i<counter;i++){            //To check if the stack is empty or not
    t = value[i];
    if(t == 0){
        printf("Empty\n");        //If empty we print "Empty"
    }else{
        printf("%u\n",value[i]);  //If not we print every element we store in value[]
    }
}
    return 0;
}

//A function to create an empty stack
void create(stack *s){
s->top=-1;
}

//A function to push an element in the stack
void push(stack *s,unsigned int num){
    if(s->top != sizeof(s->arr)-1){      //Checking if the stack's not full
    s->top++;
    s->arr[s->top]=num;
    }
}

//A function to pop an element from the stack
unsigned int pop(stack *s){
unsigned int temp=0;
   if(s->top!=-1){            //Checking if the stack's not empty
   temp=s->arr[s->top];
   s->top--;
   }
   return temp;
}

//A function to find minimum number in the stack
unsigned int min_num(stack *s){
stack st2;
unsigned int temp,min=0;
create(&st2);                //Creating another empty stack
if(s->top != -1){            //Checking if the stack's not empty
min=999999999;
while(s->top != -1){         //Pop each element from stack 1 and compare it to min the push it in stack 2
temp=pop(s);
push(&st2,temp);
  if(temp<min){
    min=temp;                //Represent the minimum number in the stack
   }
 }
while(st2.top != -1){        //Pushing every element back to stack 1
    temp=pop(&st2);
    push(s,temp);
   }
 }
 return min;                 //Returning the minimum and if it's = 0 them the stack is empty
}
