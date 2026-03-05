# CRICKET GAME 
# THIS IS AN ASSIGNMENT OF COMPUTER SCIENCE MADE BY STUDENTS STUDYING IN CLASS 12th D, SSAV SCHOOL.
# NAME OF THE STUDENTS -> Khushbu Jain, Kalash Jain

print("\n-----WELCOME TO THIS CRICKET GAME-----\n:::\n1. You have to select any random number from 0 to 6. \n2. The computer will also select a number. \n3. While batting, if the number selected by you and computer is different, then your number will add to your runs.\nIf the number selected by you and computer is same, then you will lose your wicket. \n4. While bowling, if the number selected by you and computer is different, then the computer's number will add to its runs.\nIf the number selected by you and computer is same, then the computer will lose its wicket. \n5. Each player will get 2 wickets and 2 overs (12 bowls) for batting and bowling. \n6. The innings will end after either the three wickets fell or the overs end. \n7. The player with maximum runs wins.\n8. MAGICAL STEP : When you have selected 0 then computer run will be to assigned to you and adds to your runs.")

import random
print("-------------------------------------------------------------------")

# TOSS
print("-----GAME HAS BEEN STARTED-----")
toss= input("TOSSING\nPLEASE CHOOSE HEADS OR TAILS : ")
ran_toss = random.randint(1,2)
# In ran_toss , 1 stands for HEADS and 2 stands for TAILS.
ran_option = random.randint(1,2)
# In ran_option , 1 stands for BATTING first and 2 stands for BOWLING first. 
your_option =""
comp_option =""
if ran_toss == 1 and toss == "HEADS":
    print("\nCongratulations ! , You won the toss.")
    your_option = input("CHOOSE BATTING OR BOWLING :")
elif ran_toss == 2 and toss == "TAILS":
    print("\nCongratulations ! , You won the toss.")
    your_option = input("CHOOSE BATTING OR BOWLING :")
else:
    print("\nYou lost the toss.")    
    if ran_option == 1:
        comp_option = "BATTING"
        print("\nComputer chooses to bat first -" , comp_option)
    elif ran_option == 2:
        comp_option = "BOWLING"
        print("\nComputer chooses to bowl first -", comp_option)
        
print("-------------------------------------------------------------------")
       
# FIRST INNINGS
print("\n-----FIRST INNINGS BEGINS-----") 
runsFirst = 0
wicketsFirst = 0
bowlsFirst = 0
while wicketsFirst != 2 and bowlsFirst != 12 :
    your_choice = int(input("\nCHOOSE ANY NUMBER FROM 0 TO 6 :"))
    comp_choice = random.randint(1,6)
    if your_choice < 0 or your_choice > 6:
        print("\n PLEASE CHOOSE A NUMBER FROM ZERO TO SIX AND READ ALL THE INSTRUCTIONS.")
    else:
        print("YOU HAVE CHOOSEN",your_choice , "COMPUTER HAS CHOOSEN",comp_choice)
        if your_choice == comp_choice :
            wicketsFirst += 1 
        else:
            if your_option == "BATTING" or comp_option =="BOWLING":
                batFirst = "YOU"
                bowlFirst = "COMPUTER"
                if your_choice < 7 and your_choice > 0 :
                    runsFirst += your_choice 
                else:
                    runsFirst += comp_choice
            elif your_option =="BOWLING" or comp_option == "BATTING":
                batFirst = "COMPUTER"
                bowlFirst = "YOU"
                runsFirst += comp_choice 
    print("\nSCORES = ",runsFirst)
    print("\nWICKETS = ",wicketsFirst) 
    bowlsFirst += 1 
    if bowlsFirst == 6 :
        print("-----END OF FIRST OVER-----")
    elif bowlsFirst == 12:
        print("-----END OF SECOND OVER-----")
    print("\nBOWLS REMAINING : " ,12 -bowlsFirst)
print("\n-----END OF FIRST INNINGS-----")    
print("\nFINAL SCORE :")
print("RUNS = ",runsFirst)
print("WICKETS = ",wicketsFirst)
print("\n",bowlFirst,"NEEDS",runsFirst+1,"RUNS TO WIN.")

print("-------------------------------------------------------------------")
       
# SECOND INNINGS
print("\n-----SECOND INNINGS BEGINS-----")    
runsSecond = 0
wicketsSecond = 0
bowlsSecond = 0
while wicketsSecond != 2 and bowlsSecond != 12 and runsFirst >= runsSecond :
    your_choice = int(input("\nCHOOSE ANY NUMBER FROM 0 TO 6 :"))
    comp_choice = random.randint(1,6)
    if your_choice < 0 or your_choice > 6:
        print("\n PLEASE CHOOSE A NUMBER FROM ZERO TO SIX AND READ ALL THE INSTRUCTIONS.")
    else:
        print("YOU HAVE CHOOSEN",your_choice , "COMPUTER HAS CHOOSEN",comp_choice)
        if your_choice == comp_choice :
            wicketsSecond += 1 
        else:
            if batFirst == "COMPUTER":
                batSecond = "YOU"
                if your_choice < 7 and your_choice > 0 :
                    runsSecond += your_choice
                    print("RUNS = ",runsSecond)
                    print("WICKETS = ",wicketsSecond)    

                else:
                    runsSecond += comp_choice
            elif batFirst == "YOU":
                batSecond = "COMPUTER"
                runsSecond += comp_choice 
            print("\nSCORES = ",runsSecond)
            print("\nWICKETS = ",wicketsSecond) 
            bowlsSecond += 1 
            print("\nBOWLS REMAINING : " , 12 - bowlsSecond)
            if bowlsSecond == 6 :
                print("-----END OF FIRST OVER-----")
            elif bowlsSecond == 12:
                print("-----END OF SECOND OVER-----")
            
            if runsSecond <= runsFirst and bowlsSecond <= 11 and wicketsSecond != 2 :
                print("\nTO WIN : ", batSecond ,"NEEDS", runsFirst-runsSecond + 1, "RUNS FROM", 12-bowlsSecond, "BOWLS." )         
print("\n-----END OF SECOND INNINGS-----")    
print("\nFINAL SCORE :")
print("RUNS = ",runsSecond)
print("WICKETS = ",wicketsSecond)    

print("-------------------------------------------------------------------")
       
# RESULT
if runsFirst > runsSecond:
    if batFirst =="YOU":
        print("\n CONGRATULATIONS!!! \n YOU WON THE CRICKET MATCH BY" , runsFirst - runsSecond , "RUNS.")
    else:
        print("\n SORRY!!! \n BETTER LUCK NEXT TIME! \n THE COMPUTER WON THE CRICKET MATCH BY" , runsFirst - runsSecond , "RUNS.")
elif runsSecond > runsFirst:
    if batSecond =="YOU":
        print("\n CONGRATULATIONS!!! \n YOU WON THE CRICKET MATCH BY" ,2- wicketsSecond, "WICKETS.")
    else:
        print("\n SORRY!!! \n BETTER LUCK NEXT TIME! \n THE COMPUTER WON THE CRICKET MATCH BY" ,2-wicketsSecond, "WICKETS.")
else:
    print("\n THE MATCH IS A TIE. \n NO ONE WON . \n IT'S A DRAW MATCH.")
print("\n THANK YOU FOR PLAYING. \n HAVE A NICE DAY.") 
print("\N{smiling face with smiling eyes}")