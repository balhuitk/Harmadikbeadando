#ifndef NUM_CHANGE_HPP_INCLUDED
#define NUM_CHANGE_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"

class Num_Change : public Widget{
protected:
    bool _checked;
    int _a,_b,_value;
public:
    Num_Change(int x, int y, int xmeret, int ymeret, int a, int b);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked();
    virtual bool isnt_statik();
    virtual int getValue();

    virtual void loseFocus();
    virtual void setPlayer(int p);
private:
    virtual bool bennevan1(int x, int y);
    virtual bool bennevan2(int x, int y);



    const static int eltolas=25;//levalasztott resz merete
    const static int inbetween=3;//ket ablak kozti resz
    const static int keretvastagsag=2;
    const static int stringstarter=5;//honnan kezdje irni a stringet
    const static int bigger_jump=9;
};


#endif // NUM_CHANGE_HPP_INCLUDED
