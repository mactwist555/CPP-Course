# CS 201 Summer 2013 Assignment 1: Battle Game (Part 1)
# Python version created by Rachel J. Morris

import random
import sys
import time

print( "BATTLE GAME" );

done = False
combatRound = 0

playerHP = 20
playerAtk = random.randint( 5, 8 )
playerDef = random.randint( 5, 8 )
playerAgi = random.randint( 5, 8 )

enemyHP = 20
enemyAtk = random.randint( 5, 7 )
enemyDef = random.randint( 5, 7 )
enemyAgi = random.randint( 5, 7 )

delayLength = 0.5

print()
print( "-------------" )
print( "FIGHTER STATS" )
print( "-------------" )

print()
print( "PLAYER STATS:" )
print( "HP " + str( playerHP ) )
print( "ATK " + str( playerAtk ) )
print( "DEF " + str( playerDef ) )
print( "AGI " + str( playerAgi ) )

print()
print( "ENEMY STATS:" )
print( "HP " + str( enemyHP ) )
print( "ATK " + str( enemyAtk ) )
print( "DEF " + str( enemyDef ) )
print( "AGI " + str( enemyAgi ) )

print()
choice = input( "Ready to begin? (yes/no) " )

while ( choice != "yes" ):
	print( "Well, what are you waiting for? \n" )
	choice = input( "Ready to begin? (yes/no) " )

while ( done == False ):
	combatRound += 1
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
	playerChoice = input( "What will you do? " )
	playerChoice = int( playerChoice )
	
	while ( playerChoice < 1 or playerChoice > 3 ):
		playerChoice = input( "Invalid choice, choose between 1 and 3: " )
		playerChoice = int( playerChoice )
	
	enemyChoice = random.randint( 1, 3 )
	print( "Enemy chooses option " + str( enemyChoice ) )
	print( "-------------------------------------------" )
	
	# Adjust player and enemy stats based on the type of attack they're doing
	adjustedPlayerAtk = playerAtk
	adjustedPlayerAgi = playerAgi
	
	adjustedEnemyAtk = enemyAtk
	adjustedEnemyAgi = enemyAgi
	
	if ( playerChoice == 1 ):
		adjustedPlayerAgi += 2
		adjustedPlayerAtk -= 1
	elif ( playerChoice == 3 ):
		adjustedPlayerAgi -= 1
		adjustedPlayerAtk += 2
	
	if ( enemyChoice == 1 ):
		adjustedEnemyAgi += 2
		adjustedEnemyAtk -= 1
	elif ( enemyChoice == 3 ):
		adjustedEnemyAgi -= 1
		adjustedEnemyAtk += 2
		
	# Begin battle
	print( "PLAYER attacks ENEMY!" )
	time.sleep( delayLength )
	
	randDiff = random.randint( 0, adjustedPlayerAgi )
	time.sleep( delayLength )
	
	if ( randDiff >= 1 ):
		# Calculate damage
		damage = int( adjustedPlayerAtk - enemyDef / 2 )
		print( "PLAYER hits ENEMY for " + str( damage ) + " damage!" )
		enemyHP -= damage
		
	else:
		print( "PLAYER misses!" )
	
	time.sleep( delayLength )
	
	
	print( "ENEMY attacks PLAYER!" )
	time.sleep( delayLength )
	
	randDiff = random.randint( 0, adjustedEnemyAgi )
	time.sleep( delayLength )
	
	if ( randDiff >= 1 ):
		# Calculate damage
		damage = int( adjustedEnemyAtk - playerDef / 2 )
		print( "ENEMY hits PLAYER for " + str( damage ) + " damage!" )
		playerHP -= damage
		
	else:
		print( "ENEMY misses!" )
	
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
	
	







