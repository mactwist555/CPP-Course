 
from Equipment import Equipment
from random import randint

# Player class
# Handles storing player data as well as calculating damage/agility
# during the battles. Displays messages also.
# PThe user and the NPC opponent are both "Player" types
#
# Variables:
#	m_name			The player's name (Player/Enemy)
#	m_equipped:		The equipped Equipment
#	m_strength:		The player's strength - Affected by equipment and type of attack they're performing
# 	m_defense:		The player's defense
#	m_agility:		The player's agility - Affected by equipment and type of attack they're performing
# 	m_hp:			The player's Hit Points
# 	m_attackType	This round attack type
class Player:
	def __init__( self, name, startingHP ):
		self.m_name = name
		self.m_hp = startingHP
	# End Constructor
	
	def SetEquipment( self, equip ):
		self.m_equipped = equip
		self.m_strength = equip.GetStrength()
		self.m_defense = equip.GetDefense()
		self.m_agility = equip.GetAgility()
	# End SetEquipment
	
	def SetAttack( self, attackType ):
		self.m_attackType = attackType
		
		# Reset stats to equipment values before adjusting them.
		self.m_strength = self.m_equipped.GetStrength()
		self.m_defense = self.m_equipped.GetDefense()
		self.m_agility = self.m_equipped.GetAgility()
		
		# Adjust stats based on attack (Quick = weaker but faster, Heavy = slower by stronger)
		if ( attackType == 1 ): 		# Quick Attack
			self.m_strength -= 1
			self.m_agility += 1
			
		elif ( attackType == 3 ):		# Heavy Attack
			self.m_strength += 1
			self.m_agility -= 1
			
		# Nothing happens for standard attack, just use default values.
	# End SetAttack
	
	def GetName( self ):
		return self.m_name
	# End GetName
	
	def GetPackName( self ):
		return self.m_equipped.GetName()
	# End GetPackName
	
	def GetStrength( self ):
		return self.m_strength
	# End GetStrength
	
	def GetDefense( self ):
		return self.m_defense
	# End GetDefense
	
	def GetAgility( self ):
		return self.m_agility
	# End GetAgility
	
	def GetHP( self ):
		return self.m_hp
	# End GetHP
	
	def Attacked( self, attacker ):
		if ( self.DetermineWhetherHit( attacker ) ):
			# Is hit
			damage = self.GetDamage( attacker )
			print( attacker.GetName() + " hits " + self.GetName() + " for " + str(damage) + " damage!" )
			
			# Decrease HP
			self.m_hp -= damage
		else:
			# Not hit
			print( attacker.GetName() + " misses!" )
	# End Attacked
	
	def DisplayAttackMessage( self ):
		attackMessage = self.GetName() + " (" + self.m_equipped.GetName() + ") does a "
		
		if ( self.m_attackType == 1 ):		# Quick attack
			attackMessage += "quick attack!"
			
		elif ( self.m_attackType == 2 ):		# Standard attack
			attackMessage += "standard attack!" 
			
		else:							# Heavy attack
			attackMessage += "heavy attack!"
		
		print( attackMessage )
	# End DisplayAttackMessage
	
	def DetermineWhetherHit( self, attacker ):
		agiCheck1 = randint( 0, self.GetAgility() )
		agiCheck2 = randint( 0, attacker.GetAgility() )
		
		# ( agiCheck2 <= agiCheck1 ) returns either True or False
		return ( agiCheck2 <= agiCheck1 )
	# End DetermineWhetherHit
	
	def GetDamage( self, attacker ):
		adjustedDamage = attacker.GetStrength() - ( self.GetDefense() / 2 )
		return int( adjustedDamage )
	# End GetDamage
	
