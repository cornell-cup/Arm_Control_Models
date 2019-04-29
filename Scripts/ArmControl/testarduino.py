'''
Created on Dec 2, 2018

@author: dtmasetti
'''
import serial
import time
arduino = serial.Serial('COM7', 9600)
i = 0
while 1:
    i+-1
    arduino.write(int(i))
    value = arduino.read()
    print (value[0])