# Statistics Calculator

This project provides a simple statistics calculator implemented in three different programming languages: C, OCaml, and Python. The calculator computes the mean, median, and mode of a list of integers.

## Project Structure

- `c/stats.c`: C implementation of the statistics calculator.
- `ocaml/stats.ml`: OCaml implementation of the statistics calculator.
- `python/statistic_calculator.py`: Python implementation of the statistics calculator.

## Usage

### C

1. Compile the C program:
   ```bash
   gcc -o stats c/stats.c
   ```

2. Run the compiled program:
   ```bash
   ./stats
   ```

   Enter the number of elements followed by the integers when prompted.

### OCaml

1. Compile and run the OCaml program:
   ```bash
   ocamlc -o stats ocaml/stats.ml
   ./stats <n1> <n2> ...
   ```

   Replace `<n1> <n2> ...` with the list of integers you want to calculate statistics for.

### Python

1. Run the Python script:
   ```bash
   python3 python/statistic_calculator.py <int1> <int2> ...
   ```

   Replace `<int1> <int2> ...` with the list of integers you want to calculate statistics for.

## Features

- **Mean**: Calculates the average of the list of numbers.
- **Median**: Finds the middle value when the list is sorted.
- **Mode**: Identifies the most frequently occurring number(s) in the list.

## Requirements

- **C**: GCC compiler
- **OCaml**: OCaml compiler
- **Python**: Python 3.x
