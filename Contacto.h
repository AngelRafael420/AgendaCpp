#ifndef CONTACTO_H
#define CONTACTO_H

#include <string>

class Contacto
{
    public:
        Contacto(std::string nombre, std::string telefono);
        void SetNombre(std::string nombre) { _nombre = nombre; }
        std::string GetNombre(){ return _nombre; }
        void SetTelefono(std::string telefono) { _telefono = telefono; }
        std::string GetTelefono(){ return _telefono; }
        void SetSiguiente(Contacto* siguiente) { _siguiente = siguiente; }
        Contacto* GetSiguiente() { return _siguiente; }

    private:
        std::string _nombre;
        std::string _telefono;
        Contacto* _siguiente;
};
#endif
