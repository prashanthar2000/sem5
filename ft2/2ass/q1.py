import re
import sys
from datetime import datetime

fp = open(sys.argv[1],"r")
data = fp.read()
fp.close()

#filter to search for services 
pat1=".*Service.*"
matches = re.findall(pat1,data) 
services=dict() #to store all the start services

for i in matches:
    m = re.search("Starting" , i)
    if m:
        m = re.search(r'(\d*\-\d*\-\d*\s\d*:\d*:\d*.\d*)\s.*Starting Service (.*)', i)
        s_time =m.group(1)#time of start
        
        services[m.group(2)] = m.group(1)
    m = re.search("Ending" , i)
    if m:
        m = re.search(r'(\d*\-\d*\-\d*\s\d*:\d*:\d*.\d*)\s.*Ending Service (.*)', i)
        
        SERVICE = m.group(2)
        if SERVICE in services.keys(): #end of services if found in serivces , else ignore
            start_time = datetime.strptime(services[SERVICE],"%Y-%m-%d %H:%M:%S.%f")
            end_time =datetime.strptime(m.group(1) , "%Y-%m-%d %H:%M:%S.%f")
            print(SERVICE,start_time,end_time,round(1000*((end_time-start_time).total_seconds())),sep=",")
