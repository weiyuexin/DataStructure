/*
*title: ѭ�����еĻ�������
*writer:weiyuexin
*data:2020-10-11
*/

#include<iostream>

using namespace std;

#define MAXSIZE 100
#define QElemType int

typedef struct{
    QElemType *base;     //�洢�ռ����ַ
    int front;    //ͷָ��
    int rear;     //βָ��
}SqQueue;

void InitQueue(SqQueue &Q){        //��ʼ��ѭ������
    Q.base = new QElemType[MAXSIZE];
    if(!Q.base){
        cout<<"���г�ʼ��ʧ��!"<<endl;
        return;
    }
    Q.front = Q.rear = 0;
    for(int i=0;i<MAXSIZE;i++)
    {
        Q.base[i]=NULL;
    }
    cout<<"ѭ�����г�ʼ���ɹ�!"<<endl;
}

void EnQueue(SqQueue &Q,QElemType e){    //���
    if((Q.rear + 1)%MAXSIZE == Q.front){
        cout<<"�ö��������޷�����!"<<endl;
        return;
    }
    Q.base[Q.rear] = e;    //��Ԫ�ز����β
    Q.rear = (Q.rear + 1)%MAXSIZE;      //��βָ���һ
}

QElemType DeQueue(SqQueue &Q,QElemType &ee){
    if(Q.front == Q.rear){
        cout<<"��ѭ�������ѿ�!"<<endl;
        return 0;
    }
    ee = Q.base[Q.front];   //�������ָ��
    Q.front = (Q.front + 1)%MAXSIZE;    //����ָ���һ
    return ee;
}

void Display(SqQueue Q){     //��ӡѭ������
    cout<<"��ѭ������Ϊ: "<<endl;
    cout<<"����=>";
    for(int i=Q.front;Q.base[i]!=NULL;i++){
        if(!Q.base[i]){
            break;
        }
        cout<<Q.base[i]<<" ";
    }
    cout<<"<=��β"<<endl;
}

QElemType GetHead(SqQueue Q){   //�����Ԫ��
    if(Q.front != Q.rear){   //���зǿ�
        return Q.base[Q.front];
    }else{
        cout<<"������û��Ԫ��!"<<endl;
        return 0;
    }
}

int QueueLength(SqQueue Q){   //����еĳ���
    return (Q.rear - Q.front +MAXSIZE)%MAXSIZE;
}


int main(){
    SqQueue Q;
    cout<<"ʵ��3_3---------------------ѭ�����еĻ�������"<<endl<<endl;
    cout<<"�������Ӧ����ѡ������Ҫ�Ĳ���:"<<endl;
    cout<<"1----------------����ѭ������"<<endl;
    cout<<"2----------------���"<<endl;
    cout<<"3----------------����"<<endl;
    cout<<"4----------------ȡ��ͷԪ��"<<endl;
    cout<<"5----------------��ӡѭ������"<<endl;
    cout<<"6----------------����г���"<<endl;
    cout<<"0----------------��������"<<endl;

    int operation;
    while(cin>>operation){
        switch(operation){
        case 0 :
            cout<<"�������н���!"<<endl;
            return 0;
            break;
        case 1 :
            InitQueue(Q);   //��ʼ������
            cout<<"�������Ӧ����ѡ������Ҫ�Ĳ���:"<<endl;
            break;
        case 2 :
            int e;
            cout<<"��������Ҫ��ӵ�Ԫ�أ���-1Ϊ��ֹ��:"<<endl;
            while(cin>>e){
                if(e == -1){
                    break;
                }
                EnQueue(Q,e);
            }
            cout<<"��ӳɹ�!"<<endl;
            Display(Q);
            cout<<"�������Ӧ����ѡ������Ҫ�Ĳ���:"<<endl;
            break;
        case 3 :
            cout<<"��������Ҫ���ӵ�Ԫ�ظ���:"<<endl;
            int n;
            cin>>n;
            cout<<"���ӵ�Ԫ������Ϊ: ";
            for(int i=0;i<n;i++){
                QElemType ee;
                cout<<DeQueue(Q,ee)<<" ";
            }
            cout<<endl;
            Display(Q);
            cout<<"�������Ӧ����ѡ������Ҫ�Ĳ���:"<<endl;
            break;
        case 4 :
            cout<<"����Ԫ��Ϊ:"<<GetHead(Q)<<endl;
            cout<<"�������Ӧ����ѡ������Ҫ�Ĳ���:"<<endl;
            break;
        case 5 :
            Display(Q);
            cout<<"�������Ӧ����ѡ������Ҫ�Ĳ���:"<<endl;
            break;
        case 6 :
            cout<<"��ѭ������ĳ���Ϊ:"<<QueueLength(Q)<<endl;    //����г���
            cout<<"�������Ӧ����ѡ������Ҫ�Ĳ���:"<<endl;
            break;
        default :
            cout<<"��ѡ��Ĳ��������ڣ�������ѡ��:"<<endl;
            break;
        }
    }
    return 0;
}
