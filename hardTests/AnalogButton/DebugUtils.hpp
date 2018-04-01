#ifndef TEST_CLIMATE_DEBUGUTILS_HPP
#define TEST_CLIMATE_DEBUGUTILS_HPP

#define DEBUG_PRINTER Serial

#ifdef CLIMATE_DEBUG
#define DEBUG_PRINT(...) { DEBUG_PRINTER.print(__VA_ARGS__); }
#define DEBUG_PRINTLN(...) { DEBUG_PRINTER.println(__VA_ARGS__); }
#else
#define DEBUG_PRINT(...) {}
#define DEBUG_PRINTLN(...) {}
#endif

class DebugUtils {
public:
    static int getfreeRam() {
#ifdef CLIMATE_DEBUG_RAM
        extern int __heap_start, *__brkval;
        int v;
        return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
#else
        return 0;
#endif
    }
};


#endif
