#ifndef DEFINITIONS_H
#define DEFINITIONS_H

#include <iostream>
#include <vector>
#include <cassert>
#include <system_error>         //Errores de sistema
#include <exception>
#include <cerrno>               //errno
#include <time.h>
#include <cstdlib>
//#include <cassert>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <unistd.h>             //Opciones por linea de comandos
#include <getopt.h>

const unsigned int DEF_BORDER_X = 40;
const unsigned int DEF_BORDER_Y = 40;
const unsigned int DEFAULT_GRID = 1;

const unsigned int DEF_ANT_X = 25;
const unsigned int DEF_ANT_Y = 25;

enum Color { Blanco, Negro, Azul, Rojo };      //Tipos de casilla 0 1 2 3

class myexeption : public std::exception {};

class oobantexception : public myexeption {
public:
    virtual const char* what() const throw(){
        return "Out Of Bounds Ant Exception";
    }
};

class unknownoptexeption : public myexeption {
public:
    virtual const char* what() const throw(){
        return "Unknown Option Exception";
    }
};

class initializationexeption : public myexeption {
public:
    virtual const char* what() const throw(){
        return "Initialization Error Exception";
    }
};


#endif // DEFINITIONS_H
