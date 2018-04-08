#ifndef TEST_CLIMATE_MENU_HPP
#define TEST_CLIMATE_MENU_HPP

#include "IntervalWorkerBase.hpp"
#include "PageBase.hpp"
#include "PageGroup.hpp"


class Menu : public IntervalWorkerBase {
private:
    PageBase *currentPage = nullptr;
    PageBase *previousPage = nullptr;
    PageBase *homePage = nullptr;
    PageBase *menuPage = nullptr;
    LiquidCrystal *display;

    unsigned long changeTimestamp;
    unsigned int returnToHomePageTime = 5000;

public:
    Menu(LiquidCrystal *display, int interval, PageGroup *menuPage,  PageBase *homePage) :
            IntervalWorkerBase(interval) {
        this->menuPage = menuPage;
        this->currentPage = homePage;
        this->homePage = homePage;
        this->display = display;
    }

    const PageBase *getCurrentPage() const {
        return currentPage;
    }

    void work(Values *values, unsigned long currentMillis) {
        if (currentPage != homePage) {
            if (currentMillis - changeTimestamp >= returnToHomePageTime) {
                currentPage = homePage;
                Serial.println("menu returnToHomePage");
            }
        }
        currentPage->render(display);
    }

    void up() {
        changeTimestamp = millis();
        Serial.println("menu up");
        currentPage->up();
    }

    void down() {
        changeTimestamp = millis();
        Serial.println("menu down");
        currentPage->down();
    }

    void enter() {
        Serial.println("Menu enter");
        delay(100);
        changeTimestamp = millis();
        if (currentPage == homePage) {
            Serial.println("Menu currentPage = menuPage");
            delay(100);
            currentPage = menuPage;
        } else {
            Serial.println("Menu menuPage = next menuPage");
            delay(100);
            PageBase *newCur = currentPage->enter();
            if (newCur != nullptr) {
                previousPage = currentPage;
                currentPage = newCur;
            }
        }
    }


    virtual const char *getName() const {
        return nullptr;
    }
};

#endif //TEST_CLIMATE_MENU_HPP
