#include <chrono>
#include <iostream>
#include <DisplayStub.hpp>

#include "src/Menu.hpp"
#include "src/PageValue.hpp"
#include "src/FloatChanger.hpp"
#include "src/HomePage.hpp"

using namespace std;
using namespace std::chrono;

int main() {

    cout << "StartTest" << endl;

    bool state = true;

    auto *values = new Values();

    Display *display = new DisplayStub();


    auto *tGis = new PageValue("Gisteris", new FloatChanger(&(values->getClimatVal(TEMPERATURE)->gisteris), 0, 10, 0.1));
    auto *tCur = new PageValue("Target", new FloatChanger(&(values->getClimatVal(TEMPERATURE)->target), 1, 30, 0.1));
    PageBase *tPages[] = {tCur, tGis};
    auto *tGroup = new PageGroup("Temperature", tPages, 2);


    auto *hGis = new PageValue("Gisteris", new FloatChanger(&(values->getClimatVal(HUMIDITY)->gisteris), 0, 20, 1));
    auto *hCur = new PageValue("Target", new FloatChanger(&(values->getClimatVal(HUMIDITY)->target), 10, 99, 1));
    PageBase *hPages[] = {hGis, hCur};
    auto *hGroup = new PageGroup("Humidity", hPages, 2);

    PageBase *mainPages[] = {tGroup, hGroup};
    auto *pageGroup = new PageGroup(mainPages, 2);

    Menu *menu = new Menu(display, 1, pageGroup, new HomePage(values));

    /*  menu->work(values, 0);
      menu->enter();
      menu->work(values, 0);
      menu->up();
      menu->work(values, 0);*/
    //  return 0;
    unsigned long time = 0;
    char in;

    while (state) {
        menu->work(values, time);
        std::cout << std::endl;
        std::cin >> in;

        switch (in) {
            case '+': {
                menu->up(time);
                break;
            }
            case '-': {
                menu->down(time);
                break;
            }
            case 's': {
                menu->enter(time);
                break;
            }
            case 'l': {
                time +=  50010;
                break;
            }
            case 'q': {
                state = false;
                break;
            }
            default:
                break;
        }
        time++;
    }
    return 0;
}
