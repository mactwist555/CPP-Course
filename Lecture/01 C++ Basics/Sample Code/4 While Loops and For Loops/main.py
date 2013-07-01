# Python vs. C++ Example 4
# Rachel J. Morris, 2013 - RachelJMorris@gmail.com, Moosader.com, github.com/Moosader
# MIT License

# Generally, these shouldn't be stored in separate lists; we would create
# a class to store name & age, but we will do this in a later example.

lstStudentNames = []
lstStudentAges = []
doneWithProgram = False

while ( not doneWithProgram ):
	print( "\n" )
	print( "What would you like to do?" )
	print( "1. Add another student" )
	print( "2. End" )
	
	choice = input( "? " )
	
	while ( int(choice) != 1 and int(choice) != 2 ):
		choice = input( "Invalid choice, try again: " )
		
	if ( int(choice) == 2 ):
		doneWithProgram = True
	else:
		print( "Add new student:" )
		name = input( "Name? " )
		age = input( "Age? " )
		
		while ( int(age) < 0 or int(age) > 120 ):
			print( "Invalid age, must be between 0 and 120 years old" )
			age = input( "Age?" )
		
		# Add new student to list
		lstStudentNames.append( name )
		lstStudentAges.append( age )
# while ( not doneWithProgram ):

# Program over - Display students
print( "\n\nYour students:" )
for i in range( 0, len( lstStudentNames ) ):
	print( lstStudentNames[i] + "\t\tAge: " + lstStudentAges[i] )
