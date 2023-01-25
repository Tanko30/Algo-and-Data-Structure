/*********************************************************************************************
 *
 * [Author]: Zourkalaini BOUBAKAR (CCI, 2021)
 * [Date]: Sat Feb 20, 2021 
 * [Gaol]: Sorting Encapsulation (mother program, Program.cpp)
 * [Version]: 1.3 (last version)
 * 
 * *******************************************************************************************/


#include <iostream> 
#include <cstdlib>
#include <ctime>

int main();
using namespace std;

/************************************************************************************************
  The home menu of the program (1)
 * *********************************************************************************************/
int homeSort()
{
    int choice;
    cout << "\n\t\t\t\t\t\t\t\t ===================================" <<endl;
    cout << "\n\t\t\t\t\t\t\t\t SORTING MANAGEMENT PROGRAM " <<endl;
    cout << "\n\t\t\t\t\t\t\t\t ====================================" <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 1- Selection sort " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 2- Merge sort " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 3- Exit the program " <<endl;

    do//for choice control
    {
        cout << "\n\n\t Choose to continue... " <<endl;
        cin >> choice;

    } while ((choice < 1 ) || (choice > 3));
    
    return choice;
}

/************************************************************************************************
  Select sorting function (A)
 * *********************************************************************************************/
void SelectSort()
{
    int choice; //the size of the input
    int min;
    int temp;//tempo variable for swaping
    do
    {
        cout << "Enter the size of input, at least two (02)" <<endl;
        cin >> choice;
    } while (choice < 2);
    int input[choice] = {0};
    for (int i = 0; i < choice ; i++) //input reading
    {
        cout << "Item["<< i+1 << "] :";
        cin >> input[i];
        cout <<endl;
        
    }
    //sorting
    for (int i = 0; i < choice-1 ; i++)
    {
        min = i;
        for (int j = i+1; j < choice ; j++)
        {
            if (input[j] < input[min])
            {
                min = j;
            }
        }
        //swapping
        temp = input[i];
        input[i] = input[min];
        input[min] = temp;

        
    }
    //result displaying
    cout << "\n\n\t Output: ";
    for (int i = 0; i < choice; i++)
    {
        cout << " " << input[i] ;
    }

    cout << "\n\n Thanks see you !"<<endl;

}

/************************************************************************************************
  Merge function (B-2)
 * *********************************************************************************************/
void merge(int A[], int B[], int C[], int size, int left, int right)
{

    
    
    int i=0, j=0, k=0 ;


    //merging
    while (i<left && j<right)
    {
        if (B[i] <= C[j])
        {
            A[k] = B[i];
            i = i +1;
        }else
        {
            A[k] = C[j];
            j = j+1;
        }
        k = k + 1;
        
    }
    //copy of the remain items, if any
    if (i >= left)
    {
        while (j < right)
        {
            A[k] = C[j];
            j++;
            k++;
        }
        
    }
    else
    {
        while (i < left)
        {
            A[k] = B[i];
            i++;
            k++;
        }
        
    }
    
}


/************************************************************************************************
  MergeSort function (B-1)
 * *********************************************************************************************/
void mergeSort(int A[], int size)
{
    if (size > 1) //condition to quit recursivity
    {
        int left = size/2;
        int right = size - left;
        int L[left], R[right];
        // Input data spliting into two subinput data (left and right part)
        for (int i = 0; i < left; i++)  L[i] = A[i];
        for (int j = 0; j < right; j++) R[j] = A[left+j];
        mergeSort(L, left);
        mergeSort(R, right);
        merge(A, L, R, size, left, right); //call to merge fucntion
    }
    
}



/************************************************************************************************
  Merge sorting function (B)
 * *********************************************************************************************/
 void MergeSorting()
 {
    int size; //the size of the input
    do
    {
        cout << "Enter the size of your table, at least two (02)" <<endl;
        cin >> size;
    } while (size < 2);
    int input[size];
    for (int i = 0; i < size ; i++) //input reading
    {
        cout << "Item["<< i+1 << "] :";
        cin >> input[i];
        cout <<endl;
    }
    mergeSort(input, size);//call to mergeSort function by giving input data 
    cout << "\n\t Output: ";
    for (int i = 0; i < size; i++)
    {
        cout << " " << input[i] ;
    }

    cout << "\n\n Thanks see you !"<<endl;

 }


/************************************************************************************************
  The main of the program (2)
 * *********************************************************************************************/
void MainSorting()
{
     int choice = homeSort();

    switch (choice)
    {
        case 1:
            SelectSort(); //function A
            MainSorting();
            break;
        case 2:
            MergeSorting();//function B
            MainSorting();
            break;
        case 3:
            main();
            break;
       default:
           break;
       }
}
