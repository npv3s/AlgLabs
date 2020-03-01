# 3
ps -eo "%a" > outproc.txt
# 4
sudo cat /proc/cpuinfo | grep "cpu MHz" > cpufreq.txt
# 5
mkdir swap
sudo cat /proc/meminfo | grep Swap > ./swap/swap.txt
mkdir processes
ps aux > ./processes/processes.txt
mkdir listdir
ls -l ~ > ./listdir/listdir.txt

sudo mv ./swap ./processes
sudo mv ./processes ./listdir
# 6
while true
do
clear
ps aux
sleep 30
done
# 7
top
# 8
sudo rmdir --ignore-fail-on-non-empty ./listdir
cat /proc/cpuinfo | grep "cpu MHz"
