#!/bin/bash
echo "Compiling Q11_VacationDestinations.cpp..."
g++ -std=c++17 -o Q11_VacationDestinations Q11_VacationDestinations.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q11_VacationDestinations..."
./Q11_VacationDestinations

echo ""
echo "Comparing Q11_output.txt with Q11_expected_output.txt..."
if diff -q Q11_output.txt Q11_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q11_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q11_output.txt
fi
