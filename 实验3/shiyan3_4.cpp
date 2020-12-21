/*
*title:链队的基本操作
*writer:weiyuexin
*data:2020-10-11
*/

#include<iostream>

using namespace std;

#define QElemType int

typedef struct QNode{
    QElemType data;
    struct QNode *next;
}QNode,*QueuePtr;

typedef struct{
    QueuePtr front;     //队头指针
    QueuePtr rear;     //队尾指针
}LinkQueue;

void InitQueue(LinkQueue &Q){     //初始化链队
    Q.front = Q.rear = new QNode;        //生成新结点作为头结点，队头和队尾指针指向此节点
    Q.front->next = NULL;     //头结点的指针域置空
    cout<<"链队初始化成功!"<<endl;
}

void EnQueue(LinkQueue &Q,QElemType e){     //入队
    QNode *p = new QNode();
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

QElemType DeQueue(LinkQueue &Q){      //出队
    if(Q.front == Q.rear){
        cout<<"该链队已空!"<<endl;
         return 0;
    }
    QElemType e;
    QNode *p = new QNode();
    p = Q.front->next;
    e = p->data;
    Q.front->next = p->next;
    if(Q.rear == p){
        Q.rear = Q.front;
    }
    delete p;
    return e;
}

QElemType GetHead(LinkQueue Q){        //取队首值
    if(Q.front != Q.rear){     //队列非空
        return Q.front->next->data;     //返回队首值
    }else{
       cout<<"该链队为空！"<<endl;
       return 0;
    }
}

void Display(LinkQueue Q){      //打印链队元素
    QNode *p = new QNode();
    p = Q.front->next;
    cout<<"该链队为: 队首=> ";
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"<=队尾"<<endl;
}

int main(){
    LinkQueue Q;
    cout<<"实验3_4---------------------链队列的基本操作"<<endl<<endl;
    cout<<"请输入对应数字选择您想要的操作:"<<endl;
    cout<<"1----------------建立链队列"<<endl;
    cout<<"2----------------入队"<<endl;
    cout<<"3----------------出队"<<endl;
    cout<<"4----------------取队头元素"<<endl;
    cout<<"5----------------打印链队列"<<endl;
    cout<<"0----------------结束程序"<<endl;
    int operation;
    cout<<"请输入对应的数字选择你想要进行的操作:"<<endl;
    while(cin>>operation){
        switch(operation){
        case 0 :
            cout<<"程序运行结束!"<<endl;
            return 0;
        case 1 :
            InitQueue(Q);
            cout<<"请输入对应的数字选择您想要进行的操作:"<<endl;
            break;
        case 2 :
            cout<<"请输入要入队的元素个数；"<<endl;
            int n;
            cin>>n;
            cout<<"请输入要入队的元素:"<<endl;
            for(int i=0;i<n;i++){
                QElemType e;
                cin>>e;
                EnQueue(Q,e);
            }
            cout<<n<<"个元素入队成功!"<<endl;
            Display(Q);
            cout<<"请输入对应的数字选择您想要进行的操作:"<<endl;
            break;
        case 3 :
            cout<<"请输入要出栈的元素的个数:"<<endl;
            int m;
            cin>>m;
            cout<<"出栈的元素依次为: ";
            for(int i=0;i<m;i++){
                cout<<DeQueue(Q)<<" ";
            }
            cout<<endl;
            Display(Q);
            cout<<"请输入对应的数字选择您想要进行的操作:"<<endl;
            break;
        case 4 :
            cout<<"该链队队首值为: "<<GetHead(Q)<<endl;
            cout<<"请输入对应的数字选择您想要进行的操作:"<<endl;
            break;
        case 5 :
            Display(Q);
            cout<<"请输入对应的数字选择您想要进行的操作:"<<endl;
            break;
        default :
            cout<<"您选择的操作不存在，请重新选择:"<<endl;
            break;
        }
    }
    return 0;
}
