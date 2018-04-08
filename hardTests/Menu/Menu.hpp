#ifndef TEST_CLIMATE_MENU_HPP
#define TEST_CLIMATE_MENU_HPP

#include "IntervalWorkerBase.hpp"
#include "PageBase.hpp"
#include "PageGroup.hpp"

template<typename D>
class Menu : public IntervalWorkerBase {
private:
    PageBase<D> *currentPage = nullptr;
    PageBase<D> *previousPage = nullptr;
    PageBase<D> *homePage = nullptr;
    PageBase<D> *menuPage = nullptr;
    D *display;

    unsigned long changeTimestamp;
    unsigned int returnToHomePageTime = 5000;

public:
    Menu(D *display, int interval, PageGroup<D> *menuPage,
         PageBase<D> *homePage) :
            IntervalWorkerBase(interval) {
        this->menuPage = menuPage;
        this->currentPage = homePage;
        this->homePage = homePage;
        this->display = display;
    }

    const PageBase<D> *getCurrentPage() const {
        return currentPage;
    }

    void work(Values *values, unsigned long currentMillis) {
        if (currentMillis - changeTimestamp >= returnToHomePageTime) {
            currentPage = homePage;
        }
        currentPage->render(display);
    }

    void up() {
        Serial.println("up");
        delay(100);
        changeTimestamp = millis();
        currentPage->up();
    }

    void down() {
        Serial.println("down");
        delay(100);
        changeTimestamp = millis();
        currentPage->down();
    }

    void enter() {
        Serial.println("enter");
        delay(100);
        changeTimestamp = millis();
        if (currentPage == homePage) {
            Serial.println("currentPage = menuPage");
            delay(100);
            currentPage = menuPage;
        } else {
            PageBase<D> *newCur = currentPage->enter();
            if (newCur != nullptr) {
                previousPage = currentPage;
                currentPage = newCur;
            }
        }
    }
};

#endif //TEST_CLIMATE_MENU_HPP
