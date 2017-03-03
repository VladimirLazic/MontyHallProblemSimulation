#A python program that simulates the Monty Hall problem
import random

NUMBER_OF_DOORS = 3
NUMBER_OF_TRIES = 1000000

numberOfCorrect = 0
numberOfIncorrect = 0

print("Simulation of the Monty Hall problme")
print("Starting the quiz")

for i in range(0 , NUMBER_OF_TRIES - 1):
    print("Setting the doors")
    doors = [False , False , False]
    doors[random.randint(0 , 2)] = True

    my_pick = random.randint(0 , 2)

    #Eliminating a false door
    eliminated_door = -1
    for i in range(len(doors)):
        if(doors[i] == False and i != my_pick):
            eliminated_door = i
            break

    #New pick
    for i in range(len(doors)):
        if(i != my_pick and i != eliminated_door):
            my_pick = i
            break

    if(doors[my_pick] == True):
        numberOfCorrect = numberOfCorrect + 1
        print("Behind door number " , my_pick , "was a car!")
    else:
        numberOfIncorrect = numberOfIncorrect + 1
        print("Behind door number " , my_pick , "was a goat!")

print("Number of correct: " , numberOfCorrect , "\nNumber of Incorrect " , numberOfIncorrect)
print("Probability ratio : ", 100*(numberOfCorrect/NUMBER_OF_TRIES), "%")
