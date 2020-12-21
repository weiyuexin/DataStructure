/*
*title:���ӵĻ�������
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
    QueuePtr front;     //��ͷָ��
    QueuePtr rear;     //��βָ��
}LinkQueue;

void InitQueue(LinkQueue &Q){     //��ʼ������
    Q.front = Q.rear = new QNode;        //�����½����Ϊͷ��㣬��ͷ�Ͷ�βָ��ָ��˽ڵ�
    Q.front->next = NULL;     //ͷ����ָ�����ÿ�
    cout<<"���ӳ�ʼ���ɹ�!"<<endl;
}

void EnQueue(LinkQueue &Q,QElemType e){     //���
    QNode *p = new QNode();
    p->data = e;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
}

QElemType DeQueue(LinkQueue &Q){      //����
    if(Q.front == Q.rear){
        cout<<"�������ѿ�!"<<endl;
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

QElemType GetHead(LinkQueue Q){        //ȡ����ֵ
    if(Q.front != Q.rear){     //���зǿ�
        return Q.front->next->data;     //���ض���ֵ
    }else{
       cout<<"������Ϊ�գ�"<<endl;
       return 0;
    }
}

void Display(LinkQueue Q){      //��ӡ����Ԫ��
    QNode *p = new QNode();
    p = Q.front->next;
    cout<<"������Ϊ: ����=> ";
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"<=��β"<<endl;
}

int main(){
    LinkQueue Q;
    cout<<"ʵ��3_4---------------------�����еĻ�������"<<endl<<endl;
    cout<<"�������Ӧ����ѡ������Ҫ�Ĳ���:"<<endl;
    cout<<"1----------------����������"<<endl;
    cout<<"2----------------���"<<endl;
    cout<<"3----------------����"<<endl;
    cout<<"4----------------ȡ��ͷԪ��"<<endl;
    cout<<"5----------------��ӡ������"<<endl;
    cout<<"0----------------��������"<<endl;
    int operation;
    cout<<"�������Ӧ������ѡ������Ҫ���еĲ���:"<<endl;
    while(cin>>operation){
        switch(operation){
        case 0 :
            cout<<"�������н���!"<<endl;
            return 0;
        case 1 :
            InitQueue(Q);
            cout<<"�������Ӧ������ѡ������Ҫ���еĲ���:"<<endl;
            break;
        case 2 :
            cout<<"������Ҫ��ӵ�Ԫ�ظ�����"<<endl;
            int n;
            cin>>n;
            cout<<"������Ҫ��ӵ�Ԫ��:"<<endl;
            for(int i=0;i<n;i++){
                QElemType e;
                cin>>e;
                EnQueue(Q,e);
            }
            cout<<n<<"��Ԫ����ӳɹ�!"<<endl;
            Display(Q);
            cout<<"�������Ӧ������ѡ������Ҫ���еĲ���:"<<endl;
            break;
        case 3 :
            cout<<"������Ҫ��ջ��Ԫ�صĸ���:"<<endl;
            int m;
            cin>>m;
            cout<<"��ջ��Ԫ������Ϊ: ";
            for(int i=0;i<m;i++){
                cout<<DeQueue(Q)<<" ";
            }
            cout<<endl;
            Display(Q);
            cout<<"�������Ӧ������ѡ������Ҫ���еĲ���:"<<endl;
            break;
        case 4 :
            cout<<"�����Ӷ���ֵΪ: "<<GetHead(Q)<<endl;
            cout<<"�������Ӧ������ѡ������Ҫ���еĲ���:"<<endl;
            break;
        case 5 :
            Display(Q);
            cout<<"�������Ӧ������ѡ������Ҫ���еĲ���:"<<endl;
            break;
        default :
            cout<<"��ѡ��Ĳ��������ڣ�������ѡ��:"<<endl;
            break;
        }
    }
    return 0;
}
