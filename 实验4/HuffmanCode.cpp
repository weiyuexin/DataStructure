#include <iostream>
#include <cstring>

using namespace std;

typedef struct
{
    int weight;
    int parent,lchild,rchild;
}HNode,*HuffmanTree;

typedef char **HuffmanCode;

void Select(HuffmanTree &h,int &s1,int &s2,int n)
{
    int SelectNum;
    for( int i = 1; i < n; i++)  
    {
        if( !h[i].parent )
        {
            SelectNum = h[i].weight;
            break;
        }
    }

    for( int i = 1; i < n; i++)
    {
        if( !h[i].parent )
        {
            if(h[i].weight <= SelectNum )
            {
                s1 = i;
                SelectNum = h[i].weight;
            }
        }
    }
    h[s1].parent = n;



    for( int i = 1; i < n; i++)  
    {
        if( !h[i].parent )
        {
            SelectNum = h[i].weight;
            break;
        }
    }

    for( int i = 1; i < n; i++)
    {
        if( !h[i].parent )
        {
            if(h[i].weight <= SelectNum )
            {
                s2 = i;
                SelectNum = h[i].weight;
            }
        }
    }
    h[s2].parent = n;
}

void CreatHuffmanTree(HuffmanTree &h,int n)
{
    int s1,s2;
    h = new HNode[2*n];    // ��̬����2n���ռ�

    for( int i = 1; i <= 2*n-1; i++) //����Ҷ�Ӻͷ�Ҷ�ӽڵ��parent .lchild,rchildֵ��ʼ��Ϊ0 
    {
        h[i].parent = 0;
        h[i].lchild = 0;
        h[i].rchild = 0;
    }

    cout << "������ǰ" << n << "���ڵ��Ȩ��" << endl;
    for( int i = 1; i <= n; i++)  // ����Ҷ�ӽڵ��Ȩ��
    {
        cin >> h[i].weight;
    }

    for(int i = n+1; i <= 2*n-1; i++)
    {
        Select(h,s1,s2,i);
        h[i].lchild = s1; h[i].rchild = s2;
        h[i].weight = h[s1].weight + h[s2].weight;
    }

}

void show(HuffmanTree h,int n)
{
	cout<<"����������"<<endl; 
    cout << "���i" << '\t' << "weight" << '\t' << "parent" << '\t' << "lchild" << '\t' << "rchild" << endl;
    for( int i = 1; i <= 2*n-1; i++)
    {
        cout << i << '\t' << h[i].weight << '\t' << h[i].parent << '\t' << h[i].lchild << '\t' << h[i].rchild << endl;
    }
}

void CreatHuffmanCode(HuffmanTree HT,HuffmanCode &HC,int n)
{
    int start,c,f;
    HC = new char *[n+1];
    char *cd = new char[n];
    cd[n-1]='\0';
    for(int i = 1; i<= n; i++)
    {
        start = n-1;
        c = i;
        f = HT[i].parent;
        while( f != 0)
        {
            --start;
            if( HT[f].lchild == c)
                cd[start] = '0';
            else
                cd[start] = '1';
            c = f;
            f = HT[f].parent;
        }
        HC[i] = new char[n-start];
        strcpy(HC[i],&cd[start]);
    }
    delete cd;
}

void show(HuffmanCode HC,int n)
{
    cout << endl;
    cout << "����������:" << '\t';
    for( int i = 1; i <= n; i++)
    {
        cout << HC[i] << '\t';
    }
    cout << endl;
}

int main()
{
    HuffmanCode c1;
    HuffmanTree t1;
    int n;
    cout << "�����������:" << endl;
    cin >> n;
    CreatHuffmanTree(t1,n);
    show(t1,n);

    CreatHuffmanCode(t1,c1,n);
    show(c1,n);
    return 0;
}

/*�������ݣ�  5 29 7 8 14 23 3 11    */ 



