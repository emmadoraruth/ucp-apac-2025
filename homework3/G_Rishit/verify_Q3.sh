#!/bin/bash
echo "Compiling Q3_PriorityQueue.cpp..."
g++ -o Q3_PriorityQueue Q3_PriorityQueue.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q3_PriorityQueue..."
./Q3_PriorityQueue

echo ""
echo "Comparing Q3_output.txt with Q3_expected_output.txt..."
if diff -q Q3_output.txt Q3_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q3_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q3_output.txt
    echo ""
    echo "Differences:"
    diff Q3_expected_output.txt Q3_output.txt
fi
