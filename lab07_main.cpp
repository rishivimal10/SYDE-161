//
//  main.cpp
//  lab_07
//
//  Created by Rishi Vimalendran on 2019-11-19.
//  Copyright © 2019 Rishi Vimalendran. All rights reserved.
//

#include <iostream>
#include "lab07_book.cpp"
#include "lab07_library.cpp"


void test_book_output (Book book1, Book book2, Book book3, Book book4)
{
    
    book1.print();
    book2.print();
    book3.print();
    book4.print();
}

void test_insertion (Book book5, Library& my_library)
{
    
    if (my_library.insert_book("The Alchemist", "Paulo Coelho", "1988"))
        cout << "insertion successful!" << endl;
    
    
    if (my_library.insert_book(book5))
        cout << "insertion successful!" << endl;
    
    my_library.print();
    
}

void test_removal (Library& my_library, Book book1)
{
    if (my_library.remove_book(book1))
        cout << "removal successful" << endl;
    
    if (my_library.remove_book("1984", "George Orwell", "n/a"))
        cout << "removal successful" << endl;
    
    if (!my_library.remove_book("Animal Farm", "George Orwell", "n/a"))
        cout << "removal not successful" << endl;
    
    my_library.print();
    
}


int main()
{
    Book book1 ("The God of Small Things", "Arundhati Roy");
    Book book2 ("To Kill a Mockingbird", "Harper Lee", "1960");
    Book book3 ("The Great Gatsby");
    Book book4;
    Book book5 ("1984", "George Orwell");
    
    
    vector <Book> my_books = {book1, book2, book3};
    
    Library my_library (my_books);
    
    
    test_book_output(book1, book2, book3, book4);
    test_insertion(book5, my_library);
    test_removal(my_library, book1);
    
    
}
