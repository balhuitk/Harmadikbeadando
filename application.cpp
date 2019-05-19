#include "application.hpp"
#include "graphics.hpp"
#include <fstream>
#include <vector>
#include <string.h>
using namespace genv;
using namespace std;


Application::Application(int _res1,int _res2)
{
        res1=_res1;
        res2=_res2;
        gout.open(res1,res2);
        n1 = new Num_Change(130,670,100,30,15, 30);
        n2 = new Num_Change(240,670,100,30,15, 30);
        widgets.push_back(n1);
        widgets.push_back(n2);

        std::vector <std::string> options;
        options.push_back("Egyjatekos");
        options.push_back("Ketjatekos");
        m1 = new Menu(350,670,150, 30, 100, options);
        widgets.push_back(m1);

        s1 = new Statik(130, 640, 100, 30, "Sorok");
        s2 = new Statik(240, 640, 100, 30, "Oszlopok");
        s3 = new Statik(130, 720, 100, 30, "Jatekos1");
        s4 = new Statik(350, 720, 100, 30, "Jatekos2");
        widgets.push_back(s1);
        widgets.push_back(s2);
        widgets.push_back(s3);
        widgets.push_back(s4);

        d1 = new Dinamik(130, 750, 100,30, "Nev1");
        d2 = new Dinamik(350, 750, 100,30, "Nev2");
        widgets.push_back(d1);
        widgets.push_back(d2);

        std::function <void()> f = [this](){Start(this->n1, this->n2, this->d1, this->d2);};
        p1 = new Push_Button(230, 800, 120,40, f, "Start");
        widgets.push_back(p1);


        size_widgets=widgets.size();
        player=1;
        jatekban=false;
    }

    void Application::feltolt(std::vector<Widget*> &widgets)
    {
        widgets.push_back(n1);
        widgets.push_back(n2);
        widgets.push_back(m1);
        widgets.push_back(s1);
        widgets.push_back(s2);
        widgets.push_back(s3);
        widgets.push_back(s4);
        widgets.push_back(d1);
        widgets.push_back(d2);
        widgets.push_back(p1);
        player=-1;
        size_widgets=widgets.size();
    }

    void Application::Start(Num_Change * n1, Num_Change * n2, Dinamik * d1, Dinamik * d2)
    {
        widgets.clear();
        feltolt(widgets);
        palya.clear();
        int a=n1->getValue();
        int b=n2->getValue();
        player1=d1->getValue();
        player2=d2->getValue();
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                CheckBox * c=new CheckBox(30+i*20,30+j*20,20,20,-1);
                palya.push_back(c);
            }
        }
        for(size_t i=0;i<palya.size();i++)
        {
            widgets.push_back(palya[i]);
        }
        JatekMester = new Amoba_Logic(a,b);
        jatekban=true;
    }

    int Application::Leptet(int focus)
    {
        int a=size_widgets-1;
        if(focus==a)
        {
            if(widgets[0]->isnt_statik())
                return 0;
            else{
                int b=1;
                while(!widgets[b]->isnt_statik())
                    b++;
                return b;
            }
        }
        else
            {
                int b=focus+1;
                while(!widgets[b]->isnt_statik())
                    b++;
                return b;
            }
    }

    void Application::event_loop()
    {
        event ev;
        bool checked=false;
        int focus = -1;
        while(gin >> ev )
        {
            gout<<move_to(0,0)<<color(255,255,255)<<box(res1,res2);
            if (ev.type == ev_mouse && ev.button==btn_left)
            {
                if(!(focus != -1 && widgets[focus]->is_selected(ev.pos_x, ev.pos_y)))
                {
                    checked=false;
                    for (size_t i=0; i<widgets.size(); i++)
                    {
                        if (widgets[i]->is_selected(ev.pos_x, ev.pos_y))
                        {
                            if(focus != -1)
                                widgets[focus]->loseFocus();
                            focus = i;
                            checked=true;
                            if(focus>=size_widgets)
                            {
                                JatekMester->setValue((focus - size_widgets) / JatekMester->getColumn(),(focus - size_widgets) % JatekMester->getColumn(),player);
                                player=-player;
                                for(size_t i=size_widgets; i<widgets.size(); i++)
                                {
                                    widgets[i]->setPlayer(player);
                                }
                            }
                            break;
                        }
                    }
                    if(!checked)
                    {
                        if(focus!=-1)
                            widgets[focus]->loseFocus();
                        focus=-1;
                    }
                }
            }
            if (ev.type==ev_key && ev.keycode==key_tab)
            {
                if(focus!=-1)
                {
                    widgets[focus]->loseFocus();
                    focus=Leptet(focus);
                }
            }
            if (focus!=-1)
            {
                widgets[focus]->handle(ev);
            }
            for (Widget * w : widgets)
            {
                w->draw();
            }
            if (focus!=-1)
            {

                widgets[focus]->draw();
            }
            if(jatekban && focus>size_widgets)
            {
                int index2 = (focus - size_widgets) / JatekMester->getColumn();
                int index1 = (focus - size_widgets) % JatekMester->getColumn();
                if(JatekMester->win(index1,index2)==1)
                {
                    gout << move_to(30,300) << color(255,0,0) << text(player1+" won!");
                }
                if(JatekMester->win(index1, index2)==2)
                {
                    gout << move_to(30,300) << color(255,0,0) << text(player2+" won!");
                }
                if(JatekMester->matrixfull())
                {
                    gout << move_to(30,300) << color(255,0,0) << text("DRAW!");
                }
            }
            gout << refresh;
        }
    }

