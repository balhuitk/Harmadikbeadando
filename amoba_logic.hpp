#ifndef AMOBA_LOGIC_HPP_INCLUDED
#define AMOBA_LOGIC_HPP_INCLUDED

//#include "application.hpp"
#include "graphics.hpp"


class Amoba_Logic{
private:
    int matrix[31][31];
    int row;
    int column;
public:
    Amoba_Logic(int a, int b);
    virtual int orizontal(int index1, int index2);
    virtual int vertical(int index1, int index2);
    virtual int diagonal(int index1, int index2);
    virtual int diagonal2(int index1, int index2);
    virtual int win(int index1, int index2);
    virtual int matrixfull();
    virtual int getColumn();
    virtual void setValue(int index1, int index2, int player);
};



#endif // AMOBA_LOGIC_HPP_INCLUDED
