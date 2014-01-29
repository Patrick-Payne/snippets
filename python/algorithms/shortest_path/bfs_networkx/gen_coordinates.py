#!/usr/bin/env python3

RESULT_FILE = "state_locations.dat"

def get_coordinates(name, x, y):
    return [name, x / 550, (367 - y) / 367]

if __name__ == '__main__':
    
    results = []
    while True:
        name = input("State name: ")
        if name == "end":
            break;

        x = float(input("x pixel no: "))
        y = float(input("y pixel no: "))

        results.append(get_coordinates(name, x, y))

    file = open(RESULT_FILE, "w")
    for state in results:
        file.write("{} {:.2f} {:.2f}\n".format(state[0], state[1], state[2]))




