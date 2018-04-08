#ifndef TEMPERATUREVALUE_HPP_
#define TEMPERATUREVALUE_HPP_

class Value {
private:
	float current = 0;
	int maxTarget = 0;
	int minTarget = 100;

	bool active = false;

public:
	float target = 0;
	float gisteris = 1;

	Value(float target, int minTarget, int maxTarget, float gisteris) {
		this->minTarget = minTarget;
		this->maxTarget = maxTarget;
		this->gisteris = gisteris;
		this->target = target;
		//target = minTarget + ((maxTarget - minTarget) / 2);
	}

	const float &getTarget() {
		return target;
	}

	const float &getCurrent() {
		return current;
	}

	void setCurrent(float current) {
		this->current = current;
	}

	float getGisteris() {
		return this->gisteris;
	}

	void setActive(bool value) {
		this->active = value;
	}

	bool getActive() {
		return active;
	}
};

#endif /* TEMPERATUREVALUE_HPP_ */
