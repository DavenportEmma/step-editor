#ifndef _STEP_EDITOR_H
#define _STEP_EDITOR_H

#define CONFIG_MAX_POLYPHONY 1

typedef enum {
    C8      = 0x6C,
    B7      = 0x6B,
    ASHARP7 = 0x6A,
    A7      = 0x69,
    GSHARP7 = 0x68,
    G7      = 0x67,
    FSHARP7 = 0x66,
    F7      = 0x65,
    E7      = 0x64,
    DSHARP7 = 0x63,
    D7      = 0x62,
    CSHARP7 = 0x61,
    C7      = 0x60,
    B6      = 0x5F,
    ASHARP6 = 0x5E,
    A6      = 0x5D,
    GSHARP6 = 0x5C,
    G6      = 0x5B,
    FSHARP6 = 0x5A,
    F6      = 0x59,
    E6      = 0x58,
    DSHARP6 = 0x57,
    D6      = 0x56,
    CSHARP6 = 0x55,
    C6      = 0x54,
    B5      = 0x53,
    ASHARP5 = 0x52,
    A5      = 0x51,
    GSHARP5 = 0x50,
    G5      = 0x4F,
    FSHARP5 = 0x4E,
    F5      = 0x4D,
    E5      = 0x4C,
    DSHARP5 = 0x4B,
    D5      = 0x4A,
    CSHARP5 = 0x49,
    C5      = 0x48,
    B4      = 0x47,
    ASHARP4 = 0x46,
    A4      = 0x45,
    GSHARP4 = 0x44,
    G4      = 0x43,
    FSHARP4 = 0x42,
    F4      = 0x41,
    E4      = 0x40,
    DSHARP4 = 0x3F,
    D4      = 0x3E,
    CSHARP4 = 0x3D,
    C4      = 0x3C,
    B3      = 0x3B,
    ASHARP3 = 0x3A,
    A3      = 0x39,
    GSHARP3 = 0x38,
    G3      = 0x37,
    FSHARP3 = 0x36,
    F3      = 0x35,
    E3      = 0x34,
    DSHARP3 = 0x33,
    D3      = 0x32,
    CSHARP3 = 0x31,
    C3      = 0x30,
    B2      = 0x2F,
    ASHARP2 = 0x2E,
    A2      = 0x2D,
    GSHARP2 = 0x2C,
    G2      = 0x2B,
    FSHARP2 = 0x2A,
    F2      = 0x29,
    E2      = 0x28,
    DSHARP2 = 0x27,
    D2      = 0x26,
    CSHARP2 = 0x25,
    C2      = 0x24,
    B1      = 0x23,
    ASHARP1 = 0x22,
    A1      = 0x21,
    GSHARP1 = 0x20,
    G1      = 0x1F,
    FSHARP1 = 0x1E,
    F1      = 0x1D,
    E1      = 0x1C,
    DSHARP1 = 0x1B,
    D1      = 0x1A,
    CSHARP1 = 0x19,
    C1      = 0x18,
    B0      = 0x17,
    ASHARP0 = 0x16,
    A0      = 0x15
} MIDINote_t;


typedef struct {
    MIDINote_t note;
    uint8_t velocity;
} note_t;

typedef struct {
    note_t note_on[CONFIG_MAX_POLYPHONY];
    MIDINote_t note_off[CONFIG_MAX_POLYPHONY];
    uint8_t end_of_step;
} step_t;

#endif 