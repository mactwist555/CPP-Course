-- View 
-- http://www.moosader.com/learn/introduction-to-mobile-game-development/
-- for more - audio, text, etc.

local SCREEN_WIDTH = 320
local SCREEN_HEIGHT = 480

local texture_bunny 	= Texture.new( "content/bunny.png" )
local texture_coin 		= Texture.new( "content/coin.png" )
local texture_grass 	= Texture.new( "content/grass.png" )

-- Function definitions

local targetX, targetY = 0, 0
local speed = 1
local score = 0

function MoveCoin()
	coin:setPosition( math.random( 32, SCREEN_WIDTH - 32 ), math.random( 32, SCREEN_HEIGHT - 32 ) )
end

function HandleClick( event )
	targetX = event.x
	targetY = event.y
end

function Update( event )
	-- Move player
	local x, y = player:getPosition()
	local cx, cy = coin:getPosition()
	
	if ( targetX < x ) then			x = x - speed
	elseif ( targetX > x ) then		x = x + speed
	end

	if ( targetY < y ) then			y = y - speed
	elseif ( targetY > y ) then		y = y + speed
	end
	
	player:setPosition( x, y )
	
	-- Check collision
	if ( Distance( x, y, cx, cy ) <= 30 ) then
		MoveCoin()
		score = score + 1
		print( "Score: ", score )
	end
end

function Distance( x1, y1, x2, y2 )
	return math.sqrt( ( x1 - x2 ) * ( x1 - x2 ) + ( y1 - y2 ) * ( y1 - y2 ) )
end

-- Setup

background = {}
-- Setup grass tiles
for y = 0, SCREEN_HEIGHT / 32 do
	for x = 0, SCREEN_WIDTH / 32 do
		local grass = Bitmap.new( texture_grass )
		grass:setPosition( x * 32, y * 32 )
		stage:addChild( grass )
		table.insert( background, grass )
	end
end

-- Setup and draw player
player = Bitmap.new( texture_bunny )
player:setAnchorPoint( 0.5, 0.5 )
player:setPosition( SCREEN_WIDTH/2, SCREEN_HEIGHT/2 )
stage:addChild( player )
targetX, targetY = player:getPosition()

-- Setup and draw collectable
coin = Bitmap.new( texture_coin )
coin:setAnchorPoint( 0.5, 0.5 )
MoveCoin()
stage:addChild( coin )

stage:addEventListener( Event.MOUSE_DOWN, HandleClick, self )
stage:addEventListener( Event.ENTER_FRAME, Update, self )





