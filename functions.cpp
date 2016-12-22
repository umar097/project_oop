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

void BinTree::enter(Book p)//to enter the datas for book in form of trees
{
    tree_node* t = new tree_node;
    tree_node* parent;
    t->data = p;
    t->left = NULL;
    t->right = NULL;
    parent = NULL;
  
    if(isEmpty()) 
		root = t;
    else
    {
        tree_node* curr;
        curr = root;
        // to get node parent
        while(curr!=NULL)
        {
            parent = curr;
            if(t->data.getName() > curr->data.getName()) 
				curr = curr->right;
            else 
				curr = curr->left;
        }

        if(t->data.getName() < parent->data.getName())
           parent->left = t;
        else
           parent->right = t;
    }
}

void BinTree::remove(string _name) //removing a book
{
		//insertions are as leaf nodes
		tree_node* curr, *parent;
		curr = root;
		// to get node parent
		while (curr != NULL)
		{
			if (curr->data.getName() == _name)
			{
				curr->data.setName("not_found"); // now book is not available
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
