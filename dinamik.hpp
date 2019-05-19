#ifndef DINAMIK_HPP_INCLUDED
#define DINAMIK_HPP_INCLUDED

#include "graphics.hpp"
#include "widgets.hpp"
#include <string.h>
class Dinamik : public Widget {
protected:
    bool _checked;
    int _a;
    int keretvastagsag=2;
    int vizszintes_eltolas=5;
public:
    std::string _t;
    Dinamik(int x, int y, int xmeret, int ymeret,std::string text);
    virtual void draw() ;
    virtual void handle(genv::event ev);
    virtual bool is_checked() ;
    virtual bool isnt_statik();
    virtual void loseFocus();
    virtual std::string getValue();
    virtual void setPlayer(int p);
};
#endif // DINAMIK_HPP_INCLUDED
