#include <iostream>

using namespace std;

struct tbtnode
{
    int data, lb, rb;
    tbtnode *left, *right;
};

class tbtree
{
public:
    tbtnode *head, *root;
    tbtree()
    {
        head = NULL;
        root = NULL;
    }
    void create();
    void insert(tbtnode *, tbtnode *);
    void preorder(tbtnode *);
};

void tbtree::create()
{
    int n;
    tbtnode *temp;
    if (head == NULL)
    {
        head = new tbtnode;
        head->data = 9999;
        head->left = head;
        head->right = head;
        head->lb = head->rb = 0;
    }
    cout << "enter no of nodes";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        temp = new tbtnode;
        cout << "enter data ";
        cin >> temp->data;
        temp->lb = temp->rb = 0;
        temp->left = temp->right = NULL;
        if (root == NULL)
        {
            root = temp;
            root->left = root->right = head;
            root->lb = root->rb = 0;
            head->left = root;
            head->lb = 1;
        }
        else
        {
            insert(temp, root);
        }
    }
}

void tbtree::insert(tbtnode *temp, tbtnode *r)
{
    if (temp->data < r->data)
    {
        if (r->lb == 0)
        {
            temp->left = r->left;
            r->left = temp;
            temp->right = r;
            r->lb = 1;
        }
        else
        {
            insert(temp, r->left);
        }
    }
    else
    {
        if (r->rb == 0)
        {
            temp->right = r->right;
            r->right = temp;
            temp->left = r;
            r->rb = 1;
        }
        else
        {
            insert(temp, r->right);
        }
    }
}
void tbtree::preorder(tbtnode *t)
{
    if (t != NULL)
    {
        while (t != head)
        {
            cout << "---->" << t->data;
            if (t->lb == 1)
            {
                t = t->left;
            }
            else
            {
                if (t->rb == 1)
                {
                    t = t->right;
                }
                else
                {
                    while (t->rb == 0)
                    {
                        if (t != head)
                        {
                            t = t->right;
                        }
                        else
                        {
                            break;
                        }
                    }
                    t = t->right;
                }
            }
        }
    }
}
int main()
{
    tbtree t1;
    t1.create();
    cout << "\n Preorder is======>";
    t1.preorder(t1.root);
}