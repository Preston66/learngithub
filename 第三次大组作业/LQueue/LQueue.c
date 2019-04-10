#include "LQueue.h"

/**
 *  @name        : LQueue *CreateQueue(void)
 *  @description : �������� 
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
 *  @description : ��ʼ������ 
 *  @param       :  Q����ͷ�� 
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
 *  @description : ���ٶ��� 
 *  @param       :  Q����ͷ�� 
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
 *  @description : �ж϶���Ϊ�� 
 *  @param       :  Q����ͷ�� 
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
 *  @description : ȡ��ͷ���� 
 *  @param       :  Q����ͷ����e(����) 
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
			case 4: printf("\t\t\t\t\t��ͷ��| %d |",(*(int *)Q->front->data));    break;
			case 1: printf("\t\t\t\t\t��ͷ��| %c |",(*(char *)Q->front->data));   break;
			case 8: printf("\t\t\t\t\t��ͷ��| %lf |",(*(double *)Q->front->data)); break;
		}
		return TRUE;			
	} 

	
}

int LengthLQueue(LQueue *Q)
{
	
}

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data, int sizes)
 *  @description : ��� 
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
 *  @description : ���� 
 *  @param       :  Q����ͷ��
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
 *  @description : ��ն��� 
 *  @param       :  Q����ͷ��
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
 *  @description : �������� 
 *  @param       :  Q����ͷ��
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
