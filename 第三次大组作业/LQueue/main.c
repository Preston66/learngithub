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

/*引导界面显示*/
void LeadInterface(void)
{
	system("cls");
	printf("\n\n\n\t\t\t\t\t_________________________________\n");
	printf("\t\t\t\t\t|      请输入所需操作序号       |\n");
	printf("\t\t\t\t\t|  1.输入整型数据               |\n");
	printf("\t\t\t\t\t|  2.输入字符型数据             |\n");
	printf("\t\t\t\t\t|  3.输入浮点型数据             |\n");
	printf("\t\t\t\t\t|  4.创建并初始化队列           |\n");
	printf("\t\t\t\t\t|  5.销毁队列                   |\n");
	printf("\t\t\t\t\t|  6.出队                       |\n");
	printf("\t\t\t\t\t|  7.判断是否为空，并清空队列   |\n");
	printf("\t\t\t\t\t|  8.取队头的数据               |\n");	
	printf("\t\t\t\t\t|  0.退出                       |\n");
	printf("\t\t\t\t\t|_______________________________|\n");
}

int main(void)
{
	int option1, option2;
	Status sta;
	
	void *data,*e; //数据类型 
	
	LQueue *Q;
	int size,num;
	printf("\n\n\n\t\t\t\t\t欢迎来到我的程序\n\n");
	
	system("pause");
	while(1)
	{
		LeadInterface();	//引导界面显示 
		printf("\n\n\t\t\t\t\t请输入你的选择:");		
		scanf("%d",&option1);
		
		switch(option1)
		{
			
			case 0:
				exit(0);
			case 1:
				if(Q == NULL)
				{
					printf("\t\t\t\t\t你还没有创建队列\n"); 
				}
				else
				{
					getchar();//清空缓存数据 
					printf("\t\t\t\t\t请输入数据\n\t\t\t\t\t");
					data = (int *)malloc(sizeof(int));	//重新给data一个地址 
					scanf("%d",data);
					if(EnLQueue(Q, data, sizeof(int)) == TRUE)
						printf("\t\t\t\t\t你成功地使%d入队\n",*(int *)data);
					else
						printf("\t\t\t\t\t入队失败\n"); 
					show(Q);					
				}

				break;
				
			case 2:
				if(Q == NULL)
				{
					printf("\t\t\t\t\t你还没有创建队列\n"); 
				}
				else
				{
					getchar();//清空缓存数据 
					printf("\t\t\t\t\t请输入数据\n\t\t\t\t\t");
					data = (char *)malloc(sizeof(char));	//重新给data一个地址 
					*(char *)data = getchar();
					if(EnLQueue(Q, data, sizeof(char)) == TRUE)
						printf("\t\t\t\t\t你成功地使%c入队\n",*(char *)data);
					else
						printf("\t\t\t\t\t入队失败\n"); 
					show(Q);
				}
				break;
			case 3:
				if(Q == NULL)
				{
					printf("\t\t\t\t\t你还没有创建队列\n"); 
				}
				else
				{
					getchar();//清空缓存数据 
					printf("\t\t\t\t\t请输入数据\n\t\t\t\t\t");
					data = (double *)malloc(sizeof(double));	//重新给data一个地址 
					scanf("%lf",data);
					if(EnLQueue(Q, data, sizeof(double)) == TRUE)
						printf("\t\t\t\t\t你成功地使%lf入队\n",*(double *)data);
					else
						printf("\t\t\t\t\t入队失败\n"); 
					getchar();
					show(Q);
				}
				break;
			case 4:
				Q = CreateQueue();	//创建队列 
				InitLQueue(Q);		//初始化队列 
				printf("\t\t\t\t\t恭喜你创建好了\n"); 
				break;
				
			case 5://有问题  
				if(Q == NULL)
				{
					printf("\t\t\t\t\t你还没有创建队列\n"); 
				}
				else
				{
					DestoryLQueue(Q);	//销毁队列
					printf("\t\t\t\t\t恭喜你销毁成功\n"); 
				}
				break;
				
			case 6:
				if(Q == NULL)
				{
					printf("\t\t\t\t\t你还没有创建队列\n"); 
				}
				else
				{
					printf("\t\t\t\t\t你想要几个数据出队\n\t\t\t\t\t");
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
					printf("\t\t\t\t\t此队列是空的\n"); 
				else
				{
					printf("\t\t\t\t\t此队列非空的\n");
					printf("\t\t\t\t\t你想清空吗？\n"); 
					printf("\t\t\t\t\t1:清空；2:不清空\n\t\t\t\t\t");
					scanf("%d",&option2);
					if(option2 == 1)
					{
						 ClearLQueue(Q);
						 printf("已清空"); 
					}  
				}	 
				break; 
				
			case 8:
				if(Q == NULL)
				{
					printf("\t\t\t\t\t你还没有创建队列\n"); 
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
