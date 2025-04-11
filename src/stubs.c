#include "stubs.h"

int xSemaphoreTake(int mutex, int delay) {
    return pdTRUE;
}

void xSemaphoreGive(int mutex) { }