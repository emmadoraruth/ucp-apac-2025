#!/bin/bash
echo "Compiling Q2_Heap.cpp..."
g++ -o Q2_Heap Q2_Heap.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q2_Heap..."
./Q2_Heap

echo ""
echo "Comparing Q2_output.txt with Q2_expected_output.txt..."
if diff -q Q2_output.txt Q2_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q2_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q2_output.txt
    echo ""
    echo "Differences:"
    diff Q2_expected_output.txt Q2_output.txt
fi
