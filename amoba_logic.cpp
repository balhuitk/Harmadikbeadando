#include "amoba_logic.hpp"
#include "graphics.hpp"
#include <iostream>

using namespace std;

Amoba_Logic::Amoba_Logic(int a, int b)
{
    row=a;
    column=b;
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
        matrix[i][j]=-1;
}
int Amoba_Logic::orizontal(int index1, int index2)
{
    for(int k=1;k<6;k++)
    {
        if((matrix[index2][index1-5+k] == matrix[index2][index1-4+k]) &&( matrix[index2][index1-4+k]== matrix[index2][index1-3+k]) &&(matrix[index2][index1-3+k] == matrix[index2][index1-2+k])
           &&(matrix[index2][index1-2+k] == matrix[index2][index1-1+k]) &&(matrix[index2][index1-1+k] == 1))
            return 1;
        if((matrix[index2][index1-5+k] == matrix[index2][index1-4+k]) &&( matrix[index2][index1-4+k]== matrix[index2][index1-3+k]) &&(matrix[index2][index1-3+k] == matrix[index2][index1-2+k])
           &&(matrix[index2][index1-2+k] == matrix[index2][index1-1+k]) &&(matrix[index2][index1-1+k] == 0))
            return 2;
    }
    return 0;

}
int Amoba_Logic::vertical(int index1, int index2)
{
    for(int k=1;k<6;k++)
    {
        if((matrix[index2-5-k][index1] == matrix[index2-4+k][index1]) &&( matrix[index2-4+k][index1]== matrix[index2-3+k][index1]) &&(matrix[index2-3+k][index1] == matrix[index2-2+k][index1])
           &&(matrix[index2-2+k][index1] == matrix[index2-1+k][index1]) &&(matrix[index2-1+k][index1] == 1))
            return 1;
        if((matrix[index2-5-k][index1] == matrix[index2-4+k][index1]) &&( matrix[index2-4+k][index1]== matrix[index2-3+k][index1]) &&(matrix[index2-3+k][index1] == matrix[index2-2+k][index1])
           &&(matrix[index2-2+k][index1] == matrix[index2-1+k][index1]) &&(matrix[index2-1+k][index1] == 0))
            return 2;
    }
    return 0;
}
int Amoba_Logic::diagonal(int index1, int index2)
{
    for(int k=1;k<6;k++)
    {
        if((matrix[index2-5+k][index1-5+k] == matrix[index2-4+k][index1-4+k]) &&( matrix[index2-4+k][index1-4+k]== matrix[index2-3+k][index1-3+k]) &&(matrix[index2-3+k][index1-3+k] == matrix[index2-2+k][index1-2+k])
           &&(matrix[index2-2+k][index1-2+k] == matrix[index2-1+k][index1-1+k]) &&(matrix[index2-1+k][index1-1+k] == 1))
            return 1;
        if((matrix[index2-5+k][index1-5+k] == matrix[index2-4+k][index1-4+k]) &&( matrix[index2-4+k][index1-4+k]== matrix[index2-3+k][index1-3+k]) &&(matrix[index2-3+k][index1-3+k] == matrix[index2-2+k][index1-2+k])
           &&(matrix[index2-2+k][index1-2+k] == matrix[index2-1+k][index1-1+k]) &&(matrix[index2-1+k][index1-1+k] == 0))
            return 2;
    }
    return 0;
}
int Amoba_Logic::diagonal2(int index1, int index2)
{
    for(int k=1;k<6;k++)
    {
        if((matrix[index2+5-k][index1-5+k] == matrix[index2+4-k][index1-4+k]) &&( matrix[index2+4-k][index1-4+k]== matrix[index2+3-k][index1-3+k]) &&(matrix[index2+3-k][index1-3+k] == matrix[index2+2-k][index1-2+k])
           &&(matrix[index2+2-k][index1-2+k] == matrix[index2+1-k][index1-1+k]) &&(matrix[index2+1-k][index1-1+k] == 1))
            return 1;
        if((matrix[index2+5-k][index1-5+k] == matrix[index2+4-k][index1-4+k]) &&( matrix[index2+4-k][index1-4+k]== matrix[index2+3-k][index1-3+k]) &&(matrix[index2+3-k][index1-3+k] == matrix[index2+2-k][index1-2+k])
           &&(matrix[index2+2-k][index1-2+k] == matrix[index2+1-k][index1-1+k]) &&(matrix[index2+1-k][index1-1+k] == 0))
            return 2;
    }
    return 0;
}
int Amoba_Logic::win(int index1, int index2)
{
    //std::cout<<index1<<" "<<index2<<std::endl;
    if(orizontal(index1,index2)==1||vertical(index1,index2)==1||diagonal(index1,index2)==1||diagonal2(index1,index2)==1)
        return 1;
    if(orizontal(index1,index2)==2||vertical(index1,index2)==2||diagonal(index1,index2)==2||diagonal2(index1,index2)==2)
        return 2;
    return 0;
}
int Amoba_Logic::matrixfull()
{
    bool teli=true;
    for(int i=0;i<row;i++)
        for(int j=0;j<column;j++)
        if(matrix[i][j]==-1)
            teli=false;
    return teli;
}
void Amoba_Logic::setValue(int index1, int index2, int player)
{
    if(player==1 && matrix[index1][index2]==-1)
        matrix[index1][index2]=1;
    if(player==-1 && matrix[index1][index2]==-1)
        matrix[index1][index2]=0;
}
int Amoba_Logic::getColumn()
{
    return column;
}
