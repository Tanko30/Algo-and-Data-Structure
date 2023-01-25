/*********************************************************************************************
 *
 * [Author]: Zourkalaini BOUBAKAR (CCI, 2021)
 * [Date]: Sat Feb 20, 2021 
 * [Gaol]: Stack Encapsulation (mother program, Program.cpp)
 * [Version]: 1.1 (last version)
 * 
 * *******************************************************************************************/

/*********************************************************************************************
  Libraries, iostream for input/output, string for string manupulation, cstdlib for compiler
 *********************************************************************************************/

#include <iostream> 
#include <string>
#include <cstdlib>
int main();
using namespace std;

/**********************************************************************************************
    Data of the Stack (a personnalise type): Record of students name and age
 **********************************************************************************************/
struct Data
{
    string name; 
    int age;
    Data *next;
};

/*********************************************************************************************
    Definition of the stack, as a class
 **********************************************************************************************/ 
 class Stack
{
private:
//attribute, accessible only by stack's functions
    Data *top; 
    int size;


public:
    //functions for stack manupulation
    Stack(int n); 
    ~Stack();
    void MakeEmpty();
    bool IsEmpty();
    bool IsFull();
    void Push();
    void Pop();
    void managStack();
    string DisplayStack();    

};

/********************************************************************************************
  Constructor of the stack, to initialize stack to be empty
********************************************************************************************/
Stack::Stack(int n)
{
    top = NULL;
    this->size = n;
}

/*******************************************************************************************
  Destructor of the stack, to remove all items of the stack
 * ******************************************************************************************/
Stack::~Stack()
{
    while (!IsEmpty())
    {
        Pop();
    }
}

/*********************************************************************************************
   make the stack empty by calling the destructor, which will removed all items of the stack
 * *******************************************************************************************/
void Stack::MakeEmpty()
{
    delete this;
    cout << "Clearing...."<<endl;
    cout << "All items are removed successfully !" <<endl;
    top = NULL; //to be able to display an empty stack
}

/*************************************************************************************************
  check whether the task is empty, if so will return True, otherwise False
 * ***********************************************************************************************/
bool Stack::IsEmpty(){
    return (top == NULL);
}

/*************************************************************************************************
    check whether the task is full, if so will return True, otherwise False
 * ***********************************************************************************************/
bool Stack::IsFull()
{
    return (this->size == 0);
}

/************************************************************************************************
  add new element at the top of the stack by giving data (name and age)
 * *********************************************************************************************/
void Stack::Push(){
        
   if (IsFull())
    {
        cout << "\nYou can't push in a full stack!" << endl;
    } else
    {
        // need of new Data to store the new recordment (name and age)
        Data *data = new Data;
        cout << "\nEnter the name of student: ";
        cin >> data->name;
        cout << "Enter the age of the student: ";
        cin >> data->age;
        data->next = top; //point the new data's next to the old top of the stack
        top = data; // point top to the new top of the stack
        this->size--;// "this" refers to the current stack

    }
    
}

/************************************************************************************************
  remove the last  element, which is at the top of the stack and return it
 * *********************************************************************************************/
void Stack::Pop(){
    if (!IsEmpty())
    {
        string valueName = top->name;//for name display after removing
        int valueAge = top->age;//for age display after removing
        top = top->next;
        cout << "(" +valueName + ", " + to_string(valueAge) + ") has been removed!\n";
    } else
    {
        cout << "you can't pop from an empty stack!\n";
    }
    
}

/************************************************************************************************
  Display the content of the stack, from top to bottom
 * *********************************************************************************************/
string Stack::DisplayStack(){
    string result = "(top) -> ";
    if (IsEmpty())
    {
        result = result + "NULL"; // if the stack is empty nothing to display
        return result;
    }else
    {
        Data *current = top;
        while (current != NULL)
        {
            result = result  + "(" + current->name + ", " + to_string(current->age) + ") -> ";
            current = current->next;
        }
        result = result + "(END)";
        return result;
    }
        
}


/************************************************************************************************
  The home menu of the subprogram
 * *********************************************************************************************/
int home()
{
    int choice;
    cout << "\n\t\t\t\t\t\t\t\t ===================================" <<endl;
    cout << "\n\t\t\t\t\t\t\t\t STACK MANAGEMENT PROGRAM " <<endl;
    cout << "\n\t\t\t\t\t\t\t\t ====================================" <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 1- Create a new Stack " <<endl;
    cout << "\n\t\t\t\t\t\t\t\t\t 2- Exit the program " <<endl;

    do//for choice control
    {
        cout << "\n\n\t Choose to continue... " <<endl;
        cin >> choice;

    } while ((choice < 1 ) || (choice > 2));
    
    return choice;
}

/************************************************************************************************
  Options for task management, after creating task of n (read from user) size
 * *********************************************************************************************/
void managStack()
{
    int n = 0;
    int choice;
    cout << "Enter the value of N, to create a stack of size N: ";
    cin >> n;
    Stack *s = new Stack(n);
    cout << "\n A Stack of size "<< n << " has been created successfully" <<endl;
    menu:// label for goto 
    cout << "\n\t\t\t\t\t\t\t 1- MakeEmpty " <<endl;
    cout << "\n\t\t\t\t\t\t\t 2- IsEmpty " <<endl;
    cout << "\n\t\t\t\t\t\t\t 3- IsFull " <<endl;
    cout << "\n\t\t\t\t\t\t\t 4- Push " <<endl;
    cout << "\n\t\t\t\t\t\t\t 5- Pop" <<endl;
    cout << "\n\t\t\t\t\t\t\t 6- Display" <<endl;
    cout << "\n\n\t\t\t\t\t\t\t choose to continue... Or any key to return back to home page" <<endl;
    cin >> choice;
    switch (choice)
    {
    case 1:
        s->MakeEmpty();
        goto menu;
        break;
    case 2:
        if (s->IsEmpty())
        {
            cout <<"\nIsEmpty: Yes" <<endl;

        }else
        {
            cout << "\nIsEmpty: No"<<endl;
        }
        goto menu;
        break;
    case 3:
        if (s->IsFull())
        {
            cout <<"\nIsFull: Yes" <<endl;

        }else
        {
            cout << "\nIsFull: No"<<endl;
        }
        goto menu;
        break;
    case 4:
        s->Push();
        goto menu;
        break;
    case 5:
        s->Pop();
        goto menu;
        break;
    case 6:
        cout << s->DisplayStack() <<endl;
        goto menu;
        break;
    
    default:
        cout << "Invalid choice !" <<endl;
        system("clear");
        home();
        break;
    }
}

int MainStack() {
    
    int choice = home();

    switch (choice)
    {
        case 1:
            managStack();
            break;
        case 2:
            cout << "\n\tThanks see you !" <<endl;
            main();
            break;
       default:
           break;
       }

    return 0;
} 