#include <iostream>
using namespace std;


struct Element
{
    // ������
    char data;
    // ����� ���������� �������� ������
    Element* Next;
};

// ����������� ������
class List
{
    // ����� ��������� �������� ������
    Element* Head;
    // ����� ��������� �������� ������
    Element* Tail;
    // ���������� ��������� ������
    int Count;

public:
    // �����������
    List();
    // ����������
    ~List();

    // ���������� �������� � ������
    // (����� ������� ���������� ���������)
    void Add(char data);

    // �������� �������� ������
    // (��������� �������� �������)
    void Del();
    // �������� ����� ������
    void DelAll();

    // ���������� ����������� ������
    // (���������� ���������� � ��������� ��������)
    void Print();

    // ��������� ���������� ���������, ����������� � ������
    int GetCount();
    void AddIndex(char c, int numb)
    {
        int i = 1;
        Element* temp = Head;
        while (i < numb)
        {
            temp = temp->Next;
            i++;
        }
        //       cout<<temp->data<<endl;
        Element* nElement = new Element;
        nElement->data = c;
        nElement->Next = temp->Next;
        temp->Next = nElement;
    }
    void DelIndex(int numb)
    {
        int i = 1;
        Element* temp = Head;
        while (i < numb)
        {
            temp = temp->Next;
            i++;
        }
        Element* DelElement = temp->Next;
        temp->Next = DelElement->Next;
        delete DelElement;
    }

    void FindIndex(char c)
    {
        int i = 0;
        Element* temp = Head;
        if (temp->data == c)
        {
            cout << "������� ������ ��� ����� ��������: " << i << endl;
        }
        temp = temp->Next;
        i++;
    }
};

List::List()
{
    // ���������� ������ ����
    Head = Tail = NULL;
    Count = 0;
}

List::~List()
{
    // ����� ������� ��������
    DelAll();
}

int List::GetCount()
{
    // ���������� ���������� ���������
    return Count;
}

void List::Add(char data)
{
    // �������� ������ ��������
    Element* temp = new Element;

    // ���������� �������
    temp->data = data;
    // ��������� ������� �����������
    temp->Next = NULL;
    // ����� ������� ���������� ��������� ��������� ������
    // ���� �� �� ������ �����������
    if (Head != NULL) {
        Tail->Next = temp;
        Tail = temp;
    }
    // ����� ������� ���������� ������������
    // ���� �� ������ �����������
    else {
        Head = Tail = temp;
    }
}


void List::Del()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ������������� ������ �� ��������� �������
    Head = Head->Next;
    // ������� ������ �������� �������
    delete temp;
}

void List::DelAll()
{
    // ���� ��� ���� ��������
    while (Head != 0)
        // ������� �������� �� ������
        Del();
}

void List::Print()
{
    // ���������� ����� ��������� ��������
    Element* temp = Head;
    // ���� ��� ���� ��������
    while (temp != 0)
    {
        // ������� ������
        cout << temp->data << " ";
        // ��������� �� ��������� �������
        temp = temp->Next;
    }

    cout << "\n\n";
}

// �������� ������
int main()
{
    // ������� ������ ������ List
    List lst;

    // �������� ������
 //   char s[] = "Hello, World !!!\n";
 //   // ������� ������
 //   cout << s << "\n\n";
 //   // ���������� ����� ������
 //   int len = strlen(s);
 //   // �������� ������ � ������
 //   for(int i = 0; i < len; i++)
 //      lst.Add(s[i]);
 //   // ������������� ���������� ������
 //   lst.Print();
 //   // ������� ��� �������� ������
 //   lst.Del();
 //   lst.Del();
 //   lst.Del();
 //   //������������� ���������� ������
 //   lst.Print();

    lst.Add('H');
    lst.Add('E');
    lst.Add('L');
    lst.Add('L');
    lst.Add('O');
    lst.Print();
    lst.Del();
    lst.Print();
    lst.AddIndex('X', 2);
    lst.Print();

    lst.DelIndex(3);
    lst.Print();

    lst.FindIndex('E');
    lst.Print();
}