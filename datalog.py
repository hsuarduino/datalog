import csv, datetime, serial

ser = serial.Serial('COM4', 9600, timeout = .1)
n = 1

def write():
  global n, filedate, dat, out
  with open('datalog'+str(filedate)+'.csv', 'a') as csvfile:
    chcalwriter = csv.writer(csvfile, delimiter=',', quotechar='|', lineterminator='\n')
    chcalwriter.writerow([str(datetime.datetime.now()) + "," + dat + "," + "reading # " + str(n)])
    
while True:  
  global dat
  dat = ser.readline()
  filedate = datetime.date.today()
  if dat:
    write()
    n = n + 1