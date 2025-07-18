#include <iostream>
#include <map>

// void addContact(std::map<std::string, std::string>& map, std::pair<std::string, std::string> newContact)
// {
// 
// }

// void searchContact(std::map<std::string, std::string>& map, std::string)
// {

// }

int main()
{
    std::map<std::string, std::string> agenda;
    bool isTerminated = false;
    while (!isTerminated) {
        int option;
        std::cout << "MENU: " << std::endl;
        std::cout << "[1] -> agregar contacto. " << std::endl;
        std::cout << "[2] -> buscar contacto. " << std::endl;
        std::cout << "[3] -> eliminar contacto. " << std::endl;
        std::cout << "[4] -> mostrar contactos. " << std::endl;
        std::cout << "[5] -> salir del programa. " << std::endl;
        std::cout << "Ingrese una opción: ";
        std::cin >> option;

        switch (option) {
            case 1: {
                std::string name;
                std::string phone_number;
                std::cout << "Ingrese el nombre del contacto: ";
                std::cin >> name;
                std::cout << "Ingrese el telefono del contacto: ";
                std::cin >> phone_number;

                std::cout << name << " : " << phone_number << std::endl;
                try {
                    agenda.insert({name, phone_number});
                    std::cout << "{ " << name << " : " << phone_number << " } | Successfully inserted."<< std::endl;
                } catch (std::exception e) {
                    throw e;
                }
            } break;
            case 2: {
                std::string name;
                std::cout << "Ingrese el nombre a buscar: ";
                std::cin >> name;

                if (agenda.count(name)) {
                    std::string phone = agenda[name];
                    std::cout << "Contacto encontado: " << "{ " << name << " : " << phone << " }" << std::endl;
                }
            } break;
            case 3: {

            } break;
            case 4: {
                std::cout << "Contacs: " << std::endl;
                for (auto& a : agenda) {
                    std::cout << "\t { " << a.first << " : " << a.second << " }" << std::endl;
                }
            } break;
            case 5: {
                isTerminated = !isTerminated;
            } break; 
            default: {
                std::cout << "Opcion no valida." << std::endl;
            } break;
        }
    }
    return 0;
}