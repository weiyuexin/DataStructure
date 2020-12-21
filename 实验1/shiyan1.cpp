#include<bits/stdc++.h>

using namespace std;

#define ElemType int
const int Max=9999;

struct sqList{
    ElemType *elem;
    int length;
};

void initList(sqList &L)//申请存储空间 
{
    L.elem=new ElemType[Max];
    if(!L.elem)  
	    exit(OVERFLOW);
    L.length=0;
}

void getList(sqList &L,int n)//初始化顺序表 
{
    for(int i=0;i<n;i++)
    {
        cin>>L.elem[i];
    }
    L.length=n;
}

void getvalue(sqList L,int i,ElemType &e)//取值
{

    if(i<1||i>L.length){
        cout<<"非法输入"<<endl;
    }

    e=L.elem[i-1];
}

int findElem(sqList L,ElemType e)//查找
{
    for(int i=0;i<L.length;i++)
    {
        if(L.elem[i]==e)
            return i+1;
    }
    return 0;
}

void insertElem(sqList &L,int i,ElemType e)//插入数据元素 
{
    if(i<1||(i>L.length+1))
    {
        cout<<"插入位置不正确！"<<endl;
    }
    if(L.length==Max)
    {
        cout<<"插入位置不正确！"<<endl;
    }
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    L.length++;
}

void deleteElem(sqList &L,int i)//删除数据元素 
{
    if(i<1||(i>L.length))
    {
        cout<<"该位置不存在！"<<endl;
    }
    for(int j=i;j<=L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    L.length--;
}

void printlist(sqList L)//输出顺序表 
{
    for(int i=0;i<L.length;i++)
    {
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}

void bingji(sqList x,sqList y,sqList &z)//求两个集合的并集
{
    int cnt=1;
    for(int i=0;i<x.length;i++)
    {
        if(findElem(z,x.elem[i])==0)
        {
            insertElem(z,cnt++,x.elem[i]);
        }
    }
    for(int i=0;i<y.length;i++)
    {
        if(findElem(z,y.elem[i])==0)
        {
            insertElem(z,cnt++,y.elem[i]);
        }
    }
    z.length=cnt-1;
}

void mdlist(sqList x,sqList y,sqList &z)//求两个集合的交集
{
    int cnt=1;
    for(int i=0;i<x.length;i++)
    {
        for(int j=0;j<y.length;j++)
        {
            if((x.elem[i]==y.elem[j])&&findElem(z,x.elem[i])==0)
            {
                insertElem(z,cnt++,x.elem[i]);
            }
        }
    }
    z.length=cnt-1;
}

void chajilist(sqList x,sqList y,sqList &z)//求两个差集
{
    int cnt=1;
    for(int i=0;i<x.length;i++)
    {
        if(findElem(y,x.elem[i])==0&&findElem(z,x.elem[i])==0)
        {
            insertElem(z,cnt++,x.elem[i]);
        }
    }
    z.length=cnt-1;
}

int main()
{
    sqList L;
    int n;
    ElemType value;
    cout<<"请输入元素个数:"<<endl;
    cin>>n;
    initList(L);
    cout<<"请输入数据元素："<<endl;
    getList(L,n);//初始化L并输入数据
    cout<<"该线性表为："<<endl; 
    printlist(L);

    cout<<"请输入查询的位置："<<endl;
    int h;
    cin>>h;
    getvalue(L,h,value);
    cout<<"该顺序表第"<<h<<"个值为："<<value<<endl;

    cout<<"请输入查询的元素："<<endl;
    cin>>h;
    cout<<"该顺序表中值为"<<h<<"的元素是第"<<findElem(L,h)<<"个元素"<<endl;

    cout<<"请输入插入的元素的位置和值："<<endl;
    int a,b;
    cin>>a>>b;
    insertElem(L,a,b);
    cout<<"插入后的顺序表为："<<endl; 
    printlist(L);

    cout<<"请输入删除的元素的位置："<<endl;
    cin>>a;
    deleteElem(L,a);
    cout<<"删除后的顺序表为："<<endl; 
    printlist(L);

    sqList x,y,z,c,d;
    int m;
    cout<<"请分别输入两个集合的元素的个数："<<endl;
    cin>>n>>m;
    initList(x);
    
    cout<<"请依次输入第一个集合的元素："<<endl;
    getList(x,n);
    cout<<"第一个集合为："<<endl; 
    printlist(x);
    initList(y);
    
    cout<<"请依次输入第二个集合的元素："<<endl;
    getList(y,m);
    cout<<"第二个集合为："<<endl; 
    printlist(y);

    initList(z);
    getList(z,0);
    initList(c);
    getList(c,0);
    initList(d);
    getList(d,0);

    bingji(x,y,z);
    cout<<"这两个集合的并集为：";
    printlist(z);//输出并集

    mdlist(x,y,c);
    cout<<"这两个集合的交集为：";
    printlist(c);//输出交集

    chajilist(x,y,d);
    cout<<"这两个集合的差集为：";
    printlist(d);//输出差集
    
    return 0;
}
