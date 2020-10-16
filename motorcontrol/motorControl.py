#use pip3 install pyserial
import serial

def writeMotor(ser, motorID, dir, speed):
    ser.flushInput()
    # calculate cmd word based on motorID, dir, and speed
    # calculate CRC based on cmd word
    cmd = # TODO [4:0]CRC, [2:0]motorID, [0]dir, [6:0]speed
    val = bytes(str(cmd), 'utf-8')
    ser.write(val)


if (__name__ == "__main__"):
    ser = serial.Serial("/dev/ttyACM0", 9600)
    input = input("[motorId] [dir] [speed]: ")
    motorID = #some test code
    dir = #some test code
    speed = #some test code
    writeMotor(ser, motorID, dir, speed)
