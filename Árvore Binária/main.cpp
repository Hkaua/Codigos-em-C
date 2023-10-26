#include <queue>
#include <iostream>

using namespace std;

struct node
{
  struct node *left, *right;

  int key;
};

node *
nexRight (node * root, int K)
{
  if (root == NULL)
    return 0;

  queue < node * >qn;
  queue < int >ql;
  int level = 0;

  qn.push (root);
  ql.push (level);

  while (qn.size ())

    {
      node *node = qn.front ();
      level = ql.front ();
      qn.pop ();
      ql.pop ();

      if (node->key == K)
	{

	  if (ql.size () == 0 || ql.front () != level)
	    return NULL;
	  return qn.front ();
	}

      if (node->left != NULL)
	{
	  qn.push (node->left);
	  ql.push (level + 1);
	}
      if (node->right != NULL)
	{
	  qn.push (node->right);
	  ql.push (level + 1);

	}
    }

  return NULL;

}

node *
newNode (int key)
{
  node *temp = new node;
  temp->key = key;
  temp->left = temp->right = NULL;
  return temp;
}

void
test (node * root, int k)
{
  node *nr = nexRight (root, k);
  if (nr != NULL)
    cout << "Next right of " << k << "is" << nr->key << endl;
  else
    cout << "No next right node found for" << k << endl;

}

int
main ()
{

  node *root = newNode (10);
  root->left = newNode (2);
  root->right = newNode (6);
  root->right->right = newNode (5);
  root->left->left = newNode (8);
  root->left->right = newNode (4);
  test (root, 10);
  test (root, 2);
  test (root, 6);
  test (root, 5);
  test (root, 8);
  test (root, 4);
  return 0;

}
