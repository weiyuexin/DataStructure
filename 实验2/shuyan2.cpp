/*
*title:������Ļ�������
*writer:weiyuexin
*data:2020-10-1
*/

#include<bits/stdc++.h>

using namespace std;

#define ElemType int

typedef struct LNode{
    ElemType data;    //������
    struct LNode *next;   //ָ����
}LNode ,*LinkList;

void CreateList(LinkList &L){   //��ʼ��������
    int n;
    cout<<"�����뵥����ĳ��ȣ�"<<endl;
    cin>>n;
    L = new LNode;
    L->next = NULL;
    LinkList r = L;
    cout<<"�����뵥���������Ԫ�أ�"<<endl;
    for(int i = 0;i < n; i++){
        LinkList p = new LNode;
        cin>>p->data;
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

void Display(LinkList &L){      //��ӡ������
    cout<<"�õ�����Ϊ��"<<endl;
    LinkList p = L->next;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<endl;
}

void FindElem(LinkList &L,int i){    //����Ԫ��
    LinkList p1 = L;
    LinkList p2 = L;
    int n=0;
    bool sign = false;
    while(p1){
        if(i == p1->data){
            sign = true;
            break;
        }
        p1 = p1->next;
    }
    if(sign){
        cout<<"ֵΪ"<<i<<"��Ԫ���Ǳ��еĵ�";
        while(p2){
            if(i == p2->data){
                cout<<n<<", ";
            }
            p2 = p2->next;
            n++;
        }
        cout<<"��Ԫ��"<<endl;
    }else{
        cout<<"�������в����ڸ�Ԫ��!"<<endl;
    }
}

void GetElem(LinkList L,int i){    //��λԪ��
    LinkList p = L->next;
    int j = 1;
    while(p && j<i){
        p = p->next;
        j++;
    }
    if(!p || j>i){
        cout<<"�������λ���ѳ���������ĳ���!"<<endl;
        return ;
    }
    cout<<"�õ������"<<i<<"��Ԫ��Ϊ "<<p->data<<endl;
}

void Insert(LinkList &L,int j,ElemType e){     //����Ԫ��
    LinkList p = L;
    int i = 0;
    //�ж�Ҫ�����λ���Ƿ����
    LinkList p1 = L->next;
    int length = 0;
    while(p1){
        length++;
        p1 = p1->next;
    }
    if(j>length){
        cout<<"Ҫ�����λ�ò�����!"<<endl;
        return;
    }
    while(p && i<j - 1){
        p = p->next;
        ++i;
    }

    LNode *s = new LNode();    //�����½ڵ�
    s->data = e;        //����������Ϊe
    s->next = p->next;
    p->next = s;

    cout<<"����ɹ�!"<<endl;
}

void Delete(LinkList &L,int x){     //ɾ��ָ��λ�õ�Ԫ��
    LinkList p = L;
    int i =0;
    while(p && i < x - 1){
        p = p->next;
        ++i;
    }
    if(!p->next || i>x-1){
        cout<<"ɾ��λ�ò�����!"<<endl;
    }
    LNode *r = new LNode();
    r = p->next;
    p->next = r->next;
    delete r;
    cout<<"ɾ���ɹ�!"<<endl;
}

void DeleteElem(LinkList &L,ElemType e){    //ɾ��ָ��ֵ��Ԫ��
	LinkList p = L;
	bool sign = false;
	while(p){
		if(p->next->data == e){
            LNode *r = new LNode();
            r = p->next;
            p->next = r->next;
            delete r;
            sign = true;
		}
		p = p->next;
	}
	if(sign){
		cout<<"ɾ���ɹ�!"<<endl;
		Display(L);
	}else{
		cout<<"Ҫɾ����Ԫ�ز�����!"<<endl;
		return;
	}
}
void Merger(){     //������������Ĺ鲢
    LinkList LA;
    LinkList LB;
    LinkList LC;

    LNode *pa = new LNode();
    LNode *pb = new LNode();
    LNode *pc = new LNode();

    cout<<"���ʼ��������PA:"<<endl;
    CreateList(LA);
    Display(LA);
    cout<<"���ʼ��������PB:"<<endl;
    CreateList(LB);
    Display(LB);

    pa = LA->next;    //pa��pb�ĳ�ֵ�ֱ�ָ��������ĵ�һ���ڵ�
    pb = LB->next;
    LC = LA;      //��LA��ͷ�����ΪLC��ͷ���
    pc = LC;      //pc�ĳ�ֵָ��LC��ͷ���

    while(pa && pb){    //��LA��LB��δ�ﵽ��βʱ��ѡȡ��Сֵ����LC��
        if(pa->data <= pb->data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa?pa:pb;   //���ǿձ��ʣ��Ƭ�β��뵽PC֮��
    delete LB;           //�ͷ�LB��ͷ���
    cout<<"������������鲢���!"<<endl;
    Display(LC);
}

int main(){
    LinkList L;

    cout<<"ʵ��2 ----- ������Ļ�������"<<endl<<endl;
    cout<<"����������ѡ���Ӧ�Ĳ���!!!"<<endl;
    cout<<"1---------����������"<<endl;
    cout<<"2---------��ʾ������"<<endl;
    cout<<"3---------�����������е�����Ԫ��"<<endl;
    cout<<"4---------��λ��ʾ������Ԫ��"<<endl;
    cout<<"5---------����Ԫ��"<<endl;
    cout<<"6---------ɾ��ָ��λ�õ�Ԫ��"<<endl;
    cout<<"7---------ɾ��ָ��ֵ��Ԫ��"<<endl;
    cout<<"8---------��������������Ĳ���"<<endl;
    cout<<"0---------��������"<<endl;
    cout<<"��������Ҫ���еĲ�����"<<endl;

    int operation;

    while(cin>>operation){
        switch(operation){
            case 0 :   //��������
                cout<<"�������н���!!!"<<endl;
                return 0;
            case 1 :    //����������
                CreateList(L);
                Display(L);
                cout<<"��������Ҫ���еĲ�����"<<endl;
                break;
            case 2 :    //��ʾ������
                Display(L);
                cout<<"��������Ҫ���еĲ�����"<<endl;
                break;
            case 3 :     //��������Ԫ��
                cout<<"������Ҫ������Ԫ�أ�"<<endl;
                int n;
                cin>>n;
                FindElem(L,n);
                cout<<"��������Ҫ���еĲ�����"<<endl;
                break;
            case 4 :      //�鿴ָ��λ�õ�Ԫ��
                cout<<"������Ҫ�鿴��Ԫ��λ�ã�"<<endl;
                int i;
                cin>>i;
                GetElem(L,i);
                cout<<"��������Ҫ���еĲ�����"<<endl;
                break;
            case 5 :      //����Ԫ��
                cout<<"������Ҫ�����λ��:"<<endl;
                int j;
                cin>>j;
                cout<<"������Ҫ�����Ԫ��:"<<endl;
                ElemType e;
                cin>>e;
                Insert(L,j,e);
                Display(L);
                cout<<"��������Ҫ���еĲ�����"<<endl;
                break;
            case 6 :       //ɾ��ָ��λ�õ�Ԫ��
                cout<<"������Ҫɾ��Ԫ�ص�λ��:"<<endl;
                int x;
                cin>>x;
                Delete(L,x);
                Display(L);
                cout<<"��������Ҫ���еĲ�����"<<endl;
                break;
            case 7 :       //ɾ��ָ��ֵ��Ԫ��
            	cout<<"������Ҫɾ����Ԫ��:"<<endl;
            	ElemType ee;
            	cin>>ee;
            	DeleteElem(L,ee);
            	cout<<"��������Ҫ���еĲ�����"<<endl;
                break;
            case 8 :
                Merger();
                cout<<"��������Ҫ���еĲ�����"<<endl;
                break;
            default :
                cout<<"��ѡ��Ĳ�����Ч,������ѡ��:"<<endl;
                break;
        }
    }
    return 0;
}
