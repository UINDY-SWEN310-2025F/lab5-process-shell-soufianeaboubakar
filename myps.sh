#!/bin/bash

if [ $# -ne 1 ]; then
    echo "Usage: $0 <PID>"
    exit 1
fi

PID=$1

# Check if process with PID exists
ps -p $PID > /dev/null

if [ $? -eq 0 ]; then
    # Print header and full process info for that PID
    ps -F -p $PID
else
    echo "no process found for $PID"
fi

