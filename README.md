
# iris-electrical

IRIS Electrical Team Arduino Code Repository

## void setup()

First code run by Arduino on start

Sets up serial inputs for the sabertooth from the Odroid

Assigns the direct and pwm pins as outputs to the LACs

## void loop()

Runs after setup

Creates the checksum to make sure that the data is being passed through to the Arduino correctly

Uses largestOneIndex helper function to calculate

CRC: Cyclic Redundancy Check

If the checksum came out incorrect then it will ignore the instruction.

### Motor ID Values:

    0: Left Drive
    1: Right Drive
    2: Bucket Ladder M
    3: Dump Conveyor LA
    4: Bucket Ladder LA
    5: Agitator
    6: Dump Conveyor M
    7: Shuts off all motors

Based on the motor ID value it will call the sabertooth or the linear actuators

## void linac(int power, int motor)

Inputs: power number and the specific motor number

Outputs: direction and power specific to a motor

Creates changes with two functions:

### digitalWrite(dir\_1, (int)(OdroidIn[1]/128));

Sets the direction of a given motor

### analogWrite(pwm\_3, power\*2);

Sets the magnitude of the given motor

## void stop()

This function runs through each motor and reduces its speed to 0

## int largestOneIndex(unsignedint curr)

This function parses through curr bitwise to find the index of the most significant '1'

Inputs: curr, 16-bit chars

Outputs: integer i, the first index of '1'
