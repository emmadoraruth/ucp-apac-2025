#!/bin/bash
echo "Compiling Q5_FirstKBinaryNumbers.cpp..."
g++ -o Q5_FirstKBinaryNumbers Q5_FirstKBinaryNumbers.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q5_FirstKBinaryNumbers..."
./Q5_FirstKBinaryNumbers

echo ""
echo "Comparing Q5_output.txt with Q5_expected_output.txt..."
if diff -q Q5_output.txt Q5_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q5_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q5_output.txt
    echo ""
    echo "Differences:"
    diff Q5_expected_output.txt Q5_output.txt
fi
