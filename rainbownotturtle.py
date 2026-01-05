"""
start()
    Purpose: Initializes the game and presents the player with an introduction and initial choices.
    
    Usage: Allows the player to choose between exploring the forest or heading to town.

town(name, coins)
    Purpose: Handles the scenario when the player chooses to visit the town.
    
    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.

    Usage:
        Describes the town and the player's current situation (being famished).
        Provides options to either try to obtain more coins or buy food directly.
        Handles sub-choices for how to get more money (e.g., performing or pickpocketing).
        Adjusts the player's inventory and moves the storyline forward to the blackwood() function based on the outcomes.
        
blackwood(name, coins)
    Purpose: Introduces Ms. Blackwood and the option for the player to receive tools and weapons.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.

    Usage:
        Describes the encounter with Ms. Blackwood.
        Provides the player with options to choose a tool or weapon.
        Updates the inventory based on player choices.
        Sets up the next steps, including lessons on portal creation and leading to a prison scenario.

BacktoSchool(name, coins, portals, blackwood)
    Purpose: Facilitates the return to school after the adventure.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.

    Usage:
        Describes the return to the school and potential lessons learned.
        Provides options for final dialogues with characters before returning to the present.

end(method)
    Purpose: Handles the scenario when the player dies in the game.

    Parameters:
        method: Describes how the player died.

    Usage:
        Prints a message detailing the player's death.
        Asks the player if they want to play again.
        Handles the player's response to either restart the game or exit.

ask_question(girlname, escape)
    Purpose: Prompts the player to ask a question regarding the escape plan.

    Parameters:
        girlname: The name of the girl character involved.
        escape: A boolean indicating if the escape is possible.

    Usage:
        Presents a question to the player and processes their response.
        
boom(is_drive)
    Purpose: Handles an explosive event or outcome in the game.

    Parameters:
        is_drive: A boolean indicating if the drive option was chosen.

    Usage:
        Executes an action based on whether the player chose to drive or not.

bribeing(girlname, girltitle, bribe)
    Purpose: Manages the bribe process with a girl character.

    Parameters:
        girlname: The name of the girl character being bribed.
        girltitle: The title of the girl character.
        bribe: The amount of money offered as a bribe.

    Usage:
        Checks the success of the bribing attempt and updates the game state accordingly.

continuing()
    Purpose: Allows the game to continue after a decision point.

    Usage:
        Executes the continuation logic of the game based on prior decisions made by the player.

currenttime(name, coins, portals, blackwood)
    Purpose: Placeholder for the implementation that describes the player's return to the present time.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.

    Usage:
        To be implemented in future development.

drive()
    Purpose: Manages the driving option in the game.

    Usage:
        Facilitates the scenario where the player decides to drive, possibly leading to a new location or event.

ecscaping(girlname, girltitle)
    Purpose: Handles the scenario where the player and a girl character escape from a situation.

    Parameters:
        girlname: The name of the girl character involved in the escape.
        girltitle: The title of the girl character.

    Usage:
        Describes the escape sequence and the player's choices during the process.

lookaround()
    Purpose: Allows the player to look around their current environment.

    Usage:
        Provides descriptions of the surroundings and potential interactions available to the player.

open_cell(name, coins, portals, blackwood)
    Purpose: Opens a prison cell in the storyline.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.

    Usage:
        Describes the action of opening a cell and the resulting effects on the storyline.

out(girlname, girltitle)
    Purpose: Manages the exit scenario involving a girl character.

    Parameters:
        girlname: The name of the girl character involved.
        girltitle: The title of the girl character.

    Usage:
        Describes the circumstances and outcomes of exiting a location or situation with the girl character.

prison(name, coins, portals)
    Purpose: Handles the scenario when the player is in prison.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.

    Usage:
        Describes the prison environment and provides options for the player to escape or interact with characters.

prisoncell(awake, girlname, escape, girltitle)
    Purpose: Manages the player's actions while in a prison cell.

    Parameters:
        awake: A boolean indicating if the player is awake.
        girlname: The name of the girl character in the cell.
        escape: A boolean indicating if escape is possible.
        girltitle: The title of the girl character.

    Usage:
        Describes actions and decisions available to the player in the prison cell.

questiontime(name)
    Purpose: Prompts the player to answer questions related to the story.

    Parameters:
        name: The player's name.

    Usage:
        Facilitates a quiz or question-answer session to engage the player further in the storyline.

savior(name, coins, portals)
    Purpose: Introduces a savior character who helps the player.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.

    Usage:
        Describes the interaction with the savior character and potential options the player has during this encounter.

school(name)
    Purpose: Handles the scenario when the player is at school.

    Parameters:
        name: The player's name.

    Usage:
        Describes the school environment and interactions with other characters.

walk()
    Purpose: Manages the walking action for the player.

    Usage:
        Facilitates the movement of the player character and may lead to new locations or encounters.

currenttime(name,coins,portals,blackwood)
    Purpose: Introduces a plot sequence with interactive choices affecting the storyline.
    
    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        
    Usage:
        Used to advance the narrative and provide the player with meaningful choices that impact the story progression.        

spy(name,coins,portals,blackwood,path,characters_hp)
    Purpose: Test the player's portal powers for the king.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        
    Usage:
        This function places the player character in a courtyard to demonstrate their portal powers. Initially, the player's powers are blocked by chains, but after the chains are removed by a woman in glowing armor, the player successfully creates a portal. The function ends by calling comply_spy to continue the story.

comply(name,coins,portals,blackwood,path,characters_hp)
    Purpose: Test the player's portal powers for the king, with added challenges.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        
    Usage:
        This function places the player character in a courtyard to demonstrate their portal powers under restrictive conditions. Initially, the player's powers are blocked by chains. After the chains are weakened by a woman in glowing armor, the player attempts to create a portal but finds their range limited. The function ends by calling comply_spy to continue the story.

comply_spy(name,coins,portals,blackwood,path,characters_hp):
    Purpose: Advance the story where the player interacts with Anika, Ms. Blackwood, and Hazel, and plan an attack on the king.
    
    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.

    Usage:
        This function continues the narrative after the player steps through a portal and meets Anika. It provides information about the spy within the enforcers, and the player's next decisions affect the storyline. The player either pretends to spy for the king or reveals their true intentions. The group plans to gather more magical individuals and confront the king, with the narrative branching based on the player's previous choices.

spyBattle(name,coins,portals,blackwood,path,characters_hp)
    Purpose: Handles the player’s decisions during the spy battle, including interactions with witches, fighting, and calling for help from various characters, influencing the outcome of the game.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        
    Usage:
        This function is invoked during a battle or confrontation with important characters like Ms. Blackwood, Cedric, and Anika. It prompts the player to make key decisions that will affect the flow of the game. The player's choices determine the progression of the story, such as whether they attack the witches, betray the king, or fight certain characters. The function also tracks the status of these characters and updates the player's inventory or game state based on their actions.

betrayer(name,coins,portals,blackwood,path,characters_hp):
    Purpose: Capture Anika, Ms. Blackwood, and Hazel for the king.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.

    Usage:
        This function narrates the player's betrayal of their friends to the king. It sets up the scenario where the player, accompanied by the Dread Knight, chooses who to pursue first among Anika, Ms. Blackwood, and Hazel. Depending on the player's choice, different functions (fightAnika, fightBlackwood, fightHazel) are called to continue the story.
    
fightAnika(name,coins,portals,blackwood,path,enforsercount,characters_hp)
    Purpose: To capture or defeat Anika with the help of the Dread Knight and enforcers.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        enforsercount: The amount of people in your army.
        
    Usage:
        This function narrates the confrontation with Anika. It allows the player to choose different actions, each with varying outcomes. The function evaluates the player's choices, random chances, and items in the player's inventory to determine the result of the encounter. Depending on the outcome, the story progresses by calling functions fightBlackwood, fightHazel, or allDead.

fightHazel (name,coins,portals,blackwood,path,enforsercount,characters_hp)
    Purpose: To capture or defeat Hazel with the help of the Dread Knight and enforcers.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        enforsercount: The amount of people in your army.

    Usage:
        This function narrates the confrontation with Hazel. It provides different actions for the player, each affecting the outcome. The function considers the player's inventory and random chances to determine the result. Depending on the outcome, it calls fightBlackwood, fightAnika, or allDead to continue the story.

fightBlackwood  (name,coins,portals,blackwood,path,enforsercount,characters_hp)
    Purpose: To capture or defeat Ms. Blackwood with the help of the Dread Knight and enforcers.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        enforsercount: The amount of people in your army.
    
    Usage:
        This function narrates the confrontation with Ms. Blackwood. The player can choose to either warn Ms. Blackwood or confront her directly, which leads to different outcomes. The function evaluates the player's choices to progress the storyline. Based on the choices, it may call witchGather or fightBlackwood2 to continue the story.        

fightBlackwood2 (name,coins,portals,blackwood,path,enforsercount,characters_hp)
    Purpose: To confront and capture or defeat Ms. Blackwood.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        enforsercount: The amount of people in your army.
        
    Usage:
        This function narrates the battle with Ms. Blackwood. The player chooses an item to use from their inventory, which affects the outcome of the fight. The function evaluates the player's choice and random chances to determine if they successfully capture or defeat Ms. Blackwood. Depending on the outcome, it calls the step function to continue the story.

step(name,coins,portals,blackwood,path,enforsercount,characters_hp,found)
    Purpose: Determine the next target (Hazel or Anika) after dealing with Ms. Blackwood, and continue the story.
    
    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        enforsercount: The amount of people in your army.
        found: who found you
    Usage:
        This function evaluates the status of Ms. Blackwood and guides the player to the next target (Hazel or Anika). It checks if certain characters are dead or captured and calls allDead, fightBlackwood, or fightHazel accordingly. The player then chooses the next target, and the story continues based on the player's decision.

witchGather(name,coins,portals,blackwood,path,enforsercount,characters_hp,found)
    Purpose: Manages the player’s interaction during a critical battle involving Ms. Blackwood, Anika, Hazel, Cedric, and the Dread Knight, allowing the player to make strategic decisions to influence the outcome and characters' fates.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        enforsercount: The amount of people in your army.
        found: who found you

    Usage:
        This function is used to simulate the critical decision-making moments where the player’s actions affect the battle’s progression, including interactions with witches, allies, and enemies. It also dictates the fate of characters based on the player's choices during the confrontation with the Dread Knight and other adversaries.

allDead(name,coins,portals,blackwood,path,enforsercount,characters_hp)
    Purpose: Report the outcome to the king based on the captured or killed status of the enemies.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        enforsercount: The amount of people in your army.
        
    Usage:
        This function counts the number of dead, captured, and alive enemies and constructs a message based on these counts. The player then returns to the king, who reacts accordingly. The function concludes by calling won to continue the story.

 won(name,coins,portals,blackwood,path,enforsercount,characters_hp)
    Purpose: Display the ending summary and allow the player to restart or quit the game.

    Parameters:
        name: The player's name.
        coins: The amount of coins the player currently has.
        portals: Indicates whether the player has learned about portals.
        blackwood: Placeholder for Ms. Blackwood’s influence on the story.
        path: String representing the player's chosen storyline.
        characters_hp:  Dictionary of NPC names and their HP.
        enforsercount: The amount of people in your army.
        
    Usage:
        This function calculates the total time taken to complete the game, displays a summary of the player's journey, including items collected, paths taken, and other notable details. The function then prompts the player to either play again or quit the game.
    
        
"""
import time
import datetime
import random


Inventory = {"phone": 1, "shirt" : 1, "pair of pants" : 1}
start_time = datetime.datetime.now()

def start():
    print("The sun is rising over the horizon, casting a warm glow over the quiet road.")
    print("You take a sip of coffee, savoring the calm start to your day as you head toward school.")
    print("The sky is clear, and there’s an endless stretch of road ahead.")
    while True:
        action = input ("What do you want to do next?\n\t1) Continue Driving\n\t2) Look Around\n").lower()
        if action in ("1", "continue", "continue driving", "drive", "one"):
            continuing()
            break
            
        elif action in ("2", "look", "look around", "around", "two"):
            print ("You look around and see birds flying in the sky.")
        else:
            print("Invalid choice. Please select a valid option.")
            

def continuing():
    print("A bright and vibrant rainbow appears out of thin air in front of you.")
    print("Confused, you blink and rub your eyes. When you open them again, the road is gone, replaced by an enormous stone castle looming before you.")
    print("Startled, you slam on the brakes.")
    
    while True:
        action2 = input("What do you want to do next?\n\t1) Drive Toward the Castle\n\t2) Get Out of the Car and Approach on Foot\n").lower()
        if action2 in ("1", "continue", "continue driving", "drive", "toward the castle", "one"):
            print("You put your foot down to drive to the castle. You go nowere your cars stuck. Mud flies out behind you.")
            print ("You notice atop the immaculate castle a ballista level pointing straight at you.")
            is_drive = True
            score = 1
            boom(is_drive)
            break
        
        elif action2 in ("2", "get out", "get out of the car", "approach on foot", "foot", "two"):
            print("you turn off your car")
            print ("You get out of your car.")
            Inventory["key"] = 1
            is_drive = False
            score = 1
            boom(is_drive)
            break
        else:
            print("Invalid choice. Please select a valid option.")
            score = -1
     

