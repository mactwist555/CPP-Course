class Fraction:
	def __init__( self, n, d ):
		self.num = n
		self.denom = d
	# __init__
	
	def __mul__( self, fraction2 ):
		product = Fraction( 1, 1 )
		product.num = self.num * fraction2.num
		product.denom = self.denom * fraction2.denom
		return product
	# __mul__

# Main
frac1 = Fraction( 1, 2 )
frac2 = Fraction( 2, 4 )

sumFrac = frac1 * frac2

print( str( frac1.num ) + "/" + str( frac1.denom ) )
print( str( frac2.num ) + "/" + str( frac2.denom ) )
print( str( sumFrac.num ) + "/" + str( sumFrac.denom ) )

