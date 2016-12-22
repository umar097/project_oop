#include<iostream>
#include"books.h"
#include<string>
using namespace std;

Book::Book(string autho, int isbn, string bookname)
{
	bookname = name;
	autho = Author;
	isbn = ISBN;
}
string Book::getName()
{
	return name;
}
string Book::getauthor()
{
	return Author;
}
int Book::getisbn()
{
	return ISBN;
}

void BinTree::enter(Book p)
{
    tree_node* b= new tree_node;
    tree_node* parent;
    b->data = p;
    b->left = NULL;
    b->right = NULL;
    parent = NULL;
  
    if(isEmpty()) 
		root = b;
    else
    {
        tree_node* curr;
        curr = root;
        // to get node parent
        while(curr!=NULL)
        {
            parent = curr;
            if(b->data.getName() > curr->data.getName()) 
				curr = curr->right;
            else 
				curr = curr->left;
        }

        if(b->data.getName() < parent->data.getName())
           parent->left = b;
        else
           parent->right = b;
    }
}

void BinTree::remove(string _name)
{
		tree_node* curr, *parent;
		curr = root;
		// to get node parent
		while (curr != NULL)
		{
			if (curr->data.getName() == _name)
			{
				curr->data.setName("issued");// now book is not available
				// operation
				break;
			}
			else
			{
				parent = curr;
				if (_name > curr->data.getName())
					curr = curr->right;
				else
					curr = curr->left;
				//the part for deletion and removal of the links still in progress.
			}
		}
}
void BinTree::search(string _name, int _isbn, string _author)
{
	tree_node* curr;
	tree_node* parent;
	curr = root;
	while (curr != NULL)
	{
		if (curr->data.getName() == _name || curr->data.getisbn()== _isbn|| curr->data.getauthor()==_author)
		{
			
			// operation
			break;
		}
		else
		{
			parent = curr;
			if (curr->data.getName()< _name || curr->data.getisbn() < _isbn || curr->data.getauthor() < _author) 
			curr = curr->right;
			else 
			curr = curr->left;
		}
	}
}