def boom(is_drive):
    awake = False
    
    if is_drive == True:
        print("You jump out of your car as the bolt hurtles at you.")
        print("You hear a loud metalic knock")
    elif is_drive == False:
        print("You turn to close the car door.")
        print("You hear a loud metallic knock and look to see a huge arrow sticking out of your hood.")
        
    print("You Run from the car and leap away in a last-ditch attempt to get away. Everything goes black")
    
    prisoncell(awake,"She", 1, "the girl")
    #for ecscape 1 is unknown 2 is no 3 is yes
    
def prisoncell(awake, girlname, escape, girltitle):
    if not awake:
        print("You awake with great difficulty, not able to move.")
        print("You blink to clear the haze and see a young girl kneeling beside you.")
        print("She has shards of glass and twisted metal in her hand, her long pink dress with lace cuffs flowing softly around her.")
        print("Her hair shines like silk, framing her youthful face.")
    else:
        print("You are sitting up.")
        if escape == 1:
            print(girltitle, "puts the shards to the side.")
        elif escape == 2:
            print(f"You and {girltitle} are dragged by guards through a dark hall that opens into a throne room.")
            print("The king convicts you of witchcraft, sentencing you to death by fire.")
            end("sentenced to death by fire", False)
        elif escape == 3:
            print(girltitle, 'says, "I am a witch. I was trying to get away. I used too much power and opened a portal to your', datetime.datetime.now().year, '.\nYou were just in the wrong place at the wrong time."')
            ecscaping(girlname, girltitle)

    while True:
        action3 = input("What do you do?\n\t1) Ask a question\n\t2) Do nothing\n\t3) Yell for help\n").lower()
        if action3 in ("1", "ask", "ask a question", "question", "one"):
            ask_question(girlname, escape,girltitle)
            
        elif action3 in ("2", "do nothing", "nothing", "two"):
            print(f"You wait for what feels like days when you hear footsteps and a clinking sound.")
            print(f"Guards in full armor appear and drag you and {girltitle} through a dark hall that opens into a throne room.")
            print("The king convicts you of witchcraft, sentencing you to death by fire.")
            end("sentenced to death by fire", False)
            
        elif action3 in ("3", "yell", "yell for help", "help", "three"):
            print("You get up and yell for help.")
            time.sleep(2)  # Delay 2 seconds
            print('You hear footsteps echoing along with a clinking sound. Guards in full armor appear, swords drawn.')
            print('They say, "The king wants you quiet," as one of the guards silences you with a swift swing of their sword.')
            end("too loud", False)
        else:
            print("Invalid choice. Please select a valid option.")


def ask_question(girlname, ecscape,girltitle):
    asking = True
    awake = True
    girlname = "She"
    girltitle = "the girl"
    leave = "Don't ask a question"

    while asking:
        what = input("What do you ask " + girltitle + "?\n\t1) Who are you?\n\t2) Where are we?\n\t3) How old are you?\n\t4) What happened?\n\t5) What now?\n\t6) " + leave + "\n").lower()

        if what in ("1", "who are you", "who", "one"):  # who
            print(f"You ask {girltitle}, 'Who are you?'")
            print(f"{girlname} says, 'My name is Anika.'")
            girlname = "Anika"
            girltitle = "Anika"
            leave = "All done asking"

        elif what in ("2", "where are we", "where", "two"):  # where
            print(f"You ask {girltitle}, 'Where are we?'")
            print(f"{girlname} says, 'We are in jail.'")
            leave = "All done asking"

        elif what in ("3", "how old are you", "how old", "three"):  # age
            print(f"You ask {girltitle}, 'How old are you?'")
            print(f"{girlname} says, 'I am 12 years old.'")
            leave = "All done asking"

        elif what in ("4", "what happened", "happened", "four"):  # what
            print(f"You ask {girltitle}, 'What happened?'")
            print(f"{girlname} says, \"When I saw your car blow up, I went to see if you were okay, and the knights came back out.")
            print("They arrested us both because they think you are a witch sent to kill the king. They tossed us in this cell.\"")
            leave = "All done asking"

        elif what in ("5", "what now", "now", "five"):  # now
            print(f"You ask {girltitle}. What now?")
            print("She says we could try to escape.")
            i = False
            while not i:
                plan = input("How do you respond?\n\t1) Yes\n\t2) No\n").lower()
                if plan in ("1", "yes", "y", "one"):
                    print(f"You tell {girltitle} that you want to try to escape.")
                    ecscape = 3
                    i = True
                    leave = "All done asking"
                elif plan in ("2", "no", "n", "two"):
                    print("You tell {girltitle} that you do not want to try to escape.")
                    ecscape = 2
                    leave = "All done asking"
                    i = True
                else:
                    print("Invalid choice. Please select a valid option.")
                    
        elif what in ("6", "six", "don't ask a question", "dont ask", "done", "all done", "all done asking"):  # done
            if leave == "Don't ask a question":
                print("You choose not to ask any questions.")
            else:
                print("You are all done asking questions.")
            prisoncell(awake, girlname, ecscape, girltitle)
            asking = False  # Exit the loop after handling this option
        else:
            print("Invalid choice. Please select a valid option.")

def ecscaping(girlname, girltitle):
    escapeplan = input(girltitle + " asks, how should we escape?\n\t1) Play dead\n\t2) Bribe\n\t3) Make a huge scene\n").lower()
    if escapeplan in ("1", "play dead", "dead", "one"):
        print(f'You tell {girltitle}, "We could play dead."')
        print(f'{girltitle} says, "We could try."')
        print("They both lay down, limp, and tried to breathe as little as possible. They fell asleep until yells woke them. Remembering their plan, they tried not to move.")
        print('A man squawks, "GET UP, NOW!"')
        print('Another voice says, "I think they’re dead."')
        print("Anika and you hear the clatter of keys as the guards open the cell door. They are both carried out of the metal cell.")
        print("Trying to get out the door, the guard hits your head on the iron door frame. You jump, and the warden carrying you cries out with surprise, 'Zombie! Zombie!'")
        print(f'The guard carrying {girltitle} drops her. She yelps and springs up.')
        print(f'You and {girltitle} knock out the guards.')
        k = False
        while not k:
            sword = input("Do you take one of their swords?\n\t1) Yes\n\t2) No\n").lower()
            if sword in ("1", "yes", "y", "one"):
                Inventory["sword"] = 1
                print("You pick up one of their swords and sheath it, strapping it to your belt.")
                k = True
            elif sword in ("2", "no", "n", "two"):
                print("You leave the swords.")
                k = True
            else:
                print("Invalid choice. Please select a valid option.")
        print(f"You and {girltitle} run as fast as possible, sliding under the portcullis right before it closes.")
        out(girlname, girltitle)
        
    elif escapeplan in ("2", "bribe", "two"):
        print("You chose to bribe.")
        j = False
        while not j:
            print(f'{girltitle} says, "With what?"')
            items = [f"{value} {key.lower()}" for key, value in Inventory.items()]
            formatted_inventory = ", ".join(items[:-1]) + ", and " + items[-1] if len(items) > 1 else items[0]
            print(f"You have {formatted_inventory} in your inventory.")
            bribe = input("What do you want to use?\n").lower()
            
            if bribe == "phone":
                print(f'You tell {girltitle} "Do you think my phone would work?"')
                del Inventory["phone"]
                bribeing(girlname, girltitle, bribe)
                
            elif bribe == "key":
                print(f'You tell {girltitle} "Do you think my car key would work?"')
                del Inventory["key"]
                bribeing(girlname, girltitle, bribe)
                
            elif bribe in Inventory.keys():
                print(f'{girltitle} says, "{bribe} would not be a very good bribe."')
            else:
                print("Invalid input or item not in inventory.")
            
    elif escapeplan in ("3", "make a huge scene", "scene", "three"):
        # Using formatted strings and splitting the text for better readability
        print('You chose to make a huge scene. You take a deep breath and shout at the top of your lungs, ')
        print('"HELP! GUARDS! Something’s wrong with her!"')
        print(f'{girltitle} lays down and starts writhing around dramatically.')
        print('You hear footsteps echoing along with a clinking sound. Guards in full armor appear, swords drawn.')
        print('They say, "The king wants you quiet."')
        print('As one of the guards silences you with a swift swing of their sword.')
        end("too loud",False)
    else:
        print("Invalid choice. Please select a valid option.")
        ecscaping(girlname, girltitle)  # Call the function again with parameters


import random

def bribeing(girlname, girltitle, bribe):
    print(f"You and {girltitle} wait for the guards to come.")
    print("When the guards finally arrive, one of the guards says, 'You both are coming with us.'")
    
    if bribe == "phone":
        print('You say, "I have a metal box with lots of precious metals. If you help us escape, it is all yours."')
        random_number = random.randint(0, 100)
        
        if random_number >= 10:
            print('One of the guards says, "A key to a magic chariot?"')
            print('The other guard replies, "You’ve got yourself a deal."')
            print(f'The guards put cuffs on you and {girltitle} and walk you both out.')
            print('As you are walking, a guard comes over and asks, "Where are you taking these prisoners?"')
            print(f'One of the guards escorting you and {girltitle} says, "We are taking them to be killed."')
            print('The other guard responds, "Good, that should open up more room in the cells."')
            print(f'The guards take you and {girltitle} through the portcullis, remove the cuffs, and you hand over the {bribe}.')
            print('The guards turn around and go back in.')
            out(girlname, girltitle)
        else:
            print('The guards say, "Do you think we are fools? If that little box really holds precious metals, ')
            print('we can just take it after the king deals with you."')
            print(f'You and {girltitle} are dragged by the guards through a dark hall that opens into a throne room, ')
            print('where the king convicts you of witchcraft, sentencing you to death by fire.')
            end("sentenced to death by fire and all your stuff was taken.", False)
        
    elif bribe == "key":
        print('You say, "I have a key that unlocks..."')
        print(f'{girltitle} says, The magic chariot that this person came in on."')
        random_number = random.randint(0, 100)
        
        if random_number >= 35:
            print('One of the guards says, "A key to a magic chariot?"')
            print('The other guard replies, "You’ve got yourself a deal."')
            print(f'The guards put cuffs on you and {girltitle} and walk you both out.')
            print('As you are walking, a guard comes over and asks, "Where are you taking these prisoners?"')
            print(f'One of the guards escorting you and {girltitle} says, "We are taking them to be killed."')
            print('The other guard responds, "Good, that should open up more room in the cells."')
            print(f'The guards take you and {girltitle} through the portcullis, remove the cuffs, and you hand over the {bribe}.')
            print('The guards turn around and go back in.')
            out(girlname, girltitle)
        else:
            print('The guards say, "Do you think we are fools? That is a box of witchcraft; we would never go near it,')
            print('and we can just take it after the king deals with you."')
            print(f'You and {girltitle} are dragged by the guards through a dark hall that opens into a throne room.')
            print('In the throne room, the king convicts you of witchcraft, sentencing you to death by fire.')
            end("sentenced to death by fire and all your stuff was taken.", False)

def out(girlname, girltitle):
    print(f"You and{girltitle} run along the castle wall and into a forest. You both stop to catch your breath.")
    print('You say, "I can’t believe that worked!"')
    if girltitle == "Anika":
        print(f'{girltitle} says, "After all that, I realized I never got your name?"')
    else:
        print(f'{girltitle} agrees and says, "My name is Anika. What’s yours?"')
    t = False
    while not t:
        name = input("What is your name?\n").strip().lower()
        if not name:
            print("You must input something.")
            continue  # Restart the loop if input is empty
        if any(not char.isalpha() for char in name):
            print("No special characters, no spaces.")
            continue  # Restart the loop if input contains invalid characters
        if len(name) >= 35:
            print("Must be less than 35 characters.")
            continue  # Restart the loop if name is too long
        t = True  # Valid input, exit the loop

    print(f'Anika says, "It is nice to meet you, {name.capitalize()}."')
    print('You ask, "Why were you at the castle?"')
    print('Anika says, "The king took me and my older sister in a carriage."')
    print('When it stopped, my sister opened a portal and had me go through first.')
    print('Just as I entered, the portal closed."')
    print('Anika continues, "I tried to open another portal to save her, but I couldn’t focus')
    print('and accidentally opened a portal to the future."')
    questiontime(name)

          
def questiontime(name):
    while True:  # Loop until a valid choice is made
        question = input(
            "What question do you want to ask?\n"
            "\t1) Was your sister in the castle with us?\n"
            "\t2) Could you send me back to {}?\n"
            "\t3) Should we find your sister?\n"
            "\t4) What now?\n".format(datetime.datetime.now().year)
        ).strip().lower()

        if question in ("1", "was your sister in the castle with us?", "in the castle", "one"):
            print('Anika says, "No, they were moving us to a prison in the far north when we escaped."')
        
        elif question in ("2", "could you send me back to {}".format(datetime.datetime.now().year), "send me back", "two"):
            print('Anika utters with remorse, "It was an accident to open a portal to the future.')
            print('I had so much pent-up emotion. I wouldn’t even know where to start.')
            print('My sister would be able to open a portal to the future, for sure.')
            print('She graduated from witch school."')
            
        elif question in ("3", "should we find your sister?", "find your sister", "three"):
            print('Anika says, "I thought you would be mad, since I’m the reason you ended up here."')
        
        elif question in ("4", "what now", "now", "four"):
            print("What now?")
            m = False
            while not m:
                choice = input("What do you want to do?\n\t1) Stay here?\n\t2) Go to the prison and try to save Anika's sister\n\t3) Go to the witch school\n").strip().lower()
                
                if choice in ("1", "stay here", "stay", "one"):
                    m = True
                    stay(name)
                
                elif choice in ("2", "go to the prison", "save anika's sister", "go to prison", "save sister", "two"):
                    m = True
                    print("You and Anika go to the prison.")
                    prison(name, 0, False)
                
                elif choice in ("3", "go to the witch school", "witch school", "go to school", "three"):
                    m = True
                    school(name)
                else:
                    print("Invalid choice. Please select a valid option.")
        else:
            print("Invalid choice. Please select a valid option.")


