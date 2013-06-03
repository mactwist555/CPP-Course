# CS 201 Summer 2013 Assignment 2: Battle Game (Part 2)
# Python version created by Rachel J. Morris
# License: WTFPL

import random
import sys
import time

## ----------------- FUNCTIONS ----------------- ##

def DisplayRoundMenu( combatRound, playerHP, playerAtk, playerDef, playerAgi, enemyHP, enemyAtk, enemyDef, enemyAgi ):
	print()
	print( "###########################################" )
	print( "-------------------------------------------" )
	print( "ROUND " + str( combatRound ) )
	print( "PLAYER:\t HP " + str( playerHP ) + " ATK " + str( playerAtk ) + " DEF " + str( playerDef ) + " AGI " + str( playerAgi ) )
	print( "ENEMY:\t HP " + str( enemyHP ) + " ATK " + str( enemyAtk ) + " DEF " + str( enemyDef ) + " AGI " + str( enemyAgi ) )
	print( "-------------------------------------------" )
	print( "1. Quick Attack" )
	print( "2. Standard Attack" )
	print( "3. Heavy Attack" )
# DisplayRoundMenu

def GetAdjustedAtk( atk, choice ):
	if ( choice == 1 ):
		atk -= 1
	elif ( choice == 3 ):
		atk += 2
	return atk
# GetAdjustedAtk

def GetAdjustedAgi( agi, choice ):
	if ( choice == 1 ):
		agi += 2
	elif ( choice == 3 ):
		agi -= 1
	return agi
# GetAdjustedAgi

def Attack( attackerAtk, attackerAgi, defenderDef, attackerName, defenderName ):
	print( attackerName + " attacks " + defenderName + "!" )
	
	randDiff = random.randint( 0, attackerAgi )
	damage = 0
	
	if ( randDiff >= 1 ):
		# Figure out damage
		damage = int( attackerAtk - defenderDef / 2 )
		print( attackerName + " hits " + defenderName + " for " + str( damage ) + " damage!" )
	
	else:
		print( attackerName + " misses!" )
		
	return damage
# Attack

def DisplayGameOver( playerHP, enemyHP ):
	print()
	print( "    #####################################   " )
	print( " ####                                   ####" )
	print( "#           G A M E     O V E R             #" )
	print( "# ######################################### #" )
	print( "##                                         ##" )
	print()

	if ( playerHP <= 0 ):
		print( "Too bad, you lose!" )
	elif ( enemyHP <= 0 ):
		print( "Congratulations, you won!" )
# DisplayGameOver

def DisplayEquipmentMenu( equipmentCount, equipmentNames, equipmentAtk, equipmentDef, equipmentAgi ):
	print()
	print( "---------------------" )
	print( "CHOOSE YOUR EQUIPMENT" )
	print( "---------------------" )
	
	for i in range( 0, equipmentCount ):
		print( str( i ) + ". " + equipmentNames[i] + ":" )
		print( "\t ATK " + str( equipmentAtk[i] ) + " DEF " + str( equipmentDef[i] ) + " AGI " + str( equipmentAgi[i] ) )
		print()
		
# DisplayEquipmentMenu

## ----------------- MAIN ----------------- ##

print( "BATTLE GAME" );

done = False
combatRound = 0

playerHP = 20
enemyHP = 20

delayLength = 0.5

equipmentAtk = [ 8, 4, 4 ]
equipmentDef = [ 4, 8, 3 ]
equipmentAgi = [ 3, 3, 8 ]
equipmentNames = [ "Knight's Pack", "Tank's Pack", "Rogue's Pack" ]
equipmentCount = 3

equipmentPhase = True
while ( equipmentPhase == True ):

	DisplayEquipmentMenu( equipmentCount, equipmentNames, equipmentAtk, equipmentDef, equipmentAgi )
	playerEquipment = input( "Which equipment do you want? " )
	playerEquipment = int( playerEquipment )
	
	while ( playerEquipment < 0 or playerEquipment > 2 ):
		playerEquipment = input( "Invalid choice. Choose 0, 1, or 2: " )
		playerEquipment = int( playerEquipment )
		
	# Set player stats
	playerAtk = equipmentAtk[ playerEquipment ]
	playerDef = equipmentDef[ playerEquipment ]
	playerAgi = equipmentAgi[ playerEquipment ]
	print()
	print( "PLAYER chose " + equipmentNames[ playerEquipment ] )
	
	# Get enemy equipment
	enemyEquipment = random.randint( 0, 2 )
	enemyAtk = equipmentAtk[ enemyEquipment ]
	enemyDef = equipmentDef[ enemyEquipment ]
	enemyAgi = equipmentAgi[ enemyEquipment ]
	print( "ENEMY chose " + equipmentNames[ enemyEquipment ] )

	choice = input( "Ready to begin? (yes/no) " )

	if ( choice == "yes" ):
		equipmentPhase = False
	else:
		print( "Well what are you waiting for?" )

while ( done == False ):
	combatRound += 1
	
	DisplayRoundMenu( combatRound, playerHP, playerAtk, playerDef, playerAgi, enemyHP, enemyAtk, enemyDef, enemyAgi )
	playerChoice = input( "What will you do? " )
	playerChoice = int( playerChoice )
	
	while ( playerChoice < 1 or playerChoice > 3 ):
		playerChoice = input( "Invalid choice, choose between 1 and 3: " )
		playerChoice = int( playerChoice )
	
	enemyChoice = random.randint( 1, 3 )
	print( "Enemy chooses option " + str( enemyChoice ) )
	print( "-------------------------------------------" )
	
	# Adjust player and enemy stats based on the type of attack they're doing
	adjustedPlayerAtk = GetAdjustedAtk( playerAtk, playerChoice )
	adjustedPlayerAgi = GetAdjustedAgi( playerAgi, playerChoice )
	adjustedEnemyAtk = GetAdjustedAtk( enemyAtk, enemyChoice )
	adjustedEnemyAgi = GetAdjustedAgi( enemyAgi, enemyChoice )
	
		
	# Begin battle
	damage = Attack( adjustedPlayerAtk, adjustedPlayerAgi, enemyDef, "PLAYER", "ENEMY" )
	enemyHP -= damage
	
	time.sleep( delayLength )
	
	damage = Attack( adjustedEnemyAtk, adjustedEnemyAgi, playerDef, "ENEMY", "PLAYER" )
	playerHP -= damage
	
	time.sleep( delayLength )
	
	# Check to see if either player is knocked out
	if ( playerHP <= 0 ):
		print( "PLAYER has fallen!" )
		done = True
	
	elif ( enemyHP <= 0 ):
		print( "ENEMY has fallen!" )
		done = True

# Game main loop

# At this point, either player or enemy has fallen.
DisplayGameOver( playerHP, enemyHP )
	
	







