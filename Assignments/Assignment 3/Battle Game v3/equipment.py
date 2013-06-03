import sys

# Member Variables:
# * m_name 		(string)
# * m_attack 	(int)
# * m_defense 	(int)
# * m_agility 	(int)
class Equipment:
	def __init__( self, name, attack, defense, agility ):
		# In C++ make this a constructor.
		self.Setup( name, attack, defense, agility )
	# __init__
	
	def Setup( self, name, attack, defense, agility ):
		self.m_name = name
		self.m_attack = attack
		self.m_defense = defense
		self.m_agility = agility
	# Setup
	
	def DisplayInfo( self, packNumber ):
		# sys.stdout.write Prints, but doesn't add a new line at the end.
		sys.stdout.write( "* Pack " + str( packNumber ) + ": " + self.m_name + "\t" )
		sys.stdout.write( " ATK: " + str( self.m_attack ) )
		sys.stdout.write( " DEF: " + str( self.m_defense ) )
		sys.stdout.write( " AGI: " + str( self.m_agility ) )
		print()
	# DisplayInfo
	
	def GetName( self ):
		return self.m_name
	# GetName
	
	def GetAttack( self ):
		return self.m_attack		
	# GetAttack
	
	def GetDefense( self ):
		return self.m_defense
	# GetDefense
	
	def GetAgility( self ):
		return self.m_agility
	# GetAgility
	
# Equipment
