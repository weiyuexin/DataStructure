#include<iostream>

using namespace std;

#define KeyType int
#define InfoType int

typedef struct{
    KeyType key;   //关键字
    InfoType otherinfo;   //其他数据项
}ElemType;

typedef struct BSTNode{
    ElemType data;        //每个节点的数据域包括关键字项和其他数据项
    struct BSTNode *lchild,*rchild;    //左右孩子
}BSTNode,*BSTree;

void InsertBST(BSTree &T,ElemType e)     //二叉排序树的插入
{
    //当二叉排序树T中不存在关键字e.key的数据元素时，则插入该元素
    if(!T)
    {         //找到插入位置，递归结束
        BSTNode* S = new BSTNode;   //生成新节点*S
        S->data = e;     //新节点的数据域置为e
        S->lchild = S->rchild =NULL;    //新节点作为叶子节点
        T=S;     //把新节点*S链接到已找到的插入位置
    }else if(e.key<T->data.key)
    {
        InsertBST(T->lchild,e);     //将*S插入到左子树
    }else{
        InsertBST(T->rchild,e);    //将*S插入到右子树
    }
}

void CreateBST(BSTree &T)      //创建二叉排序树
{
    //依次读入一个关机字为key的节点，将此节点插入二叉排序树中
    T=NULL;    //二叉排序树初始化为空
    ElemType e;

    cout<<"请输入二叉树元素(-1结束):"<<endl;
    cin>>e.key;
    while(e.key!=-1)
    {
        InsertBST(T,e);
        cin>>e.key;
    }
    cout<<"二叉排序树创建成功!"<<endl;
}

BSTree SearchBST(BSTree T,KeyType key,int &num)    //二叉排序树的递归查找
{
    num++;
    if((!T) || key==T->data.key)
        return T;
    else if(key<T->data.key)
        return SearchBST(T->lchild,key,num);
    else
        return SearchBST(T->rchild,key,num);
}

void InOrderTraverse(BSTree T){    //中序遍历二叉树
    if(T)
    {
        InOrderTraverse(T->lchild);
        cout<<T->data.key<<" ";
        InOrderTraverse(T->rchild);
    }
}

int main()
{
    cout<<"实验六-------------------二叉排序树"<<endl;
    BSTree T;
    CreateBST(T);        //创建二叉排序树
    cout<<"初始化后的二叉排序树的中序遍历序列为:"<<endl;
    InOrderTraverse(T);   //中序遍历二叉排序树
    cout<<endl;
    cout<<"请输入要查找的关键字；"<<endl;
    KeyType key;   //要查找的关键字
    while(cin>>key){
        int num=0;    //查找次数
        if(SearchBST(T,key,num) == NULL)
        {
            cout<<"二叉排序树中不存在该元素!"<<endl;
            cout<<"共查找了"<<num<<"次"<<endl;
        }else{
            cout<<"查找成功！"<<endl;
            cout<<"共查找了"<<num<<"次"<<endl;
        }
        cout<<"请输入要查找的关键字；"<<endl;
    }
    return 0;
}
