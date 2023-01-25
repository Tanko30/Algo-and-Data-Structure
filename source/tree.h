/*********************************************************************************************
 *
 * [Author]: Zourkalaini BOUBAKAR (CCI, 2021)
 * [Date]: Sat Feb 20, 2021 
 * [Gaol]: Tree traversals Encapsulation (mother program, Program.cpp)
 * [Version]: 1.1 (last version)
 * 
 * *******************************************************************************************/

#include <iostream> 
#include <cstdlib>
#include <string>

int main();
using namespace std;

/***************************************************************************************************
         Data of the tree (a personnalise type): Record of family members (name and age)
 * *************************************************************************************************/
struct Data_t
{
    string name; 
    int age;
    Data_t *left;
    Data_t *right;
    Data_t(string name, int age)
    {
        this->name = name;
        this->age = age;
        this->left = NULL;
        this->right = NULL;
    };
    
};

/**********************************************************************************
    Preorder function
 **********************************************************************************/ 
void Preorder(Data_t *root)
{
    if (root == NULL) return;
    
    cout << "(" << root->name << ", " <<root->age << ") " <<endl;//print the data
    Preorder(root->left);//print the left subtree
    Preorder(root->right);//print the right subtree
    
}



/**********************************************************************************
    Inorder function
 **********************************************************************************/ 
void Inorder(Data_t *root)
{
    if (root == NULL) return;

    Inorder(root->left);//print the left subtree
    cout << "(" << root->name << ", " <<root->age << ") " <<endl;//print the data
    Inorder(root->right);//print the right subtree
    
}

/**********************************************************************************
    Postorder function
 **********************************************************************************/ 
void Postorder(Data_t *root)
{
    if (root == NULL) return;

    Postorder(root->left);//print left subtree
    Postorder(root->right);//print the right subtree
    cout << "(" << root->name << ", " <<root->age << ") " <<endl;//print the data    
}


/************************************************************************************************
  The home menu of the program
 * *********************************************************************************************/
int homeTree()
{
    int choice;
    cout << "\n\t\t\t\t\t\t\t\t ===================================" <<endl;
    cout << "\n\t\t\t\t\t\t\t\t TREE TRAVERSALS MANAGEMENT PROGRAM " <<endl;
    cout << "\n\t\t\t\t\t\t\t\t ====================================" <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 1- Preorder " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 2- Inorder " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 3- Postorder " <<endl;
    cout << "\n\n\t\t\t\t\t\t\t\t\t 4- Exit the program " <<endl;

    do//for choice control
    {
        cout << "\n\n\t Choose to continue... " <<endl;
        cin >>choice;

    } while ((choice < 1 ) || (choice > 4));
    
    return choice;
}



/************************************************************************************************
  main of the program
 * *********************************************************************************************/
int MainTree()
{

    //tree data set  (example of data set)
    Data_t *root = new Data_t("Ancestor [1]", 102);
    root->left = new Data_t("Grand Father [2]", 80); 
    root->right = new Data_t("Grand Mother [3]", 89); 
    root->left->left = new Data_t("Father[4]", 63); 
    root->left->right = new Data_t("Mother [5]", 52);
    root->left->right->left = new Data_t("Elder [6]", 45);
    root->left->right->right = new Data_t("Youngest [7]", 52);
    





     int choice = homeTree();

    switch (choice)
    {
        case 1:
            cout << "\t\t\tPreorder traversal: " <<endl;
            Preorder(root);
            MainTree();
            break;
        case 2:
            cout << "\t\t\tInorder traversal: " <<endl;
            Inorder(root);
            MainTree();
            break;
        case 3:
            cout << "\t\t\tPostorder traversal: " <<endl;
            Postorder(root);
            MainTree();
            break;
        case 4:
            main();
            break;
       default:
           break;
       }
    return 0;
}