def f6(first: str, second: str) -> bool:
    """Trying to find the second word in the doubled first"""

    if len(first) != len(second):
        return False

    return search_word(first * 2, second)


def search_word(text: str, word: str) -> bool:
    """Linear algorithm KMP"""

    word_prefixes = prefix(word)
    matches = 0
    for symbol in text:
        while matches > 0 and word[matches] != symbol:
            matches = word_prefixes[matches-1]

        matches = matches + (word[matches] == symbol)
        if matches == len(word):
            return True
    return False


def prefix(word: str) -> list:
    """Linear algorithm to fill an array with maximum values
        when the prefix is equal to the suffix"""

    result = [0] * len(word)

    prefix_len = 0
    for i in range(1, len(word)):

        while prefix_len > 0 and word[prefix_len] != word[i]:
            prefix_len = result[prefix_len-1]

        prefix_len = prefix_len + (word[prefix_len] == word[i])
        result[i] = prefix_len
    return result


def demonstration():
    print('F6 starts.\nTo close program enter #')
    while True:
        a = input('enter first string: ')
        if a == '#':
            break
        b = input('enter second string: ')
        if b == '#':
            break

        print('cycle' if f6(a, b) else 'not cycle')

    print('Have a nice day!')


if __name__ == '__main__':
    demonstration()
