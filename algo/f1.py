from typing import Optional
from os.path import exists
import random


def f1(input_file: str, output_file: str, n) -> None:
    temp_names = [f'temp_{i}' for i in range(n)]
    split_files(*temp_names, input_file=input_file)

    while True:
        merge_files(*temp_names, output_file=output_file)
        if split_files(*temp_names, input_file=output_file):
            return


def split_files(*files, input_file: str) -> bool:
    temp_files = [open(file, 'wt') for file in files]
    file_sorted = True
    with open(input_file, mode='rt') as file:
        last = None
        while True:
            numbers = [next_number(file) for _ in range(len(files))]

            if None in numbers:
                if all((i is None for i in numbers)):
                    break
                numbers.remove(None)
            if last is not None:
                if last > numbers[0]:
                    file_sorted = False
            last = numbers[-1]
            if numbers[0] != min(numbers):
                file_sorted = False

            for i, number in enumerate(sorted(numbers)):
                if number is not None:
                    append_number(temp_files[i], number)

    [file.close() for file in temp_files]
    return file_sorted


def merge_files(*files, output_file: str):
    temp_files = [open(file, 'rt') for file in files]
    numbers = [next_number(file) for file in temp_files]

    def clear():
        while None in numbers:
            index = numbers.index(None)
            numbers.pop(index)
            temp_files[index].close()
            temp_files.pop(index)

    with open(output_file, mode='wt') as file:
        while True:
            clear()
            if not numbers:
                break
            min_index, _ = min(enumerate(numbers), key=lambda x: x[1])
            append_number(file, numbers[min_index])
            numbers[min_index] = next_number(temp_files[min_index])


def next_number(file) -> Optional[int]:
    number = ''
    while True:
        char = file.read(1)
        if char == '\t':
            return int(number)
        if not char:
            return None
        number += char


def append_number(file, number: int):
    file.write(f'{number}\t')


def fill_random(file_name, left, right, n):
    if left > right:
        left, right = right, left

    with open(file_name, mode='wt') as file:
        for i in (random.randint(left, right) for _ in range(n)):
            append_number(file, i)


def demonstration():
    input_name = 'input.txt'
    output_name = 'output.txt'
    print(f'F1 starts. Reading data from {input_name}...')

    if not exists(input_name):
        fill_random(input_name, -9, 20, 9)

    f1(input_name, output_name, 2)

    print(f'Have a nice day! Result saved in {output_name} file')


if __name__ == '__main__':
    demonstration()
