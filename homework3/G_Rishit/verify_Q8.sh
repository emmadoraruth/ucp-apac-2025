#!/bin/bash
echo "Compiling Q8_AlternatingPath.cpp..."
g++ -std=c++17 -o Q8_AlternatingPath Q8_AlternatingPath.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q8_AlternatingPath..."
./Q8_AlternatingPath

echo ""
echo "Comparing Q8_output.txt with Q8_expected_output.txt..."
if diff -q Q8_output.txt Q8_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q8_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q8_output.txt
fi
