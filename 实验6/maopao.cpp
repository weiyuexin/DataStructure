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

void BubbleSort(SqList &L)
{
    int m = L.length-1;
    int flag = 1;      //flag 用来标记某一趟排序是否发生交换

    //while((m>0) && (flag == 1))
    for(int i=0;i<m;i++)
    {
        flag =0;            //flag 置为0本地没有发生交换，则不会发生下一趟排序
        for(int j=0;j<=m-i;j++)
        {
            if(L.r[j].key>L.r[j+1].key)
            {
                flag =1;    //发生交换，flag置为1
                RedType t =L.r[j];    //交换前后两个记录
                L.r[j]=L.r[j+1];
                L.r[j+1]=t;
            }
        }
        if(flag == 0)
            break;
    }
}

int main()
{
    cout<<"实验6------冒泡排序"<<endl;
    SqList L;
    insertList(L);
    cout<<"初始化后的顺序表为:"<<endl;
    Display(L);
    BubbleSort(L);
    cout<<"冒泡排序后的序列为:"<<endl;
    Display(L);
    return 0;
}
