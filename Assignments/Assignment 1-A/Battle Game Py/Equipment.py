 
# Equipment Class
# A set of equipment in the game has certain Strength, Defense, and Agility stats.
# When a player chooses a set of equipment, it is equipped to the "Player" class
# and is used during the player's battle.

# Variables:
# 	m_name:				Name of the equipment set
# 	m_description:		Description (for in-game, help the player choose)
#	m_strength:			Strength stat (int)
#	m_defense:			Defense stat (int)
# 	m_agility:			Agility stat (int)
class Equipment:
	def __init__( self, name, strength, defense, agility, description ):
		self.Setup( name, strength, defense, agility, description )
	# End Constructor
	
	def Setup( self, name, strength, defense, agility, description ):
		self.m_name = name
		self.m_description = description
		self.m_strength = strength
		self.m_agility = agility
		self.m_defense = defense
	# End Setup
	
	def DisplayInfo( self, packNum ):
		print( "* Pack " + str( packNum ) + ", " + self.m_name )
		print( " STR: " + str( self.m_strength ) + "\t DEF: " + str( self.m_defense ) + "\t AGI: " + str( self.m_agility ) )
		print( " " + self.m_description )
	# End DisplayInfo
	
	def GetName( self ):
		return self.m_name
	# End GetName
	
	def GetStrength( self ):
		return self.m_strength
	# End GetStrength
	
	def GetDefense( self ):
		return self.m_defense
	# End GetDefense
	
	def GetAgility( self ):
		return self.m_agility
	# End GetAgility
	
	
	
	
	
	
	
