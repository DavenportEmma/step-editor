import argparse
import json

class Step:
    def __init__(self, note_on, note_off, end_of_step):
        self.note_on = note_on
        self.note_off = note_off
        self.eos = end_of_step

    def stringify(self):
        s = "{{"

        for n in self.note_on:
            s+="{"
            s+="{},{}".format(n['note'], n['velocity'])
            s+="},"

        s+="}, {"

        for n in self.note_off:
            s+="{},".format(n)

        s+="}, "

        s+=str(self.eos)

        s+="}"

        return s

class Sequence:
    def __init__(self, steps):
        self.steps = steps

    def stringify(self):
        s = "{\n"

        for step in self.steps:
            s+="\t{},\n".format(step.stringify())

        s += "}"

        return s

def main(args):
    with open(args.input, "r") as input_file:
        sequence_data = json.load(input_file)
    
    steps = []
    for s in sequence_data:
        steps.append(
            Step(s['note_on'], s['note_off'], s['end_of_step'])
        )
        
    seq = Sequence(steps)

    out = """#ifndef _SEQUENCE_H
#define _SEQUENCE_H
#include \"step-editor.h\"

step_t edit_buffer[] = {};
#endif""".format(seq.stringify())

    with open(args.output, "w") as out_file:
        out_file.write(out)
    

if __name__ == "__main__":
    parser = argparse.ArgumentParser()

    parser.add_argument(
        "-i",
        "--input",
        type=str,
        help="input json file"
    )

    parser.add_argument(
        "-o",
        "--output",
        type=str,
        help="output c header file"
    )

    args = parser.parse_args()

    main(args)