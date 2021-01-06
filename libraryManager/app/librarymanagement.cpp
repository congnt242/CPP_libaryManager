#include "librarymanagement.h"

/**
 * @brief operator <<
 * @param os
 * @param it
 * show single book information
 * @return os
 */
std::ostream& operator<<(std::ostream &os,std::list<Book>::iterator it )
{
    os<<it->getBookId()<<"*|*"<<it->getBookName()<<"*|*"<<it->getBookPosition()
     <<"*|*" <<it->getBookAmount()<<"*|\n";
    return os;
}

/**
 * @brief LibraryManagement::addBookToLib
 * @param newBook
 * add a new book to library
 */
void LibraryManagement::addBookToLib(Book &newBook)
{
    unsigned int temp = 0;
    temp = bookList.size() + 1;
    newBook.changeBookId(temp);
    bookList.push_back(newBook);
}

/**
 * @brief LibraryManagement::removeBookFromLib
 * @param currentBook
 * remove a book from library via book object address. Get address via findBookViaId(unsigned int id)
 */
void LibraryManagement::removeBookFromLib(Book *currentBook)
{
    iterator = bookList.begin();
    unsigned int tempId = currentBook->getBookId();
    for (unsigned int i = 1; i < tempId; i++)
    {
        iterator++;
    }
    bookList.erase(iterator);
    iterator = bookList.end();
    for (unsigned int i = bookList.size()+1; i >= tempId; i--)
    {
        iterator->decreaseIdAfterDelete();
        iterator--;
    }
}

/**
 * @brief LibraryManagement::viewListOfBook
 * show all book in library
 */
void LibraryManagement::viewListOfBook()
{
    std::cout<<"*************************Books in library:**************************\n";
    std::cout<<"*******************id|name|position|amount**************************\n";
    iterator = bookList.begin();
    while(iterator != bookList.end())
    {
        std::cout<<iterator;
        iterator++;
    }
}

/**
 * @brief LibraryManagement::findBookViaId
 * @param id
 * @return book obj address in library inorder to delete that book
 */
Book* LibraryManagement::findBookViaId(unsigned int id)
{
    iterator = bookList.begin();
    while(iterator->getBookId() != id)
    {
        iterator++;
    }
    return &(*iterator);
}

/**
 * @brief LibraryManagement::updateBookInfo
 * @param id
 * modify each field of book
 * cannot modify multifield in once
 */
void LibraryManagement::updateBookInfo(unsigned int id)
{
    char select = '0';
    std::string tempName = "unchange";
    unsigned int temp = 0;
    iterator = bookList.begin();
    while(iterator->getBookId() != id)
    {
        iterator++;
    }
    do{
        std::cout<<"\n Which field do you want to update?Name(n)/Position(p)/Amount(a)?n/p/a:";
        std::cin>>select;
    }while((select!='a')&&(select!='n')&& (select!='p') );

    std::cin.ignore();
    switch(select)
    {
    case 'n':
        std::cout<<"\n Enter new name of book: ";
        std::getline(std::cin,tempName);
        iterator->changeBookName(tempName);
        break;
    case 'p':
        std::cout<<"\n Enter new position of book: ";
        std::cin>>temp;
        iterator->changeBookPosition(temp);
        break;
    case 'a':
        std::cout<<"\n Enter new amount of book: ";
        std::cin>>temp;
        iterator->changeBookAmount(temp);
        break;
    default:
        std::cout<<"You don't make a right selection";
        break;
    }
}
