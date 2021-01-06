#include "controller.h"
/**
 * @brief Controller::Controller
 * initialize library with some books in library
 */
Controller::Controller()
{
    Book a("Toan",1,1);
    Book b("Van", 2, 2);
    Book c("Vat Ly",3, 4);
    Book d("Hoa hoc", 10, 8);
    Book e("Lich su",3, 4);
    myLibrary.addBookToLib(a);
    myLibrary.addBookToLib(b);
    myLibrary.addBookToLib(c);
    myLibrary.addBookToLib(d);
    myLibrary.addBookToLib(e);
}
/**
 * @brief Controller::RunSystem
 * controll operation of libManager
 * show menu, select feature
 */
void Controller::RunSystem()
{
    char exitState = 1;
    while (exitState) {
        char checkValidInput = 1;
        /**
          @main memu
          */
        system("clear");
        std::cout<<"\n**********Library management system*********";
        std::cout<<"\n***View all book in library:             (1)";
        std::cout<<"\n***Add a book to library:                (2)";
        std::cout<<"\n***Remove a book from library:           (3)";
        std::cout<<"\n***Update a book information in library: (4)";
        std::cout<<"\n***Exit                                : (5)\n";

        while(checkValidInput){
            char select = getUserSelectInput(select);
            switch (select) {
            case '1':
            {
                checkValidInput = 0;
                myLibrary.viewListOfBook();
                std::cout<<"\nEnter any key to return menu!!!";
                std::cin>>select;
            }
                break;
            case '2':
            {
                checkValidInput = 0;
                addNewBookToLib();
                std::cout<<"\nEnter any key to return menu!!!";
                std::cin>>select;
            }
                break;
            case '3':
            {
                checkValidInput = 0;
                std::cout << "\nEnter book id you want to delete: ";
                unsigned int selectID = 0;
                std::cin >> selectID;
                myLibrary.removeBookFromLib(myLibrary.findBookViaId(selectID));
            }
                break;
            case '4':
            {
                checkValidInput = 0;
                std::cout << "\nEnter book id you want to modify: ";
                unsigned int selectID = 0;
                std::cin >> selectID;
                myLibrary.updateBookInfo(selectID);
                std::cout<<"\nEnter any key to return menu!!!";
                std::cin>>select;
            }
                break;
            case '5':
                exitState = 0;
                checkValidInput = 0;
                break;
            default:
                std::cout<<"\n You enter invalid selection, please select again!!!";
                checkValidInput = 1;
                break;
            }
        }
    }

}

/**
 * @brief Controller::getUserSelectInput
 * get input from keyboard
 * @param select
 * @return select
 */
char Controller::getUserSelectInput(char& select)
{
    std::cout<<"\nPlease enter your choise: ";
    std::cin>>select;
    return select;
}

/**
 * @brief Controller::addNewBookToLib
 * add new book to library
 */
void Controller::addNewBookToLib()
{
    std::string name = "n";
    unsigned int pos = 0;
    unsigned int amount = 0;
    std::cout << "\n*****New book*******";
    std::cout << "\n Enter book name: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "\n Enter book position in library: ";
    std::cin >> pos;

    std::cout << "\n Enter amount of books in library: ";
    std::cin >> amount;
    Book newBook(name, pos, amount);
    myLibrary.addBookToLib(newBook);

}
