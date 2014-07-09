
import serial
import time

ser = serial.Serial('/dev/tty.usbmodem1411', 9600)

time.sleep(1)

print ser.name

while(1):
  word = raw_input('> ')

  if(word == "end"):
    break;

  #Sends the text one character at a time
  for x in range(0, len(word)):
    ser.write(word[x])
    time.sleep(.01)

#Closes the connection
ser.close()
