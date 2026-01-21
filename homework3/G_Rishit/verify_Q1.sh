#!/bin/bash
echo "Compiling Q1_GraphAlgo.cpp..."
g++ -o Q1_GraphAlgo Q1_GraphAlgo.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q1_GraphAlgo..."
./Q1_GraphAlgo

echo ""
echo "Comparing Q1_output.txt with Q1_expected_output.txt..."
if diff -q Q1_output.txt Q1_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q1_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q1_output.txt
    echo ""
    echo "Differences:"
    diff Q1_expected_output.txt Q1_output.txt
fi
