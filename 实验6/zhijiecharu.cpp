/*
*author：weiyuexin 
*date: 2020/12/18
*/ 

#include<iostream>

using namespace std;

#define MAXSIZE 100

typedef int KeyType;    //定义关键字类型为整型
typedef int InfoType;
typedef struct{      //记录类型
    KeyType key;         //关键字项
    InfoType otherinfo;     //其他数据项
}RedType;
typedef struct{
    RedType r[MAXSIZE+1];       //r[0]闲置或用作哨兵单元
    int length;       //顺序表长度
}SqList;

void insertList(SqList &L)
{
    cout<<"请输入元素个数:"<<endl;
    int n;
    cin>>n;
    cout<<"请输入"<<n<<"个元素(以空格隔开):"<<endl;
    for(int i=1;i<=n;i++)
    {
        cin>>L.r[i].key;
    }
    L.length=n;
    cout<<n<<"个元素插入到顺序表成功!"<<endl;
}

void Display(SqList L)
{
    for(int i=1;i<=L.length;i++)
    {
        cout<<L.r[i].key<<" ";
    }
    cout<<endl;
}

void InsertSort(SqList &L)     //直接插入排序
{
    for(int i=2;i<=L.length;++i)
    {
        int j;
        if(L.r[i].key<L.r[i-1].key)
        {
            L.r[0] = L.r[i];     //将待插入的记录暂存到监视哨
            L.r[i] = L.r[i-1];    //r[i-1]后移
            for(j=i-2;L.r[0].key<L.r[j].key;--j)
                L.r[j+1] = L.r[j];
            L.r[j+1] = L.r[0];
        }
    }
}

int main()
{
    cout<<"实验6------直接插入排序"<<endl;
    SqList L;
    insertList(L);
    cout<<"初始化后的顺序表为:"<<endl;
    Display(L);
    InsertSort(L);
    cout<<"直接插入排序后的序列为:"<<endl;
    Display(L);
    return 0;
}
