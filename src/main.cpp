#include <iostream>

#include "../include/turingm.h"

void procesamiento_de_opciones(bool& help_option, bool& interactive, bool& verbose, bool& fastforward, int& repetitions,
                               int argc, char* argv[]){
    static struct option long_options[] ={
          {"help",              no_argument,       0, 'h'},
          {"interactive",       no_argument,       0, 'i'},
          {"fastforward",       required_argument, 0, 'f'},
          {"verbose",           no_argument,       0, 'v'},
          {0, 0, 0, 0}
    };
    int option_index = 0;
    int c;
    while ( (c = getopt_long(argc, argv, "hivf:", long_options, &option_index)) != -1) {
        switch (c) {
        case 'h':
            help_option = true;
            break;
        case 'i':
            interactive = true;
            break;
        case 'v':
            verbose = true;
            break;
        case 'f':       //opcion guardada en optarg
            fastforward = true;
            repetitions = atoi(optarg);
            break;
        case '?':
            //Error message already sent
            break;
        default:
            std::fprintf(stderr, "?? getopt devolvió código "
                    "de error 0%o ??\n", c);
            break;
        }
    }
    if (optind < argc) {
        std::cout << "-- argumentos no opción --\n";
        for (; optind < argc; ++optind) {
            std::cout << "argv[" << optind << "]: " <<
            argv[optind] << '\n';
        }
    }
}

int main(int argc, char* argv[])
{
    std::cout << "Hormiga de Langton, demostracion: \n"
            "Pulse ENTER para iniciar ...";

    std::cin.get();
    bool gameover = false;
    bool help_option = false;
    bool interactive = false;
    bool fastforward = false;
    int repetitions;
    bool verbose = true;

    try{
        procesamiento_de_opciones(help_option, interactive, verbose, fastforward, repetitions, argc, argv);
        if(help_option){
            throw std::string("HELP: prog_name [-i/--interactive] [-v/--verbose] [-f/--fastforward (repetitions)] | [-h/--help]");
        }

        TuringM automata;
        if(interactive){
            while(!gameover){
                automata.Actualize();
                automata.NextStatus();
                if(verbose){
                    for(unsigned int i = 0; i < automata.getAnts().size(); i++){
                    std::cout << "Posicion X:[" << i << "] " << automata.getAnts()[i] -> getX() << std::endl
                              << "Posicion Y:[" << i << "] " << automata.getAnts()[i] -> getY() << std::endl
                              << "Direccion:["  << i << "] " << automata.getAnts()[i] -> getDir() << std::endl
                              << "Iteracion:  "  << automata.Pasos_ << std::endl;
                    }
                }
                std::cin.get();
            }
        }
        else if(fastforward){
            for(unsigned int i = 0; i < repetitions; i++){
                automata.NextStatus();
            }
            automata.Actualize();
            if(verbose){
              /*  std::cout << "Posicion X: "  << automata.getAnt().getX() << std::endl
                          << "Posicion Y: "  << automata.getAnt().getY() << std::endl
                          << "Direccion:  "  << automata.getAnt().getDir() << std::endl
                          << "Iteracion:  "  << automata.Pasos_ << std::endl;
                */
            }
            std::cin.get();
        }
    }
    catch(std::exception& e){
        std::cerr << e.what() << " :\n";
        return -1;
    }
    catch(std::string str){
        std::cerr << str << ":\n";
    }

    return 0;
}
