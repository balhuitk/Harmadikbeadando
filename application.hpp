#ifndef APPLICATION
#define APPLICATION
#include "graphics.hpp"
#include "widgets.hpp"
#include "num_change.hpp"
#include "menu.hpp"
#include "checkbox.hpp"
#include "statik.hpp"
#include "dinamik.hpp"
#include "push_button.hpp"
#include "amoba_logic.hpp"


class Application {
private:
    std::vector<Widget*> widgets;
    std::vector<CheckBox*> palya;
    std::string player1;
    std::string player2;
    int res1;
    int res2;
    int size_widgets;
    int player;
    bool jatekban;
    Num_Change * n1;
    Num_Change * n2;
    Statik * s1;
    Statik * s2;
    Statik * s3;
    Statik * s4;
    Statik * s5;
    Dinamik * d1;
    Dinamik * d2;
    Push_Button * p1;
    Amoba_Logic * JatekMester;

public:
    Application(int _res1,int _res2);
    virtual int Leptet(int focus);
    virtual void event_loop();
    virtual void Start(Num_Change * n1, Num_Change * n2, Dinamik * d1, Dinamik * d2);
    virtual void feltolt(std::vector <Widget*> &widgets);
};


#endif // APPLICATION_HPP_INCLUDED
