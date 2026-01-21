#!/bin/bash
echo "Compiling Q4_NumberOfIslands.cpp..."
g++ -o Q4_NumberOfIslands Q4_NumberOfIslands.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q4_NumberOfIslands..."
./Q4_NumberOfIslands

echo ""
echo "Comparing Q4_output.txt with Q4_expected_output.txt..."
if diff -q Q4_output.txt Q4_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q4_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q4_output.txt
    echo ""
    echo "Differences:"
    diff Q4_expected_output.txt Q4_output.txt
fi
