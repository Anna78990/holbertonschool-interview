#!/usr/bin/python3
""" Reads stdin line by line and computes metrics """
import sys


def print_stats(file_size, status_codes):
    """
    Reads stdin line by line and computes metrics
    Args:
        file_size: file size
        status_code: status code
    Returns:
        Nothing
    """
    print("File size: {}".format(file_size))
    sorted_codes = sorted(status_codes.keys())
    for code in sorted_codes:
        if status_codes[code] > 0:
            print("{}: {}".format(code, status_codes[code]))


if __name__ == '__main__':
    line_count = 0
    file_size = 0
    status_codes = {
        "200": 0,
        "301": 0,
        "400": 0,
        "401": 0,
        "403": 0,
        "404": 0,
        "405": 0,
        "500": 0
    }

    try:
        for line in sys.stdin:
            line_count += 1
            split_line = line.split()
            if len(split_line) >= 7:
                file_size += int(split_line[-1])
                status_code = split_line[-2]
                if status_code in status_codes:
                    status_codes[status_code] += 1

            if line_count % 10 == 0:
                print_stats(file_size, status_codes)

    except KeyboardInterrupt:
        print_stats(file_size, status_codes)
        raise
