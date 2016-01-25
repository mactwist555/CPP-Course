 
# -- LIST
studentNames = []
studentNames.append( "Kourtney" )
studentNames.append( "Frank" )
studentNames.append( "Patel" )
studentNames.append( "Hana" )

i = 3
studentNames.pop( i )

for student in studentNames:
	print( student )

print()

# -- DICTIONARY
gradeLookup = {}
gradeLookup["Elizabeth"] = 100
gradeLookup["Anne"] = 75
gradeLookup["Aki"] = 86

for student, grade in gradeLookup.items():
	print( "Name: " + student + "\t Grade: " + str( grade ) )
