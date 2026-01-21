#!/bin/bash
echo "Compiling Q9_MergeKSortedArrays.cpp..."
g++ -std=c++17 -o Q9_MergeKSortedArrays Q9_MergeKSortedArrays.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q9_MergeKSortedArrays..."
./Q9_MergeKSortedArrays

echo ""
echo "Comparing Q9_output.txt with Q9_expected_output.txt..."
if diff -q Q9_output.txt Q9_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q9_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q9_output.txt
fi
