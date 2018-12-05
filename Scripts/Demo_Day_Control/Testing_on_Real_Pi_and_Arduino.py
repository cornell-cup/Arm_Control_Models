'''
Created on Nov 17, 2018
Function that can be called on R2D2 to command the arm to the location specified object recognition function output
Assumes that "ReadEncoder", "ElbowAngleLookup", and "GetObjectRecognitionLocation" functions are all available on R2 System
@author: dtmasetti
'''
import serial
import time
ser = serial.Serial('/dev/ttyACM6', 9600)
command = ["M2D130E", "M1D130E", "M2D80E", "M1D180E"]
while(1):
    ser.write(command[1].encode('utf-8'))
    time.sleep(1)
    ser.write(command[3].encode('utf-8'))
    time.sleep(1)
    ser.write(command[0].encode('utf-8'))
    time.sleep(1)
    ser.write(command[2].encode('utf-8'))
    time.sleep(1)

    

