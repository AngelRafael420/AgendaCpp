#ifndef AGENDA_H
#define AGENDA_H

#include <string>
#include "Contacto.h"

class Agenda
{
    public:
        Agenda();
        void Agregar(Contacto* contacto);
        Contacto* GetPrimer() { return _primer; }
        bool Eliminar(int indice);
        bool Modificar(int indice, std::string nombre, std::string telefono);
        void Cargar(); //Carga los contactos almacenados en el disco duro
        void Guardar(); //Guarda permanentemente en el disco duro

    private:
        Contacto* _primer;
        Contacto* _ultimo;
};
#endif
