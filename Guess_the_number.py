import random

number = random.randint(1, 10)
guess_the_number = None
print("You only get 3 chances!")
for i in range(3):
    guess_the_number = int(input("guess a number between 1 and 10: "))
    if guess_the_number == number:
        print("HURRAY YOU GUESSED IT!")
        break
    else:
        print("YOU GUESSED IT WRONG!")
        if (guess_the_number > number):
            print("Too high!")
        else:
            print("Too low!")
