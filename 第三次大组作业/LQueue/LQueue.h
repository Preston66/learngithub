/***************************************************************************************
 *	File Name				:	linkedList.h
 *	CopyRight				:	2019 QG Studio  
 *	SYSTEM					:   win10
 *	Create Data				:	2019.3.20
 *	Author/Corportation		:	Preston
 *
 *
 *--------------------------------Revision History--------------------------------------
 *	No	version		Data			Revised By			Item			Description
 *
 *
 ***************************************************************************************/

 /**************************************************************
*	Multi-Include-Prevent Section
**************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

/**************************************************************
*	Macro Define Section
**************************************************************/


/**************************************************************
*	Struct Define Section
**************************************************************/
//队列结构体 
typedef struct node
{
    void *data;                   //泛型数据 
    struct node *next;            //指向下一个指针 
    int length;                   //字长 
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头指针 
    Node *rear;                    //队尾指针 

} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#include <stdlib.h>
#include <stdio.h>

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/
LQueue *CreateQueue(void);

void InitLQueue(LQueue *Q);

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 閿�姣侀槦鍒�
 *    @param         Q 闃熷垪鎸囬拡Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue *Q);

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 妫�鏌ラ槦鍒楁槸鍚︿负绌�
 *    @param         Q 闃熷垪鎸囬拡Q
 *    @return         : 绌�-TRUE; 鏈┖-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue *Q);

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 鏌ョ湅闃熷ご鍏冪礌
 *    @param         Q e 闃熷垪鎸囬拡Q,杩斿洖鏁版嵁鎸囬拡e
 *    @return         : 鎴愬姛-TRUE; 澶辫触-FALSE
 *  @notice      : 闃熷垪鏄惁绌�
 */
Status GetHeadLQueue(LQueue *Q, void *e);

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 纭畾闃熷垪闀垮害
 *    @param         Q 闃熷垪鎸囬拡Q
 *    @return         : 鎴愬姛-TRUE; 澶辫触-FALSE
 *  @notice      : None
 */
int LengthLQueue(LQueue *Q);


Status EnLQueue(LQueue *Q, void *data, int sizes);

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 鍑洪槦鎿嶄綔
 *    @param         Q 闃熷垪鎸囬拡Q
 *    @return         : 鎴愬姛-TRUE; 澶辫触-FALSE
 *  @notice      : None
 */
Status DeLQueue(LQueue *Q);

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 娓呯┖闃熷垪
 *    @param         Q 闃熷垪鎸囬拡Q
 *  @notice      : None
 */
void ClearLQueue(LQueue *Q);

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 閬嶅巻鍑芥暟鎿嶄綔
 *    @param         Q 闃熷垪鎸囬拡Q锛屾搷浣滃嚱鏁版寚閽坒oo
 *    @return         : None
 *  @notice      : None
 */
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q));

/**
 *  @name        : void LPrint(void *q)
 *    @description : 鎿嶄綔鍑芥暟
 *    @param         q 鎸囬拡q
 
 *  @notice      : None
 */
void LPrint(void *q);

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED

