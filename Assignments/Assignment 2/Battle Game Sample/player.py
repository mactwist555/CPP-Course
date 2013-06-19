
import sys
import random

# Member Variables:
# * m_name 					(string)
# * m_equipped 				(Equipment)
# * m_adjustedAttack 		(int)
# * m_adjustedAgility 		(int)
# * m_adjustedDefense 		(int)
# * m_hp 					(int)
# * m_attackTypeThisRound 	(int)

class Player:
	def __init__( self, name, startingHP ):
		# In C++, make this a constructor.
		self.m_name = name
		self.m_hp = startingHP
		self.m_adjustedAttack = -1
		self.m_adjustedDefense = -1
		self.m_adjustedAgility = -1
	# __init__
	
	def SetEquipment( self, equipment ):
		self.m_equipped = equipment;
		self.m_adjustedAttack = self.m_equipped.GetAttack()
		self.m_adjustedDefense = self.m_equipped.GetDefense()
		self.m_adjustedAgility = self.m_equipped.GetAgility()
	# SetEquipment
	
	def SetAttack( self, attackType ):
		self.m_attackTypeThisRound = attackType
		
		# Reset stats to equipment values
		self.m_adjustedAttack = self.m_equipped.GetAttack()
		self.m_adjustedDefense = self.m_equipped.GetDefense()
		self.m_adjustedAgility = self.m_equipped.GetAgility()
		
		# Adjust stats this round based on type of attack
		if ( self.m_attackTypeThisRound == 1 ):		# Quick Attack
			self.m_adjustedAttack -= 1
			self.m_adjustedAgility += 2
			
		elif ( self.m_attackTypeThisRound == 3 ):	# Heavy Attack
			self.m_adjustedAttack += 2
			self.m_adjustedAgility -= 1
	# SetAttack
	
	def GetName( self ):
		return self.m_name
	# GetName
	
	def GetPackName( self ):
		return self.m_equipped.GetName()
	# GetPackName
	
	def GetAttack( self ):
		return self.m_adjustedAttack
	# GetAttack
	
	def GetDefense( self ):
		return self.m_adjustedDefense
	# GetDefense
	
	def GetAgility( self ):
		return self.m_adjustedAgility
	# GetAgility
	
	def GetHP( self ):
		return self.m_hp
	# GetHPs
	
	def DisplayAttackMessage( self ):
		sys.stdout.write( self.GetName() + " (" + self.m_equipped.GetName() + ") does a " );
		
		if ( self.m_attackTypeThisRound == 1 ):
			sys.stdout.write( "quick attack!" ) 
		elif ( self.m_attackTypeThisRound == 2 ):
			sys.stdout.write( "standard attack!" )
		elif ( self.m_attackTypeThisRound == 3 ):
			sys.stdout.write( "heavy attack!" )
		
		print() # newline
	# DisplayAttackMessage
	
	def Attacked( self, attacker ):	
		if ( self.GetsHit() ):
			damage = self.GetDamage( attacker )
			if ( damage < 0 ):
				damage = 0
			
			print( attacker.GetName() + " hits " + self.GetName() + " for " + str( damage ) + " damage!" )
			
			self.m_hp -= damage
			
			if ( self.m_hp <= 0 ):
				print( self.GetName() + " falls!" )
			
		else:
			print( attacker.GetName() + " misses!" )
			
	# Attacked
	
	def GetsHit( self ):
		agiCheck = random.randint( 0, self.GetAgility() )
		return ( agiCheck >= 1 )
	# GetsHit
	
	def GetDamage( self, attacker ):
		adjustedDamage = int( attacker.GetAttack() - self.GetDefense() / 2 )
		return adjustedDamage
	# GetDamage
	
# Player
