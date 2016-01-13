# Python vs. C++ Example 3
# Rachel J. Morris, 2013 - RachelJMorris@gmail.com, Moosader.com, github.com/Moosader
# MIT License
 
import random

random.seed( 3 )

playerDead = False
monsterDead = False
playerIsBlocking = False

playerHP = 100
monsterHP = 100

# GAME LOOP - Game repeats until the Player or Monster die
while ( playerDead == False and monsterDead == False ):
	# Reset any commands from last time
	playerIsBlocking = False
	
	# Display menu
	print( "\n" )
	print( "------------------------" )
	print( "Your HP: \t" + str( playerHP ) )
	print( "Monster HP: \t" + str( monsterHP ) )
	print( "------------------------" )
	print( "A. Attack" )
	print( "B. Block" )
	print( "H. Heal" )
	
	# Ask the player for their choice
	choice = input( "What will you do? " ) 
	
	#ATTACK
	if ( choice == "a" or choice == "A" ):
		# Randomly generate attack damage
		playerDamage = random.randint( 0, 11 )
		print()
		print( "You swing your sword!" )
		print( "You hit the monster for " + str( playerDamage ) + " damage!" )
		
		# Remove damage from the monster's HP, check if it's dead
		monsterHP -= playerDamage
		if ( monsterHP <= 0 ):
			print( "You have slain the monster!" )
			monsterDead = True
		
	# BLOCK
	elif ( choice == "b" or choice == "B" ):
		print( "You block!" )
		playerIsBlocking = True
		
	# HEAL
	elif ( choice == "h" or choice == "H" ):
		print( "You use a potion!" )
		healAmount = random.randint( 0, 5 )
		print( "You heal " + str( healAmount ) + " HP!" )
		
		playerHP += healAmount
		if ( playerHP > 100 ):
			playerHP = 100
	
	# Monster's turn (if it's still alive)
	if ( monsterDead == False ):
		# Monster attacks! Randomly generate damage
		monsterDamage = random.randint( 0, 10 )
		
		if ( playerIsBlocking ):
			monsterDamage = monsterDamage / 2
		
		print()
		print( "The monster claws at you!" )
		print( "The monster does " + str( monsterDamage ) + " damage to you!" )
		
		# Remove damage from player's HP, check if you're dead
		playerHP -= monsterDamage
		if ( playerHP <= 0 ):
			print( "You have fallen!" )
			playerDead = True	
# Main game loop

if ( playerDead ):
	print( "\n\nMan, who hired you to hunt monsters? You suck." )

elif ( monsterDead ):
	print( "\n\nYou killed the monster and are awarded with fifty mansions!" )



