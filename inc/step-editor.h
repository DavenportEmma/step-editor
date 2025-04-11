#ifndef _STEP_EDITOR_H
#define _STEP_EDITOR_H

#include "stdint.h"
#include "stubs.h"

typedef struct {
    MIDINote_t note;
    uint8_t velocity;
} note_t;

typedef struct {
    note_t note_on[CONFIG_MAX_POLYPHONY];
    MIDINote_t note_off[CONFIG_MAX_POLYPHONY];
    uint8_t end_of_step;
} step_t;

/*
    edit note should edit the note on for the step and update the note off
    for the next step. edit step note should allow the user to send a note from
    a midi controller
*/
void edit_step_note(uint8_t step, MIDINote_t note);
void edit_step_velocity(uint8_t step, uint8_t velocity);

/*
    step disabled/enabled information should be held at the sequence level like
    mute/unmute

*/
void disable_step(uint8_t step);
void enable_step(uint8_t step);

/*
    mute and unmute should probably be held at the sequence level. perhaps
    there is a muted step mask in the struct representing the sequence.

    the note off commands in each step should still be sent even if the step
    is muted
*/
// void mute_step(uint8_t step);
// void unmute_step(uint8_t step);

#endif 