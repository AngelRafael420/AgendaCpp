#include "Agenda.h"
#include <fstream>
#include <string>

#define NOMBRE_ARCHIVO "contactos.txt"

Agenda::Agenda(): _primer(NULL) , _ultimo(NULL)
{
}

void Agenda::Agregar(Contacto* contacto)
{
    if (_primer == NULL) {
        _primer = _ultimo = contacto;
    }
    else {
        _ultimo->SetSiguiente(contacto);
        _ultimo = contacto;
    }
}

bool Agenda::Eliminar(int indice)
{
    // Si la lista está vacía, no se puede eliminar ningún elemento
    if(_primer == NULL)
    {
        return false;
    }
    
    // Si el índice es 0, eliminamos el primer elemento
    if(indice == 0)
    {
        Contacto* temp = _primer;
        _primer = _primer->GetSiguiente();
        delete temp;
        return true;
    }
    
    // Si el índice es mayor a 0, buscamos el elemento que está en la posición indicada
    int contador = 0;
    Contacto* actual = _primer;
    Contacto* anterior = NULL;
    while(actual != NULL && contador != indice)
    {
        anterior = actual;
        actual = actual->GetSiguiente();
        contador++;
    }
    
    // Si encontramos el elemento, lo eliminamos
    if(actual != NULL)
    {
        anterior->SetSiguiente(actual->GetSiguiente());
        if(actual == _ultimo)
        {
            _ultimo = anterior;
        }
        delete actual;
        return true;
    }
    
    // Si no encontramos el elemento, retornamos false
    return false;
}


bool Agenda::Modificar(int indice, std::string nombre, std::string telefono)
{
    // Si la lista está vacía, no se puede modificar ningún elemento
    if(_primer == NULL)
    {
        return false;
    }
    
    // Si el índice es mayor o igual a 0, buscamos el elemento que está en la posición indicada
    int contador = 0;
    Contacto* actual = _primer;
    while(actual != NULL && contador != indice)
    {
        actual = actual->GetSiguiente();
        contador++;
    }
    
    // Si encontramos el elemento, lo modificamos
    if(actual != NULL)
    {
        actual->SetNombre(nombre);
        actual->SetTelefono(telefono);
        return true;
    }
    
    // Si no encontramos el elemento, retornamos false
    return false;
}


void Agenda::Cargar()
{
    std::ifstream lector(NOMBRE_ARCHIVO);
    std::string linea;

    while (getline(lector, linea)) {
        // Separar el nombre y teléfono por la coma
        size_t coma_pos = linea.find(",");
        std::string nombre = linea.substr(0, coma_pos);
        std::string telefono = linea.substr(coma_pos + 1);

        // Crear el contacto y agregarlo a la agenda
        Contacto* contacto = new Contacto(nombre, telefono);
        Agregar(contacto);
    }

    lector.close();
}


void Agenda::Guardar()
{
    std::ofstream escritor(NOMBRE_ARCHIVO);

    // Recorrer la lista de contactos y escribir cada uno en el archivo
    for (Contacto* contacto = _primer; contacto != NULL; contacto = contacto->GetSiguiente()) {
        escritor << contacto->GetNombre() << "," << contacto->GetTelefono() << std::endl;
    }

    escritor.close();
}

