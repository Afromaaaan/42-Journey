#!/bin/bash

source ./tester/colors.sh

loops=250

max_result_100=0
max_result_500=0
min_result_100=999999
min_result_500=999999
total_result_100=0
total_result_500=0


logHeader "-----------------------------------\n"
logHeader "|                                 |\n"
logHeader "|     Size: 100    Loops: 250     |\n"
logHeader "|                                 |\n"
logHeader "-----------------------------------\n"
log "\n"

for ((i = 0; i < $loops; i++)); do
	numbers=($(shuf -i 1-100 -n 100 | tr '\n' ' '))
	numbers_string="${numbers[*]}"

	result=$(./push_swap "$numbers_string" | wc -l)

	if ((result > max_result_100)); then
		max_result_100=$result
	fi

	if ((result < min_result_100)); then
		min_result_100=$result
	fi

	total_result_100=$((total_result_100 + result))
done

average_result=$((total_result_100 / $loops))

log "Max value: "
if ((max_result_100 > 700)); then
	logError "$max_result_100\n"
else
	logCorrect "$max_result_100\n"
fi

log "Min value: "
if ((min_result_100 > 700)); then
	logError "$min_result_100\n"
else
        logCorrect "$min_result_100\n"
fi

log "Average: "
if ((average_result > 700)); then
        logError "$average_result\n"
else
        logCorrect "$average_result\n"
fi

log "Grade: "
if ((max_result_100 > 1500)); then
	logError "0/5\n"
elif ((max_result_100 > 1300)); then
	logCorrect "1/5\n"
elif ((max_result_100 > 1100)); then
	logCorrect_100 "2/5\n"
elif ((max_result_100 > 900)); then
	logCorrect "3/5\n"
elif ((max_result_100 > 700)); then
	logCorrect "4/5\n"
else
	logCorrect "5/5\n"
fi

log "\n\n"

logHeader "-----------------------------------\n"
logHeader "|                                 |\n"
logHeader "|     Size: 500    Loops: 250     |\n"
logHeader "|                                 |\n"
logHeader "-----------------------------------\n"
log "\n"

for ((i = 0; i < $loops; i++)); do
	numbers=($(shuf -i 1-500 -n 500 | tr '\n' ' '))
	numbers_string="${numbers[*]}"

	result=$(./push_swap "$numbers_string" | wc -l)

	if ((result > max_result_500)); then
		max_result_500=$result
	fi

	if ((result < min_result_500)); then
		min_result_500=$result
	fi

	total_result_500=$((total_result_500 + result))
done

average_result=$((total_result_500 / $loops))

log "Max value: "
if ((max_result_500 > 5500)); then
	logError "$max_result_500\n"
else
	logCorrect "$max_result_500\n"
fi

log "Min value: "
if ((min_result_500 > 5500)); then
	logError "$min_result_500\n"
else
        logCorrect "$min_result_500\n"
fi

log "Average: "
if ((average_result > 5500)); then
        logError "$average_result\n"
else
        logCorrect "$average_result\n"
fi

log "Grade: "
if ((max_result_500 > 11500)); then
	logError "0/5\n"
elif ((max_result_500 > 10000)); then
	logCorrect "1/5\n"
elif ((max_result_500 > 8500)); then
	logCorrect "2/5\n"
elif ((max_result_500 > 7000)); then
	logCorrect "3/5\n"
elif ((max_result_500 > 5500)); then
	logCorrect "4/5\n"
else
	logCorrect "5/5\n"
fi

log "\n\n"