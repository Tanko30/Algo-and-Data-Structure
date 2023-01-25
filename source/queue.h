/*********************************************************************************************
 *
 * [Author]: Zourkalaini BOUBAKAR (CCI, 2021)
 * [Date]: Sat Feb 20, 2021 
 * [Gaol]: Qeue Encapsulation (mother program, Program.cpp)
 * [Version]: 1.3 (last version)
 * 
 * *******************************************************************************************/

#include <iostream> 
#include <string>
#include <cstdlib>

int main();
using namespace std;

/******************************************************************************************
       Data of the Queue (a personnalise type): Record of students name and age
 *******************************************************************************************/
struct Dataq
{
    string name; 
    int age;
    Dataq *link;
};

/*******************************************************************************************
    Definition of the Queue, as a class
 *******************************************************************************************/ 
 class Queue
{
private:
    //attribute, accessible only by queue's functions 
    Dataq *front = NULL;
    Dataq  *rear =NULL;
    int size = 0;//increase with dequeue and decrease with enqueue
    int MaxSize = 0;//fixed value after creting a new queue



public:
    //functions
    Queue(int n); 
    ~Queue();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Enqueue();
    void Dequeue();
    void managQueue();
    string DisplayQueue();
    

};

/**********************************************************************************
  Constructor of the Queue, to initialize Queue to be empty
***********************************************************************************/
Queue::Queue(int n)
{
    this->size = n;
    this->MaxSize = n;
}

/**********************************************************************************
  Destructor of the Queue, to remove all items of the Queue
 * ********************************************************************************/
Queue::~Queue()
{
    while (!IsEmpty())
    {
        Dequeue();
    }
}

/*********************************************************************************************
   make the Queue empty by calling the destructor, which will removed all items of the Queue
 * *******************************************************************************************/
void Queue::MakeEmpty()
{
    delete this;//call of destructor
    cout << "Clearing...."<<endl;
    cout << "All items are removed successfully !" <<endl;
    front = rear = NULL;
    
}

/*************************************************************************************************
  check whether the Queue is empty, if so will return True, otherwise False
 * ***********************************************************************************************/
bool Queue::IsEmpty(){
    return ((front == NULL) && (rear == NULL) && (size == MaxSize));
}

/*************************************************************************************************
    check whether the Queue is full, if so will return True, otherwise False
 * ***********************************************************************************************/
bool Queue::IsFull()
{
    return (this->size == 0);
}

/************************************************************************************************
  add new element at the rear of the Queue by giving data (name and age)
 * *********************************************************************************************/
void Queue::Enqueue(){
        
   if (IsFull())
    {
        cout << "\nYou can't enqueue in a full queue!" << endl;
    } else
    {
        Dataq *temp = new Dataq();
        cout << "\nEnter the name of student: ";
        cin >> temp->name;
        cout << "Enter the age of the student: ";
        cin >> temp->age;
        temp->link = NULL;
        if (front == NULL)//if we are inserting for the first time
        {
            front = temp;
            rear = temp;
        } else
        {
            rear->link = temp;
            rear = temp;
        }
        
        this->size--;

    }
    
}

/************************************************************************************************
  remove the element at the front of the Queue and return it
 * *********************************************************************************************/
void Queue::Dequeue(){
    if (!IsEmpty())
    {
        string name = front->name;//to show the name and the age of the delete data
        int age = front->age;


        if ((front == rear))//in case we have only one element inside the queue
        {   
            free(front);
            front = rear = NULL;
            this->size++; 
            cout << "(" + name + ", " + to_string(age) + ") has been removed!";
        } else// in case we have many elements inside the queue
        {
            front = front->link;
            this->size++;  
            cout <<  "(" + name + ", " + to_string(age) + ") has been removed";

        }
        
    } else 
    {
        cout << "you can't Dequeue from an empty Queue!" << endl;
    }
    
}

/************************************************************************************************
  Display the content of the Queue, from front to rear
 * *********************************************************************************************/
string Queue::DisplayQueue(){
    string result = "(Front) -> ";
    if (IsEmpty())
    {
        result = result + "NULL -> (Rear)"; // if the Queue is empty nothing to display
        return result;
    }else
    {
        Dataq *current = front;
        while (current != NULL)
        {
            result = result  + "(" + current->name + ", " + to_string(current->age) + ") -> "; 
            current = current->link;
        }
        result = result + "(Rear)";
        return result;
    }
        
}


/************************************************************************************************
  The home menu of the program
 * *********************************************************************************************/
int homeq()
{
    int choice;
    cout << "\n\t\t\t\t\t\t\t\t ===================================" <<endl;
    cout << "\n\t\t\t\t\t\t\t\t QUEUE MANAGEMENT PROGRAM " <<endl;
    cout << "\n\t\t\t\t\t\t\t\t ====================================" <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 1- Create a new Queue " <<endl;
    cout << "\n\t\t\t\t\t\t\t\t\t 2- Exit the program " <<endl;

    do//for choice control
    {
        cout << "\n\n\t Choose to continue... " <<endl;
        cin >> choice;

    } while ((choice < 1 ) || (choice > 2));
    
    return choice;
}

/************************************************************************************************
  Options for Queue management, after creating queue of n (to be read from user) size
 * *********************************************************************************************/
void managQueue()
{
    int n = 0;
    int choice;
    cout << "Enter the value of N, to create a Queue of size N: ";
    cin >> n;
    Queue *q = new Queue(n);
    cout << "\n A Queue of size "<< n << " has been created successfully" <<endl;
    menu:// label for goto 
    cout << "\n\t\t\t\t\t\t\t 1- MakeEmpty" <<endl;
    cout << "\n\t\t\t\t\t\t\t 2- IsEmpty" <<endl;
    cout << "\n\t\t\t\t\t\t\t 3- IsFull" <<endl;
    cout << "\n\t\t\t\t\t\t\t 4- Enqueue" <<endl;
    cout << "\n\t\t\t\t\t\t\t 5- Dequeue" <<endl;
    cout << "\n\t\t\t\t\t\t\t 6- Display" <<endl;
    cout << "\n\n\t\t\t\t\t\t\t choose to continue... Or any key to return back to home page" <<endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        q->MakeEmpty();
        goto menu;
        break;
    case 2:
        if (q->IsEmpty())
        {
            cout <<"\nIsEmpty: Yes" <<endl;

        }else
        {
            cout << "\nIsEmpty: No"<<endl;
        }
        goto menu;
        break;
    case 3:
        if (q->IsFull())
        {
            cout <<"\nIsFull: Yes" <<endl;

        }else
        {
            cout << "\nIsFull: No"<<endl;
        }
        goto menu;
        break;
    case 4:
        q->Enqueue();
        goto menu;
        break;
    case 5:
        q->Dequeue();
        goto menu;
        break;
    case 6:
        cout << q->DisplayQueue() <<endl;
        goto menu;
        break;
    
    default:
        homeq();
        break;
    }
}

void MainQueue() {
    
    int c = homeq();

    switch (c)
    {
        case 1:
            managQueue();
            break;
        case 2:
            cout << "\n\tThanks see you !" <<endl;
            main();
            break;
       default:
           break;
       }
} 