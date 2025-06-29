#include <iostream>
#include "contactos.h"

using namespace std;

int main() {
    ContactoEmail contactos[100];
    int numContactos = 0;
    int opcion;

    do {
        cout << "\nGestion de Contactos\n";
        cout << "1. Agregar un contacto\n";
        cout << "2. Eliminar un contacto\n";
        cout << "3. Mostrar listado general de contactos\n";
        cout << "4. Mostrar listado ordenado por servidor de correo\n";
        cout << "5. Salir\n";
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch(opcion) {
            case 1:
                agregarContacto(contactos, numContactos);
                break;
            case 2:
                eliminarContacto(contactos, numContactos);
                break;
            case 3:
                mostrarContactos(contactos, numContactos);
                break;
            case 4:
                mostrarContactosOrdenadosPorDominio(contactos, numContactos);
                break;
            case 5:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida.\n";
        }

    } while(opcion != 5);

    return 0;
}
