/*********************************************************************************************
 *
 * [Author]: Zourkalaini BOUBAKAR (CCI, 2021)
 * [Date]: Sat Feb 20, 2021 
 * [Gaol]: Searching Encapsulation (mother program, Program.cpp)
 * [Version]: 1.2 (last version)
 * 
 * *******************************************************************************************/

#include <iostream> 
#include <cstdlib>

int main();
using namespace std;


/************************************************************************************************
  The home menu of the program
 * *********************************************************************************************/
int homeSearch()
{
    int choice;
    cout << "\n\t\t\t\t\t\t\t\t ===================================" <<endl;
    cout << "\n\t\t\t\t\t\t\t\t SEARCHING MANAGEMENT PROGRAM " <<endl;
    cout << "\n\t\t\t\t\t\t\t\t ====================================" <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 1- Sequential search " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 2- Binary Search " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 3- Exit the program " <<endl;

    do//for choice control
    {
        cout << "\n\n\t Choose to continue... " <<endl;
        cin >> choice;

    } while ((choice < 1 ) || (choice > 3));
    
    return choice;
}

/************************************************************************************************
  Sequential search function
 * *********************************************************************************************/
void SequentialSearch()
{
    //exemple of data set
    int dataSet[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43};
    int dataSetSize = sizeof(dataSet)/sizeof(dataSet[0]);//size of the data set
    int element;
    bool found = false;
    
    cout << "Enter the value of the element you are looking for: ";
    cin >> element;
    cout <<endl;


    for (int i = 0; i < dataSetSize; i++)
    {
        if (dataSet[i] == element)
        {
            cout << "Found!\t Value: "<< element <<"\t Position: "<< i + 1<<endl;
            found = true;
            break;
        }
        
    }
    if (!found)
    {
        cout <<"Oups! the element: " << element <<" was not found"<< endl; 
        cout << "\n\n\t Default Data Set: ";
            for (int i = 0; i < dataSetSize; i++)
            {
                cout << " " << dataSet[i] ;
            }
    }
    
    
}

/************************************************************************************************
  Binary search function 
 * *********************************************************************************************/

void BinarySearch()
{
    //exemple of data set
    int dataSet[] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43};
    int dataSize = sizeof(dataSet)/sizeof(dataSet[0]);
    int first = 0;
    int last = dataSize;
    int midle;
    int element;
    bool found = false;

    cout << "Enter the value of the element you are looking for: ";
    cin >> element;
    cout <<endl;

    while ((first <= last) && !found)
    {
        midle = (first + last)/2;
        if (element > dataSet[midle])
        {
            first = midle + 1;
        }
        else if (element < dataSet[midle])
        {
            last = midle -1;
        }
        else
        {
            cout << "Found!\t Value: "<< element <<"\t Position: "<< midle + 1<<endl;
            found = true;
            

        }
           
    }
    if (!found)
    {
        cout <<"Oups! the element: " << element <<" was not found"<< endl;
        cout << "\n\n\t Default Data Set: ";
            for (int i = 0; i < dataSize; i++)
            {
                cout << " " << dataSet[i] ;
            }
    }
}



/************************************************************************************************
  main of the program
 * *********************************************************************************************/
int MainSearching ()
{

     int choice = homeSearch();

    switch (choice)
    {
        case 1:
            SequentialSearch();
            MainSearching();
            break;
        case 2:
            BinarySearch();
            MainSearching();
            break;
        case 3:
            main();
            break;
       default:
           break;
       }
    return 0;
}