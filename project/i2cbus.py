import smbus
import time

bus = smbus.SMBus(1)
address_datas = 0x14

def getTemperature():
        return bus.read_byte_data(address_datas, 100)

def getHumidity():
        return bus.read_byte_data(address_datas, 101)

def getMotorActivity():
        return bus.read_byte_data(address_datas, 102)

def setTemperatureLimit(limit):
        bus.write_byte(address_datas, limit)

setTemperatureLimit(24)

while True:
        tmp = getTemperature()
        print("Temperature: " + str(tmp) + " degrees")
        hum = getHumidity()
        print("Humidity: " + str(hum) + " %")
        mot = getMotorActivity()
        print("Motor activity: " + str(mot))

        #setTemperatureLimit(24)
        time.sleep(5)
