#include <iostream>
#include "lab07_library.hpp"

using namespace std;

Library::Library () : books ()
{
}

Library::Library (vector<Book> new_book) : books (new_book)
{
}

void Library::print ()
{
    for (int i = 0; i < books.size(); i++)
    {
       cout << "Book Index: " << i << endl;
       books[i].print();
    }
}

bool Library::insert_book (string new_title, string new_authors, string new_dop)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (new_title == books[i].get_title() && new_authors == books[i].get_authors()
                && new_dop == books[i].get_dop())
            return false;
    }
    
    Book add_book (new_title, new_authors, new_dop);
    
    books.push_back(add_book);
    
    return true;
    
}

bool Library::insert_book (Book new_book)
{
    for (int i = 0; i < books.size(); i++)
    {
        if (new_book.get_title() == books[i].get_title()
            && new_book.get_authors() == books[i].get_authors()
            && new_book.get_dop() == books[i].get_dop())
            return false;
    }
    
    books.push_back (new_book);
    
    return true;
}

bool Library::remove_book (string cur_title, string cur_authors, string cur_dop)
{
    
    for (int i = 0; i < books.size(); i++)
    {
        if (cur_title == books[i].get_title() && cur_authors == books[i].get_authors()
            && cur_dop == books[i].get_dop())
        {
            books.erase (books.begin () + i);
            return true;
        }
        
    }
    
    
    return false;
}

bool Library::remove_book (Book cur_book)
{
    
    for (int i = 0; i < books.size(); i++)
    {
        if (cur_book.get_title() == books[i].get_title()
            && cur_book.get_authors() == books[i].get_authors()
            && cur_book.get_dop() == books[i].get_dop())
        {
            books.erase (books.begin () + i);
            return true;
        }
        
    }
    
    
    return false;
}
