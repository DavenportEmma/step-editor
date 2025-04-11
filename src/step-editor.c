#include "stubs.h"
#include "step-editor.h"
#include "sequence.h"

void edit_step_note(uint8_t step, MIDINote_t note) {
    if(xSemaphoreTake(edit_buffer_mutex, portMAX_DELAY) == pdTRUE) {
        step_t* st = &edit_buffer[step];
        st->note_on[0].note = note;

        if(st->end_of_step == 0xFF) {
            step = 0;
        } else {
            step++;
        }

        st = &edit_buffer[step];
        st->note_off[0] = note;

        xSemaphoreGive(edit_buffer_mutex);
    }
}
