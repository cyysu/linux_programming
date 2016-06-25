#!/bin/sh

while true
do
    clear
    ps -u $USER | grep "fork$"
    sleep 1
done