def stay(name):
    print("You choose to stay.")
    print("You find the forest peaceful and a lot more comfortable than the prison cell, and you fall asleep.")
    print("You are awoken to the sound of branches snapping.")
    print("You jolt up to see a group of guards.")
    
    if "sword" in Inventory: 
        print("You stumble to your feet trying to draw your sword but trip forward and fall onto it.")
        end("clumsy",False)
    else:
        print("You open your eyes to see a sword coming down.")
        end("lazy",False)

def prison(name, coins, portals):
    print("When you both arrive at the prison, you see the enormous foreboding Blackmont prison.")
    print("The top of the prison is lined with ballistae and the walls have unmanned archer slits.")
    print("You walk to the excessively large door.")
    print('Anika says, "You should knock on the door."')

    # Determine chances of death based on inventory
    if "moonstone pendant" in Inventory:
        chance1 = " Chance of death: 50%"
        chance2 = " Chance of death: 15%"
    else:
        chance1 = ""
        chance2 = ""

    a = False
    while not a:
        who = input("Who should knock?\n\t1) You" + chance2 + "\n\t2) Anika" + chance1 + "\n").lower()
        if who in ("1", "you", "me", "one"):
            print("You knock on the huge wooden door laden with metal. The door slowly opens.")
            print("You see a man pointing a bow straight at you and another man with a sword.")
            if any(item in Inventory for item in ["sword", "flameblade knife", "enchanted dagger"]):
                print("You quickly draw your blade and slash the bow in half, knocking the sword out of the other man's hands.")
                print("Anika picks up the man's sword.")
                a = True
            else:
                print("Recognition appearing in the man's face, he lets an arrow fly.")
                end("popular",False)
        elif who in ("2", "anika", "two"):
            random_number = random.randint(0, 100)
            if random_number >= 50:
                print("Anika knocks on the huge wooden door laden with metal.")
                print("The door slowly opens.")
                print("Seeing a man raising a bow, Anika jumps into action, grabbing the bow and firing one shot, killing the archer.")
                print("You yell, 'That one has a sword!'")
                print("Anika draws back the bow and shoots an arrow, hitting the swordsman.")
                print("Anika hands you the bow and picks up the man's sword.")
                Inventory["bow"] = 1
                a = True
            else:
                print("The door opens as arrows fly out of the now-open door.")
                end("a pincushion",False)
        else:
            print("Invalid choice. Please select a valid option.")
            
    print('You and Anika enter the prison and look around.')
    print('Anika yells out, "Hazel, where are you?!"')
    print('You hear a quiet voice, “Anika,” followed by the clattering of armor.')
    print('Soldiers charge in from everywhere.')

    items = ', a '.join([item.capitalize() for item in Inventory.keys()])
    skilled = " or you can try and use a portal" if portals else ""
    b = False
    random_number = random.randint(0, 100)

    while not b:
        print(f"Your options include a {items}{skilled} (please use the full name of the items.)")
        battle = input("What do you want to use?\n").lower()
        if battle in Inventory:
            if battle in ("flameblade knife", "enchanted dagger"):
                print(f"You draw your {battle}.")
                print("You fend off several guards with Anika fighting by your side,")
                print("but you are greatly overwhelmed.")
                if random_number >= 20:
                    savior(name, coins, portals)
                    b = True
                else:
                    end("outnumbered",False)
            elif battle == "sword":
                chance = 15 if portals else 20
                if random_number >= chance:
                    print("You and Anika fighting fiercely manage to take down all the guards.")
                    print("You walk over and pick up a key ring that one of the guards had dropped.")
                    Inventory["cell key"] = 1
                    b = True
                    blackwood = ""
                    open_cell(name, coins, portals, blackwood)
                else:
                    end("outnumbered",False)
            elif battle == "moonstone pendant":
                print("You bring out your pendant.")
                savior(name, coins, portals)
            else:
                print("You can't use " + battle + " right now.")
        else:
            print("You seem not to have that item.")

        
def savior(name, coins, portals):
    print("A portal opens, and you see a hooded figure float through.")
    print("All the soldiers stop and stare in shock.")
    print("Suddenly, they all go up in a blaze of purple flames")
    print("and fall to the ground as dust.")
    blackwood = " and Ms. Blackwood"  
    open_cell(name, coins, portals, blackwood)

def open_cell(name, coins, portals, blackwood):
    print(f"You and Anika {blackwood} find where Hazel's cell is.")
    if "cell key" in Inventory:
        print("You use the keys you picked up to unlock the cell and free Hazel from her cuffs.")
    elif "key" in Inventory:
        print("You try using your car key to unlock the cell, and it surprisingly works! You enter and unlock Hazel's cuffs.")
    else:
        print("Anika produces a key and unlocks the cell, freeing Hazel from her cuffs.")

    # Consolidated dialogue after unlocking
    print('Hazel says, "Thank you!"')
    print('Anika asks, "Why did you not open a portal?"')
    print('Hazel replies, "I think the cuffs were blocking my power."')
    print("Anika says, 'We should get back to the school.'")
    print("Hazel opens a portal, and everyone goes through.")
    BacktoSchool(name, coins, portals, blackwood)
    
def school(name):
    coins = 0
    print("You choose to go to the school.")
    print("You and Anika begin to walk when you come to a river.")
    while True:
        river = input("What do you want to do?\n\t1) Swim across\n\t2) Look around\n").lower()
        
        if river in ("1", "swim across", "swim", "across", "one"):
            random_number = random.randint(0, 100)
            if random_number >= 30:
                print("You jump in and swim across, climbing out on the other side.")
                print(f'Anika yells across the river, "There are crocs in the river, {name}!"')
                print("Anika walks over to a bridge and crosses.")
                break
            else:
                print("You jump in and start to swim when a crocodile swims over to you and eats you!")
                end("lunch for a crocodile",False)
        
        elif river in ("2", "look around", "look", "around", "two"):
            print("You and Anika walk over to a bridge and cross.")
            break
        
        else:
            print("Invalid choice. Please select a valid option.")

    print('You hear pounding hoof beats as knights mounted on horses enter view.')
    print('One of the guards yells, "THERE THEY ARE!"')
    print('The knights race across the bridge, one jumps from their mount, landing near you and Anika.')

    random_number = random.randint(0, 100)
    coins = 0
    if random_number >= 40:
        while True:
            action = input("What do you want to do?\n\t1) Fight\n\t2) Run\n\t3) Bargain\n").lower()
            
            if action in ("1", "fight", "one"):
                if "sword" in Inventory:
                    print('You draw your sword and lunge at the knight, trying to block their attack.')
                    print('Your swing is slow due to inexperience.')
                    print('Anika jumps onto the knight’s back and yanks off his helmet.')
                    print('The knight throws her from his back.')
                    print('You seize the opportunity and swing your sword, slicing cleanly through the knight\'s neck.')
                    print('The other two guards, frightened, turn and flee back over the bridge.')
                    coins += random.randint(10, 100)
                    print(f"You find a bag on the knight's belt containing {coins} coins.")
                    print("You and Anika continue walking.")
                    town(name, coins)
                else:
                    print("You put your fists up, ready to fight. The knight draws their sword and easily dispatches you.")
                    end("crazy and bringing fists to a sword fight",False)
                    
            elif action in ("2", "run", "two"):
                if random.randint(0, 100) >= 40:
                    print("You and Anika turn and run as fast as you can, successfully escaping the forest.")
                    town(name, coins)
                else:
                    print("You and Anika run, but the knights easily catch up on their horses.")
                    end("crazy and trying to outrun a horse",False)
                
            elif action in ("3", "bargain", "three"):
                if "phone" in Inventory:
                    print('You say, "I have a metal box with lots of precious metals. If you let us go, it is all yours."')
                    print("The knights take your bribe and let you go.")
                    del Inventory["phone"]
                    town(name, coins)
                else:
                    print("You don’t have anything worth bargaining with.")
            
            else:
                print("Invalid choice. Please select a valid option.")
    
    else:
        print('Anika says, "Over here!"')
        print("You look over and see a strange rainbow. You run over and leap into the portal just before it collapses.")
        town(name, coins)
            

def town(name, coins):
    print("You and Anika end up in a town.")
    print('Anika says, “We aren’t too far from the school I attend."')
    
    if coins > 0:
        print(f"You are famished, having not eaten in a while. You realize you have {coins} coins.")
    else:
        print("You are famished, having not eaten in a while. You realize you have no money.")
    
    w = False  # Initialize w here
    while not w:
        more = input("Do you want to try and get more money?\n\t1) Yes\n\t2) No\n").lower()
        
        if more in ("1", "yes", "y", "one"):
            a = False
            while not a:
                how = input("How do you want to get more money?\n\t1) Street Performer\n\t2) Pickpocket\n").lower()
                
                if how in ("1", "street performer", "performer", "one"):
                    print("You and Anika start dancing, drawing a crowd, but the city guards notice and kick you out.")
                    end("very thirsty",False)
                
                elif how in ("2", "pickpocket", "two"):
                    random_number = random.randint(0, 100)
                    if random_number >= 20:
                        coins += random_number 
                        print(f"You successfully pickpocket someone and find {random_number} coins.")
                        print("You have enough to buy food and water that you share with Anika.")
                        print("You both leave the town and go to the witch school.")
                        coins -= 10
                        blackwood(name, coins)
                    else:
                        print("You try to pickpocket someone but get caught. The city guards kick you out.")
                        end("very thirsty",False)
                
                else:
                    print("Invalid choice. Please select a valid option.")
        
        elif more in ("2", "no", "n", "two"):
            if coins >= 10:
                print("You choose not to get more money but have enough to buy food and water that you share with Anika.")
                print("You both leave the town and go to the witch school.")
                coins -= 10
                blackwood(name, coins)
            else:
                print('Anika says, "I have some money." She buys food and water that you both share.')
                print("You both leave the town and go to the witch school.")
                blackwood(name, coins)
        
        else:
            print("Invalid choice. Please select a valid option.")
            
def blackwood(name, coins):
    print('Anika knocks on the front door.')
    print('An older lady who looks nothing like the witches from stories opens the door, looking more like a queen than a witch.')
    print('She is wearing an elegant purple robe and a shiny tiara on her head.')
    print(f'The lady says, "Hello Anika!"')
    print('Anika asks, "Can we come in?"')
    print('“Come in, come in,” Ms. Blackwood says with much happiness.')
    print('You enter to see a huge, majestic brick fireplace with beautiful purple flames casting a cozy violet tint on everything.')
    print('There are tall leather armchairs on ornate woven carpets.')
    print('Ms. Blackwood asks Anika, "Who is your friend?"')
    print(f'Anika says, “Ms. Blackwood, this is {name}, he is from the future."')
    print('Anika goes on to tell Ms. Blackwood the story of how they ended up there.')
    print('Ms. Blackwood tells them to follow her to another room where she hands you a disguise.')
    print()
    print('Ms. Blackwood offers you some tools and weapons and asks which do you want?')
    print('Flameblade Knife\n\tA knife that ignites with a vibrant purple flame when struck.')
    print('Moonstone Pendant\n\tA small pendant with a moonstone that glows faintly when danger is near.')
    print('Enchanted Dagger\n\tA dagger that returns to your hands if thrown.')
    Inventory["disguise"] = 1
    a = False
    while not a:
        tool = input("What do you want?\n\t1) Flameblade Knife\n\t2) Moonstone Pendant\n\t3) Enchanted Dagger\n\t4) Don't take anything\n").lower()
        if tool in ("1", "knife", "flameblade", "flameblade knife", "one"):
            Inventory["flameblade knife"] = 1
            a = True
        elif tool in ("2", "moonstone pendant", "moonstone", "pendant", "two"):
            Inventory["moonstone pendant"] = 1
            a = True
        elif tool in ("3", "enchanted", "dagger", "enchanted dagger", "three"):
            Inventory["enchanted dagger"] = 1
            a = True
        elif tool in ("4", "don't take anything", "dont take anything", "nothing", "four"):
            a = True
        else:
            print("Invalid choice. Please select a valid option.")
    items = [f"{value} {key.capitalize()}" for key, value in Inventory.items()]
    formatted_inventory = ", ".join(items[:-1]) + ", and " + items[-1] if len(items) > 1 else items[0]
    print(f'You have {formatted_inventory} in your inventory and {coins} coins.')
    print(f'Ms. Blackwood says, “Now {name}, as for you, I think you should have some lessons on creating portals.”')
    print('Ms. Blackwood teaches you the basics of how to open portals.')
    print('After learning about portals, you try to get some sleep but can\'t fall asleep.')
    print('You go outside and practice fighting.')
    print('The next morning, you meet Ms. Blackwood and Anika in the front room where Ms. Blackwood has set out breakfast for you to eat.')
    print('Ms. Blackwood says, "I will send you two near Blackmont prison so you can save your energy for breaking into the prison."')
    print('You both walk through the portal.')
    portals = True
    prison(name, coins, portals)

