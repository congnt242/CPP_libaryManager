#include "book.h"


Book::Book(std::string name, unsigned int pos, unsigned int amount)
{
    m_name = name;
    m_position = pos;
    m_amount = amount;
}


void Book::changeBookName(std::string newName)
{
    m_name = newName;
}

void Book::changeBookPosition(unsigned int newPosition)
{
    m_position = newPosition;
}

void Book::changeBookAmount(unsigned int newAmount)
{
    m_amount = newAmount;
}

std::string Book::getBookName()
{
    return m_name;
}

unsigned int Book::getBookId()
{
    return m_id;
}

unsigned int Book::getBookPosition()
{
    return m_position;
}

unsigned int Book::getBookAmount()
{
    return m_amount;
}

void Book::decreaseIdAfterDelete()
{
    m_id-=1;
}

void Book::changeBookId(unsigned int newId)
{
    m_id = newId;
}
