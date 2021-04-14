import re 
import sys
import datetime

fp = open(sys.argv[1] , 'r')
# count = 0
d = {}

while True:
    i = fp.readline()
    if not i:
        break
    # print(i, count)
    # count += 1
    if "Starting Service"  in i:
        # print(i)
        m = re.search(r'(\d+\-\d+\-\d+\s\d+:\d+:\d+.\d*)\s.*Starting Service (.+)', i)
        d[m.group(2)] = m.group(1)
        # print(m.groups())
        # print(d)
    elif "Ending Service" in i:
        m = re.search(r'(\d+\-\d+\-\d+\s\d+:\d+:\d+.\d*)\s.*Ending Service (.+)', i)
        if m.group(2) in d.keys():
            a = datetime.datetime.strptime(d[m.group(2)] , "%Y-%m-%d %H:%M:%S.%f")
            b = datetime.datetime.strptime(m.group(1),"%Y-%m-%d %H:%M:%S.%f" )
            time_diff = round((b -a).total_seconds() * 1000)
            print(m.group(2),d[m.group(2)],m.group(1),time_diff, sep=",")
