#include <bits/stdc++.h>
using namespace std;

 
#define MAX 50
  
struct Node
{
  
char data;
   
unsigned isEndOfstring = 0;	// Inicializado como 0 em vez de 1
  Node *left, *eq, *right;
 
};

 
Node * newNode (char data)
{
  
Node * temp = new Node ();
  
temp->data = data;
  
temp->isEndOfstring = 0;
  
temp->left = temp->eq = temp->right = NULL;
  
return temp;

}


 
void
insert (Node ** root, char *word)
{
  
if (!(*root))		// Corrigido o operador de negaC'C#o
    *root = newNode (*word);
  
 
if (*word < (*root)->data)
    
insert (&((*root)->left), word);
  
  else
    {
      
if (*(word + 1))
	
insert (&((*root)->eq), word + 1);	// Corrigido "ep" para "eq"
      else
	
(*root)->isEndOfstring = 1;
    
}

}


 
void
traverseTSTUtil (Node * root, char *buffer, int depth)
{				// Corrigido os parC"metros
  if (root)
    {
      
traverseTSTUtil (root->left, buffer, depth);
      
buffer[depth] = root->data;	// Corrigido para atribuiC'C#o C:nica =
      if (root->isEndOfstring)
	{
	  
buffer[depth + 1] = '\0';	// Corrigido para '\0'
	  cout << buffer << endl;
	
}
      
traverseTSTUtil (root->eq, buffer, depth + 1);	// Corrigido "ep" para "eq"
      traverseTSTUtil (root->right, buffer, depth);	// Corrigido o parC"metro
    }

}


 
void
traverseTST (Node * root)
{
  
char buffer[MAX];
  
traverseTSTUtil (root, buffer, 0);

} 
 
int

search (Node * root, char *word)
{				// Corrigido o nome da funC'C#o
  if (!root)
    
return 0;
  
 
if (*word < (root)->data)
    
return search (root->left, word);	// Corrigido o nome da funC'C#o
  else if (*word > (root)->data)
    
return search (root->right, word);	// Corrigido o nome da funC'C#o
  else
    {
      
if (*(word + 1) == '\0')
	
return root->isEndOfstring;
      
 
return search (root->eq, word + 1);	// Corrigido "ep" para "eq" e o nome da funC'C#o
    }

}


 
int
main ()
{
  
Node * root = NULL;
  
char cat[] = "cat";
  
char cats[] = "cats";
  
char up[] = "up";
  
char bug[] = "bug";
  
char bu[] = "bu";
  
insert (&root, cat);
  
insert (&root, cats);
  
insert (&root, up);
  
insert (&root, bug);
  
 
cout << "Following is traversal of ternary search tree\n";
  
traverseTST (root);
  
cout <<
    "\nFollowing are search results for cats, bu and cat repetitively\n";
  
search (root, cats) ? cout << "Found" : cout << "Not Found";
  
search (root, bu) ? cout << "Found" : cout << "Not Found";
  
search (root, cat) ? cout << "Found" : cout << "Not Found";
  
 
return 0;

}
