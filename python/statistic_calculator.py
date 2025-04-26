#!/usr/bin/env python3
from collections import Counter
import sys

class StatisticsCalculator:
    def __init__(self, data):
        self.data = data

    def mean(self):
        return sum(self.data) / len(self.data) if self.data else 0

    def median(self):
        s = sorted(self.data)
        n = len(s)
        mid = n // 2
        if n % 2 == 0:
            return (s[mid - 1] + s[mid]) / 2
        return s[mid]

    def mode(self):
        if not self.data:
            return [], 0
        counts = Counter(self.data)
        max_count = max(counts.values())
        modes = [k for k, v in counts.items() if v == max_count]
        return modes, max_count

def main():
    if len(sys.argv) < 2:
        print(f"Usage: {sys.argv[0]} <int1> <int2> ...")
        sys.exit(1)

    nums = list(map(int, sys.argv[1:]))
    calc = StatisticsCalculator(nums)

    print(f"Mean: {calc.mean():.2f}")
    print(f"Median: {calc.median():.2f}")
    modes, freq = calc.mode()
    print(f"Mode ({freq} occurrences): {', '.join(map(str, modes))}")

if __name__ == "__main__":
    main()