def BacktoSchool(name, coins, portals, blackwood):
    if not blackwood:
        print("Hazel knocks on the door to the school.")
        print("Ms. Blackwood opens the door and invites everyone in.")
        print("You and Anika share what happened.")
        if not portals:
            print("Ms. Blackwood teaches you how to use portals.")
    else:
        print("Ms. Blackwood opens the door and invites everyone in.")
        if not portals:
            print("Ms. Blackwood teaches you how to use portals.")

    print(f'You ask, "This was an adventure and all, but I want to go back to {datetime.datetime.now().year}."')
    print('Hazel says, "Give me a few days to recharge, and then yes."')
    print('Ms. Blackwood gives you a satchel and tells you, "This bag has a property to hold things that should be far too large to fit inside."')
    print("You spend the next few days learning more about opening portals and practicing with a sword.")
    print("You're happy to have time to perfect your new talent.")
    print("You, Anika, Ms. Blackwood, and Hazel all meet in the courtyard after Hazel has recharged.")
    print('Anika hugs you and says, "Thank you for your help and saving my sister."')
    print(f'Ms. Blackwood says, "You’re a good kid, {name}. You would make a great witch."')
    print(f'Hazel says, "Thanks for saving me. Are you ready to go back to {datetime.datetime.now().year}?"')
    print('You say, "Yes."')
    
    last = input("Is there anything you want to say?\n").lower()
    
    farewell_responses = {
        ("bye", "goodbye", "good bye", "goodbye everyone", "farewell"): 'Anika, Hazel, and Ms. Blackwood all say "Safe travels!"',
        ("bye anika", "goodbye anika", "good bye anika", "farewell anika"): 'Anika smiles softly, "Goodbye, and thank you again. You’ll always be welcome here."',
        ("bye hazel", "goodbye hazel", "good bye hazel", "farewell hazel"): 'Hazel replies, "Safe travels! Remember, magic isn’t as far away as you think."',
        ("can i come back", "can i come back?", "may i return", "may i return?"): 'Ms. Blackwood smiles, "Once a traveler between worlds, always a traveler. You might find your way back someday."',
        ("thank you", "thanks", "thank you very much", "appreciated"): 'Ms. Blackwood responds, "Gratitude is powerful. You may find it serves you well in this world."',
        ("no", "nah"): "Hazel crosses her arms. 'Oh, well... I’m opening the portal anyway, so... good luck!'",
        ("am i a witch", "am i magical"): "Ms. Blackwood winks, 'Aren’t we all, in our own little ways?'",
        ("what if i get lost", "what if i end up somewhere else"): "Hazel gives a mischievous smirk, 'Then you’ll have a whole new adventure! Not my fault, though.'",
        ("give me a souvenir", "can i have a souvenir"): "Anika tosses you a small, glittering stone. 'Here! It’s just a rock, but hey, good memory, right?'",
        ("this isn’t over", "i’ll be back"): "Hazel nods knowingly, 'I’ll leave a light on for you.'",
        ("hug", "group hug"): "Everyone awkwardly side-hugs. Even Hazel rolls her eyes but joins in for a quick squeeze."
    }
    
    # Find the response based on user input
    for key, response in farewell_responses.items():
        if last in key:
            print(response)
            break
    else:
        print('')  # If no condition matched, just print a newline

    print("You walk through the portal.")
    currenttime(name, coins, portals, blackwood)
    
def currenttime(name,coins,portals,blackwood):
    characters_hp = {"Dread Knight": "Alive", "Anika": "Alive", "Ms. Blackwood": "Alive","Hazel": "Alive","King": "Alive"}
    print('You are overwhelmed by the sound of car horns, sirens, and the enormous buildings.')
    print('You head home.')
    print('You knock on the door and a worried woman opens it.')
    print('Seeing you standing there, your mother starts crying and asking where you’ve been for the past weeks.')
    print('She also asks what you are wearing, what happened to your clothes, and why you have a sword.')
    print('You say, "It’s a long story."')
    print('The next day was Monday.')
    print('Your mother asks, "How will you get to school if you don’t have a car?"')
    print('You say, "Like this."')
    print('Trying to create a portal but unable to.')
    print('You continue to try but seemingly unable to this time.')
    print('In the following days, you share your journey with friends, who are fascinated.')
    print("You can't stop thinking about Anika, Hazel, and Ms. Blackwood.")
    print('One evening as you sit in your bedroom you see a rainbow appear in front of you.')
    print('You grab your sword off the wall and a satchel with the items from your last adventure and run into the portal, expecting to see your friends.')
    print('Instead, you are met by twenty enforcers with heavy chains.')
    print('They lunge at you, and everything goes black.')
    print('You wake up feeling drained.')
    print('You are fully shackled, and there is a very itchy hood over your head.')
    print('You hear the constant clomp of horse hooves.')
    print('You are jostled around and realize you are in the back of a horse-drawn wagon.')
    print('You feel the cart slow to a stop and hear muffled voices as the cart starts crawling forward.')
    a = False
    while a == False:
        in_cart = input("What do you want to do?\n\t1) Try to listen in on the conversation.\n\t2) Attempt to loosen the shackles.\n\t3) Open a portal\n\t4) Stay still\n").lower()
        if in_cart in ("1","one","listen", 'try to listen','listen in', "try to listen in on the conversation"):
            print("You try and listen but can't hear anything over the horses")
            a=True
        elif in_cart in ("2","two","attempt to loosen the shackles","loosen the shackles","loosen"):
            print("you try and loosen the shackles to no avail")
            a=True
        elif in_cart in ("3","three","open a portal","portal"):
            print("you try and open a portal to no avail")
            a=True
        elif in_cart in ("4","four","stay still","still","keep still", "dont move","don't move"):
            print("you stay put.")
            a=True
        else:
            print("Invalid choice. Please select a valid option.")
            a=False
    print('The cart eases to a stop.')
    print('A hand yanks the hood off your head.')
    print('A man with an immaculate set of armor tells you, "I am the Dread Knight."')
    print('He continues, "You’re a part of the rebellious group wreaking havoc on the empire."')
    print('He adds, "You thought you could hide in a different time. You will pay for your crimes against the king."')
    print('The Dread Knight pulls you out of the cart.')
    print('You try yelling out in pain as you are against the wooden floor of the cart.')
    print('You make no noise, and you also see that the chains you are wearing seem to be glowing.')
    print('You look around and see a beautiful medieval city.')
    print('You are led around the carriage, and in front of you is a gigantic, magnificent castle.')
    print('You are dragged into the castle and see a man sitting on a golden throne.')
    print('You also see tons of guards with all manner of medieval weaponry.')
    print('The man says with a voice that shakes the building, "I am the king."')
    print('He continues, "You have a power which is a crime to possess."')
    print('The king adds, "Unless you work for me, you will be killed!"')


    path = "undecided"
    SilentCount = 0
    b= False
    while b == False:
        chat = input ("What do you want to do?\n\t1) Pledge Loyalty to the King and Become a Spy\n\t2) Remain Silent\n\t3) Betray Anika, Ms. Blackwood, and Hazel to Cut a Deal\n\t4) Comply with the King’s Orders but Secretly Plot an Escape\n\t5) Challenge the King’s Views on Power\n")
        if chat in ("1", "one", "pledge loyalty", "become a spy", "pledge loyalty to the king and become a spy"):
            print("You pledge loyalty to the King and become a spy.")
            path = "spy"
            spy(name,coins,portals,blackwood,path,characters_hp)
            
        elif chat in ("2", "two", "remain silent", "silent"):
            print("You remain silent.")
            path = "silent"
            if SilentCount == 1:
                print("The king does not like this and sentences you to death.")
                end("silent",True)
            else:
                print('The king says "last chance to talk!"')
                b = False
            
        elif chat in ("3", "three", "betray", "betray anika", "betray ms. blackwood", "betray hazel", "cut a deal", "betray anika, ms. blackwood, and hazel to cut a deal"):
            print("You betray Anika, Ms. Blackwood, and Hazel to cut a deal.")
            print("You tell the king that the first time you were sucked into the past,")
            print("it was by Anika trying to escape.")
            print("You go on to tell the king about Hazel and Ms. Blackwood.")
            path = "betray"
            betrayer(name,coins,portals,blackwood,path,characters_hp)

        elif chat in ("4", "four", "comply", "comply with the king’s orders", "secretly plot an escape", "comply with the king’s orders but secretly plot an escape"):
            print("You comply with the King’s orders but secretly plot an escape.")
            path = "comply"
            comply(name,coins,portals,blackwood,path,characters_hp)
            
        elif chat in ("5", "five", "challenge", "challenge the king", "challenge the king’s views on power"):
            print("You challenge the King’s views on power.")
            print("The king does not like this and sentences you to death.")
            end("to questioning",True)

def spy(name,coins,portals,blackwood,path,characters_hp):
    print('The king likes this and he says, "I will test your power."')
    print('You are taken to a courtyard still in chains.')
    print('A woman clad in glowing armor similar to the chains you have around your wrists tells you, "I will test your power; create a portal next to me."')
    print('You try to open a portal next to the woman but can\'t.')
    print('The woman says, "Sorry, the chains block your power," as the chains fall to the ground.')
    print('You feel a surge of power, feeling like you could open a portal anywhere.')
    print('You open a portal next to the woman.')
    print('The woman tells you her power is to charge objects to increase or decrease others\' powers.')
    print('"I gave you more power."')
    print('You step through the portal.')
    characters_hp["Aurelia"] = "Alive"
    comply_spy(name,coins,portals,blackwood,path,characters_hp)
        
def comply(name,coins,portals,blackwood,path,characters_hp):
    enforsercount = 0
    print(f'The king says, "I will test how powerful you are, {name}."')
    print('You are taken to a courtyard still in chains.')
    print(f'A woman clad in glowing armor similar to the chains you have around your wrists tells you, "I will test your power; create a portal next to me."')
    print('You try to open a portal next to the woman but can\'t.')
    print('The woman says, "Sorry, the chains block your power," as the chains glow lessens.')
    print(f'You feel a surge of power, feeling like you could open a portal anywhere.')
    print('You try and make a portal to the town that you were in but fail.')
    print('The woman laughs, "Did you really think you would escape that easily?"')
    print('The woman tells you her power is to charge objects to increase or decrease others\' powers.')
    print('"I gave you more power but limited your range."')
    print('You open a portal next to the woman.')
    print('You step through the portal.')
    characters_hp["Aurelia"] = "Alive"
    comply_spy(name,coins,portals,blackwood,path,characters_hp)

def comply_spy(name,coins,portals,blackwood,path,characters_hp):
    print(f'When you exit the portal, you look around and see a tranquil meadow in front of you.')
    print('There is a stone monument engraved with mystical symbols you walk over.')
    print('As you are examining the monument, you hear, "You came back."')
    print(f'You look up to see Anika standing next to the monument.')
    print('Anika opens a portal and tells you, "Go through, I do not know if they can follow you."')
    print(f'You exit the portal to find yourself outside the school.')
    print(f'Anika tells you how a spy they have inside the ranks of the enforcers informed them of a boy fitting your description.')
    print('Ms. Blackwood created a small portal through which we could watch you.')
    print('We saw you open a portal, and I placed a portal in front of you.')

    if path == "spy":
        print("You save that information to tell the king")
    print('You and Anika enter the school to find Ms. Blackwood and Hazel sitting in the atrium.')
    print('You and Anika join them.')
    print('Ms. Blackwood tells you the reason that the king is testing people\'s powers:')
    print('It is to gain enough power to create a permanent portal between our time and some time in the future.')
    if path == "spy":
        print("Anika tells Ms. Blackwood and Hazel about how you were smart to tell the king you would spy on them.")
        print("She explains how this strategy gave you the chance to escape.")
        a = False
        while a == False:
            do = input("What do you say?\n\t1) False Confession\n\t2) Stop Spying\n").lower()
            if do in ("1", "false confession", "1) false confession", "confess falsely", "admit falsely", "false confess", "one"):
                print("You tell them you are greatful that they found you")
                a = True
            elif do in ("2", "stop spying", "2) stop spying", "quit spying", "cease spying", "halt spying", "two"):
                print ("you tell them how greatful you are that they saved you.")
                path = "comply"
                a = True
            else:
                print("Invalid choice. Please select a valid option.")
                a = False
    else:
        print("you tell them how greatful you are that they saved you.")
    print("Hazel tells you about how they have been in hiding since the Dread Knight became the head enforcer.")
    print("They begin to plan on how to stop the king.")
    print("You all try to gather more magical individuals.")
    print("One of Ms. Blackwood’s friends, Cedric, has the power to change something’s shape and add mechanical elements.")
    print("You get ready and go to the city to fight the king.")
    print("You, Ms. Blackwood, Anika, Hazel, and Cedric reach the outskirts of the city.")
    characters_hp["Cedric"] = "Alive"            
    if path == "spy":
        print("you warned the king that you all were coming")
        
    else:
        print("As you all approach the city, bells ring out.")
        print("Enforcers, led by the Dread Knight and the woman that was testing your power, exit the city.")

    print("You count over 200 enforcers in front of the city.")
    if path == "spy":
        gusto = " and that will destroy the universe"
    else:
        gusto = ""
    print(f'Ms. Blackwood yells to the Dread Knight, "We know the king will try and create a permanent portal to the future{gusto}!"')
    print("The Dread Knight responds with, \"You couldn’t stop us if you had an army of a hundred magicians. What should we do with them, Aurelia?\"")
    print("As he draws a sword that is eight feet long from a two-foot sheath.")
    print("Aurelia says, \"We should end them\" as she throws a knife rippling with magic, presumably to block their powers.")
    print("You see Anika draw her sword, purple flames dancing up and down its length.")
    print("She swings the sword, blocking the knife. The flames sputter out as all the magic leaves the sword.")
    print("Ms. Blackwood summons a fireball and shoots it at Anika's sword, reigniting its magic.")
    print("The enforcers all rush forward, armed with all manner of weapons.")
    print("You watch as enforcers fall from a portal, placed a hundred feet off the ground by Hazel.")
    print("Ms. Blackwood is fighting Aurelia.")
    if path == "spy":
        spyBattle(name,coins,portals,blackwood,path,characters_hp)
    else:
        enforsercount = 0
        found = ""
        witchGather(name,coins,portals,blackwood,path,enforsercount,characters_hp,found)
        

