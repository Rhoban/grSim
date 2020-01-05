/*
grSim - RoboCup Small Size Soccer Robots Simulator
Copyright (C) 2011, Parsian Robotic Center (eew.aut.ac.ir/~parsian/grsim)

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include <QtWidgets/QApplication>
#include "mainwindow.h"
#include "winmain.h"
#include <iostream>

int main(int argc, char *argv[])
{
    std::locale::global( std::locale( "" ) );
    
    char** argend = argc + argv;

    QCoreApplication::setOrganizationName("Parsian");
    QCoreApplication::setOrganizationDomain("parsian-robotics.com");
    QCoreApplication::setApplicationName("grSim");
    QApplication a(argc, argv);
    MainWindow w;
    bool headless=false;
    
    for(int i=0;i<argc;i++)
    {
      
      if(std::string(argv[i]).compare("--headless")==0 || std::string(argv[i]).compare("-H")==0)
      {
        std::cout<<"Headless mode"<<std::endl;
        w.hide();
        w.setIsGlEnabled(false);
        w.hide();
        headless=true;
      }
      
      if(std::string(argv[i]).compare("-i")==0)
      {
        if(i+1<=argc)
        {
          w.changeInterface(std::string(argv[i+1]));
          std::cout<<"changing to interface "<<std::string(argv[i+1])<<std::endl;

        }
      }
    }

    if(!headless)
      w.show();
    
    return a.exec();
}
