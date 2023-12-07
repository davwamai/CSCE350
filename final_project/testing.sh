#!/bin/bash

# directories for output and time files
outputDir="output_files/"
timeDir="time_files/"

# output file for execution times
executionTimeFile="Wamai_David_executionTime.txt"
averageExecutionTimeFile="Wamai_David_averageExecutionTime.txt"

# clear the execution time file if it already exists
> $executionTimeFile

# function to run sort and record execution time
runQuicksort() {
    size=$1
    index=$2
    inputFile="input${size}_${index}.txt"
    outputFile="output${size}_${index}.txt"
    timeFile="${timeDir}output${size}_${index}_time.txt"

    ./Wamai_David_Quicksort $inputFile $outputFile

    if [ -f $timeFile ]; then
        read -r time < $timeFile
        echo -e "$size\t$time" >> $executionTimeFile
    else
        echo "Time file $timeFile not found."
    fi
}

sizes=(10 100 1000)

# loop through each size and file index
for size in "${sizes[@]}"; do
    for i in {0..24}; do
        runQuicksort $size $i
    done
done

echo "Execution times recorded in $executionTimeFile"