def spyBattle(name,coins,portals,blackwood,path,characters_hp):
    a = False
    while a == False:
        do = input("What will you do?\n\t1) Attack the witches\n\t2) Double Cross the king\n")
        if do in ("1", "attack the witches", "1) attack the witches", "attack witches", "fight the witches", "assault the witches", "combat the witches", "one"):
            print("You draw your sword and see it start to glow like Aurelia's armor.")
            print("You feel a rush of power and open a portal steping through you stab Hazel")
            characters_hp["Hazel"] = "Dead"
            print("You turn to see Cedric creating a stone army that is fighting the enforcers.")
            print("A purple fireball whizzes past your head.")
            print("Ms. Blackwood screams at you, \"TRAITOR!\"")
            a = True
        elif do in ("2", "double cross the king", "2) double cross the king", "betray the king", "deceive the king", "turn on the king", "trick the king", "two"):
             complyBattle (name,coins,portals,blackwood,path,characters_hp)
        else:
            print("Invalid choice. Please select a valid option.")
            a = False
            
    b = False
    while b == False:
        action = input("what now?\n\t1) Fight Cedric and Destroy the Stone Army\n\t2) Attempt to Convince Ms. Blackwood That You Are Still Loyal\n\t3) Fight Ms. Blackwood\n\t4) Find and Fight Anika\n")
        if action in ("1", "fight cedric and destroy the stone army", "1) fight cedric and destroy the stone army", "fight cedric", "destroy the stone army", "fight stone army", "combat cedric", "one"):
            print("You ignore Ms. Blackwood and run over to fight cedric")
            print("Cedric turns a sword apiring in his hand he swings at you and you block with your sword")
            if "enchanted dagger" in Inventory:
                print("You draw your Enchanted Dagger with your other hand.")
                print("You stab Cedric.")
                print("You see all the stone soldiers fall.")
                print("You look over to see Ms. Blackwood and Anika being overrun by enforcers.")
                print("You return to the king.")
                print("The king congratulates you.")
                print("He thanks you for your help in ridding this world of rebellious witches.")
                characters_hp["Cedric"] = "Dead"
                characters_hp["Ms. Blackwood"] = "Dead"
                characters_hp["Anika"] = "Dead"
                enforsercount = 0
                won(name,coins,portals,blackwood,path,enforsercount,characters_hp)
            elif "flameblade knife" in Inventory:
                print("You draw your Flameblade with your other hand.")
                print("You stab Cedric.")
                print("He goes up in flames.")
                print("You see all the stone soldiers fall.")
                print("You look over to see Ms. Blackwood and Anika being overrun by enforcers.")
                print("You return to the king.")
                print("The king congratulates you.")
                print("He thanks you for your help in ridding this world of rebellious witches.")
                characters_hp["Cedric"] = "Dead"
                characters_hp["Ms. Blackwood"] = "Dead"
                characters_hp["Anika"] = "Dead"
                enforsercount = 0
                won(name,coins,portals,blackwood,path,enforsercount,characters_hp)
            else:
                print("Cedric creates another sword in his other hand impailing you")
                end("outclassed in combat and pierced through by Cedric’s twin blades",True)
        elif action in ("2", "attempt to convince ms. blackwood that you are still loyal", "2) attempt to convince ms. blackwood that you are still loyal", "convince ms. blackwood", "still loyal", "prove loyalty", "persuade ms. blackwood", "two"):
            print("Ms. Blackwood is not convinced.")
            print("She becomes enraged.")
            print("She summons a huge purple fireball.")
            print("She launches it at you.")
            print("The fireball hits, and you are killed.")
            end("incinerated by a magical explosion",True) 
            
        elif action in ("3", "fight ms. blackwood", "3) fight ms. blackwood", "combat ms. blackwood", "attack ms. blackwood", "battle ms. blackwood", "three"):
            b=True
            
        elif action in ("4", "find and fight anika", "4) find and fight anika", "fight anika", "search for anika", "combat anika", "battle anika", "four"):
            print("You turn to fight anika when a fireball hits you from behind.")
            end("dead",True)
        
        else:
            print("Invalid choice. Please select a valid option.")
            b= False
            
    c=False
    chance1 = ""
    chance2 =""
    chance3 = ""
    chance4 = ""
    chance5 = ""
    if "moonstone pendant" in Inventory:
        chance1 = ": Chance of death 80%"
        chance2 =": Chance of death 40%"
        chance3 = ": Chance of death 20%"
        chance4 = ": Chance of death 50%"
        chance5 =": Chance of death 60%"
        
    chooses = [f"1) Fight without Weapons{chance1}",f"2) Call for the Dread Knight’s Help{chance2}",f"3) Call for Aurelia's help{chance3}"]
    if "flameblade knife" in Inventory:
        chooses.append(f"4) Flameblade Knife{chance4}")
    if "enchanted dagger" in Inventory:
        chooses.append(f"4) Enchanted Dagger{chance5}")
    while c==False:
        print("what do you want to do?")
        for choice in chooses:
            print(choice)
        fun = input("").lower()
        if fun in ("1", "fight without weapons", "1) fight without weapons", "unarmed fight", "barehanded", "no weapons", "one"):
            random_number = random.randint(0, 100)
            if random_number <= 80:
                print(f'You brandish your fists you charge at Ms. Blackwood she conjures a huge ball of fire sending it at you')
                end("unarmed against an overwhelmingly powerful enemy",True)
            else:
                print("You charge at Ms. Blackwood bare-handed, dodging fireballs with quick reflexes and determination.")
                print("Ms. Blackwood, caught off guard by your bold approach, hesitates for a crucial moment.")
                print("You manage to grapple her, forcing her off balance.")
                print("You direct one of her own fireballs back at her, igniting her cloak.")
                print("As Ms. Blackwood stumbles, you take advantage, knocking her to the ground.")
                print("You use her own magic to trap her.")
                print("Cedric and Anika, distracted by the chaos and the enforcers surrounding them, barely react in time.")
                print("You seize the opportunity to confront them both.")
                print("In an intense struggle, you manage to turn Cedric’s mechanical constructs against him.")
                print("You neutralize him with his own stone weapons.")
                print("Anika, trying to defend herself, finds herself overwhelmed by your sheer determination and the enforcers pressing her on all sides.")
                print("Both Cedric and Anika fall, leaving you victorious over the three witches.")
                c=True
                
        elif fun in ("2", "call for the dread knight’s help", "2) call for the dread knight’s help", "call dread knight", "summon dread knight", "ask dread knight for help","two"):
            random_number = random.randint(0, 100)
            if random_number <= 40:
                print("You call for the Dread Knight, whose massive form begins to rush toward Ms. Blackwood, sword in hand.")
                print("She swiftly turns, her expression darkening as she channels an enormous burst of magic directly at the Dread Knight, freezing him mid-stride.")
                print("As the spell builds, she lifts him off the ground and slams him down with devastating force.")
                print("Seeing the Dread Knight incapacitated, she redirects her magic toward you.")
                print("You're caught off-guard as she pulls you into the center of her energy vortex.")
                print("Your vision blurs as you feel yourself engulfed in Ms. Blackwood's raw magical force.")
                end("Unlucky",True)

            else:
                print("You signal the Dread Knight, who strides forward with his enormous sword, casting an intimidating shadow over the battlefield.")
                print("Ms. Blackwood, recognizing the threat, tries to fend off the Dread Knight with a volley of powerful spells.")
                print("However, the Dread Knight’s sword absorbs her magical energy, growing stronger with each hit.")
                print("He charges, catching Ms. Blackwood in a devastating blow that knocks her backward, and she collapses, defenseless.")
                print("Cedric attempts to use his shaping powers to block the Dread Knight, forming barriers and throwing weaponized constructs.")
                print("But the Dread Knight’s sword cleaves through them with ease, and he cuts Cedric down with a single, precise strike.")
                print("Anika, desperate, lunges to protect her fallen comrades, but the Dread Knight’s sheer force and your support overwhelm her.")
                print("Together, you and the Dread Knight vanquish the three witches.")
                c=True
                
        elif fun in ("3", "call for aurelia's help", "3) call for aurelia's help", "call aurelia", "summon aurelia", "ask aurelia for help", "three"):
            random_number = random.randint(0, 100)
            if random_number <= 20:
                print("You call out to Aurelia, who begins to channel energy into amplifying your abilities.")
                print("As she focuses, a flicker of hesitation crosses Ms. Blackwood’s face, but she quickly refocuses her energy.")
                print("She launches a dark, spiraling tendril of magic toward Aurelia.")
                print("Distracted by the spell, Aurelia is forced to break her concentration to defend herself.")
                print("As she falters, Ms. Blackwood strikes you directly.")
                print("Unshielded and unenhanced, you feel the crushing weight of Ms. Blackwood’s power as it overwhelms you.")
                print("You are left helpless in the face of her fury.")
                end("Unlucky",True)
            else:
                print("You call Aurelia, who steps in with her power to drain and manipulate magic.")
                print("She raises her hands, focusing her energy on Ms. Blackwood, and siphons away Ms. Blackwood’s magic, rendering her powerless.")
                print("Ms. Blackwood tries to counterattack but finds herself weakened and unable to resist.")
                print("You close in for the final strike.")
                print("Aurelia then turns her focus on Cedric, amplifying your abilities.")
                print("With her help, you navigate Cedric’s stone constructs with ease.")
                print("Cedric, overwhelmed by his own magic turned against him, is no match for you.")
                print("You strike him down.")
                print("Anika, realizing the odds are stacked against her, attempts to flee.")
                print("Aurelia blocks her escape.")
                print("Trapped, Anika fights back, but you, empowered by Aurelia’s boost, defeat her decisively.")
                print("The battlefield quiets as the three witches lie defeated, with you standing victorious alongside Aurelia.")
                c=True
                 
        elif fun in ("4", "flameblade knife", "4) flameblade knife", "use flameblade knife", "draw flameblade knife", "flame knife", "four") and "flameblade knife" in Inventory:
            random_number = random.randint(0, 100)
            if random_number <= 50:
                print("You lunge at Ms. Blackwood with the Flameblade Knife, hoping its enchanted edge will penetrate her defenses.")
                print("She senses your approach and watches with a cold smile.")
                print("Ms. Blackwood mutters a counterspell that transforms the air around you into a suffocating heat.")
                print("The Flameblade grows too hot to hold, scalding your hand and forcing you to drop it.")
                print("As you reel from the pain, Ms. Blackwood seizes the opportunity.")
                print("She hurls you back with a wave of fire that engulfs you completely.")
                print("The last thing you hear is her laughter echoing in the flames.")
                end("laughed at",True)
            else:
                print("You draw the Flameblade, its edge glowing with fiery magic.")
                print("Advancing on Ms. Blackwood, you see her quickly realize the danger and attempt to neutralize the flame with a spell.")
                print("But the blade, fueled by your determination, resists her magic.")
                print("You use the flames to cut through Ms. Blackwood’s defenses.")
                print("In a decisive moment, you land a powerful strike that overpowers her.")
                print("Cedric tries to retaliate, summoning weapons and stone soldiers.")
                print("But your Flameblade cuts through his constructs, igniting each one and reducing his defenses to rubble.")
                print("Anika, enraged, attacks with her own magic-infused sword.")
                print("But you deflect her strikes, eventually overpowering her with a final slash.")
                print("The three witches lie defeated, their power extinguished by your flame-wielding hand.")
                c=True
                
        elif fun in ("4", "enchanted dagger", "4) enchanted dagger", "use enchanted dagger", "draw enchanted dagger", "magic dagger","four") and "enchanted dagger" in Inventory:
            random_number = random.randint(0, 100)
            if random_number <= 60:
                print("You throw the Enchanted Dagger toward Ms. Blackwood, hoping to catch her off guard with the weapon’s magical return ability.")
                print("The dagger sails through the air, but Ms. Blackwood quickly raises her hand, summoning a swirling barrier of energy.")
                print("The dagger strikes her barrier and, to your horror, begins to rotate in mid-air, trapped in her magic.")
                print("With a slight twist of her wrist, Ms. Blackwood turns the dagger back toward you.")
                print("You watch in shock as your own weapon, now glowing with Ms. Blackwood’s magic, hurtles back.")
                print("The dagger strikes with unerring accuracy, and as it returns to your hand, it delivers a fatal burst of energy from Ms. Blackwood’s spell.")
                print("Overwhelmed by the force, you are struck instantly, feeling the magic overwhelm you.")
                end("unable to control  your own weapon",True)
            else:
                print("You throw the Enchanted Dagger at Ms. Blackwood.")
                print("Expecting it to be a mere distraction, she’s surprised when the dagger returns instantly to your hand, allowing for quick successive strikes.")
                print("She attempts to create barriers to block the dagger, but its speed and persistence begin to wear her down.")
                print("In a final throw, the dagger strikes her directly, draining her remaining strength.")
                print("Cedric, witnessing her defeat, attacks you with his stone constructs.")
                print("But you use the dagger’s magical return to attack Cedric from multiple angles, eventually breaking through his defenses.")
                print("Anika, the last witch standing, tries to deflect the dagger but is caught off guard by its unpredictable path.")
                print("You land a final strike with the dagger, sealing the fate of the three witches.")
                c=True
        else:
            print("Invalid choice. Please select a valid option.")
            c = False
    characters_hp["Ms. Blackwood"] = "Dead"
    characters_hp["Anika"] = "Dead"
    characters_hp["Cedric"] = "Dead"
    print("You return to the king.")
    print("He congratulates you and thanks you for your help.")
    print("He praises you for ridding this world of rebellious witches.")
    won(name,coins,portals,blackwood,path,enforsercount,characters_hp)
                
