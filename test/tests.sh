#!/bin/bash
parent_path=$( cd "$(dirname "${BASH_SOURCE[0]}")" ; pwd -P )
bin="$parent_path/../bin/tp2"

garbagefile="$parent_path/files/_garbage.txt"
testfile="$parent_path/files/test_1_signals_10000_points.txt"
testfile2="$parent_path/files/test_10_signals_1000_points.txt"
testfile3="$parent_path/files/test_100_signals_100_points.txt"

test_fft_1_signal_10000_points() {
  echo "FFT 1 signal 10000 points x100 runs"

  max=100
  for i in `seq 2 $max`
  do
    $bin -i $testfile -o $garbagefile
  done
}

test_fft_10_signal_1000_points() {
  echo "FFT 10 signals 1000 points x100 runs"

  max=100
  for i in `seq 2 $max`
  do
    $bin -i $testfile2 -o $garbagefile
  done
}

test_fft_100_signal_100_points() {
  echo "FFT 100 signals 100 points x100 runs"

  max=100
  for i in `seq 2 $max`
  do
    $bin -i $testfile3 -o $garbagefile
  done
}

test_dft_1_signal_10000_points() {
  echo "DFT 1 signal 10000 points x10 runs"

  max=10
  for i in `seq 2 $max`
  do
    $bin -m DFT -i $testfile -o $garbagefile
  done
}

test_dft_10_signal_1000_points() {
  echo "DFT 10 signals 1000 points x10 runs"

  max=10
  for i in `seq 2 $max`
  do
    $bin -m DFT -i $testfile2 -o $garbagefile
  done
}

test_dft_100_signal_100_points() {
  echo "DFT 100 signals 100 points x10 runs"

  max=10
  for i in `seq 2 $max`
  do
    $bin -m DFT -i $testfile3 -o $garbagefile
  done
}

echo ""
time test_fft_1_signal_10000_points
echo "Done."

echo ""
time test_fft_10_signal_1000_points
echo "Done."

echo ""
time test_fft_100_signal_100_points
echo "Done."

echo ""
time test_dft_1_signal_10000_points
echo "Done."

echo ""
time test_dft_10_signal_1000_points
echo "Done."

echo ""
time test_dft_100_signal_100_points
echo "Done."

