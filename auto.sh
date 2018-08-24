#!/bin/bash
source env.bash
recipes=(sync-central sync-local sync-itc-coli sync-ptp-central sync-ptp-local sync-multi-control sync-multi-local sync-riptp-control sync-riptp-local sync-remote-central sync-ntp-central sync-ntp-local sync-ngsm-central sync-ngsm-local sync-port-central sync-port-local sync-eth-central sync-eth-local sync-testport-central sync-testport-local sync-pm-central linuxptp16 sync-dcg scspi sync-fm sync-pm)

echo " ">compilelog/G2G3-report.log

for file in "${recipes[@]}"
do
	
        echo " Working on $file " 
	#mkdir compilelog/$file
	WITH=lint bitbake $file >compilelog/$file/compile32.log
	WITH=lint TARGET=dusg3 bitbake $file >compilelog/$file/compile64.log

	grep -E 'WARNING|ERROR' compilelog/$file/compile32.log|grep -Eo '\[sync-.+\]'|grep -Eo 'sync(-[a-z]+)+'>compilelog/$file/Sync32.log
	grep -E 'WARNING|ERROR' compilelog/$file/compile32.log|grep -Eo '\[[a-z]+\]'|grep -Eo '[a-z]+'>>compilelog/$file/Sync32.log
	sort -n compilelog/$file/Sync32.log|uniq>compilelog/$file/SyncList32.log
	grep -E 'WARNING|ERROR' compilelog/$file/compile64.log|grep -Eo '\[sync-.+\]'|grep -Eo 'sync(-[a-z]+)+'>compilelog/$file/Sync64.log
	grep -E 'WARNING|ERROR' compilelog/$file/compile64.log|grep -Eo '\[[a-z]+\]'|grep -Eo '[a-z]+'>>compilelog/$file/Sync64.log
	sort -n compilelog/$file/Sync64.log|uniq>compilelog/$file/SyncList64.log
	
	echo " ">compilelog/$file/report32.log
	while read -r line
	do 
	echo " ">>compilelog/$file/report32.log
	echo "$line">>compilelog/$file/report32.log
	grep -E 'WARNING|ERROR' compilelog/$file/compile32.log|grep $line>>compilelog/$file/report32.log
	done < compilelog/$file/SyncList32.log

	echo " ">compilelog/$file/report64.log
	while read -r line
	do 
	echo " ">>compilelog/$file/report64.log
	echo $line>>compilelog/$file/report64.log
	grep -E 'WARNING|ERROR' compilelog/$file/compile64.log|grep $line>>compilelog/$file/report64.log
	done < compilelog/$file/SyncList64.log

	echo "\\section{${file}}" >compilelog/$file/diff-g2g3-report.log
	diff compilelog/$file/report32.log compilelog/$file/report64.log >>compilelog/$file/diff-g2g3-report.log
	cat compilelog/$file/diff-g2g3-report.log >>compilelog/G2G3-report.log
	echo " ">>compilelog/G2G3-report.log
done