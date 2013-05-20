from random import randint
from Player import Player
from Equipment import Equipment
import time
import sys

###################################
## --------- FUNCTIONS --------- ##
###################################

def DisplayTitleScreen():
	print( "###    ##   ##### #####  #    ####  ##" )
	print( "#  #  #  #    #     #    #    #     ##" )
	print( "###   ####    #     #    #    ####  ##" )
	print( "#  #  #  #    #     #    #    #       " )
	print( "###   #  #    #     #    #### ####  ##" )
	print()
	print( "Welcome to BATTLE!  In this game, you will be fighting in an arena." )
	print( "You have a playerChoice of a set of equipment to use, which have different" )
	print( "effects on your Strength, Defense, and Agility." )
	print()
	print( "Fight your opponent to the death, and for the love of Jim," )
	print( "try not to die." )
	print()
	print( "1. Start game" )
	print( "2. End game" )
# End DisplayTitleScreen

def DisplayEquipmentMenu( equipmentList, totalEquipment ):
	print( "**********************************************************************" )
	print( "CHOOSE YOUR EQUIPMENT" )
	print( "---------------------" )
	
	# Display all equipment
	for i in range( 0, totalEquipment ):
		equipmentList[i].DisplayInfo( i )
		print()
	print( "**********************************************************************" )
	print( "What equipment do you want? (Please enter the pack #)" )
# End DisplayEquipmentMenu

def DisplayBattleMenu( currentRound, player, enemy ):
	# sys.stdout.write is similar to print() but doesn't automatically new-line!
	
	print( "**********************************************************************" )
	sys.stdout.write( "Round " + str(currentRound ) )
	sys.stdout.write( "\t" 		+ player.GetName() + " HP: " + str( player.GetHP() ) )
	sys.stdout.write( "\t\t\t"	+ enemy.GetName() + " HP: " + str( enemy.GetHP() ) )
	print()
	sys.stdout.write( "\t"		+ player.GetName() + " Pack: " + player.GetPackName() )
	sys.stdout.write( "\t"		+ enemy.GetName() + " Pack: " + enemy.GetPackName() )
	print()
	sys.stdout.write( "\tS:" 		+ str( player.GetStrength() ) + " A:" + str( player.GetAgility() ) + " D:" + str( player.GetDefense() ) )
	sys.stdout.write( "\t\t\tS:" 	+ str( enemy.GetStrength() ) + " A:" + str( enemy.GetAgility() ) + " D:" + str( enemy.GetDefense() ) )
	print()
	print( "----------------------------------------------------------------------" )
	print( "1. Quick Attack\t\t(Try to strike quickly and avoid counter-attack)" )
	print( "2. Standard Attack\t(Attack normally" )
	print( "3. Heavy Attack\t\t(Try to do more damage, but move slower)" )
	print( "**********************************************************************" ) 
	print( "What will you do?" )
# End DisplayBattleMenu

def GetUserChoice( minVal, maxVal ):
	choice = input( ">> " )
	
	while ( int( choice ) < minVal or int( choice ) > maxVal ):
		print( "Invalid choice. Please choose between " + str( minVal ) + " and " + str( maxVal ) )
		choice = input( ">> " )
	
	return choice
# End GetUserChoice

######################################
## --------- MAIN PROGRAM --------- ##
######################################

# Game variables
done = False
equipmentPhase = True

# Create Player and Enemy
player = Player( "PLAYER", 20 )
enemy = Player( "OPPONENT", 20 )

# Create Equipment types
equip1 = Equipment( "Knight's Pack",	8, 4, 3, "This pack is meant to do the most damage.\n It has a two-handed Great Sword, with good armor but poor boots." )
equip2 = Equipment( "Tank's Pack", 	4, 8, 3, "This pack is meant for those who want to absorb damage.\n It has a light sword, heavy armor,\n but movement won't be good because of the weight." )
equip3 = Equipment( "Rogue's Pack", 	4, 3, 8, "This pack is for those who would rather avoid damage than shield against it.\n A dagger and light leather armor protects the rogue,\n but they make up for it in speed." )

equipmentList = []
equipmentList.append( equip1 )
equipmentList.append( equip2 )
equipmentList.append( equip3 )
totalEquipment = 3

currentRound = 0

# Begin game
DisplayTitleScreen()
playerChoice = GetUserChoice( 1, 2 )

if ( playerChoice == 2 ):		# Quit game
	done = True

# Start game loop
while ( done == False ):
	if ( equipmentPhase ):			## --- EQUIPMENT PHASE
		DisplayEquipmentMenu( equipmentList, totalEquipment )
		
		playerChoice = GetUserChoice( 0, 2 )
		player.SetEquipment( equipmentList[ int( playerChoice ) ] )
		
		enemyChoice = randint( 0, 2 )
		enemy.SetEquipment( equipmentList[ int( enemyChoice ) ] )
		
		print()
		print( player.GetName() + " chose equipment: " + player.GetPackName() )
		print( enemy.GetName() + " chose equipment: " + enemy.GetPackName() )
		
		equipmentPhase = False
		
	# End Equipment phase
	else:							## --- BATTLE PHASE
		currentRound += 1
		DisplayBattleMenu( currentRound, player, enemy )
		
		playerChoice = GetUserChoice( 1, 3 )
		player.SetAttack( playerChoice )
		
		enemyChoice = randint( 1, 3 )
		enemy.SetAttack( enemyChoice )
		
		# Enemy Turn
		enemy.DisplayAttackMessage()
		time.sleep( 1 )
		
		player.Attacked( enemy )
		time.sleep( 1 )
		
		# Player Turn
		player.DisplayAttackMessage()
		time.sleep( 1 )
		
		enemy.Attacked( player )
		time.sleep( 1 )
		
		# Check to see if either is dead
		if ( player.GetHP() <= 0 or enemy.GetHP() <= 0 ):
			done = True
		
		print()
	
	# End Battle phase
# while not done

# Once the program exits the while loop, that means a player has died and it's game over.
# Check to see who won
if ( player.GetHP() > 0 ):
	print( enemy.GetName() + " has fallen!" )
	print( "Congratulations, you win!" )
	
else:
	print( player.GetName() + " has fallen!" )
	print( "Sorry, you fail at battling!" )

print( "\n\n GAME OVER \n\n" )




