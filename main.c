#include <stdio.h>
#include <stdlib.h>

typedef struct Node sq;

struct Node
{
    int data;
    struct Node *next;
};
sq *front=NULL;
sq *rear=NULL;

int main()
{

    int choice;
    printf("-----------------------------\n");
    printf("QUEUEING USING LINKED LIST\n");
    printf("-----------------------------\n");

    do{
    printf("____________________________");
    printf("\nCHOOSE A QUEUE OPERATION\n(1)INSERT\n(2)DELETE\n(3)DISPLAY\n(4)PEEK\n(5)EXIT\n");
    printf("____________________________");

    printf("\nENTER YOUR CHOICE :");
    scanf("%d",&choice);

    switch(choice)
    {
    case 1:
            enque();
             break;

    case 2: deque();
            break;

    case 3: display();
             break;

    case 4: {
                printf("\n----------------------------");
                printf("\nCHOOSE A PEEK OPERATION\n\n(1)PEEK FRONT\n(2)PEEK REAR\n(3)EXIT\n");
                printf("\n----------------------------");
                int option;
                printf("\nENTER YOUR CHOICE :");
                scanf("%d",&option);
                printf("\n----------------------------");
                switch(option){
                    case 1: peek(option);
                            break;

                    case 2: peek(option);
                            break;

                    case 3: printf("\nEXIT\n");
                            break;

                    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");
                }

            }
            break;

    case 5: printf("\nEXIT");
             break;

    default: printf("\nINVALID CHOICE!!\nPLEASE ENTER A VALID OPTION\n");

    }
  }while(choice!=5);

  getch();
  return 0;

}

//return queue status: Empty or Not

int isEmpty(){
    if(front==NULL&&rear==NULL) return 1;

    return 0;
}

//return queue status: Full or Not

int isFull(){
    sq *newnode = (sq*)malloc(sizeof(sq));
    if(newnode==NULL) return 1;

    return 0;
}

void enque()
{
    if(isFull()){
        printf("\nQUEUE OVERFLOW!!!\n");
        return;
      }

      int x;
      printf("\nENTER AN ELEMENT TO INSERT IN THE QUEUE: ");
      scanf("%d",&x);


      sq *newnode;
      newnode = (sq*)malloc(sizeof(sq));
      newnode->data =x;
      newnode->next = 0;

      if(front==0 && rear==0)
      {
          front=rear=newnode;
          printf("\nINSERTED ELEMENT IS THE QUEUE :%d\n", rear->data);

      }
      else
      {
          rear->next = newnode;
          rear = newnode;
          printf("\nINSERTED ELEMENT IS THE QUEUE :%d\n", rear->data);

      }




}

void deque()
{
    if(isEmpty())
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }
    else
    {
       sq *temp;
       temp = front;
       printf("\nDELETED ELEMENT FROM THE QUEUE  :%d\n",front->data);
       if(front->next==NULL){
           front=rear=NULL;
           free(temp);
       }
       else{
            front = front->next;
            free(temp);
       }

    }
}

void display()
{
    struct Node *temp;

    if(isEmpty())
   {
     printf("\nQUEUE UNDERFLOW!!!\n");

   }


    else
    {
        temp = front;
        printf("\nELEMENTS IN THE QUEUE :\n");
        while(temp!=0)
        {
            printf("%d \n",temp->data);
            temp = temp->next;
        }
    }

}



void peek(int signal)
{

    if(isEmpty())
    {
        printf("\nQUEUE UNDERFLOW!!!\n");
    }
    else if(signal==1)
    {
        printf("\nFRONT ELEMENT OF THE QUEUE :%d\n",front->data);
    }
    else
    {
        printf("\nREAR ELEMENT OF THE QUEUE :%d\n",rear->data);
    }
}

