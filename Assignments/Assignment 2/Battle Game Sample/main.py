# CS 201 Summer 2013 Assignment 3: Battle Game (Part 3)
# Python version created by Rachel J. Morris
# License: WTFPL

import random
import sys
import time

from equipment import Equipment
from player import Player

## ----------------- FUNCTIONS ----------------- ##

def DisplayTitleScreen():
	print( "###    ##   ##### #####  #    ####  ##" )
	print( "#  #  #  #    #     #    #    #     ##" )
	print( "###   ####    #     #    #    ####  ##" )
	print( "#  #  #  #    #     #    #    #       " )
	print( "###   #  #    #     #    #### ####  ##" )

	print();

	print( "Welcome to BATTLE!  In this game, you will be fighting in an arena." )
	print( "You have a playerChoice of a set of equipment to use, which have different " )
	print( "effects on your Strength, Defense, and Agility." )

	print();

	print( "Fight your opponent to the death, and for the love of Jim," )
	print( "try not to die." )

	print();
# DisplayTitleScreen

def DisplayRoundMenu( combatRound, player, enemy ):
	print()
	print( "###########################################" )
	print( "-------------------------------------------" )
	print( "ROUND " + str( combatRound ) )
	print( "PLAYER:\t HP " + str( player.GetHP() ) + " ATK " + str( player.GetAttack() ) + " DEF " + str( player.GetDefense() ) + " AGI " + str( player.GetAgility() ) )
	print( "ENEMY:\t HP " + str( enemy.GetHP() ) + " ATK " + str( enemy.GetAttack() ) + " DEF " + str( enemy.GetDefense() ) + " AGI " + str( enemy.GetAgility() ) )
	print( "-------------------------------------------" )
	print( "1. Quick Attack" )
	print( "2. Standard Attack" )
	print( "3. Heavy Attack" )
# DisplayRoundMenu

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

def DisplayEquipmentMenu( equipmentCount, equipmentList ):
	print()
	print( "---------------------" )
	print( "CHOOSE YOUR EQUIPMENT" )
	print( "---------------------" )
	
	for i in range( 0, equipmentCount ):
		equipmentList[i].DisplayInfo( i )
# DisplayEquipmentMenu

def GetUserChoice( minVal, maxVal ):
	playerChoice = input( ">> " )
	playerChoice = int( playerChoice )
	
	while ( playerChoice < minVal or playerChoice > maxVal ):
		print( "Invalid choice, please choose between " + str( minVal ) + " and " + str( maxVal ) )
		playerChoice = input( ">> " )
		playerChoice = int( playerChoice )
		
	return playerChoice
# GetUserChoice

def LoadInEquipment( filename, equipmentList ):
	infile = open( filename, "r" )
	lines = infile.readlines()
	
	name = ""
	attack = defense = agility = 0
	for line in lines:
		if ( "NAME_BEGIN" in line ):
			name = line.replace( "NAME_BEGIN", "" ).replace( "NAME_END", "" )
			name = name.strip()
		
		elif ( "ATTACK" in line ):
			attack = int (line.replace( "ATTACK", "" ).strip() )
		
		elif ( "DEFENSE" in line ):
			defense = int (line.replace( "DEFENSE", "" ).strip() )
		
		elif ( "AGILITY" in line ):
			agility = int (line.replace( "AGILITY", "" ).strip() )
		
		elif ( "EQUIPMENT_END" in line ):
			equipment.append( Equipment( name, attack, defense, agility ) )
	# end for loop
	
	return len( equipment )
# LoadInEquipment

## ----------------- MAIN ----------------- ##

print( "BATTLE GAME" );

done = False
combatRound = 0

player = Player( "PLAYER", 20 )
enemy = Player( "ENEMY", 20 )

delayLength = 0.5

equipment = []
equipmentCount = LoadInEquipment( "equipment.txt", equipment )

equipmentPhase = True
while ( equipmentPhase == True ):
	DisplayEquipmentMenu( equipmentCount, equipment )
	
	print( "Which equipment do you want? " )
	playerEquipment = GetUserChoice( 0, equipmentCount-1 )
	player.SetEquipment( equipment[ playerEquipment ] )
	print( "PLAYER chose " + equipment[ playerEquipment ].GetName() )
	
	# Get enemy equipment
	enemyEquipment = random.randint( 0, equipmentCount-1 )
	enemy.SetEquipment( equipment[ enemyEquipment ] )
	print( "ENEMY chose " + equipment[ enemyEquipment ].GetName() )

	choice = input( "Ready to begin? (yes/no) " )

	if ( choice == "yes" ):
		equipmentPhase = False
	else:
		print( "Well what are you waiting for?" )

while ( done == False ):
	combatRound += 1
	
	DisplayRoundMenu( combatRound, player, enemy )
	print( "What will you do? " )
	playerChoice = GetUserChoice( 1, 3 )
	player.SetAttack( playerChoice )

	enemyChoice = random.randint( 1, 3 )
	enemy.SetAttack( enemyChoice )
	print( "Enemy chooses option " + str( enemyChoice ) )
	print( "-------------------------------------------" )	
		
	## PLAYER TURN
	player.DisplayAttackMessage()
	time.sleep( delayLength )
	enemy.Attacked( player )
	time.sleep( delayLength )
	
	## ENEMY TURN
	enemy.DisplayAttackMessage()
	time.sleep( delayLength )
	player.Attacked( enemy )
	time.sleep( delayLength )
	
	# Check to see if either player is knocked out
	if ( player.GetHP() <= 0 or enemy.GetHP() <= 0 ):
		done = True
# Game main loop

# At this point, either player or enemy has fallen.
DisplayGameOver( player.GetHP(), enemy.GetHP() )
	
	







