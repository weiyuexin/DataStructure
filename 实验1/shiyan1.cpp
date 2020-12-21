#include<bits/stdc++.h>

using namespace std;

#define ElemType int
const int Max=9999;

struct sqList{
    ElemType *elem;
    int length;
};

void initList(sqList &L)//����洢�ռ� 
{
    L.elem=new ElemType[Max];
    if(!L.elem)  
	    exit(OVERFLOW);
    L.length=0;
}

void getList(sqList &L,int n)//��ʼ��˳��� 
{
    for(int i=0;i<n;i++)
    {
        cin>>L.elem[i];
    }
    L.length=n;
}

void getvalue(sqList L,int i,ElemType &e)//ȡֵ
{

    if(i<1||i>L.length){
        cout<<"�Ƿ�����"<<endl;
    }

    e=L.elem[i-1];
}

int findElem(sqList L,ElemType e)//����
{
    for(int i=0;i<L.length;i++)
    {
        if(L.elem[i]==e)
            return i+1;
    }
    return 0;
}

void insertElem(sqList &L,int i,ElemType e)//��������Ԫ�� 
{
    if(i<1||(i>L.length+1))
    {
        cout<<"����λ�ò���ȷ��"<<endl;
    }
    if(L.length==Max)
    {
        cout<<"����λ�ò���ȷ��"<<endl;
    }
    for(int j=L.length-1;j>=i-1;j--)
    {
        L.elem[j+1]=L.elem[j];
    }
    L.elem[i-1]=e;
    L.length++;
}

void deleteElem(sqList &L,int i)//ɾ������Ԫ�� 
{
    if(i<1||(i>L.length))
    {
        cout<<"��λ�ò����ڣ�"<<endl;
    }
    for(int j=i;j<=L.length-1;j++)
    {
        L.elem[j-1]=L.elem[j];
    }
    L.length--;
}

void printlist(sqList L)//���˳��� 
{
    for(int i=0;i<L.length;i++)
    {
        cout<<L.elem[i]<<" ";
    }
    cout<<endl;
}

void bingji(sqList x,sqList y,sqList &z)//���������ϵĲ���
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

void mdlist(sqList x,sqList y,sqList &z)//���������ϵĽ���
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

void chajilist(sqList x,sqList y,sqList &z)//�������
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
    cout<<"������Ԫ�ظ���:"<<endl;
    cin>>n;
    initList(L);
    cout<<"����������Ԫ�أ�"<<endl;
    getList(L,n);//��ʼ��L����������
    cout<<"�����Ա�Ϊ��"<<endl; 
    printlist(L);

    cout<<"�������ѯ��λ�ã�"<<endl;
    int h;
    cin>>h;
    getvalue(L,h,value);
    cout<<"��˳����"<<h<<"��ֵΪ��"<<value<<endl;

    cout<<"�������ѯ��Ԫ�أ�"<<endl;
    cin>>h;
    cout<<"��˳�����ֵΪ"<<h<<"��Ԫ���ǵ�"<<findElem(L,h)<<"��Ԫ��"<<endl;

    cout<<"����������Ԫ�ص�λ�ú�ֵ��"<<endl;
    int a,b;
    cin>>a>>b;
    insertElem(L,a,b);
    cout<<"������˳���Ϊ��"<<endl; 
    printlist(L);

    cout<<"������ɾ����Ԫ�ص�λ�ã�"<<endl;
    cin>>a;
    deleteElem(L,a);
    cout<<"ɾ�����˳���Ϊ��"<<endl; 
    printlist(L);

    sqList x,y,z,c,d;
    int m;
    cout<<"��ֱ������������ϵ�Ԫ�صĸ�����"<<endl;
    cin>>n>>m;
    initList(x);
    
    cout<<"�����������һ�����ϵ�Ԫ�أ�"<<endl;
    getList(x,n);
    cout<<"��һ������Ϊ��"<<endl; 
    printlist(x);
    initList(y);
    
    cout<<"����������ڶ������ϵ�Ԫ�أ�"<<endl;
    getList(y,m);
    cout<<"�ڶ�������Ϊ��"<<endl; 
    printlist(y);

    initList(z);
    getList(z,0);
    initList(c);
    getList(c,0);
    initList(d);
    getList(d,0);

    bingji(x,y,z);
    cout<<"���������ϵĲ���Ϊ��";
    printlist(z);//�������

    mdlist(x,y,c);
    cout<<"���������ϵĽ���Ϊ��";
    printlist(c);//�������

    chajilist(x,y,d);
    cout<<"���������ϵĲΪ��";
    printlist(d);//����
    
    return 0;
}
