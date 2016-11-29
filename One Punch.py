#import different graphing packages that are needed
import pylab
import os
import matplotlib.pyplot as plt
import numpy as np

#make path to file
script_dir = os.path.split(os.path.realpath(__file__))[0]
datapath = script_dir+"/DATALOG.TXT"

#open file
input = open(datapath);

#find index for last round
mark = 0
line = input.readline()
while line != "":
    if "New Round" in line:

        mark = input.tell()

    line = input.readline()
input.seek(mark)
input.readline()

#split into different columns

time = []
force = []
speed = []

for line in input:

    words = line.split()
    time.append(int(words[0]))  #first column is time
    force.append(int(words[1]))  #second is force
    speed.append(float(words[2]))  #third is force
input.close()

#plot time versus force
f1 = plt.figure()
plt.ylim([400,800])  #better focuses the graph

myvec = np.array([time,force])
plt.plot(myvec[0,],myvec[1,],'ro')
plt.xlabel('Time Stamp')
plt.ylabel('Force')
plt.title('Force Values for Newest Round of Data')
   
#plot time versus speed 
f2 = plt.figure()
plt.ylim([3,9])

myvec1 = np.array([time,speed])
plt.plot(myvec1[0,],myvec1[1,],'bo')
plt.xlabel('Time Stamp')
plt.ylabel('Speed')
plt.title('Speed Values for Newest Round of Data')

plt.show()