def betrayer(name,coins,portals,blackwood,path,characters_hp):
    print("The Dread Knight removes your chains.")
    print('He tells you, "I am glad to see someone with so much respect for the throne."')
    print("The king tells you and the Dread Knight to bring Anika, Ms. Blackwood, and Hazel to him so he can sentence them properly.")
    print("You follow the Dread Knight out of the castle to the cart you were brought in on.")
    print("The Dread Knight reaches in and grabs your sword and your satchel.")
    enforsercount = 12
    items = [f"{value} {key.capitalize()}" for key, value in Inventory.items()]
    formatted_inventory = ", ".join(items[:-1]) + ", and " + items[-1] if len(items) > 1 else items[0]
    print(f"You open the satchel to find {formatted_inventory} and {coins} coins.")
    print ('The dread knight asks you')
    a = False
    while a == False:
        
        first = input ("Who should we go after first?\n\t1) Anika\n\t2) Ms. Blackwood\n\t3) Hazel\n").lower()
        if first in ("1","one","anika"):
            print("You choose to go after Anika.")
            fightAnika(name,coins,portals,blackwood,path,enforsercount,characters_hp)
            a = True
        elif first in ("two","2","ms. blackwood","blackwood"):
            fightBlackwood  (name,coins,portals,blackwood,path,enforsercount,characters_hp)
            a = True
        elif first in ("three", "3",'hazel'):
            fightHazel (name,coins,portals,blackwood,path,enforsercount,characters_hp)
            a = True
        else:
            print("Invalid choice. Please select a valid option.")
            a = False

def fightAnika(name,coins,portals,blackwood,path,enforsercount,characters_hp):
    print('You tell the Dread Knight, "We should fight Anika."')
    print("The Dread Knight informs you of a lead as to the location of Anika.")
    print("You and the Dread Knight set off, followed by a group of enforcers,")
    print(f"{enforsercount} strong, on your way to a desolate mountain.")
    print("You finally make it.")
    print("As you begin to ascend the mountain, you see Anika on a ledge above you.")
    chance1 = ""
    chance2 = ""
    chance = int(100 - enforsercount/12 *100)
    chance3 = ""
    chance4 = ""
    if "moonstone pendant" in Inventory:
        chance1 = ": Chance of Death 50%"
        chance = int(100 - enforsercount/12 *100)
        chance2 = f": Chance of Death {chance}%" 
        chance3 = ": Chance of Death 30%"
        chance4 = ": Chance of Death 10%"
    fire = ""
    if "bow" in Inventory:
        fire = f"\t4) Use your bow{chance4}\n"
    a = False
    while a == False:
        action = input(f"What do you want to do?\n\t1) Warn Anika{chance1}\n\t2) Continue up the mountain{chance2}\n\t3) Open Portal{chance3}\n{fire}").lower()
        if action in ("1", "warn anika", "warn her", "tell anika", "alert anika", "one"):
            print("You call out to Anika")
            random_number = random.randint(0, 100)
            if random_number>= 50:
                print('You call out to Anika.')
                print('She looks down to see you surrounded by enforcers.')
                print('The next thing you know, she is standing next to you, holding a sword in each hand.')
                print('You draw your sword and fight alongside Anika.')
                print('Together, you kill the Dread Knight.')
                print('You tell Anika about the deal you made with the king.')
                characters_hp["Dread Knight"] = "Dead"
                d = 0
                if characters_hp["Ms. Blackwood"] == "Dead":
                    print("and how you felt like you had no choice and killed Ms. Blackwood.")
                    d = d +1
                if characters_hp["Hazel"] == "Dead":
                    print("and how you felt like you had no choice and killed Hazel.")
                    d = d + 1
                if d >= 1:
                    print('Anika looks at you with disgust.')
                    print('She says, "You kill them, but not me? You traitor!"')
                    print('Anika slices you in half before you even know what happened.')
                    end("sliced down by poetic justice")
                print (" to find her.")
                witchGather(name,coins,portals,blackwood,path,enforsercount,characters_hp,"Anika")
            else:
                print("You yell out to Anika.")
                print("The Dread Knight turns to you and yells, 'You traitor!'")
                print("He draws an 8-foot long sword out of a 2-foot sheath on his belt.")
                print("With a swift motion, he swings the sword.")
                print("The blade cuts you in half.")
                end("a double double agent", True)
        elif action in ("2", "continue up the mountain", "keep climbing", "go up the mountain", "climb", "continue", "keep going", "two"):
            if chance < 25:
                print(f"You, the Dread Knight, and {enforsercount} enforcers make your way up to Anika.")
                print("You all prepare for a fight.")
                print("Anika, using a lot of effort, manages to push you all off the cliff.")
                end("a victim to hights",True)
            else: 
                characters_hp["Anika"] = "captured"
                ret = "unconscious"
                enfor = random.randint(0, enforsercount)
                enforsercount = enforsercount - enfor
                print(f"You, the Dread Knight, and {enforsercount} enforcers make your way up to Anika.")
                print("You all engage in a fierce fight.")
                print(f"Anika manages to kill {enfor} of your enforcers before you land a blow.")
                print("You knock out Anika, capturing her.")
                print("The Dread Knight congratulates you.")
                a = True
                
        elif action in ("3","open portal", "open it", "activate portal", "three"):
            random_number = random.randint(0, 100)
            if random_number>= 30:
                print("You open a portal and tell the Dread Knight, 'Let's go.'")
                print("You and the Dread Knight run through the portal.")
                print("You come out right behind Anika.")
                print("You knock her out.")
                print("The Dread Knight congratulates you.")
                characters_hp["Anika"] = "captured"
                ret = "unconscious"
                a = True
                
            else:
                print("You open a portal.")
                print("The Dread Knight draws an 8-foot-long sword from a 2-foot sheath on his belt.")
                print('He yells, "No!"')
                print("With a swift motion, he swings the sword and cuts you in half.")
                end("slashed mid-escape",True)
        elif action in ("4", "use your bow", "shoot", "bow", "fire arrow", "use bow", "four"):
            if "bow" not in Inventory:
                print("Invalid choice. Please select a valid option.")
                a = False
            random_number = random.randint(0, 100)
            if random_number>= 10:
                print("You draw back your bow firing an arrow up. It hits Anika killing her.")
                characters_hp["Anika"] = "Dead"
                ret = "Dead"
                print('The dread knight congradulates you but reminds you that the king wants them captured.')
                a = True
                
            else:
                print("You draw back your bow.")
                print("You aim and fire one arrow straight up into the air.")
                print("The arrow comes up short.")
                print("It begins to rotate back toward the ground.")
                print("As it falls, it hits you.")
                end("a victim of gravity",True)
        else:
            print("Invalid choice. Please select a valid option.")
            a = False
            
    b = False
    if (characters_hp["Hazel"] == "Dead" or characters_hp["Hazel"] == "captured") and (characters_hp["Ms. Blackwood"] == "Dead" or characters_hp["Ms. Blackwood"] == "captured"):
        allDead(name,coins,portals,blackwood,path,enforsercount,characters_hp)
    if characters_hp["Hazel"] == "Dead" or characters_hp["Hazel"] == "captured":
        fightBlackwood  (name,coins,portals,blackwood,path,enforsercount,characters_hp)
    if characters_hp["Ms. Blackwood"] == "Dead" or characters_hp["Ms. Blackwood"] == "captured":
        fightHazel (name,coins,portals,blackwood,path,enforsercount,characters_hp)
    if characters_hp["Hazel"] == "Alive" and characters_hp["Ms. Blackwood"] == "Alive":
        while b == False:
            target = input("Who next?\n\t1)Ms. Blackwood\n\t2) Hazel\n").lower()
            if target in ("one","1","ms. blackwood","blackwood"):
                print(f"you return to the castle with Anika's {ret} body.")
                fightBlackwood  (name,coins,portals,blackwood,path,enforsercount,characters_hp)
            elif target in ("two", "2",'hazel'):
                fightHazel (name,coins,portals,blackwood,path,enforsercount,characters_hp)
            else:
                 print("Invalid choice. Please select a valid option.")
                 b=False
        
        
        print("You tell the dread knight lets go after")

def fightHazel (name,coins,portals,blackwood,path,enforsercount,characters_hp):
    print('You tell the Dread Knight, "We should capture Hazel."')
    print('You ask the king if he knows where Hazel is.')
    print('He tells you she is in a cave and gives you a map.')
    print(f'You, the Dread Knight, and a group of {enforsercount} enforcers set off on your way to the cave.')
    print('The group arrives at the cave.')
    Inventory["map"] = 1
    light = "torch"
    if "flameblade knife" in Inventory:
        print("You draw your Flameblade Knife")
        light = "flameblade knife"
    else:
        print("The dread knight picks up a stick and the end catches a blaze")

    print(f"Everyone enters, guided by {light}.")
    print("The deeper you go, the quieter it gets.")
    print("Then, you hear footsteps in the distance.")
    print("As you reach a fork, the sound grows louder.")
    chance1 = ""
    chance2 = ""
    chance = int(100 - enforsercount/12 *100)
    chance3 = ""
    if "moonstone pendant" in Inventory:
        chance1 = ": Chance of Death 60%"
        chance = int(100 - enforsercount/12 *100)
        chance2 = f": Chance of Death {chance}%" 
        chance3 = ": Chance of Death 0%"
    random_number = random.randint(0, 100)
    a = False
    retu = "Alive"
    while a == False:
        do = input(f"What to do?\n\t1) Warn her{chance1}\n\t2) Charge{chance2}\n\t3) Stealthily{chance3}\n")
        if do in ("1", "warn her", "1) warn her", "alert her", "tell her", "one"):
            if random_number <= 40:
                print ("You call out for Hazal and the dread knight does not like that.")
                end(" a triple agent", True)
            else:
                print("You call out to Hazal")
                if light ==  "Flameblade Knife":
                    print("As you spin around, you launch your Flaming Knife at the Dread Knight.")
                    print("The knife strikes him, and he falls, defeated.")
                    print("You swiftly draw your sword and charge at the enforcers.")
                    print("With a few precise strikes, you kill the remaining enforcers.")
                else:
                    print("you spin around drawing your sword dispaching the Dread knight and the enforsers.")
            print("You Find Hazel")       
            characters_hp["Dread Knight"] = "Dead"
            print("You tell Hazel about the deal you made with the king")
            d = 0
            if characters_hp["Ms. Blackwood"] == "Dead":
                print("and how you felt like you had no choice and killed Ms. Blackwood.")
                d = d +1
            if characters_hp["Anika"] == "Dead":
                print("and how you felt like you had no choice and killed Anika.")
                d = d + 1
            if d >= 1:
                print('Hazal looks at you with disgust.')
                print('She says, "You kill them, but not me, you traitor."')
                print('Before you even know what happens, Hazal slices you in half.')
                end("sliced down by poetic justice")
            print (" to find her.")
            witchGather(name,coins,portals,blackwood,path,enforsercount,characters_hp,"Hazal")
                    
        elif do in ("2", "charge", "2) charge", "attack", "rush", "run at", "two"):
            if chance >= 25:
                print("You the dread knight and the enforsers charge forward following the sound of footsteps.")
                print("you reach Hazel")
                if light ==  "Flameblade Knife":
                    print("you through your knife impailing Hazel")
                    retu = "Dead"
                else:
                    enfor = random.randint(0, enforsercount)
                    enforsercount = enforsercount - enfor
                    print("You draw your sword, catching Hazel by surprise.")
                    print(f"She draws a knife, managing to kill {enfor} before you kill her.")
                    retu = "Dead"
                    a= True
                    
            else:
                print(f"You charge in, followed by the Dread Knight and the {enforsercount} enforcers.")
                print("Hazel, with surprise on her face, dodges your blade.")
                print("She knocks you down, dispatching the rest of your group.")
                print("Then, she summons a fireball, setting you ablaze.")
                end("cooked",True)
                 
        elif do in ("3", "stealthily", "3) stealthily", "sneak", "move quietly", "creep", "three"):
            print(f"You and the Dread Knight creep forward.")
            print("When you see Hazel, you run toward her.")
            print("You catch her off guard and knock her out.")
            retu = "unconscious"
            a = True
    print("the dread knight congradulates you")
    b = False
    if (characters_hp["Anika"] == "Dead" or characters_hp["Anika"] == "captured") and (characters_hp["Ms. Blackwood"] == "Dead" or characters_hp["Ms. Blackwood"] == "captured"):
        allDead(name,coins,portals,blackwood,path,enforsercount,characters_hp)
    if characters_hp["Anika"] == "Dead" or characters_hp["Anika"] == "captured":
        fightBlackwood  (name,coins,portals,blackwood,path,enforsercount,characters_hp)
    if characters_hp["Ms. Blackwood"] == "Dead" or characters_hp["Ms. Blackwood"] == "captured":
        fightHazel (name,coins,portals,blackwood,path,enforsercount,characters_hp)
    if characters_hp["Anika"] == "Alive" and characters_hp["Ms. Blackwood"] == "Alive":
        while b == False:
            target = input("Who next?\n\t1)Ms. Blackwood\n\t2) Anika\n").lower()
            if target in ("one","1","ms. blackwood","blackwood"):
                print(f"you return to the castle with Hazel's {ret} body.")
                fightBlackwood  (name,coins,portals,blackwood,path,enforsercount,characters_hp)
            elif target in ("two", "2",'anika'):
                fightAnika (name,coins,portals,blackwood,path,enforsercount,characters_hp)
            else:
                 print("Invalid choice. Please select a valid option.")
                 b=False       
    
