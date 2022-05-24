#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct BSTnode
{
    int data;
    BSTnode *left, *right;
};

class BST
{

    BSTnode *root;

public:
    BST() { root = NULL; }
    void create();
    void display();
    void operations();
};

void insert(BSTnode *root_new, BSTnode *temp)
{
    if (temp->data >= root_new->data)
    {
        if (root_new->right == NULL)
        {
            root_new->right = temp;
        }
        else
        {
            insert(root_new->right, temp);
        }
    }

    else
    {
        if (root_new->left == NULL)
        {
            root_new->left = temp;
        }
        else
        {
            insert(root_new->left, temp);
        }
    }
}

void pre_ord(BSTnode *root)
{
    if (root != NULL)
    {
        cout << root->data << endl;
        pre_ord(root->left);
        pre_ord(root->right);
    }
}
void in_ord(BSTnode *root)
{
    if (root != NULL)
    {
        pre_ord(root->left);
        cout << root->data << endl;
        pre_ord(root->right);
    }
}
void post_ord(BSTnode *root)
{
    if (root != NULL)
    {
        pre_ord(root->left);
        pre_ord(root->right);
        cout << root->data << endl;
    }
}

int find_min(BSTnode *root)
{
    while (root->left != NULL)
    {
        root = root->left;
    }
    return (root->data);
}

int find_max(BSTnode *root)
{
    while (root->right != NULL)
    {
        root = root->right;
    }
    return (root->data);
}

int height(BSTnode *root)
{
    int lh, rh;
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 0;
    }
    lh = height(root->left);
    rh = height(root->right);
    if (lh > rh)
    {
        return (1 + lh);
    }
    else
    {
        return (1 + rh);
    }
}

BSTnode *copy(BSTnode *root)
{
    BSTnode *temp;
    if (root != NULL)
    {
        temp = new BSTnode;
        temp->data = root->data;
        temp->right = copy(root->right);
        temp->left = copy(root->left);
        return temp;
    }
    return NULL;
}

BSTnode *mirror(BSTnode *root)
{
    BSTnode *temp;
    if (root != NULL)
    {
        temp = new BSTnode;
        temp->data = root->data;
        temp->right = mirror(root->left);
        temp->left = mirror(root->right);
        return temp;
    }
    return NULL;
}

int count_leaf(BSTnode *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    else
    {
        return (count_leaf(root->left) + count_leaf(root->right));
    }
}

void BST ::create()
{
    BSTnode *temp;
    temp = new BSTnode;
    cout << "Enter Value : ";
    cin >> temp->data;
    temp->left = temp->right = NULL;

    if (root == NULL)
    {
        root = temp;
    }
    else
    {
        insert(root, temp);
    }
}

void BST ::display()
{
    cout << "Enter P : Pre-order " << endl;
    cout << "Enter X :  Post-order " << endl;
    cout << "Enter I : In-order " << endl;
    char choice;
    cin >> choice;
    switch (choice)
    {
    case 'P':
        pre_ord(root);
        break;
    case 'X':
        post_ord(root);
        break;
    case 'I':
        in_ord(root);
        break;
    default:
        cout << "WRONG CHOICE" << endl;
        break;
    }
}

void BST::operations()
{
    int choice;
    cout << "\nOperations : \n\t1.Minimum\n\t2.Maximum\n\t3.Height\n\t4.Copy\n\t5.Mirror\n\t6.Leaf Node\nChoice : ";
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "\nMin = " << find_min(root);
        break;

    case 2:
        cout << "\nMax = " << find_max(root);
        break;

    case 3:
        cout << "\nHeight = " << height(root);
        break;

    case 4:
        cout << "\n(Pre-Order) Is " << endl;
        pre_ord(root);
        cout << "\nCopy(Pre-Order) is " << endl;
        pre_ord(copy(root));
        break;

    case 5:
        cout << "\n(Pre-Order) Is " << endl;
        pre_ord(root);
        cout << "\nMirror(Pre-Order) Is " << endl;
        pre_ord(mirror(root));
        break;

    case 6:
        cout << "\nNo Of Leaf Nodes = " << count_leaf(root);
        break;

    default:
        cout << "Wrong Choice";
        break;
    }
}

int main()
{
    BST ins;
    int choice;
    system("cls");
    system("color 0c");
    cout << "1.Create\n2.Display\n3.Operations\n0.Exit" << endl;

    do
    {
        cout << "\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            exit(1);
            break;
        case 1:
            ins.create();
            break;
        case 2:
            ins.display();
            break;
        case 3:
            ins.operations();
            break;
        default:
            break;
        }
    } while (choice < 3);
    return 0;
    // getch();
}