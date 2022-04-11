import serial, string, time, datetime
 
 #In this example /dev/ttyUSB0 is used
#This may change in your case to /dev/ttyUSB1, /dev/ttyUSB2, etc.
ser = serial.Serial('/dev/ttyACM0', 4800) #!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!MAKE SURE CORRECT PORT IS SELECTED
#to see what port, write ls /dev/tty* in terminal

#The following block of code works like this:
#If serial data is present, read the line, decode the UTF8 data,
#...remove the trailing end of line characters
#...split the data into temperature and humidity
#...remove the starting and ending pointers (< >)
#...print the output


          
          #  now = datetime.datetime.now()
          # filename = '/home/pi/log' +now.strftime ('%Y-%m-%d') + '.txt'
          #  f=open(filename,'a')
          #  f.write(now.strftime ('%H : %M : %S') + ' ' + s + '\n')


while True:

       # if ser.in_waiting > 0:
            rawserial = ser.readline()
            cookedserial = str(rawserial.decode('utf-8').strip('\r\n'))
            #datasplit = cookedserial.split(',')
            #humidity= datasplit[0].strip('<')
            #temp = datasplit[1]
            # conduct =datasplit [2]
            #ph = datasplit [3]
            #n = datasplit [4]
            #p = datasplit [5]
            #k = datasplit [6]
            #ambtemp =datasplit [7] 
            #ambhumid = datasplit [8]
            #light = datasplit[9].strip('>')
            
            print(cookedserial)
  
            #logPrint(humidity)





#f.close()