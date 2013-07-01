# Python vs. C++ Example 6
# Rachel J. Morris, 2013 - RachelJMorris@gmail.com, Moosader.com, github.com/Moosader
# MIT License

from random import randint
from Pet import Pet

		
print( "VIRTUAL PET" )
name = input( "What is your pet's name? " ) 

pet = Pet()
pet.SetName( name )

done = False

while ( done == False ):
	print( "***********************************************" )
	
	isPetSleeping = pet.Update()
	
	if ( isPetSleeping == False ):
		print( "1. View " + pet.GetName() + "'s Stats" )
		print( "2. Feed " + pet.GetName() )
		print( "3. Play with " + pet.GetName() )
		print( "4. Send " + pet.GetName() + " to bed" )
		print( "5. Quit" )
		choice = int ( input( "What do you want to do? " ) )
		
		while ( choice < 1 or choice > 5 ):
			choice = int ( input( "Invalid choice. What do you want to do? " ) )

		if ( choice == 1 ):			# Stats
			pet.PrintInfo()
		# End Stats
		
		elif ( choice == 2 ):		# Feed
			print( "\n" )
			print( "------------------------------" )
			print( "1. Bacon" )
			print( "2. Carrots" )
			print( "3. Candy" )
			choice = int ( input( "What do you want to feed " + pet.GetName() + "? " ) )
			
			while ( choice < 1 or choice > 3 ):
				choice = int( input( "Invalid choice. What do you want to feed " + pet.GetName() + "?" ) )
			
			if ( choice == 1 ):
				pet.Feed( "bacon" )
				
			elif ( choice == 2 ):
				pet.Feed( "cheese" )
				
			elif ( choice == 3 ):
				pet.Feed( "candy" )
		# End Feed
		
		elif ( choice == 3 ):		# Play
			pet.Play()
		# End Play
		
		elif ( choice == 4 ):		# Sleep
			pet.Sleep()
		# End Sleep
		
		elif ( choice == 5 ):		# Quit
			done = True
		# End Quit
		
	else:
		print( "Cannot do anything this turn" )

# End main game loop

print( "Goodbye!" )

