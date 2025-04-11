#ifndef _STUBS_H
#define _STUBS_H

#define pdTRUE 1
#define portMAX_DELAY 10
#define edit_buffer_mutex 1

int xSemaphoreTake(int mutex, int delay);
void xSemaphoreGive(int mutex);

#endif