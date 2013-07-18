#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	map< string, vector< float > > playerAccounts;

	vector< float > simpleFloat;
	simpleFloat.push_back( 2.99 );
	simpleFloat.push_back( 3.99 );


	playerAccounts[ "Dave" ].push_back( 109.93 );
	playerAccounts[ "Dave" ].push_back( 2932.32 );
	playerAccounts[ "Dave" ].push_back( 53.43 );

	playerAccounts[ "Merryl" ].push_back( 29.34 );
	playerAccounts[ "Merryl" ].push_back( 1001.34 );

	for ( map< string, vector< float > >::iterator player = playerAccounts.begin();
			player != playerAccounts.end();
			player++ )
	{
		cout << "\n\n\t PLAYER: " << player->first << endl;

		for ( vector< float >::iterator account = player->second.begin();
				account != player->second.end();
				account++ )
		{
			cout << "* $" << *account << endl;
		}
	}

	return 0;
}
