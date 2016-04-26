import time
from serial import Serial

serial_port = Serial(port='/dev/ttyUSB0', baudrate=9600)

while(True):
	serial_port.readline()
	time.sleep(1000)
