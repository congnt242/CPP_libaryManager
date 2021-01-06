#ifndef CONTROLLER_H
#define CONTROLLER_H
#include"librarymanagement.h"
/**
 * @brief The Controller class
 * Obj controller controlls operation of library management system
 * Controlls menu, adds, views book, deletes book, modifies information of book
 */
class Controller
{
    LibraryManagement myLibrary;
public:
    Controller();
    void RunSystem();
    char getUserSelectInput(char& select);
    void addNewBookToLib();
    unsigned int getInputId();
};

#endif // CONTROLLER_H
