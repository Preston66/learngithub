#include "LQueue.h"

/**
 *  @name        : LQueue *CreateQueue(void)
 *  @description : 创建队列 
 *  @param       : None 
 * 	@return		 : LQueue *
 *  @notice      : None
 */
LQueue *CreateQueue(void)
{
	LQueue *Q;
	Q = (LQueue *)malloc(sizeof(LQueue));
	return Q; 
} 

/**
 *  @name        : void InitLQueue(LQueue *Q)
 *  @description : 初始化队列 
 *  @param       :  Q（队头） 
 * 	@return		 : unsigned int
 *  @notice      : None
 */
void InitLQueue(LQueue *Q)
{
	Node *r;
	r = (Node *)malloc(sizeof(Node));
	r->data = NULL;
	r->next = NULL;
	Q->front = r;
	Q->rear = r; 
}

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *  @description : 销毁队列 
 *  @param       :  Q（队头） 
 * 	@return		 : None
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q)
{
	while(Q->front != NULL)
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *  @description : 判断队列为空 
 *  @param       :  Q（队头） 
 * 	@return		 : Status 
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->front == Q->rear)
		return TRUE;
	else
		return FALSE;
}

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *  @description : 取队头数据 
 *  @param       :  Q（队头），e(数据) 
 * 	@return		 : Status 
 *  @notice      : None
 */
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->front == NULL)
		return FALSE;
	else
	{
		switch(Q->front->length)
		{			
			case 4: printf("\t\t\t\t\t队头是| %d |",(*(int *)Q->front->data));    break;
			case 1: printf("\t\t\t\t\t队头是| %c |",(*(char *)Q->front->data));   break;
			case 8: printf("\t\t\t\t\t队头是| %lf |",(*(double *)Q->front->data)); break;
		}
		return TRUE;			
	} 

	
}

int LengthLQueue(LQueue *Q)
{
	
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data, int sizes)
 *  @description : 入队 
 *  @param         
 *  @return      : 
 *  @notice      : 
 */
Status EnLQueue(LQueue *Q, void *data, int sizes)
{
	Node *r;
	LQueue *LQ;
	r = (Node *)malloc(sizeof(Node));
	LQ = Q;
	if(r == NULL) return FALSE;
	
	r->data = data;
	r->next = NULL;
	r->length = sizes;
	if(LQ->front->data == NULL)
	{
		LQ->front = r;
	}
	LQ->rear->next = r;
	LQ->rear = r;
	return  TRUE;
}

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *  @description : 出队 
 *  @param       :  Q（队头）
 * 	@return		 : Status 
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q)
{
	Node *f;
	if(Q->front == Q->rear )
		return FALSE;
	f = Q->front;
	Q->front = f->next;
	free(f);
	return TRUE;
}

/**
 *  @name        : void ClearLQueue(LQueue *Q)
 *  @description : 清空队列 
 *  @param       :  Q（队头）
 * 	@return		 : None 
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q)
{
	Node *f;
	while(Q->rear != Q->front)
	{
		f = Q->front;
		Q->front = f->next;
		free(f);
	}
	InitLQueue(Q); 
}

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *  @description : 遍历队列 
 *  @param       :  Q（队头）
 * 	@return		 : Status 
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	Node *f;
	f = Q->front;
	while(f != NULL)
	{
		switch(f->length)
		{
			case 2: (*foo)((int *)f->data);    break;
			case 4: (*foo)((char *)f->data);   break;
			case 8: (*foo)((double *)f->data); break;
		}
		f = f->next;
	}
}

void LPrint(void *q)
{
	
}
