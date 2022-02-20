#include<iostream>
#include<stdlib.h>
#include<cstdio>
#include<stdio.h>

using namespace std;

struct s_node* create();

/////////////////////////////////////  Calling Node  /////////////////////////////////

struct node_customer
{
    char* name;
    float time;
};

/////////////////////////////////////  Main Node  ////////////////////////////////////

struct node
{
    int data;
    bool get_servicing;
    struct node* next;
    struct node_customer* add;
    struct s_node* address;

}*head = NULL, * tail = NULL;

struct node* curr;

////////////////////////////////////  Creating Nodes  /////////////////////////////////

void node_create(int value, struct s_node* addr)
{

    curr = (struct node*)malloc(sizeof(struct node));
    curr->data = value;
    curr->address = addr;
    curr->get_servicing = false;
    curr->add = NULL;
    curr->next = NULL;

    if (head == NULL)
    {
        head = curr;
        tail = curr;
    }
    else
    {

        tail->next = curr;
        tail = curr;
    }


}

////////////////////////////////////  printing Nodes  /////////////////////////////////

void node_print()
{

    struct node* current;
    current = head;
    cout << endl << "Printing all Nodes" << endl << endl;

    while (current != NULL)
    {

        cout << "The value is: " << current->data << endl;
        current = current->next;
    }
}

////////////////////////////////////  Server Check  /////////////////////////////////


struct node* check_server()
{
    struct node* temp;
    temp = head;

    while (temp != NULL)
    {
        if (temp->get_servicing == false)
        {
            return temp;
        }
        else
            temp = temp->next;
    }
    return NULL;
}

////////////////////////////////////  stack  ///////////////////////////////////////////

struct node_stack
{
    char* name;
    float time;
    float waiting_time;
    struct node_stack* next;
};

struct s_node
{
    int Count;
    struct node_stack* top;
};

struct s_node* create()
{
    struct s_node* s_info;
    s_info = (struct s_node*)malloc(sizeof(struct s_node));
    s_info->Count = -1;
    return s_info;
};


void push(char* Name, float value,float w_time, struct s_node* s_info)
{
    struct node_stack* newnode;

    newnode = (struct node_stack*)malloc(sizeof(struct node_stack));

    if (s_info->Count == -1)
    {
        newnode->name = (char*)malloc(sizeof(char) * 20);
        newnode->name = Name;
        newnode->waiting_time = w_time;
        newnode->time = value;
        newnode->next = NULL;
        s_info->top = newnode;
        (s_info->Count)++;
    }
    else
    {
        newnode->name = (char*)malloc(sizeof(char) * 20);
        newnode->name = Name;
        newnode->waiting_time = w_time;
        newnode->time = value;
        newnode->next = s_info->top;
        s_info->top = newnode;
        (s_info->Count)++;
    }

}
//////////////////////////////////////////////  stack pop (don't need)  /////////////////////////////////
void pop(struct s_node* s_info)
{
    if (s_info->Count == -1)
    {
        cout << "No elements" << endl;
    }
    else
    {
        struct node_stack* temp;
        temp = s_info->top;
        s_info->top = s_info->top->next;
        (s_info->Count)--;
        free(temp);
    }

}

void print(struct s_node* s_info)
{
    if (s_info->Count == -1)
    {
        cout << endl << "No History " << endl;
    }
    else
    {
        cout << endl << "The History List: " << endl << endl;
        struct node_stack* temp;
        temp = s_info->top;
        while (true)
        {
            cout << "Name = " << temp->name << " & Time = " << temp->time << "  Waiting Time: "<<temp->waiting_time<<endl;
            if (temp->next == NULL)
            {
                break;
            }
            temp = temp->next;
        }
        cout << endl;
    }
}

////////////////////////////////////////////////// Queue  //////////////////////////////////////////////

struct node_queue
{
    char* name;
    float time;
    struct node_queue* next;
};

struct q_node
{
    int Count;
    struct node_queue* Front, * Rear;
};

