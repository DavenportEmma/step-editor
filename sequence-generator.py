import argparse
import json

def main(args):
    with open(args.input, "r") as input_file:
        sequence_data = json.load(input_file)

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