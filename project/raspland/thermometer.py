import os
import time
comand = '{"celcius":"10","isMotorActived":"false","humidity":"50"}'
os.system('curl -i -X POST -H "Content-Type:application/json" -d '+comand+' https://api.mlab.com/api/1/databases/arduiland/collections/Temperature?apiKey=e16CW-yUW4cxtREIjflDYuVWANP6V70W')
