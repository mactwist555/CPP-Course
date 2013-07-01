# Sample Code for CS 201 - Math
# Rachel J. Morris, 2013
# License: WTFPL 

## FLOATS

tax = 0.0725

print( "\n" )
costOfDVD = input( "How much does a DVD cost? $" )

totalCostOfDVD = float( costOfDVD ) + ( float( costOfDVD ) * tax )

print( "With tax, that is $" + str( totalCostOfDVD ) )

## INTS

print( "\n" )
howMany = input( "How many fibonacci numbers do you want? " )

lastNumber = 1
thisNumber = 1

for i in range( 0, int( howMany ) ):
	print( thisNumber )
	
	oldNum = thisNumber
	thisNumber = thisNumber + lastNumber
	lastNumber = oldNum

## STRINGS

print( "\n" )

firstName = input( "What is your first name? " )
lastName = input( "What is your last name? " )

fullName = lastName + ", " + firstName

print( "Your name is \"" + fullName + "\"." )








