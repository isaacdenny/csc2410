#!/bin/bash
# Number of runs
num_runs=10
# Output file for storing results
output_file="performance_results.txt"
# Clear previous results if they exist
> $output_file
echo "Running performance comparison with and without core affinity..."

for ((i = 1; i <= num_runs; i++))
do
	echo "Run $i with core affinity..."
	# Run with core affinity (set_affinity=1)
	./performance_comparison_affinity 1 >> $output_file
	echo "Run $i without core affinity..."
	# Run without core affinity (set_affinity=0)
	./performance_comparison_affinity 0 >> $output_file
	sleep 1 # Delay between runs for consistency
done

echo "All runs completed. Results saved to $output_file."
