#!/bin/bash
echo "Compiling Q7_ReverseWords.cpp..."
g++ -o Q7_ReverseWords Q7_ReverseWords.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q7_ReverseWords..."
./Q7_ReverseWords

echo ""
echo "Comparing Q7_output.txt with Q7_expected_output.txt..."
if diff -q Q7_output.txt Q7_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q7_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q7_output.txt
fi
