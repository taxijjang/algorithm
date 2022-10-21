class LetterFilter:

    def __init__(self, s):
        self.s = s
        self.vowels = ['a', 'e', 'i', 'o', 'u']
        self.consonants = ['b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'y', 'z']

    # Enter your code here.
    # Complete the classes below.
    # Reading the inputs and writing the outputs are already done for you.
    #
    # class LetterFilter:
    #
    #   def __init__(self, s):
    #       self.s = s

    def filter_vowels(self):
        word = self.s
        for vowel in self.vowels:
            word = word.replace(vowel, '')
        return word

    def filter_consonants(self):
        word = self.s
        for consonant in self.consonants:
            word = word.replace(consonant, '')
        return word


# Enter your code here
# Return a string

s = input()
f = LetterFilter(s)
print(f.filter_vowels())
print(f.filter_consonants())