#ifndef BOOK_H
#define BOOK_H
#include<string>
/**
 * @brief The Book class
 * define atributes of book in library
 *
 */
class Book
{
private:
    std::string m_name; //book name
    unsigned int m_id; //book id
    unsigned int m_position; //position of book in library
    unsigned int m_amount; // number of books in library, assume library has less than 255 book
public:
    Book(std::string name = "new book", unsigned int pos = 0, unsigned int amount = 0);
    void changeBookName(std::string newName);
    void changeBookId(unsigned int newId);
    void changeBookPosition(unsigned int newPosition);
    void changeBookAmount(unsigned int newAmount);
    void decreaseIdAfterDelete();

    std::string getBookName();
    unsigned int getBookId();
    unsigned int getBookPosition();
    unsigned int getBookAmount();
};

#endif // BOOK_H
