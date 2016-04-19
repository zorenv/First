#ifndef _Hash_H_
#define _Hash_H_

#include <iostream>
#include <stdlib.h>
#include <memory.h>
#include <math.h>
using namespace std;

#define MAX_NUMBER 100
typedef int valuetype;

typedef struct myhash
{
    valuetype value;
    myhash *next;
}myHash, *pmyHash;
myHash myHashList[MAX_NUMBER];

FILE *fp;
int length = 0, k, target; //length为输入的数据个数,k为hash表长度,target为欲查找的数字
int  number[MAX_NUMBER];

void InputNumber();
void ShowNumber();
void makeHashList();
int FindNumber();
void Result();
int FindPrime();
int IsPrime(int i);
void Insert( pmyHash tmp, valuetype value,int key );


void InputNumber()
{
    for( int i = 0; i < MAX_NUMBER; i++ )
    {
        myHashList[i].value = 0;
    }
    int m;
    do
    {
        fscanf( fp, "%d", &m );
        number[length] = m;
        length++;
    }while( m != -1 );
    length--;
    printf("The number of inputs is %d,\nthe numbers are:\n", length);
}

void ShowNumber()
{
    for( int i = 0; i < length; i++ )
    {
        printf("%d\t", number[i]);
    }
    printf("\n");
}

void makeHashList()
{
    k = FindPrime(); //将不大于length的最大质数做为hash表的长度
    printf("The length of hash list is %d.\n", k);
    for( int i = 0; i < length; i++ )
    {
        int key = number[i] % k;
        //printf("aaa %d\n", number[i]);
        Insert( &myHashList[key], number[i],key );
    }
}

void Insert( pmyHash tmp, valuetype value, int key )
{
    pmyHash p, q;
    q = tmp;
    p = (myHash *)malloc(sizeof(myHash));
    while( q->next )
    {
        //printf("    %d\n", value);
        q = q->next;
    }
    p->value = value;
    //printf("%d\n", p->value);
    p->next = q->next;
    q->next = p;
    //printf("bbb %d\n", myHashList[2].value);
    tmp = q;
    myHashList[key].value = tmp->next->value;
    //printf("ccc %d\n",  tmp->next->value);
    //printf("%d\n", p->value);
}

int FindNumber()
{
    fscanf( fp, "%d", &target );
    printf("The target number  is %d.\n", target);
    int key = target % k;
    pmyHash tmp = (myHash *)malloc(sizeof(myHash));

 /*   for( int i = 0; i <= k; i++ )
    {
        tmp = &myHashList[i];
        while( tmp->next )
        {
            printf("%d\t", tmp->value);
            tmp = tmp->next;
        }
        printf("\n");
    }
*/
    tmp = &myHashList[key];
    while( tmp->next )
    {
        if( target == tmp->value )
        {
            //printf("%d\n", tmp->value);
            return 1;
        }
        tmp = tmp->next;
    }
    return 0;
}

void Result()
{
    int flag = FindNumber();
    if( flag )
    {
        printf("Find the target number %d!\n", target);
    }
    else
    {
        printf("Don't find the target number %d!\n", target);
    }
}

int FindPrime()
{
    for( int i = length; i > 0; i-- )
    {
        if( IsPrime(i) )
        {
            return i;
        }
    }
    return 0;
}

int IsPrime(int i)
{
    for( int j = 2; j <= sqrt(i) + 1; j++ )
    {
        if( i % j == 0)
            return 0;
    }
    return 1;
}

#endif // _Hash_H_
