/*
*writer:weiyuexin
*title:数据结构实验4----二叉树
*data:2020-10-26
*/


#include<iostream>

using namespace std;

#define TElemtype char

typedef struct BiTNode{
    TElemtype data;
    struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree &T)     //先序初始化二叉树
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

void PreOrderTraverse(BiTree T)    //先序遍历
{
    if(T)
    {
        cout<<T->data<<" ";
        PreOrderTraverse(T->lchild);
        PreOrderTraverse(T->rchild);
    }
}

void InOrderTraverse(BiTree T)    //中序遍历
{
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data<<" ";
        InOrderTraverse(T->rchild);
    }
}

void PostOrderTraverse(BiTree T)    //后序遍历
{
    if(T)
    {
        PostOrderTraverse(T->lchild);
        PostOrderTraverse(T->rchild);
        cout<<T->data<<" ";
    }
}

int Depth(BiTree T)    //计算二叉树的深度
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

int NodeCount(BiTree T)    //统计二叉树的结点数
{
    if(T==NULL)
        return 0;
    else
        return NodeCount(T->lchild)+NodeCount(T->rchild)+1;
}

int LeafCount(BiTree T)//统计二叉树的叶子结点数
{
    if(T==NULL) return 0;
    else if(T->lchild==NULL&&T->rchild==NULL)
        return 1+LeafCount(T->lchild)+LeafCount(T->rchild);
    else
    {
        return LeafCount(T->lchild)+LeafCount(T->rchild);
    }
}

int LeafCount1(BiTree T)  //统计度为1的节点
{
    if(T==NULL) return 0;
    else if((T->lchild==NULL && T->rchild!=NULL) || (T->lchild!=NULL && T->rchild==NULL))
        return 1+LeafCount1(T->lchild)+LeafCount1(T->rchild);
    else{
        return LeafCount1(T->lchild)+LeafCount1(T->rchild);
    }
}

int LeafCount2(BiTree T)   //统计度为2的节点
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
    //先序序列： A B C # # D E # G # # F # # #
    BiTree T;
    cout<<"------------数据结构实验四——二叉树的基本操作---------------"<<endl;
    cout<<"初始化二叉树:"<<endl;
    cout<<"请输入二叉树的元素:"<<endl;
    CreateBiTree(T);

    cout<<"先序输出为:"<<endl;
    PreOrderTraverse(T);
    cout<<endl;

    cout<<"中序输出为:"<<endl;
    InOrderTraverse(T);
    cout<<endl;

    cout<<"后序输出为:"<<endl;
    PostOrderTraverse(T);
    cout<<endl;

    cout<<"二叉树的深度为:"<<Depth(T)<<endl;

    cout<<"二叉树的结点个数为:"<<NodeCount(T)<<endl;

    cout<<"二叉树的叶子结点个数为:"<<LeafCount(T)<<endl;

    cout<<"二叉树的度为1的结点个数为:"<<LeafCount1(T)<<endl;

    cout<<"二叉树的度为2的结点个数为:"<<LeafCount2(T)<<endl;

    return 0;
}
