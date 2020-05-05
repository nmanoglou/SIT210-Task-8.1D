import RPi.GPIO as GPIO
from smbus import SMBus
import time

GPIO.setmode(GPIO.BCM)

# set up the bus on address 40 on I2C channel 1
address = 0x40
bus = SMBus(1)

toggle = True

# the RPI will send a "1" to the argon when toggle is set to true and will send a "0
# when toggle is false
try:
    while True:
        if (toggle):
            bus.write_byte(address, 1)
            toggle = False
        elif (toggle == False):
            bus.write_byte(address, 0)
            toggle = True
        else:
            exit()

        time.sleep(0.5)
        
        
except KeyboardInterrupt:
    print("Goodbye")