#ifndef TEST_CLIMATE_TIMEUTILS_HPP
#define TEST_CLIMATE_TIMEUTILS_HPP

class TimeUtils {

public:
    static bool isWorkTime(unsigned long prevMillis, unsigned long currentMillis,unsigned int interval) {
        if (currentMillis < prevMillis) {//проверка обнуления миллисекунд раз в 50 дней
            prevMillis = currentMillis;
        }
        return (currentMillis - prevMillis) >= interval;
    }
};


#endif //TEST_CLIMATE_TIMEUTILS_HPP
