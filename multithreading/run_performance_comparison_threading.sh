#!/bin/bash
# Number of runs
num_runs=10

# Output file for storing results
output_file="performance_results_threading.txt"

# Clear previous results if they exist
> $output_file

echo "Running performance comparison with and without
multithreading..."

for ((i = 1; i <= num_runs; i++))
do

	echo "Run $i with multithreading..."

	# Run with multithreading (use_multithreading=1)
	./performance_comparison_threading 1 >> $output_file

	echo "Run $i without multithreading..."

	# Run without multithreading (single-threaded, use_multithreading=0)
	./performance_comparison_threading 0 >> $output_file

	sleep 1 # Delay between runs for consistency

done

echo "All runs completed. Results saved to $output_file."
