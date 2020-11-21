import functools


def f7(text: str, sub_text: str) -> (int, int):
    return -1, -1


def rabin_karp(text: str, sub_text: str) -> int:
    if len(text) < len(sub_text):
        return -1

    sub_hash = functools.reduce(next_poly, sub_text, 0)
    size = len(sub_text)
    start = text[:size]
    cur_hash = functools.reduce(next_poly, start, 0)

    if sub_hash == cur_hash and start == sub_text:
        return 0

    for right in range(size, len(text)):
        left = right - size
        cur_hash = next_poly(cur_hash - ord(text[left]) * 2 ** (size - 1), text[right])
        if cur_hash == sub_hash and sub_text == text[left + 1: right + 1]:
            return left + 1

    return -1


def next_poly(now, char, p=53):
    return (now * p + ord(char)) % 2147483647


def demonstration():
    print('F7 starts.')
    a = input('enter string (MxM): ')
    b = input('enter sub_string (NxN): ')

    print(f7(a, b))

    print('Have a nice day!')


if __name__ == '__main__':
    demonstration()