def fightBlackwood  (name,coins,portals,blackwood,path,enforsercount,characters_hp):
    print('You tell the Dread Knight, "We should capture Ms. Blackwood. I bet she is at the Witch school."')
    print(f'You set off with the Dread Knight and the {enforsercount} enforcers.')
    print("You arrive at the school.")
    print("You yell out to Ms. Blackwood.")
    a = False
    while a == False:
        do = input ("What do you say?\n\t1) Warn her\n\t2) Come out?\n")
        if do in ("1", "warn her", "1) warn her", "alert her", "tell her", "one"):
            print('You call out to Ms. Blackwood saying that there are soldiers.')
            print('The next thing you know,')
            print('where the Dread Knight and all the enforcers were standing lay piles of ash.')
            characters_hp["Dread Knight"] = "Dead"
            print("You tell Ms. Blackwood about the deal you made with the king")
            d = 0
            if characters_hp["Hazal"] == "Dead":
                print("and how you felt like you had no choice and killed Hazal.")
                d = d +1
            if characters_hp["Anika"] == "Dead":
                print("and how you felt like you had no choice and killed Anika.")
                d = d + 1
            if d >= 1:
                print('Ms. Blackwood looks at you with disgust.')
                print('She says, "You kill them, but not me, you traitor."')
                print('Ms. Blackwood sends you up in flames.')
                end("burnt down by poetic justice")
            print (" to find her.")
            witchGather(name,coins,portals,blackwood,path,enforsercount,characters_hp,"Ms. Blackwood")

        elif do in ("2", "come out", "2) come out", "show yourself", "reveal yourself", "step out", "appear", "two"):
            fightBlackwood2 (name,coins,portals,blackwood,path,enforsercount,characters_hp)
        else:
            print("Invalid choice. Please select a valid option.")
            a =False       

def fightBlackwood2 (name,coins,portals,blackwood,path,enforsercount,characters_hp):
    print("Ms. Blackwood exits the door")
    a= False
    while a == False:
        items = [f"{value} {key.title()}" for key, value in Inventory.items()]
        formatted_inventory = ", ".join(items[:-1]) + ", and " + items[-1] if len(items) > 1 else items[0]
        print(f"You have {formatted_inventory} in your inventory")
        do = input("What to use?\n").lower()
        if do == "moonstone pendant" and "moonstone pendant" in Inventory:
            del Inventory["moonstone pendant"]
            print("Ms. Blackwood uncreated your Moonstone Pendant")
            a = False
        elif do == "disguise" and "disguise" in Inventory:
            del Inventory["disguise"]
            print("Ms. Blackwood uncreated your Disguise")
            a = False
        elif do == "flameblade knife" and "flameblade knife" in Inventory:
            del Inventory["flameblade knife"]
            Inventory["knife"] = 1
            print("Ms. Blackwood took flame from your Flameblade Knife")
            a = False
        elif do == "enchanted dagger" and "enchanted dagger" in Inventory:
            del Inventory["enchanted dagger"]
            Inventory["dagger"] = 1
            print("Ms. Blackwood took enchantment from your Enchanted Dagger")
            a = False
        elif do == "phone" and "phone" in Inventory:
            print("No service")
            a = False
        elif do == ("shirt" or "pair of pants") and ("pair of pants" in Inventory or "shirt" in Inventory):
            print("Do you really think that that would help.")
            a=False
        elif do == ("key" or "cell key") and ("key" in Inventory or "cell key" in Inventory):
            print("there is nothing to unlock")
            a=False
        elif do == "sword" and "sword" in Inventory:
            weapon = "sword"
            chanceBuff = 50
            a = True
        elif do == "bow" and "bow" in Inventory:
            weapon = "bow"
            chanceBuff = 60
            a = True
        elif do == "knife" and "knife" in Inventory:
            weapon = "knife"
            chanceBuff = 30
            a = True
        elif do == "dagger" and "dagger" in Inventory:
            weapon = "dagger"
            chanceBuff = 30
            a = True
        elif do == "map" and "map" in Inventory:
            weapon = "map"
            chanceBuff = 100
            a = True
        else:
            print("Invalid choice or you do not have that item. Please select a valid option.")
            a = False
    print(f"You draw your {weapon}")
    print(f"Ms. Blackwood summens a fireball and hurals it at you")
    random_number = random.randint(0, 100)
    random_number = random_number + chanceBuff
    if random_number >= 40:
        print("You dodge out of the way of the fireball")
    else:
        print("you are hit with the fireball")
        end("hit with a fireball",True)
    if weapon == "bow":
        print("You fire an arrow cliping Ms. Blackwood's Leg")
        characters_hp["Ms. Blackwood"] = "Hurt"
    else:
        print("The Dread Knight charges at Ms. Blackwood with his sword drawn.")
        print("Ms. Blackwood opens a portal that blocks the Dread Knight.")
        
    if enforsercount >= 2:
        print("Ms. Blackwood summining another fireball huraling it at two of your enforsers killing them")
        enforsercount= enforsercount-2
    random_number = random.randint(0, 100)
    random_number = random_number + chanceBuff
    if random_number >= 60:
        if weapon == "sword" or "dagger" or "knife":
            print(f"You open a portal above Ms. Blackwood swining your {weapon} through hitting Ms. Blackwood")
            characters_hp["Ms. Blackwood"] = "captured"
            step(name,coins,portals,blackwood,path,enforsercount,characters_hp,found)
        elif wepon == "bow":
            print(f"You open a portal above Ms. Blackwood fireing an arrow through hitting Ms. Blackwood in the head")
            print("Your arrow kills Ms. Blackwood")
            characters_hp["Ms. Blackwood"] = "Dead"
            step(name,coins,portals,blackwood,path,enforsercount,characters_hp,found)
        elif weapon == "map":
            print("You roll up your map and open a portal steping through you knock out Ms. Blackwood")
            characters_hp["Ms. Blackwood"] = "captured"            
    else:
        print("Ms. Blackwood Opens a portal underneth you and you fall through coming out over an active volcano")
        end("turned to rock",True)
        step(name,coins,portals,blackwood,path,enforsercount,characters_hp,found)                 
    
def step(name,coins,portals,blackwood,path,enforsercount,characters_hp,found):
    if characters_hp["Ms. Blackwood"] == "Dead":
        ret = "Dead"
    else:
        ret = "unconscious"
    
    print("The dread knight Congratulates you")
    b = False
    if (characters_hp["Anika"] == "Dead" or characters_hp["Anika"] == "captured") and (characters_hp["Hazel"] == "Dead" or characters_hp["Hazel"] == "captured"):
        allDead(name,coins,portals,blackwood,path,enforsercount,characters_hp)
    if characters_hp["Anika"] == "Dead" or characters_hp["Anika"] == "captured":
        fightBlackwood  (name,coins,portals,blackwood,path,enforsercount,characters_hp)
    if characters_hp["Hazel"] == "Dead" or characters_hp["Hazel"] == "captured":
        fightHazel (name,coins,portals,blackwood,path,enforsercount,characters_hp)
    if characters_hp["Anika"] == "Alive" and characters_hp["Hazel"] == "Alive":
        while b == False:
            target = input("Who next?\n\t1)Hazel\n\t2) Anika\n").lower()
            if target in ("one","1","hazel"):
                print(f"you return to the castle with Ms. Blackwood's {ret} body.")
                fightBlackwood  (name,coins,portals,blackwood,path,enforsercount,characters_hp)
            elif target in ("two", "2",'anika'):
                fightAnika (name,coins,portals,blackwood,path,enforsercount,characters_hp)
            else:
                 print("Invalid choice. Please select a valid option.")
                 b=False       
        

