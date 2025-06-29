#ifndef CONTACTOS_H
#define CONTACTOS_H

struct ContactoEmail {
    char nombres[100];
    char sexo;
    int edad;
    char telefono[30];
    char email[50];
    char nacionalidad[50];
};

void agregarContacto(ContactoEmail contactos[], int &numContactos);
void eliminarContacto(ContactoEmail contactos[], int &numContactos);
void mostrarContactos(const ContactoEmail contactos[], int numContactos);
void mostrarContactosOrdenadosPorDominio(ContactoEmail contactos[], int numContactos);

#endif
