#ifndef STATIK_HPP_INCLUDED
#define STATIK_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string.h>

class Statik : public Widget {
protected:
    std::string _t;
    int vizszintes_eltolas=5;
    int keretvastagsag=2;
    int l;
public:
    Statik(int x, int y, int xmeret, int ymeret, std::string text);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;
    virtual bool isnt_statik();
    virtual void loseFocus();
    virtual void setValue(std::string text);
    virtual void setPlayer(int p);
};
#endif // STATIK_HPP_INCLUDED