def witchGather(name,coins,portals,blackwood,path,enforsercount,characters_hp,found):
    characters_hp["Cedric"] = "Alive"
    if characters_hp["Hazel"] == "captured":
        print("you find and save Hazel")
    if characters_hp["Ms. Blackwood"]  =="captured":
        print("you find and save Ms. Blackwood")
    if characters_hp["Anika"] == "captured":
        print("you find and save Anika")
    if path == "betray":
        gusto = " and that will destroy the universe"
        print("Ms. Blackwood tells you that the reason the king is testing people's powers is to gain enough power to create a permanent portal between our time and some time in the future.")
        print("They begin to plan on how to stop the king.")
        print("You all try to gather more magical individuals.")
        print("One of Ms. Blackwood’s friends, Cedric, has the power to change something’s shape and add mechanical elements.")
        print("You get ready and go to the city to fight the king.")
        print("You, Ms. Blackwood, Anika, Hazel, and Cedric reach the outskirts of the city.")
        print("As you all approach the city, bells ring out as enforcers, led by the Dread Knight and the woman who was testing your power, exit the city.")
        print("You count over 200 enforcers in front of the city.")
        print("Ms. Blackwood yells to the Dread Knight, 'We know the king will try and create a permanent portal to the future " + gusto + "!'")
        print('The Dread Knight responds with, "You couldn’t stop us if you had an army of a hundred magicians. What should we do with them, Aurelia?" as he draws a sword that is eight feet long from a two-foot sheath.')
        print('Aurelia says, "We should end them" as she throws a knife rippling with magic, presumably to block their powers.')
        print("You see Anika draw her sword, purple flames dancing up and down its length.")
        print("She swings the sword, blocking the knife. The flames sputter out as all the magic leaves the sword.")
        print("Ms. Blackwood summons a fireball and shoots it at Anika's sword, reigniting its magic.")
        print("The enforcers all rush forward, armed with all manner of weapons.")
        print("You watch as enforcers fall from a portal, placed a hundred feet off the ground by Hazel.")
        print("Ms. Blackwood is fighting Aurelia.")
        print("The Dread Knight charges at you and swings his sword.")
        print("You draw your sword and try to block, but the immense force from the Knight’s sword knocks you over.")
        print("You jump to your feet, feeling anger wash over you.")
        print("The flames of your sword grow into an inferno, the color changing from purple to red as you leap in to fight the Dread Knight.")
        print('The Dread Knight looks confused. "I thought your power was portals, not elemental manipulation."')
    a = False
    if "moonstone pendant" in Inventory:
        chance1 = " Chance of death: 0%" # 100% survive
        chance2 = " Chance of death: 80%" # if random_number >= 20: survive
        chance3 = " Chance of death: 50%" # if random_number >= 50: survive
        chance4 = " Chance of death: 70%" # if random_number >= 30: survive
        chance5 = " Chance of death: 100%" # 100% death
        chance6 = " Chance of death: 40%" # if random_number >= 60: survive
    else:
        chance1 = ""
        chance2 = ""
        chance3 = ""
        chance4 = ""
        chance5 = ""
        chance6 = ""
    
    ch1 = ("1", "charge the dread knight head-on", "1) charge the dread knight head-on", "charge dread knight", "attack dread knight head-on", "head-on charge", "one")
    ch2 = ("2", "call on hazel for help", "2) call on hazel for help", "call hazel", "ask hazel for help", "summon hazel", "two")
    ch3 = ("3", "call on ms. blackwood for help", "3) call on ms. blackwood for help", "call ms. blackwood", "ask ms. blackwood for help", "summon ms. blackwood", "three")
    ch4 = ("4", "call on anika for help", "4) call on anika for help", "call anika", "ask anika for help", "summon anika", "four")
    ch5 = ("5", "call on cedric for help", "5) call on cedric for help", "call cedric", "ask cedric for help", "summon cedric", "five")
    ch6 = ("6", "disarm the dread knight", "6) disarm the dread knight", "disarm dread knight", "disable dread knight", "six")
    while a == False:
        random_number = random.randint(0, 100)
        action = input("What do you do?\n\t1) Charge the Dread Knight Head-On" + chance1 + "\n\t2) Call on Hazel for Help" + chance2 + "\n\t3) Call on Ms. Blackwood for Help" + chance3 + "\n\t4) Call on Anika for Help" + chance4 + "\n\t5) Call on Cedric for Help" + chance5 + "\n\t6) Disarm the Dread Knight" + chance6 + "\n").lower()
        if action in ch1:
            print("You respond by swinging your red-hot sword at the Knight.")
            print("He blocks, and the two swords weld together.")
            print("The Dread Knight draws a knife that immediately grows to eight feet long.")
            print("Hazel pushes you out of the way, tossing you a knife.")
            print("Hazel turns to fight the Dread Knight.")
            a = True
            
        elif action in ch2:
            print("Hazel creates a portal that disorients the Dread Knight.")
            print("But he quickly adapts.")
            print("While Hazel is distracted, one of the enforcers manages to knock her down.")
            print("You witness Ms. Blackwood fighting Aurelia.")
            print("Aurelia attempts to defend you.")
            random_number = random.randint(0, 100)
            if random_number >= 20:
                a = True
            else:
                print("The Dread Knight capitalizes on the opening.")
                print("He swings his massive sword down before you can react.")
                print("The last thing you see is Hazel scrambling to intervene.")
                print("But she’s just a moment too late.")
                end("caught off guard by a surprise strike",True)

        elif action in ch3:
            random_number = random.randint(0, 100)
            print("Ms. Blackwood diverts her attention from Aurelia.")
            print("She throws a fireball toward the Dread Knight to help you.")
            print("However, this leaves her vulnerable, and Aurelia seizes the moment.")
            print("Aurelia kills Ms. Blackwood.")
            print("The distraction lets the Dread Knight get the upper hand.")
            print("Chaos ensues as you watch the unfolding battle.")
            characters_hp["Ms. Blackwood"] = "Dead"
            if random_number >= 50:
                a = True
            else:
                print("With Ms. Blackwood dead,")
                print("Aurelia casts a devastating spell that immobilizes you.")
                print("You see the Dread Knight raising his sword,")
                print("bringing it down upon you.")
                end("too distracted by the battle's chaos",True)
        elif action in ch4:
            print("Anika deflects attacks from several enforcers to aid you,")
            print("but in doing so, she leaves herself open.")
            print("She holds her ground with impressive skill,")
            print("though one enforcer kills her.")
            print("Ms. Blackwood faces Aurelia,")
            print("unable to sustain her defense.")
            characters_hp["Anika"] = "Dead"
            if random_number >= 30:
                a = True
            else:
                print("The Dread Knight seizes the opportunity, disarming you and striking a fatal blow.")
                end("taken down by a single crushing blow",True)
                
        elif action in ch5:
            print("Cedric Stops making sodiers to help which alowed the enforsers to help the Dread Knight kill you")
            end("a destraction",True)
            
        elif action in ch6:
            print("You attempt to disarm the Dread Knight,")
            print("managing to make him drop his sword temporarily.")
            print("However, he quickly adapts,")
            print("retrieving it with newfound aggression.")

            if random_number >= 60:
                a = True
            else:
                print("As you focus on disarming the Dread Knight,")
                print("he retaliates with a powerful kick that throws you off balance.")
                print("In one swift motion, he reclaims his sword")
                print("and strikes you down while you’re vulnerable.")
                end("caught between the Dread Knight and a sea of enforcers",True)
        else:
            print("Invalid choice. Please select a valid option.")
            a= False       
    print('With all of your anger, you feel your hand start to heat up as you look down to see fire.')
    print('You run over and help wipe out enforcers. You feel amazing using so much power,')
    print('but then you feel all your power drain from you, causing all the mud soldiers to fall.')
    print('You see Hazel fall. All the enforcers still alive push forward, able to overpower the group with sheer numbers.')
    print('One of the enforcers knocks you out.')
    print('You look over to see a huge rainbow starting to appear.')
    print('You notice the king has begun manifesting a permanent portal.')
    print('Strange fluctuations in energy, flickering lights, and occasional ripples in the air displayed the imbalance in the portal.')
    print('Hazel yells to you, "I am going to stabilize the portal so that I can collapse it without destroying the universe."')
    print('"You protect Hazel while she stabilizes the portal and I will go fight the king," responds Cedric.')
    print('You notice the Dread Knight running towards Hazel.')
    print('You summon a fireball and launch it at the Dread Knight.')
    print('The fireball disappears as Aurelia blocks the magic.')
    print('You draw your sword as they grow closer.')
    print('You see the king turn away from the portal as he grows to five times his height, drawing a sword.')
    print('Cedric pulls rock from underground, covering himself in stone armor, making himself the same size as the king.')
    print('You see the portal collapse as you hear Hazel cheer.')
    characters_hp["Dread Knight"] = "Dead"
    if characters_hp["Ms. Blackwood"] == "Dead":
        print("You summon a fireball and launch it at Aurelia killing her")
    else:
        print("you look over to see Aurelia driving a sword through Ms. Blackwood’s chest.")
        characters_hp["Ms. Blackwood"] = "Dead"
    print("You look over to see Cedric kill the king.")
    characters_hp["King"] == "Dead"
    if characters_hp["Anika"] == "Dead":
        print("You summon a fireball and launch it at Aurelia killing her")
    else:
        print('Aurelia, unrelenting, gets up and charges at you, a portal appearing next to her.')
        print('Anika steps out with a sword in each hand, clearly angry.')
        print('Anika dispatches Aurelia, displaying her eminent prowess with a blade')
        print('and showing the tremendous force she puts into each blow.')

    if characters_hp["Anika"] == "Dead":
        print('Silence descends upon the devastated park, broken only by your soft sobs and Hazel\'s.')
        print('You stand in shock, feeling the weight of the losses you’ve just endured.')
        print('Hazel places a comforting hand on your shoulders, her expression somber yet resolute.')
        print('“We did everything we could,” she murmurs, her voice carrying the weight of your shared loss.')
        print('You stand amidst the destruction, your mind reeling from the magnitude of the event.')
        print('The absence of Anika and Ms. Blackwood feels like a heavy void.')
        print('In the days that follow, you and Hazel work together to restore the building and mend the wounds left by the portal’s collapse.')
        print('It’s a somber task, tinged with bittersweet memories of your time together.')
        print('Anika’s legacy lives on in the kingdom as her absence is felt by all who knew her.')
        print('But now, it’s your turn to carry the mantle forward.')
        won(name,coins,portals,blackwood,path,0,characters_hp)
    else:
        print('Silence descends upon the devastated park, broken only by your soft sobs and Anika’s.')
        print('Hazel places a comforting hand on your shoulders, her expression somber yet resolute.')
        print('“We did everything we could,” she murmurs, her voice carrying the weight of your shared loss.')
        print('You stand amidst the destruction, your mind reeling from the magnitude of the event.')
        print('You feel a profound sadness at the loss of the connection to your friends’ world.')
        print('In the days that follow, you all work together to restore the building and mend the wounds left by the portal’s collapse.')
        print('It’s a somber task, tinged with bittersweet memories of your time together.')
        print('Anika takes up the throne, now ready to lead with a newfound understanding of power and responsibility.')
        print('Feeling ready to return to your own time, you realize that you are unable to create a portal through time,')
        print('and that the permanent portal being closed has cut off time travel.')
        print('You join Anika and Hazel in ruling the kingdom as you create ways for all to learn magic,')
        print('ensuring the future remains bright despite the cost.')
        won(name,coins,portals,blackwood,path,0,characters_hp)
         
def allDead(name,coins,portals,blackwood,path,enforsercount,characters_hp):
    print("You return to the king")
    enemies = ["Anika", "Ms. Blackwood", "Hazel"]
    
    # Count how many are dead and how many are captured
    dead_count = sum(1 for enemy in enemies if characters_hp[enemy] == "Dead")
    captured_count = sum(1 for enemy in enemies if characters_hp[enemy] == "captured")
    alive_count = sum(1 for enemy in enemies if characters_hp[enemy] == "Alive")
    
    # Construct the outcome message based on counts
    if dead_count == len(enemies):
        outcome = "all_dead"
        print("All enemies have been killed.")
    elif captured_count == len(enemies):
        outcome = "all_captured"
        print("All enemies have been captured.")
    elif dead_count > 0 and captured_count > 0:
        outcome = "some_dead_some_captured"
        print(f"{dead_count} enemies have been killed, and {captured_count} have been captured.")
    else:
        outcome = "incomplete"
        print(f"{dead_count} enemies have been killed, {captured_count} have been captured, and {alive_count} are still alive.")
    
    if outcome == "all_dead":
        print("The king tells you I wanted them alive but it is good to be rid of them.")
    if outcome == "all_captured":
        print("The king Congradulates you for capuring all three witches")
    if outcome == "some_dead_some_captured":
        print("The king Congratulates you for the witches you captured and tells you he wanted all three alive but it is good to be rid of them")
    won(name,coins,portals,blackwood,path,enforsercount,characters_hp)

def won(name,coins,portals,blackwood,path,enforsercount,characters_hp):
    end_time = datetime.datetime.now()
    time_difference = end_time - start_time
    total_seconds = time_difference.total_seconds()
    hours = int(total_seconds // 3600)
    minutes = int((total_seconds % 3600) // 60)
    seconds = int(total_seconds % 60)
    print("")
    print(f"Total Time to complete this ending: {hours:02} hours {minutes:02} minutes and {seconds:02} seconds")
    print("")
    print(f"You have found one of the endings Congradulations {name.title()}!!!")
    print("")
    items = [f"{value} {key.title()}" for key, value in Inventory.items()]
    formatted_inventory = ", ".join(items[:-1]) + ", and " + items[-1] if len(items) > 1 else items[0]
    print(f"The items you finished with include: {formatted_inventory} and {coins} coins")
    print("")
    print(f"The path you took was: {path.title()}")
    print("")
    if path == "betray":
        print(f"The path you took was: {path.title()}")
        print(f"You finished with {enforsercount} enforcers following you.")
        print("In the aftermath of your betrayal, you rise to a position of power within the King's court.")
        print("Your name becomes both feared and revered as the one who turned the tide against the rebels.")
        print("However, the weight of your decisions haunts you, and whispers of your treachery follow you wherever you go.")
        print("The world may have gained peace, but at a cost that only you can fully understand.")
    elif path == "spy":
        print(f"The path you took was: {path.title()}")
        print("You pledge loyalty to the King and become a spy.")
        print("Living a double life, you navigate the treacherous waters of loyalty and deception.")
        print("Your covert actions save countless lives as you feed crucial information to the rebels.")
        print("In the shadows, you play a pivotal role in thwarting the King's plans, though your true allegiances remain hidden.")
        print("The duality of your existence weighs heavily, but your silent sacrifices pave the way for a brighter future.")
    elif path == "comply":
        print(f"The path you took was: {path.title()}")
        print("You comply with the King’s orders but secretly plot an escape.")
        print("Every action you take is a calculated move towards freedom.")
        print("You gather allies and resources, all while maintaining the facade of loyalty.")
        print("When the time is right, you lead a daring escape that not only frees you but also inspires others to rise against the King.")
        print("Your name becomes a symbol of resistance and hope for those who yearn for liberation.")
        print("Though the journey was fraught with danger, your courage and cunning bring about a new era of defiance and change.")

    print("")
    print("Thank you for playing!")
    play_from = " to play again?"
    again = input(f"Do you want{play_from}\n\t1) yes\n\t2) no\n").lower()  # Convert input to lowercase for easier comparison
    if again in ("1", "yes", "y", "one"):
        print("You choose to play again.")
        start()
    elif again in ("2", "no", "n", "two"):
        print("Thank you again for playing!")
        time.sleep(10)  # Delays for 10 seconds
        quit()
    else:
        print("Invalid choice. Please select a valid option.")
        won(name,coins,portals,blackwood,path,enforsercount,characters_hp)
    
    
def end(method, Halfway):
    print(f"You died due to being {method}!")  # Corrected string formatting
    if Halfway == True:
        play_from = " to play from getting back to your time?"
    else:
        play_from = " to play again?"
    
    again = input(f"Do you want{play_from}\n\t1) yes\n\t2) no\n").lower()  # Convert input to lowercase for easier comparison
    
    if again in ("1", "yes", "y", "one"):
        print("You choose to play again.")
        if Halfway == True:
            currenttime("bob", 0, True, True)
        else:
            start()
    elif again in ("2", "no", "n", "two"):
        print("Thank you for playing!")
        time.sleep(10)  # Delays for 10 seconds
        quit()
    else:
        print("Invalid choice. Please select a valid option.")
        end(method, Halfway)  # Pass method again to maintain context

start()

