#!/bin/bash
source env.bash
grep 'WARNING' warning32.log|grep -Eo '\[sync-.+\]'|grep -Eo 'sync(-[a-z]+)+'>Sync32.log
grep 'WARNING' warning32.log|grep -Eo '\[[a-z]+\]'|grep -Eo '[a-z]+'>>Sync32.log
sort -n Sync32.log|uniq>SyncList32.log
grep 'WARNING' warning64.log|grep -Eo '\[sync-.+\]'|grep -Eo 'sync(-[a-z]+)+'>Sync64.log
grep 'WARNING' warning64.log|grep -Eo '\[[a-z]+\]'|grep -Eo '[a-z]+'>>Sync64.log
sort -n Sync64.log|uniq>SyncList64.log

while read -r line
do 
echo " ">>report32.log
echo $line>>report32.log
grep 'WARNING' warning32.log|grep '$line'>>report32.log
done < SyncList32.log

while read -r line
do 
echo " ">>report64.log
echo $line>>report64.log
grep 'WARNING' warning64.log|grep '$line'>>report64.log
done < SyncList64.log