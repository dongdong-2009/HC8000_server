#########################################################################
# File Name: restart.sh
# Author: fluency
# mail: 1005068694@qq.com
# Created Time: Mon 13 Nov 2017 03:22:06 PM CST
#########################################################################
#!/bin/bash
  
while true  
do   
    procnum=` ps |grep "server"|grep -v grep|wc -l`  
   if [ $procnum -eq 0 ]; then  
       /home/server/server&  
   fi
   sleep 30  
done  


