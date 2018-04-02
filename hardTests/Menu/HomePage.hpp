/*
 * HomePage.hpp
 *
 *  Created on: Mar 31, 2018
 *      Author: vst
 */

#ifndef HOMEPAGE_HPP_
#define HOMEPAGE_HPP_
#include <LiquidCrystal.h>
#include "Values.hpp"
#include "PageBase.hpp"
template<typename D>
class HomePage: public PageBase<D> {
private:
	Values * values;
public:
	HomePage(Values * values) {
		this->values = values;
	}

	void render(D * display) {

		display->setCursor(0, 0);
		display->print("T:");
		display->print(values->getClimatVal(TYPE_CLIMATE_VALUE::TEMPERATURE)->getCurrent());
		display->print("->");
		display->print(values->getClimatVal(TYPE_CLIMATE_VALUE::TEMPERATURE)->getTarget());
		display->print("C");


		display->setCursor(0, 1);
		display->print("H:");
		display->print(values->getClimatVal(TYPE_CLIMATE_VALUE::HUMIDITY)->getCurrent());
		display->print("->");
		display->print(values->getClimatVal(TYPE_CLIMATE_VALUE::HUMIDITY)->getTarget());
		display->print("%");
	}
};

#endif /* HOMEPAGE_HPP_ */
