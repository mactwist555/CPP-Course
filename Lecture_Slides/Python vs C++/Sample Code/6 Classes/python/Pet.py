class Pet:
	def __init__( self ):
		self.m_hunger = 0
		self.m_energy = 0
		self.m_happiness = 50
		self.m_name = ""
		self.m_sleepTurns = 0
	# __init__
	
	def SetName( self, name ):
		self.m_name = name
	# SetName
	
	def GetName( self ):
		return self.m_name
	# GetName
	
	def Update( self ):
		if ( self.m_sleepTurns > 0 ):
			print( self.m_name + " is sleeping... " + str( self.m_sleepTurns ) )
			self.m_sleepTurns -= 1
			self.m_energy += 25
			self.Balance()
			
			if ( self.m_energy == 100 ):
				self.m_sleepTurns = 0
				print( self.m_name + " wakes up!" )
			return True # Lets program know it cannot do anything this turn
		
		# Not sleeping
		self.Balance()
		return False
	# Update
	
	def Balance( self ):
		if ( self.m_hunger > 100 ):
			self.m_hunger = 100
		elif ( self.m_hunger < 0 ):
			self.m_hunger = 0
			
		if ( self.m_energy > 100 ):
			self.m_energy = 100
		elif ( self.m_energy < 0 ):
			self.m_energy = 0
			
		if ( self.m_happiness > 100 ):
			self.m_happiness = 100
		elif ( self.m_happiness < 0 ):
			self.m_happiness = 0
	# Balance
	
	def Feed( self, foodType ):
		if ( foodType == "bacon" ):
			self.m_hunger -= 10
			self.m_happiness += 5
			self.m_energy += 5
		elif ( foodType == "carrots" ):
			self.m_hunger -= 8
			self.m_happiness -= 2
		elif ( foodType == "candy" ):
			self.m_hunger -= 5
			self.m_happiness += 2
	# Feed
	
	def Play( self ):
		self.m_happiness += 10
		self.m_energy -= 5
	# Play
	
	def Sleep( self ):
		self.m_sleepTurns = 3
	# Sleep
		
	def PrintInfo( self ):
		print( "------------------------------" )
		print( self.m_name + "'s Mood: " )
		
		if ( self.m_happiness <= 25 ):
			print( "\t Miserable (" + str( self.m_happiness ) + "/100)" )
		elif ( self.m_happiness <= 50 ):
			print( "\t Adequate (" + str( self.m_happiness ) + "/100)" )
		elif ( self.m_happiness <= 75 ):
			print( "\t Content (" + str( self.m_happiness ) + "/100)" )
		else:
			print( "\t Joyous (" + str( self.m_happiness ) + "/100)" )

		print( self.m_name + "'s Hunger: " )
	
		if ( self.m_hunger <= 25 ):
			print( "\t Full (" + str( self.m_hunger ) + "/100)" )
		elif ( self.m_hunger <= 50 ):
			print( "\t Content (" + str( self.m_hunger ) + "/100)" )
		elif ( self.m_hunger <= 75 ):
			print( "\t Peckish (" + str( self.m_hunger ) + "/100)" )
		else:
			print( "\t Starving (" + str( self.m_hunger ) + "/100)" )

		print( self.m_name + "'s Energy: " )
	
		if ( self.m_energy <= 25 ):
			print( "\t Exhausted (" + str( self.m_energy ) + "/100)" )
		elif ( self.m_energy <= 50 ):
			print( "\t Drowsy (" + str( self.m_energy ) + "/100)" )
		elif ( self.m_energy <= 75 ):
			print( "\t Awake (" + str( self.m_energy ) + "/100)" )
		else:
			print( "\t Energetic" )
		
