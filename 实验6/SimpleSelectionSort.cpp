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

void SelectSort(SqList &L)     //简单选择排序
{
    for(int i=1;i<L.length;++i)
    {
        int k=i;
        for(int j=i+1;j<=L.length;++j)
        {
            if(L.r[j].key<L.r[k].key)
            {
                k=j;           //k指向此趟排序中关键字最小的记录
            }
        }
        if(k!=i)
        {
            RedType t=L.r[i];
            L.r[i]=L.r[k];
            L.r[k]=t;
        }
    }
}

int main()
{
    cout<<"实验6------简单选择排序"<<endl;
    SqList L;
    insertList(L);
    cout<<"初始化后的顺序表为:"<<endl;
    Display(L);
    SelectSort(L);
    cout<<"简单选择排序后的序列为:"<<endl;
    Display(L);
    return 0;
}
