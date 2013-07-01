# Sample Code for CS 201 - Bank
# Rachel J. Morris, 2013
# License: WTFPL

done = False

balance = 0
transactions = 0

while ( done == False ):
	print( "\n\n" )
	print( "-------------------------------" )
	print( "Your current balance is $" + str( balance ) )
	print( "Your have made " + str( transactions ) + " transactions" )
	print()
	print( "1. Deposit money" )
	print( "2. Withdraw money" )
	print( "3. Leave" )
	
	choice = input( "What do you want to do? " )
	
	if ( int( choice ) == 1 ):
		amount = input( "How much do you want to deposit? "  )
		balance += float( amount )
		transactions += 1
		
	elif ( int( choice ) == 2 ):
		amount = input( "How much do you want to withdraw? " )
		if ( balance - float( amount ) < 0 ):
			print( "You cannot withdraw that amount; you would end up with less than $0!" )
		else:
			balance -= float( amount );
			print( "$" + amount + " withdrawn. New balance is " + str( balance ) )
			transactions += 1
		
	elif ( int( choice ) == 3 ):
		done = True
		print( "Thank you for using ATM" )
	
	else:
		print( "Invalid option, try again." )