struct q_node* create_queue()
{
    struct q_node* q_info;
    q_info = (struct q_node*)malloc(sizeof(struct q_node));
    q_info->Count = -1;
    return q_info;
}

void enqueue(char* Name, float value, struct q_node* q_info)
{

    struct node_queue* newnode;

    newnode = (struct node_queue*)malloc(sizeof(struct node_queue));

    if (q_info->Count == -1)
    {
        newnode->time = value;
        newnode->name = (char*)malloc(sizeof(char) * 20);
        newnode->name = Name;
        newnode->next = NULL;
        q_info->Front = newnode;
        q_info->Rear = newnode;
        (q_info->Count)++;
    }
    else
    {
        newnode->time = value;
        newnode->name = (char*)malloc(sizeof(char) * 20);
        newnode->name = Name;
        newnode->next = NULL;
        q_info->Rear->next = newnode;
        q_info->Rear = newnode;
        (q_info->Count)++;
    }

}

struct node_customer* dequeue(struct q_node* q_info)
{

    if (q_info->Count == -1)
    {
        cout << "No elements" << endl;
    }
    else
    {
        struct node_queue* temp;
        temp = q_info->Front;
        q_info->Front = q_info->Front->next;
        (q_info->Count)--;


        struct node_customer* new_customer_deq;
        new_customer_deq = (struct node_customer*)malloc(sizeof(struct node_customer));

        new_customer_deq->name = (char*)malloc(sizeof(char) * 20);
        new_customer_deq->name = temp->name;
        new_customer_deq->time = temp->time;

        free(temp);
        return new_customer_deq;
    }

}

void print(struct q_node* q_info)
{
    if (q_info->Count == -1)
    {
        cout << endl << "No Waiting List " << endl;
    }
    else
    {
        cout << endl << "The Waiting List : " << endl << endl;
        struct node_queue* temp;
        temp = q_info->Front;
        while (true)
        {
            cout << "Name = " << temp->name << " & Time = " << temp->time << endl;
            if (temp->next == NULL)
            {
                break;
            }
            temp = temp->next;
        }
        cout << endl;
    }
}


////////////////////////////////////////////////////////////  Main Function  ////////////////////////////////////////


