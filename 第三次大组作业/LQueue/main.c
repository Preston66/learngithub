#include <stdio.h>
#include <stdlib.h>
#include "LQueue.h" 

void show(LQueue *Q)
{
	Node *f;
	f = Q->front;
	do
	{
		switch(f->length)
		{
			case 4: printf("| %d |",(*(int *)f->data));    break;
			case 1: printf("| %c |",(*(char *)f->data));   break;
			case 8: printf("| %lf |",(*(double *)f->data)); break;
		}		

		f = f->next;
	}
	while(f);
} 

/*����������ʾ*/
void LeadInterface(void)
{
	system("cls");
	printf("\n\n\n\t\t\t\t\t_________________________________\n");
	printf("\t\t\t\t\t|      ����������������       |\n");
	printf("\t\t\t\t\t|  1.������������               |\n");
	printf("\t\t\t\t\t|  2.�����ַ�������             |\n");
	printf("\t\t\t\t\t|  3.���븡��������             |\n");
	printf("\t\t\t\t\t|  4.��������ʼ������           |\n");
	printf("\t\t\t\t\t|  5.���ٶ���                   |\n");
	printf("\t\t\t\t\t|  6.����                       |\n");
	printf("\t\t\t\t\t|  7.�ж��Ƿ�Ϊ�գ�����ն���   |\n");
	printf("\t\t\t\t\t|  8.ȡ��ͷ������               |\n");	
	printf("\t\t\t\t\t|  0.�˳�                       |\n");
	printf("\t\t\t\t\t|_______________________________|\n");
}

int main(void)
{
	int option1, option2;
	Status sta;
	
	void *data,*e; //�������� 
	
	LQueue *Q;
	int size,num;
	printf("\n\n\n\t\t\t\t\t��ӭ�����ҵĳ���\n\n");
	
	system("pause");
	while(1)
	{
		LeadInterface();	//����������ʾ 
		printf("\n\n\t\t\t\t\t���������ѡ��:");		
		scanf("%d",&option1);
		
		switch(option1)
		{
			
			case 0:
				exit(0);
			case 1:
				if(Q == NULL)
				{
					printf("\t\t\t\t\t�㻹û�д�������\n"); 
				}
				else
				{
					getchar();//��ջ������� 
					printf("\t\t\t\t\t����������\n\t\t\t\t\t");
					data = (int *)malloc(sizeof(int));	//���¸�dataһ����ַ 
					scanf("%d",data);
					if(EnLQueue(Q, data, sizeof(int)) == TRUE)
						printf("\t\t\t\t\t��ɹ���ʹ%d���\n",*(int *)data);
					else
						printf("\t\t\t\t\t���ʧ��\n"); 
					show(Q);					
				}

				break;
				
			case 2:
				if(Q == NULL)
				{
					printf("\t\t\t\t\t�㻹û�д�������\n"); 
				}
				else
				{
					getchar();//��ջ������� 
					printf("\t\t\t\t\t����������\n\t\t\t\t\t");
					data = (char *)malloc(sizeof(char));	//���¸�dataһ����ַ 
					*(char *)data = getchar();
					if(EnLQueue(Q, data, sizeof(char)) == TRUE)
						printf("\t\t\t\t\t��ɹ���ʹ%c���\n",*(char *)data);
					else
						printf("\t\t\t\t\t���ʧ��\n"); 
					show(Q);
				}
				break;
			case 3:
				if(Q == NULL)
				{
					printf("\t\t\t\t\t�㻹û�д�������\n"); 
				}
				else
				{
					getchar();//��ջ������� 
					printf("\t\t\t\t\t����������\n\t\t\t\t\t");
					data = (double *)malloc(sizeof(double));	//���¸�dataһ����ַ 
					scanf("%lf",data);
					if(EnLQueue(Q, data, sizeof(double)) == TRUE)
						printf("\t\t\t\t\t��ɹ���ʹ%lf���\n",*(double *)data);
					else
						printf("\t\t\t\t\t���ʧ��\n"); 
					getchar();
					show(Q);
				}
				break;
			case 4:
				Q = CreateQueue();	//�������� 
				InitLQueue(Q);		//��ʼ������ 
				printf("\t\t\t\t\t��ϲ�㴴������\n"); 
				break;
				
			case 5://������  
				if(Q == NULL)
				{
					printf("\t\t\t\t\t�㻹û�д�������\n"); 
				}
				else
				{
					DestoryLQueue(Q);	//���ٶ���
					printf("\t\t\t\t\t��ϲ�����ٳɹ�\n"); 
				}
				break;
				
			case 6:
				if(Q == NULL)
				{
					printf("\t\t\t\t\t�㻹û�д�������\n"); 
				}
				else
				{
					printf("\t\t\t\t\t����Ҫ�������ݳ���\n\t\t\t\t\t");
					scanf("%d",&num);
					while(num)
					{
						DeLQueue(Q);
						num--;
					} 
					getchar();
					show(Q);
				}
				break; 
			case 7:
				if(IsEmptyLQueue(Q) ==TRUE)
					printf("\t\t\t\t\t�˶����ǿյ�\n"); 
				else
				{
					printf("\t\t\t\t\t�˶��зǿյ�\n");
					printf("\t\t\t\t\t���������\n"); 
					printf("\t\t\t\t\t1:��գ�2:�����\n\t\t\t\t\t");
					scanf("%d",&option2);
					if(option2 == 1)
					{
						 ClearLQueue(Q);
						 printf("�����"); 
					}  
				}	 
				break; 
				
			case 8:
				if(Q == NULL)
				{
					printf("\t\t\t\t\t�㻹û�д�������\n"); 
				}
				else
				{
					if(GetHeadLQueue(Q, e) == FALSE)
						printf("error");
				} 
				break;
			default: ;
		}
	printf("\n\n\n\t\t\t\t\t");
	system("pause");
			
	}
	
	return 0;
}
