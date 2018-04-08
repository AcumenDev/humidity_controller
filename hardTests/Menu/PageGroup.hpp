//
// Created by vst on 10/15/17.
//

#ifndef TEST_CLIMATE_PAGEGROUP_HPP
#define TEST_CLIMATE_PAGEGROUP_HPP

#include "PageBase.hpp"
template<typename D>
class PageGroup: public PageBase<D> {
private:
	PageBase<D> **pages;
	byte size;
	int current = 0;
public:

	PageGroup(PageBase<D> **pages, byte size) {
		this->pages = pages;
		this->size = size;
	}

	PageGroup(const char *name, PageBase<D> **pages, byte size) :
			PageBase<D>(name) {
		this->pages = pages;
		this->size = size;
	}

	// void add(PageBase *pBase);
	const PageBase<D> *getCurrentPage() {
		return pages[current];
	}

	 void render(D * display){
		display->setCursor(0, 0);
		/*display->print("T:");
		display->print(values->getClimatVal(TYPE_CLIMATE_VALUE::TEMPERATURE)->getCurrent());*/
		display->println(pages[current]->getName());
	}

	void up() {
		if (current >= size - 1) {
			current = 0;
		} else {
			current++;
		}
	}

	void down() {
		if (current <= 0) {
			current = size - 1;
		} else {
			current--;
		}
	}

	PageBase<D> *enter() {
		return pages[current];
	}

private:
	//  void render(const Display *dispay) override;

};

#endif //TEST_CLIMATE_PAGEGROUP_HPP
