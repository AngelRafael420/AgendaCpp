#include "Agenda.h"
#include <iostream>
#include <string>

using namespace std;
Agenda* agenda = new Agenda();

bool Listar()
{
    cout << endl << endl;
    int i = 1;
    Contacto* contacto = agenda->GetPrimer();
    while(contacto != NULL)
    {
        cout << i << "- " << contacto->GetNombre() << " " << contacto->GetTelefono() << endl;
        contacto = contacto->GetSiguiente();
        i++;
    }
    if(i == 1)
    {
        cout << endl << "** Agenda vacía **" << endl;
        return false;
    }
    cout << endl << endl;
    return true;
}

void Introducir()
{
    string nombre;
    string telefono;
    cout << "Introducir el nombre del contacto: ";
    getline(cin, nombre);
    cout << "Introducir el telefono del contacto: ";
    getline(cin, telefono);
    Contacto* contacto = new Contacto(nombre, telefono);
    agenda->Agregar(contacto);
    cout << "-- Contacto Agregado --" << endl;
    cout << endl;
    agenda->Guardar();
}

void Eliminar()
{
    if(!Listar())
    {
        return;
    }
    int indice = 0;
    Listar();
    cout << "Elija el contacto a eliminar => ";
    cin >> indice;
    agenda->Eliminar(indice - 1);
    cout << endl;
    Listar();
    cout << endl;
    agenda->Guardar();
}

void Modificar()
{
    if(!Listar())
    {
        return;
    }
    int indice = 0;
    string nombre, telefono;
    cout << "Elija el contacto a modificar => ";
    cin >> indice;
    cin.ignore();
    cout << "Elija nuevo nombre del contacto => ";
    getline(cin, nombre);
    cout << "Elija el nuevo telefono del contacto => ";
    getline(cin, telefono);
    agenda->Modificar(indice - 1 , nombre, telefono);
    cout << endl;
    Listar();
    cout << endl;
    agenda->Guardar();
}

void MostrarMenu()
{
    int opcion = 0;
    do
    {        
        cout << "1- Listar contactos" << endl;
        cout << "2- Introducir nuevo contacto" << endl;
        cout << "3- Eliminar Contacto" << endl;
        cout << "4- Modificar Contacto" << endl;
        cout << "5- Salir" << endl;
        cout << "Elija una opción => ";
        cin >> opcion;
        cin.ignore();
        
        switch(opcion)
        {
            case 1:
                Listar();
            break;
            case 2:
                Introducir();
            break;
            case 3:
                Eliminar();
            break;
            case 4:
                Modificar();
            break;
            case 5:
            break;
            default:
                cout << "Opción inválida" << endl;
            break;
        }
    }while(opcion != 5);
}

int main()
{
    agenda->Cargar();
    MostrarMenu();
    return 0;
}
