#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<stdbool.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

int login();
void menu();
void enqueue();
void dequeue();
void search();
void selectionsort();
void list_node();

struct user
{
    char name[50];
    char ID[10];
};

struct node
{
    char subject[20];
    int sec;
    int date;
    struct user detail;
    struct node *ptrnext;
};

struct node *front, *rear, *thisptr, *newptr, *headptr, *walker, *smallest;
int count = 0;

int main()
{
    time_t t;
    time(&t);


    printf("\t*************************************************\n");
	printf("\t*                                               *\n");
	printf("\t*     ------------------------------------      *\n");
	printf("\t*     STUDENT ATTENDANCE MANAGEMENT SYSTEM      *\n");
	printf("\t*     ------------------------------------      *\n");
	printf("\t*                                               *\n");
	printf("\t*************************************************\n\n\n");
    for(int i=0;i<65;i++)
    printf("-");
    printf("\nCurrent date and time : %s",ctime(&t));
    for(int i=0;i<65;i++)
    printf("-");

    int access = login();
    if(access == 1)
        menu();
    else
        printf("\nThank You!");

    system("cls");
}

int login()
{
    int access = 0;
	int a=0,i=0;
    char username[10],c=' ';
    char userpwd[10],code[10];
    char user_name[10] = "admin2020";
    char user_pass[10]  = "abc123";


    do
    {
        printf("\n\n  **************************  LOGIN  **************************  ");
        printf(" \n\n                ENTER USERNAME: ");
        scanf("%s", &username);
        printf(" \n                ENTER PASSWORD: ");
        while(i<8)
        {
            userpwd[i]=getch();
            c=userpwd[i];
            if(c==13) break;
            else printf("*");
            i++;
        }
        userpwd[i]='\0';

        i=0;

        if(!strcmp(username,user_name) && !strcmp(userpwd,user_pass))
        {
            printf("\n\n\n             LOGIN IS SUCCESSFUL!");
            access = 1;
            return access;
        }
        else
        {
            printf("\n\n\n                 SORRY !!!!  LOGIN IS UNSUCESSFUL");
            a++;
            getch();
        }
    }
	while(a<=2);
	if (a>2)
	{
		printf("\nSorry you have entered the wrong username and password for four times!!!");
		getch();
    }


}



void menu()
{
    system("cls");
    char ch;
	int choice=TRUE;

	front=NULL;

	while(choice==TRUE)
	{
		printf("\n\n[-----------STUDENT ATTENDANCE MANAGEMENT SYSTEM-----------]");
		printf("\nA - Enqueue queue");
		printf("\nB - Dequeue queue");
		printf("\nS - Search student ID");
		printf("\nF - Sort student by section");
		printf("\nD - Display queue content");
		printf("\nX - Exit\n");
		printf("\nEnter choice: ");
		scanf(" %c",&ch);
		ch=toupper(ch);
		switch(ch)
		{
		case 'A':enqueue();break;
		case 'B':dequeue();break;
        case 'S':search();break;
        case 'F':selectionsort();break;
		case 'D':list_node();break;
		case 'X': choice=FALSE; break;

		default: printf("\nOnly one of the above");

		}
	}


}

void enqueue()
{
    system("cls");
	newptr =(struct node *)malloc(sizeof (struct node));

	printf("\nEnter student name: ");
    scanf(" %s",&newptr->detail.name);
    fflush(stdin);
    printf("\nEnter student ID: ");
    scanf(" %s",&newptr->detail.ID);
    fflush(stdin);
    printf("\n Enter subject:");
    scanf(" %s",&newptr->subject);
    fflush(stdin);
    printf("\n CHOOSE SECTION: \n");
    printf("\n 01-section 01G\n");
    printf("\n 02-section 02G\n");
    printf("\n 03-section 03G\n");
    printf("\n 04-section 04G\n");
    printf("\n 05-section 05G\n");
    printf("\n Enter section:");
    scanf(" %d",&newptr->sec);
    fflush(stdin);


    newptr->ptrnext=NULL;


	if (front==NULL)
	{
	    front=rear=newptr;
	}

	else
	{
		rear->ptrnext=newptr;
		rear=newptr;
	}

count++;


}

void dequeue()
{
    system("cls");
	thisptr = front;


	if (front==NULL)
	{
      printf("\n Student List is empty. Cannot delete!!!\n\n");
      return;
	}

	else
	{
	front=front->ptrnext;
	free(thisptr);
	}

count--;
	list_node();
}

void search()
{
     system("cls");
     char key[10];
     printf("\n Enter student ID:");
     scanf(" %s",&key);
     thisptr = front;
     while(thisptr!=NULL)
     {
        if(strcmp(thisptr->detail.ID,key)==0)
        {
            printf("\n Student Records found!\n");
    		printf("\n\n Student Name :%s",thisptr->detail.name);
	        printf("\n\n Student ID :%s",thisptr->detail.ID);
    	    printf("\n\n Subject:%s",thisptr->subject);
        	printf("\n\n Section :%d",thisptr->sec);
			printf("\n");

            return;

        }
           thisptr = thisptr->ptrnext;

     }
               printf("\nSorry, no student ID match found.\n");
               return;


}

void selectionsort()
{
    system("cls");
    struct node *temp, *curr, *nodes[10];
    int count = 0;

    curr = front;
    if(front==NULL)
    return;

    for(int i = 0; curr; i++)
	{
		nodes[i] = curr;
		curr = curr->ptrnext;
		count++;
	}

	bool sorted = false;
	for(int pass = 1; (pass < count) && !sorted; pass++)
			{
				sorted = true;
				for(int i = 0; i < count - pass; i++)
					if(nodes[i]->sec > nodes[i+1]->sec)
					{
						temp = nodes[i];
						nodes[i] = nodes[i+1];
						nodes[i+1] = temp;
						sorted = false;
					}
			}

for(int i = 0; i < count; i++)
	{
		if(i == 0)
		{
			front = nodes[i];
			front->ptrnext = NULL;
			rear = front;
		}
		else
		{
			rear->ptrnext = nodes[i];
			rear = rear->ptrnext;
			rear->ptrnext = NULL;
		}
	}
}


void list_node()
{
	if (front==NULL)
	{
		printf("\n Student List is empty.\n\n");
		return;
	}

	thisptr=front;
	do
	{
		printf("\n\n Student Name :%s",thisptr->detail.name);
        printf("\n\n Student ID :%s",thisptr->detail.ID);
        printf("\n\n Subject:%s",thisptr->subject);
        printf("\n\n Section :%d",thisptr->sec);

		printf("\n");
		thisptr=thisptr->ptrnext;
	}while(thisptr !=NULL);

	printf("\n\nPress any key to continue");
    getch();
}

