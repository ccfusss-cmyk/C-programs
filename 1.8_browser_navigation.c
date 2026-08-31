#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};

struct Node* current=NULL;

void visitNewpage(char url[]){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url,url);
    newNode->prev=current;
    newNode->next=NULL;

    if(current!=NULL)
    {
        current->next=newNode;
    }

    current=newNode;
    printf("visited: %s\n",current->url);
}

void goBack(){
    if(current==NULL||current->prev==NULL)
    {
        printf("cannot go back. no previous page\n");
    }
    else
    {
        current=current->prev;
        printf("moved back to :%s\n",current->url);
    }
}

void goForward(){
    if(current==NULL||current->next==NULL)
    {
        printf("cannot go forward. no next page \n");
    }
    else
    {
        current=current->next;
        printf("moved forward to:%s\n",current->url);
    }
}

void displayCurrentpage(){
    if(current==NULL)
    {
        printf("no page visisted yet\n");
    }
    else
    {
        printf("current page:%s\n",current->url);
    }
}

int main(){
    int choice;
    char url[100];

    do
    {
        printf("\n Menu\n");
        printf("1.Visited Page\n");
        printf("2.go back\n");
        printf("3.go forward\n");
        printf("4.display current page\n");
        printf("5.exit\n");
        printf("enter choice\n");
        scanf("%d",&choice);
        getchar();

        switch(choice){
            case 1:
                printf("enter url to visit:");
                fgets(url,100,stdin);
                visitNewpage(url);
                break;

            case 2:
                goBack();
                break;

            case 3:
                goForward();
                break;

            case 4:
                displayCurrentpage();
                break;

            case 5:
                printf("exiting browsersimulator\n");
                break;

            default:
                printf("invalid choice\n");
        }
    }
    while(choice!=5);

    return 0;
}
