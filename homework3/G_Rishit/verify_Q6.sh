#!/bin/bash
echo "Compiling Q6_RoadNetworks.cpp..."
g++ -o Q6_RoadNetworks Q6_RoadNetworks.cpp

if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi

echo "Running Q6_RoadNetworks..."
./Q6_RoadNetworks

echo ""
echo "Comparing Q6_output.txt with Q6_expected_output.txt..."
if diff -q Q6_output.txt Q6_expected_output.txt > /dev/null; then
    echo "✓ Output matches expected output!"
else
    echo "✗ Output differs from expected output."
    echo ""
    echo "Expected output:"
    cat Q6_expected_output.txt
    echo ""
    echo "Actual output:"
    cat Q6_output.txt
    echo ""
    echo "Differences:"
    diff Q6_expected_output.txt Q6_output.txt
fi
