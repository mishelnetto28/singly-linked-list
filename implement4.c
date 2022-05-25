#include<stdio.h>
#include<stdlib.h>
void main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head=NULL, *pos=NULL, *tail=NULL;
	int ch,entry,count=0,num=0,flag=0;
	while(1)
	{
		printf("\n 1.Insert \n 2.Display \n 3.Count \n 4.Search an Element \n 5.Delete \n 6.Exit");
		printf("\n Enter your choice:");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: 
				{
					printf("\n Enter Data");
					scanf("%d",&entry);
					if (head==NULL)
					{
						head=(struct node*)malloc(sizeof(struct node));
						head->data=entry;
						pos=head;
						tail=head;
					}
					else
					{
						tail->next=(struct node*)malloc(sizeof(struct node));
						tail=tail->next;
						tail->data=entry;
					}break;
				}
			case 2:
				{
					pos=head;
					printf("\n Elements are: ");
					while(pos!=NULL)
					{
						printf("\t %d",pos->data);
						pos=pos->next;
					}
				}break;
			case 3:
				{
					pos=head;
					while (pos!=NULL)
					{
						count=count+1;
						pos=pos->next;
					}
					printf("\n The count is %d",count);
					break;
				}
			case 4:
				{
					printf("Enter element to be searched");
					scanf("%d",&num);
					pos=head;
					count=0;
					while(pos!=NULL)
					{
						count++;
						if(pos->data==num)
						{
							printf("\n Element found at position %d",count);
							flag=1;
						}
						pos=pos->next;
					}
					if(flag==0)
					{
						printf("\n Element not present\n");
					}
					break;
				}
			case 5:
				{
					struct node *temp=head;
					int i;
					printf("Enter position of data");
					scanf("%d",&entry);
					if(entry==0)
					{
						head=head->next;
						temp->next=NULL;
						free(temp);
					}
					else
					{
						for(int i=0;i<entry-1;i++)
						temp=temp->next;
						struct node *def=temp->next;
						temp->next=temp->next->next;
						def->next=NULL;
						free(def);
					}
					break;
				}
			case 6:
				{
						printf("\n Goodbye");
						exit(0);
				}
		}
	}
}
