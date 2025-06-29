#include <iostream>
#include <cstring>
#include "contactos.h"

using namespace std;

void agregarContacto(ContactoEmail contactos[], int &numContactos) {
    ContactoEmail nuevoContacto;

    cout<<"Ingrese nombres completos: ";
    cin.ignore();
    cin.getline(nuevoContacto.nombres,100);

    cout<<"Ingrese sexo (M/F): ";
    cin >> nuevoContacto.sexo;

    cout<<"Ingrese edad: ";
    cin >> nuevoContacto.edad;
    cin.ignore();

    cout<<"Ingrese telefono: ";
    cin.getline(nuevoContacto.telefono, 30);

    cout<<"Ingrese email: ";
    cin.getline(nuevoContacto.email, 50);

    cout<<"Ingrese nacionalidad: ";
    cin.getline(nuevoContacto.nacionalidad, 50);

    contactos[numContactos++] = nuevoContacto;
    cout << "Contacto agregado exitosamente.\n";
}

void eliminarContacto(ContactoEmail contactos[], int &numContactos) {
    if (numContactos == 0) {
        cout << "No hay contactos para eliminar.\n";
        return;
    }

    int indice;
    cout << "Ingrese el indice del contacto a eliminar (0 a " << numContactos - 1 << "): ";
    cin >> indice;

    if (indice < 0 || indice >= numContactos) {
        cout << "Índice inválido.\n";
        return;
    }

    for (int i = indice; i < numContactos - 1; i++) {
        contactos[i] = contactos[i + 1];
    }

    numContactos--;
    cout << "Contacto eliminado exitosamente.\n";
}

void mostrarContactos(const ContactoEmail contactos[], int numContactos) {
    if (numContactos == 0) {
        cout << "No hay contactos para mostrar.\n";
        return;
    }

    for (int i = 0; i < numContactos; i++) {
        cout << "Contacto " << i << ":\n";
        cout << "Nombres: " << contactos[i].nombres << endl;
        cout << "Sexo: " << contactos[i].sexo << endl;
        cout << "Edad: " << contactos[i].edad << endl;
        cout << "Teléfono: " << contactos[i].telefono << endl;
        cout << "Email: " << contactos[i].email << endl;
        cout << "Nacionalidad: " << contactos[i].nacionalidad << endl;
    }
}

void mostrarContactosOrdenadosPorDominio(ContactoEmail contactos[], int numContactos) {
    if (numContactos == 0) {
        cout << "No hay contactos para mostrar.\n";
        return;
    }

    for (int i = 0; i < numContactos - 1; i++) {
        for (int j = i + 1; j < numContactos; j++) {
            char *domA = strchr(contactos[i].email, '@');
            char *domB = strchr(contactos[j].email, '@');

            if (domA && domB && strcmp(domA, domB) > 0) {
                ContactoEmail temp = contactos[i];
                contactos[i] = contactos[j];
                contactos[j] = temp;
            }
        }
    }

    mostrarContactos(contactos, numContactos);
}