int main()
{
    int f_wTime = 0,l_wTime = 0;

    struct q_node* address;                 //////// Creating Queue ////////
    address = create_queue();


    int l_server, v_server;                 //////// Creating Server ////////
    cout<<endl<<"Enter Server size: ";
    cin >> l_server;
    for (int i = 0; i < l_server; i++)
    {
        struct s_node* address;
        address = create();
        cout <<endl<< "Enter Server Name ( like: 1,2) : ";
        cin >> v_server;
        node_create(v_server, address);
    }



    int choice;
    while (true)
    {
        system("cls");
        cout << endl << "1. Call the Server " << endl;
        cout << "2. Print Server Information " << endl;
        cout << "3. Waiting List " << endl;
        cout << "4. Server History " << endl;
        cout << "5. Exit " << endl;

        cout << endl << "Enter your choice" << endl;
        cin >> choice;

        switch (choice)
        {

        case 5:
            exit(0);

        case 1:
            system("cls");

            struct node_customer* new_customer;
            new_customer = (struct node_customer*)malloc(sizeof(struct node_customer));

            new_customer->name = (char*)malloc(sizeof(char) * 20);

            cout <<"\t\t"<< "Information of Customer"<<endl<<endl;

            cout << "Input customer name: ";
            cin >> new_customer->name;
            cout << "Input customer servicing time: ";
            cin >> new_customer->time;

            struct node* che_ser;
            che_ser = check_server();

            if (che_ser == NULL)
            {
                cout << endl << "You are in waiting list ";
                enqueue(new_customer->name, new_customer->time, address);
            }
            else
            {
                cout << endl << "Your call is taken by Server: " << che_ser->data << endl;
                che_ser->add = new_customer;
                che_ser->get_servicing = true;
            }

            fflush(stdin);
            getchar();
            break;

        case 2:
            system("cls");

            struct node* ser_list;
            ser_list = head;

            while (ser_list != NULL)
            {
                if (ser_list->get_servicing == true)
                {
                    cout << "Server: " << ser_list->data << " = Busy" << endl;
                }
                else
                    cout << "Server: " << ser_list->data << " = Available" << endl;

                ser_list = ser_list->next;
            }

            char release;
            int rel_ser;

            cout <<endl<< "Do you want to Release any Server ? (y/n) : ";
            cin >> release;

            if (release == 'y')
            {
                cout<<endl << "Which Server you want to Release ? : ";
                cin >> rel_ser;

                int rel_num = 1;

                struct node* ser_rel;
                ser_rel = head;

                while (ser_rel != NULL)
                {
                    if (rel_num == rel_ser)
                    {
                        if (ser_rel->add->time > 10)
                        {
                            ser_rel->add->time = ser_rel->add->time - 10;
                            struct node* che_ser_ano;
                            che_ser_ano = check_server();

                            if (che_ser_ano == NULL)
                            {
                                cout << endl << "You are in waiting list ";
                                enqueue(ser_rel->add->name, ser_rel->add->time, address);
                            }
                            else
                            {
                                cout << endl << "Your call is taken by Server: " << che_ser_ano->data << endl;
                                che_ser_ano->add = ser_rel->add;
                                che_ser_ano->get_servicing = true;
                                ser_rel->get_servicing = true;
                            }

                            if (address->Count != -1)
                            {
                                struct node_customer* deq_cus;
                                deq_cus = dequeue(address);

                                cout<<"Input Waiting Time in Waiting list for customer "<<deq_cus->name<<" : ";
                                cin>>l_wTime;

                                ser_rel->add = deq_cus;
                                ser_rel->get_servicing = true;
                            }

                            break;
                        }
                        else
                        {
                            f_wTime = f_wTime + l_wTime;

                            cout <<endl<<"\t\t"<< "Pushing into Server history (stack) " << endl;
                            push(ser_rel->add->name, ser_rel->add->time,f_wTime,ser_rel->address);

                            f_wTime = 0;
                            l_wTime = 0;

                            if (address->Count != -1)
                            {
                                struct node_customer* deq_cus;
                                deq_cus = dequeue(address);

                                cout<<endl<<"Input Waiting Time in Waiting list for customer "<<deq_cus->name<<" : ";
                                cin>>f_wTime;

                                ser_rel->add = deq_cus;
                                ser_rel->get_servicing = true;
                            }
                            else
                                ser_rel->get_servicing = false;

                            break;
                        }
                    }
                    else
                    {
                        ser_rel = ser_rel->next;
                        rel_num++;
                    }

                }

            }
            fflush(stdin);
            getchar();
            break;

        case 3:
            system("cls");
            print(address);

            cout<<endl<<"Total Customer in Waiting List: "<<(address->Count + 1)<<endl;

            fflush(stdin);
            getchar();
            break;

        case 4:
            system("cls");

            struct node* ser_list_his;
            ser_list_his = head;

            while (ser_list_his != NULL)
            {
                if (ser_list_his->get_servicing == true)
                {
                    cout << "Server: " << ser_list_his->data << " = Busy" << endl;
                }
                else
                    cout << "Server: " << ser_list_his->data << " = Available" << endl;

                ser_list_his = ser_list_his->next;
            }

            int ser_his, ser_num = 1;
            cout <<endl<< "Which Server History You Want to See : ";
            cin >> ser_his;

            ser_list_his = head;

            while (ser_list_his != NULL)
            {
                if (ser_his == ser_num)
                {
                    print(ser_list_his->address);
                    break;
                }
                else
                {
                    ser_list_his = ser_list_his->next;
                    ser_num++;
                }


            }

            fflush(stdin);
            getchar();
            break;


        }
    }

}
