# Fantasy Race Simulation

This project simulates three fantasy races (Orcs, Humans, and Elves) using object-oriented programming concepts in C++. It was developed as a project for an Advanced Programming course to demonstrate the application of concepts learned in class.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Usage](#usage)
- [Implementation Details](#implementation-details)
- [How to Run](#how-to-run)

## Introduction

The project creates and manages information about fantasy races through structures and unions in C++. Each race (Orcs, Humans, and Elves) has specific attributes and behaviors defined by structures. The program allows for manual or random generation of race attributes and displays their information accordingly.

## Features

- **Object-Oriented Approach**: Uses structures (`struct`) and unions (`union`) to encapsulate attributes and behaviors of each fantasy race.
- **Dynamic Memory Allocation**: Allows for the creation of arrays of race objects based on user input.
- **Manual and Random Data Generation**: Provides options for manually entering race attributes or generating them randomly.
- **Flexible and Extensible**: Easily extendable to add more races or attributes due to modular design.

## Usage

The program presents a menu where the user can choose:
1. The race to simulate (Orcs, Humans, or Elves).
2. Whether to generate a single race instance or an array of instances.
3. How to fill the attributes of each race instance (manual input or random generation).

After filling the attributes, the program displays the details of each created instance, including characteristics like strength, intelligence, occupation, and weapon details.

## Implementation Details

### Structures and Unions
- **Orcs**: Attributes include strength, skin color, level, height, and weapon details.
- **Humans**: Attributes include age, intelligence, occupation, height, and weapon details.
- **Elves**: Attributes include magic ability, ability level, rank, height, and weapon details.
- **Height Union**: Stores height information specific to each race.

### Functions
- **Manual and Random Fill Functions**: Separate functions for manually inputting or randomly generating attributes for each race.
- **Show Info Functions**: Display functions to print detailed information about each race instance.

### Main Functionality
- Uses `switch` statements and user input to guide the flow of the program based on chosen options.

## How to Run

To compile and run the program:
1. Ensure you have a C++ compiler installed (e.g., g++ for Linux, MinGW for Windows).
2. Clone the repository or download the source files.
3. Navigate to the directory containing the source code files.
4. Compile the code.
5. Run the executable.
