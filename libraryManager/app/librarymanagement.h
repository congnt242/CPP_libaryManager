#ifndef LIBRARYMANAGEMENT_H
#define LIBRARYMANAGEMENT_H
#include"book.h"
#include<iostream>
#include<list>
class LibraryManagement
{
    std::list<Book> bookList;
    std::list<Book>::iterator iterator;
public:
    LibraryManagement();
    void viewListOfBook();
    void addBookToLib(Book &);
    void removeBookFromLib(Book*);
    void updateBookInfo(unsigned int id);
    Book* findBookViaId(unsigned int id);
    friend std::ostream& operator<<(std::ostream &os,const Book& currentBook);
};

#endif // LIBRARYMANAGEMENT_H
