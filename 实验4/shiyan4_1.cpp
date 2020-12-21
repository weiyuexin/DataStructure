/*
*writer:weiyuexin
*title:���ݽṹʵ��4----������
*data:2020-10-26
*/


#include<iostream>

using namespace std;

#define TElemtype char

typedef struct BiTNode{
    TElemtype data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T)     //�����ʼ��������
{
    char ch;
    cin>>ch;
    if(ch=='#')
        T=NULL;
    else
    {
        T=new BiTNode;
        T->data=ch;
        CreateBiTree(T->lchild);
        CreateBiTree(T->rchild);
    }
}

void PreOrderTraverse(BiTree T)    //�������
{
    if(T)
    {
        cout<<T->data<<" ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T)    //�������
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data<<" ";
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T)    //�������
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout<<T->data<<" ";
    }
}

int Depth(BiTree T)    //��������������
{
    int m,n;
    if(T==NULL)
        return 0;
    else
    {
        m=Depth(T->lchild);
        n=Depth(T->rchild);
        if(m>n)
            return (m+1);
        else
            return (n+1);
    }
}

int NodeCount(BiTree T)    //ͳ�ƶ������Ľ����
{
    if(T==NULL)
        return 0;
    else
        return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

int LeafCount(BiTree T)//ͳ�ƶ�������Ҷ�ӽ����
{
    if(T==NULL) return 0;
    else if(T->lchild==NULL&&T->rchild==NULL)
        return 1+LeafCount(T->lchild)+LeafCount(T->rchild);
    else
    {
        return LeafCount(T->lchild)+LeafCount(T->rchild);
    }
}

int LeafCount1(BiTree T)  //ͳ�ƶ�Ϊ1�Ľڵ�
{
    if(T==NULL) return 0;
    else if((T->lchild==NULL && T->rchild!=NULL) || (T->lchild!=NULL && T->rchild==NULL))
        return 1+LeafCount1(T->lchild)+LeafCount1(T->rchild);
    else{
        return LeafCount1(T->lchild)+LeafCount1(T->rchild);
    }
}

int LeafCount2(BiTree T)   //ͳ�ƶ�Ϊ2�Ľڵ�
{
    if(T==NULL) return 0;
    else if(T->lchild!=NULL && T->rchild!=NULL)
        return 1+LeafCount2(T->lchild)+LeafCount2(T->rchild);
    else{
        return LeafCount2(T->lchild)+LeafCount2(T->rchild);
    }
}

int main()
{
    //�������У� A B C # # D E # G # # F # # #
    BiTree T;
    cout<<"------------���ݽṹʵ���ġ����������Ļ�������---------------"<<endl;
    cout<<"��ʼ��������:"<<endl;
    cout<<"�������������Ԫ��:"<<endl;
    CreateBiTree(T);

    cout<<"�������Ϊ:"<<endl;
    PreOrderTraverse(T);
    cout<<endl;

    cout<<"�������Ϊ:"<<endl;
    InOrderTraverse(T);
    cout<<endl;

    cout<<"�������Ϊ:"<<endl;
    PostOrderTraverse(T);
    cout<<endl;

    cout<<"�����������Ϊ:"<<Depth(T)<<endl;

    cout<<"�������Ľ�����Ϊ:"<<NodeCount(T)<<endl;

    cout<<"��������Ҷ�ӽ�����Ϊ:"<<LeafCount(T)<<endl;

    cout<<"�������Ķ�Ϊ1�Ľ�����Ϊ:"<<LeafCount1(T)<<endl;

    cout<<"�������Ķ�Ϊ2�Ľ�����Ϊ:"<<LeafCount2(T)<<endl;

    return 0;
}
