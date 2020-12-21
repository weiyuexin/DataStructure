/*
*title: 循环队列的基本操作
*writer:weiyuexin
*data:2020-10-11
*/

#include<iostream>

using namespace std;

#define MAXSIZE 100
#define QElemType int

typedef struct{
    QElemType *base;     //存储空间基地址
    int front;    //头指针
    int rear;     //尾指针
}SqQueue;

void InitQueue(SqQueue &Q){        //初始化循环队列
    Q.base = new QElemType[MAXSIZE];
    if(!Q.base){
        cout<<"队列初始化失败!"<<endl;
        return;
    }
    Q.front = Q.rear = 0;
    for(int i=0;i<MAXSIZE;i++)
    {
        Q.base[i]=NULL;
    }
    cout<<"循环队列初始化成功!"<<endl;
}

void EnQueue(SqQueue &Q,QElemType e){    //入队
    if((Q.rear + 1)%MAXSIZE == Q.front){
        cout<<"该队列已满无法插入!"<<endl;
        return;
    }
    Q.base[Q.rear] = e;    //新元素插入对尾
    Q.rear = (Q.rear + 1)%MAXSIZE;      //队尾指针加一
}

QElemType DeQueue(SqQueue &Q,QElemType &ee){
    if(Q.front == Q.rear){
        cout<<"该循环队列已空!"<<endl;
        return 0;
    }
    ee = Q.base[Q.front];   //保存队首指针
    Q.front = (Q.front + 1)%MAXSIZE;    //队首指针加一
    return ee;
}

void Display(SqQueue Q){     //打印循环队列
    cout<<"该循环队列为: "<<endl;
    cout<<"队首=>";
    for(int i=Q.front;Q.base[i]!=NULL;i++){
        if(!Q.base[i]){
            break;
        }
        cout<<Q.base[i]<<" ";
    }
    cout<<"<=队尾"<<endl;
}

QElemType GetHead(SqQueue Q){   //求队首元素
    if(Q.front != Q.rear){   //队列非空
        return Q.base[Q.front];
    }else{
        cout<<"队列中没有元素!"<<endl;
        return 0;
    }
}

int QueueLength(SqQueue Q){   //求队列的长度
    return (Q.rear - Q.front +MAXSIZE)%MAXSIZE;
}


int main(){
    SqQueue Q;
    cout<<"实验3_3---------------------循环队列的基本操作"<<endl<<endl;
    cout<<"请输入对应数字选择您想要的操作:"<<endl;
    cout<<"1----------------建立循环队列"<<endl;
    cout<<"2----------------入队"<<endl;
    cout<<"3----------------出队"<<endl;
    cout<<"4----------------取队头元素"<<endl;
    cout<<"5----------------打印循环队列"<<endl;
    cout<<"6----------------求队列长度"<<endl;
    cout<<"0----------------结束程序"<<endl;

    int operation;
    while(cin>>operation){
        switch(operation){
        case 0 :
            cout<<"程序运行结束!"<<endl;
            return 0;
            break;
        case 1 :
            InitQueue(Q);   //初始化队列
            cout<<"请输入对应数字选择您想要的操作:"<<endl;
            break;
        case 2 :
            int e;
            cout<<"请输入想要入队的元素，以-1为截止符:"<<endl;
            while(cin>>e){
                if(e == -1){
                    break;
                }
                EnQueue(Q,e);
            }
            cout<<"入队成功!"<<endl;
            Display(Q);
            cout<<"请输入对应数字选择您想要的操作:"<<endl;
            break;
        case 3 :
            cout<<"请输入想要出队的元素个数:"<<endl;
            int n;
            cin>>n;
            cout<<"出队的元素依次为: ";
            for(int i=0;i<n;i++){
                QElemType ee;
                cout<<DeQueue(Q,ee)<<" ";
            }
            cout<<endl;
            Display(Q);
            cout<<"请输入对应数字选择您想要的操作:"<<endl;
            break;
        case 4 :
            cout<<"队首元素为:"<<GetHead(Q)<<endl;
            cout<<"请输入对应数字选择您想要的操作:"<<endl;
            break;
        case 5 :
            Display(Q);
            cout<<"请输入对应数字选择您想要的操作:"<<endl;
            break;
        case 6 :
            cout<<"该循环链表的长度为:"<<QueueLength(Q)<<endl;    //求队列长度
            cout<<"请输入对应数字选择您想要的操作:"<<endl;
            break;
        default :
            cout<<"您选择的操作不存在，请重新选择:"<<endl;
            break;
        }
    }
    return 0;
}
