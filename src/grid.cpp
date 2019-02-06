#include "../include/grid.h"

grid::grid(const unsigned int m, const unsigned int n, const unsigned int opt){
    //Constructor with parameters, dimensions and grid option
    assert((m > 0) && (n > 0));
    assert((opt > 0) && (opt < 3));

    switch (opt) {
        case 1:
            //Standard Initialization
            n_ = n;
            m_ = m;
            slots_ = std::vector<unsigned int>(n_*m_, 0);
        break;
        case 2:
            //A different one, for fun
            throw unknownoptexeption();
        break;
        default:
            //Exit with exception
            throw initializationexeption();
        break;
    }
}

grid::~grid(){
    //Default destructor
}

unsigned int grid::getM() const  { return m_; }
unsigned int grid::getN() const  { return n_; }

void grid::repaint(const std::vector<Ant*>& hormigas){
    unsigned int k = 0;
    for(unsigned int i = 1; i <= m_; i++){
        for(unsigned int j = 1; j <= n_; j++){
            if(rpos(i, j) == rpos(hormigas[k] -> getX(), hormigas[k] -> getY())){
                hormigas[k] -> paint();
                if(k < hormigas.size() - 1) k++;
            }
            else if(pos(i,j) == Color::Negro)                std::cout << " x ";      //True  ' '
            else if(pos(i,j) == Color::Blanco)               std::cout << "   ";      //Blanco 'x'
            else if(pos(i,j) == Color::Azul)                 std::cout << " - ";
            else if(pos(i,j) == Color::Rojo)                 std::cout << " + ";
        }
        std::cout << std::endl;
    }
}

void grid::reset(){
    slots_ = std::vector<unsigned int>(n_*m_, 0);
}

Color grid::pos(unsigned int i, unsigned int j) const{
    //Obtains position in sparse matrix
    //First position is [1,1]
    if((i <= 0) || (j <= 0)){
        throw oobantexception();
    }
    return (Color)slots_[(i - 1) * n_ + (j - 1)];
}

unsigned int grid::rpos(unsigned int i, unsigned int j) const{
    if((i <= 0) || (j <= 0)){
        throw oobantexception();
    }
    return ((i - 1) * n_ + (j - 1));
}

void grid::setPos(unsigned int i, unsigned int j, Color val){
    slots_[(i - 1) * n_ + (j - 1)] = (unsigned int)val;
}
