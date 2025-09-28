#!/bin/bash

# Check if a PID is provided as an argument
if [ -z "$1" ]; then
    echo "Usage: $0 <PID>"
    exit 1
fi

PID_TO_FIND="$1"

# Use ps -o to get the desired fields for the specific PID
# The 'F,S,UID,PID,PPID,C,PRI,NI,ADDR,SZ,WCHAN,TTY,TIME,CMD' format matches the requested output.
PROCESS_INFO=$(ps -o F,S,UID,PID,PPID,C,PRI,NI,ADDR,SZ,WCHAN,TTY,TIME,CMD -p "$PID_TO_FIND" --no-headers 2>/dev/null)

# Check if PROCESS_INFO is empty (i.e., process not found)
if [ -z "$PROCESS_INFO" ]; then
    echo "no process found for $PID_TO_FIND"
else
    # Print the header line first
    echo "F S UID PID PPID C PRI NI ADDR SZ WCHAN TTY TIME CMD"
    # Print the process information
    echo "$PROCESS_INFO"
fi
