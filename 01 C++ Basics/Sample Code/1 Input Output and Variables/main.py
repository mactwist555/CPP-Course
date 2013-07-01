# Python vs. C++ Example 1
# Rachel J. Morris, 2013 - RachelJMorris@gmail.com, Moosader.com, github.com/Moosader
# MIT License

# -- GREET USER
print( "Welcome to the program!" )
print()

# -- GET USER INPUT
name = input( "What is your name? " )
age = input( "What is your age? " )
price = input( "How much does a soda cost? (Dollars and cents) $" )

# -- RESULTS
print( "\n\n" )

name = "Captain " + name
print( "Your name is now " + name + "\n" )

age = int(age) + 1
print( "Next year you will be " + str( age ) + "\n" )

price = float(price)
price = price + ( price * 0.725 ) # Adding tax
print( "With a tax of 7.25%, a soda is $" + str( price ) )

print( "\n\nGoodbye!" )
