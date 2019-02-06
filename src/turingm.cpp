#include "../include/turingm.h"


TuringM::TuringM(unsigned int i, unsigned int j, unsigned int mod){
    std::fstream fs;
    std::string line;
    unsigned int num_of_ants, opt = 1;
    Ant* aux;
    fs.open("config/dataset.txt", std::ios::in);
    if(fs.is_open()){
        std::getline(fs, line);
        std::istringstream in(line);
        in >> i;
        in >> j;
        in >> mod;
        Malla_ = grid(i, j, mod);

        std::getline(fs, line);
        std::istringstream in2(line);
        in2 >> num_of_ants;
        for(unsigned int k = 0; k < num_of_ants; k++){
            srand(time(NULL));
            sleep(1);
            in2 >> opt;
            switch(opt){
            case 1:
                aux = new LangtonAntDIDI(1 + rand() % (i-1), 1 + rand() % (j-1), rand() % (4), i, j);
                break;
            case 2:
                aux = new LangtonAntDDII(1 + rand() % (i-1), 1 + rand() % (j-1), rand() % (4), i, j);
                break;
            case 3:
                aux = new LangtonAntIIDD(1 + rand() % (i-1), 1 + rand() % (j-1), rand() % (4), i, j);
                break;
            case 4:
                aux = new LangtonAntIDDI(1 + rand() % (i-1), 1 + rand() % (j-1), rand() % (4), i, j);
                break;
            default:
                fs.close();
                throw initializationexeption();
                break;
            }
            Hormigas_.push_back(aux);
        }
        fs.close();
    }
    quicksortAnts();
}


TuringM::~TuringM(){}           //

void TuringM::showGrid(){       //Procedimiento para pruebas
    Malla_.repaint(Hormigas_);
}

void TuringM::reset(){          //
    Malla_.reset();
}

void TuringM::NextStatus(){     //Deberia estar
    for(unsigned int k = 0; k < Hormigas_.size(); k++){
        unsigned int i = Hormigas_[k] -> getX();
        unsigned int j = Hormigas_[k] -> getY();

        swapSquare(i, j, Hormigas_[k] -> move(Malla_.pos(i, j)));
    }
    Pasos_++;
    quicksortAnts();
}

void TuringM::Actualize(){
    //Malla_.repaint();
    Malla_.repaint(Hormigas_);
}

void TuringM::swapSquare(unsigned int i, unsigned int j, Color color){  //
    Malla_.setPos(i,j, color);
}

std::vector<Ant*> TuringM::getAnts() const{   //
    return Hormigas_;
}

//***************************************************************************************

void TuringM::quicksortAnts(){
    std::stable_sort(Hormigas_.begin(), Hormigas_.end());
}

unsigned int TuringM::Pasos_ = 0;
