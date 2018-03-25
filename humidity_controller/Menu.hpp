#ifndef TEST_CLIMATE_MENU_HPP
#define TEST_CLIMATE_MENU_HPP

#include "IntervalWorkerBase.hpp"
#include "PageBase.hpp"
#include "PageGroup.hpp"

template<typename D>
class Menu: public IntervalWorkerBase {
	PageBase<D> *currentPage = nullptr;
	PageBase<D> *previousPage = nullptr;
	D * display;
public:
	Menu(D *display, int interval, PageGroup<D> *pageGroup) :
			IntervalWorkerBase(interval) {
		this->currentPage = pageGroup;
		this->display = display;
	}


	const PageBase<D> *getCurrentPage() const {
		return currentPage;
	}
	void work(Values *values, unsigned long currentMillis) {
	    currentPage->render(display);
	}

	void up() {
	    currentPage->up();
	}

	void down() {
	    currentPage->down();
	}

	void enter() {
	    PageBase<D> *newCur = currentPage->enter();
	    if (newCur != nullptr) {
	        previousPage = currentPage;
	        currentPage = newCur;
	    }
	}
};

#endif //TEST_CLIMATE_MENU_HPP
