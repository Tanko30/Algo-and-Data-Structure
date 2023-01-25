#include "stack.h"
#include "queue.h"
#include "sorting.h"
#include "searching.h"
#include "tree.h"
#include "graph.h"

int MainHome()
{
    int choice;
    cout << "\n\t\t\t\t\t\t\t\t ===================================" <<endl;
    cout << "\n\t\t\t\t\t\t\t\t WELCOME TO DATA STRUCTURE PROGRAM " <<endl;
    cout << "\n\t\t\t\t\t\t\t\t ====================================" <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 1: Stack " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 2: Queue " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 3: Sorting " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 4: Searching " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 5: Tree Traversals " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 6: Graph traversals " <<endl;



    do//for choice control
    {
        cout << "\n\n\t Choose to continue...Or quit with \"0\"" <<endl;
        cin >> choice;

    } while ((choice < 0 ) || (choice > 6));
    
    return choice;
}
int main() {
    int choice = MainHome();

    switch (choice)
    {
        case 0:
            cout <<"\n\t\t Thanks, see you!"<<endl;
            return 0;
            break;
        case 1:
            MainStack();
            break;
        case 2:
            MainQueue();
            break;
        case 3:
            MainSorting();
            break;
        case 4:
            MainSearching();
            break;
        case 5:
            MainTree();
            break;
        case 6:
            MainGraph();
            break;

       default:
           break;
       }

    return 0;
} 