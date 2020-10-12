#include<iostream>
using namespace std;
struct node
{
    node *next;
    node *prev;
    int data;
};

class doubly
{
    private:
    node* head;
    public:
    doubly()
    {
        head = NULL;
    }

    node* creat_Node(int data)
    {
        node* temp = new node();
        temp->data = data;
        temp->next = NULL;
        temp->prev = NULL;
        return temp;
    }  


    node* search(int data)
    {
        node *temp;
        temp = head;
        while(temp->data!=data)
        {
            temp = temp->next;
        }
        return temp;
    }


    node* search_list_node(int data,int info)
    {
        node* temp;
        temp = head;
        while(temp->data != data)
        {
            temp = temp->next;
        }
        node *temp1 = new node();
        temp1->data = info;
        return temp1;
    }
      
    void add(int data)
    {
        if(head==NULL)
        {
            head = creat_Node(data);
         //   cout<<head->data;
            return;     
        }
        node *new_node = creat_Node(data);
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
       // cout<<new_node->data;
        return; 
      }

    void inseart_Node(int data,int info)
    {
        node* temp = search(data);
        if(temp->next == NULL)
        {
            node* new_node = search_list_node(data,info);
            temp->next =  new_node;
            new_node->prev = temp;
            new_node->next = NULL;
            return;
        }
        node* new_node = search_list_node(data,info);
        new_node->next = temp->next;
        temp->next = new_node;
        new_node->prev = temp;
        temp->next->prev = new_node;
        return;

    }
       void print(){
        node* temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
       }



};

int main()
{
    doubly l1;
    l1.add(5);
    l1.add(4);
    l1.print();
    l1.inseart_Node(5,6);
    l1.print();
}