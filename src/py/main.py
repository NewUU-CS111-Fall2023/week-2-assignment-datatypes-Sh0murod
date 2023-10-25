# * Author:Shomurod Anvarov SSE1 20221400164
# * Date: 25.10.2023
1
year = int(input("year: "))

if year % 400 == 0:
    leap = True
elif year % 100 == 0:
    leap = False
elif year % 4 == 0:
    leap = True
else:
    leap = False

if leap:
    print(year, " – leap year.")
else:
    print(year, " – non-leap year.")

2

import random

correct = int(input("Write a correct number:"))
random = random.randint(1, 100)
while correct != random:
 if correct < random:
  print("low")
  correct = int(input("Write a correct number:"))
 elif correct > random:
  print("high")
  correct = int(input("Write a correct number:"))
if correct == random:
 print("Congratulations !!! You have found a number")

3

sentence = input("sentence: ")
word = input("word to search for: ")
sentence = sentence.lower()
word = word.lower()
if word in sentence:
    index = sentence.find(word)
    print(f"The word '{word}' was found at index {index} in the sentence.")
else:
    print("no match")

4

import random
digits = [random.randint(0, 9) for _ in range(100)]
number = int(''.join(map(str, digits)))
print(number)
number_A = int(input("number:"))
result = number / number_A
print(result)

