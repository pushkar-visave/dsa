#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct avlnode
{
    string word;
    string mean;
    avlnode *left, *right;
};

class avl
{

public:
    avl()
    {
        root = NULL;
    }
    avlnode *root;
    avlnode *insert(avlnode *, string, string);
    int bal_fact(avlnode *);
    int height(avlnode *);
    avlnode *ll(avlnode *);
    avlnode *rr(avlnode *);
    avlnode *lr(avlnode *);
    avlnode *rl(avlnode *);
    void search(avlnode *, string);
    void display(avlnode *);
};

// Height
int avl::height(avlnode *t)
{
    int lh, rh;
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        // Left Height
        if (t->left == NULL)
        {
            lh = 0;
        }
        else
        {
            lh = 1 + height(t->left);
        }

        // Right Height
        if (t->right == NULL)
        {
            rh = 0;
        }
        else
        {
            rh = 1 + height(t->right);
        }

        if (lh > rh)
            return (lh);
        return (rh);
    }
}

// Balance Factor
int avl::bal_fact(avlnode *t)
{
    int lh, rh;
    // Left
    if (t->left == NULL)
    {
        lh = 0;
    }
    else
    {
        lh = 1 + height(t->left);
    }
    // Right
    if (t->right == NULL)
    {
        rh = 0;
    }
    else
    {
        rh = 1 + height(t->right);
    }
    return lh + rh;
}

// Rotations
avlnode *avl::ll(avlnode *t)
{
    avlnode *x;
    x = t->left;
    t->left = x->right;
    x->right = t;
    return x;
}
avlnode *avl::rr(avlnode *t)
{
    avlnode *x;
    x = t->right;
    t->right = x->left;
    x->left = t;
    return x;
}
avlnode *avl::lr(avlnode *t)
{
    t->left = rr(t->right);
    t = ll(t);
    return t;
}
avlnode *avl::rl(avlnode *t)
{
    t->right = ll(t->left);
    t = rr(t);
    return t;
}

// Insert
avlnode *avl::insert(avlnode *t, string w, string m)
{
    if (t == NULL)
    {
        t = new avlnode;
        t->word = w;
        t->mean = m;
        t->left = t->right = NULL;
    }

    else
    {
        // Left Sub-Tree
        if (w < t->word)
        {
            t->left = insert(t->left, w, m);
            if (bal_fact(t) == 2)
            {
                if (w < t->left->word)
                {
                    t = ll(t);
                }
                else
                {
                    t = lr(t);
                }
            }
        }

        // Right Sub-Tree
        else
        {
            t->right = insert(t->right, w, m);
            if (bal_fact(t) == -2)
            {
                if (w < t->right->word)
                {
                    t = rr(t);
                }
                else
                {
                    t = rl(t);
                }
            }
        }
    }
    return (t);
}

// Display
void avl::display(avlnode *t)
{
    if (t != NULL)
    {
        cout << "\nWord = " << t->word << "\tMean = " << t->mean;
        display(t->left);
        display(t->right);
    }
}

// Search Word
void avl::search(avlnode *t, string w)
{
    if (t == NULL)
    {
        cout << "Element No Found";
    }
    else
    {
        if (w < t->word)
            search(t->left, w);
        else if (w > t->word)
            search(t->right, w);
        else
            cout << "\nWord = " << t << "\tMeaning = " << w;
    }
}

// Main
int main()
{
    avl a1;
    string w, m;
    int choice;
    system("cls");
    cout << "\n0.Exit\n1.Insert Node\n2.Display\n3.Search Word\n--------------";
    do
    {
        cout << "\nEnter Choice : ";
        cin >> choice;
        switch (choice)
        {
        case 0:
            exit(0);
            break;
        case 1:
            cout << "Enter New Word & Meaning : ";
            cin >> w >> m;
            a1.root = a1.insert(a1.root, w, m);
            break;
        case 2:
            a1.display(a1.root);
            break;
        case 3:
            cout << "\nEnter Word To Search : ";
            cin >> w;
            a1.search(a1.root, w);
            break;
        default:
            cout << "Error";
        }

    } while (choice < 4);
    return 0;
}