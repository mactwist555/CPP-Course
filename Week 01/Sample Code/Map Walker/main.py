# Sample Code for CS 201 - Map Walker
# Rachel J. Morris, 2013
# License: WTFPL

# Create map locations
#      N
#    0 1 2
# E  3 4 5  W
#    6 7 8
#      S
lstLocations = ["DESERT\nYou are standing in a desert. There are dry bones on the ground!",
	"LAKE\nYou are wading through a shallow lake. It is kind of cold here.",
	"FOREST\nYou are in the forest. There are many trees here.",
	"MARS\nYou have wandered to Mars. You would be dead if you weren't a Waterbear!",
	"GROCERY STORE\nYou are in line at a grocery store. The person in front of you is apparently buying dinner for an entire orphanage, because it's taking too damn long!",
	"THRONE ROOM\nYou are in a castle in front of the king's throne. He looks kind of pissed for some reason.",
	"CABIN\nYou are outside of a cabin. You need to think of a way to get in, but HOW?!",
	"COFFEE SHOP\nYou are in a coffee shop. Unfortunately, it is not Christmas so they have no Peppermint Mocha Lattes.",
	"BATHTUB\nYou are taking a bath. Good job!"]

currentMap = 0
mapWidth = 3
mapHeight = 3
done = False

while ( done == False ):
	
	# Print current location info
	print( "\n\n" + lstLocations[ currentMap ] )
	choice = input( "What direction would you like to go? (North/South/East/West or Exit): " )
	
	if ( choice == "North" or choice == "north" ):
		if ( currentMap - mapWidth < 0 ):
			print( "You cannot move North!" )
		else:
			currentMap = currentMap - mapWidth
			
	elif ( choice == "South" or choice == "south" ):
		if ( currentMap + mapWidth >= mapWidth*mapHeight ):
			print( "You cannot move South!" )
		else:
			currentMap = currentMap + mapWidth
		
	elif ( choice == "East" or choice == "east" ):
		if ( currentMap + 1 >= mapWidth*mapHeight or
				currentMap % mapWidth == 2 ):
			print( "You cannot move East!" )
		else:
			currentMap = currentMap + 1
		
	elif ( choice == "West" or choice == "west" ):	
		if ( currentMap - 1 < 0 or 
				currentMap % mapWidth == 0 ):
			print( "You cannot move West!" )
		else:
			currentMap = currentMap - 1
	
	elif ( choice == "Exit" or choice == "exit" ):
		done = True
		print( "OK :(" )
		
	else:
		print( "Invalid command" )
		
# while ( quit == False )



