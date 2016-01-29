
void SearchAndAnalyze( string sentence, string searchTerm, int& wordCount, int& letterCount, int& searchHitCount )
{
    wordCount = 0;
    letterCount = 0;
    searchHitCount = 0;
    for ( int i = 0; i < sentence.size(); i++ )
    {
        if ( sentence[i] != ' ' )
        {
            letterCount++;
            if ( i == 0 )
            {
                wordCount++;
            }
        }
        else
        {
            wordCount++;
        }
    }
    
    int foundPos = sentence.find( searchTerm );
    while ( foundPos != string::npos )
    {
        sentence = sentence.replace( foundPos, searchTerm.size(), "" );
        searchHitCount++;
        foundPos = sentence.find( searchTerm );
    }
}


float PriceAfterTax( float price, float tax )
{
    price += price * tax;
    return price;
}


void MainMenu()
{
    cout << endl;
    cout << "1. Calculate Perimeter" << endl;
    cout << "2. Calculate Area" << endl;
    cout << "3. Exit" << endl;
}

void DrawPerimeter( int width, int height )
{
    for ( int y = 0; y < height; y++ )
    {
        for ( int x = 0; x < width; x++ )
        {
            if ( x == 0 || x == width - 1 || y == 0 || y == height - 1 )
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

void DrawArea( int width, int height )
{
    for ( int y = 0; y < height; y++ )
    {
        for ( int x = 0; x < width; x++ )
        {
            cout << "*";
        }
        cout << "\n";
    }
}

float CalculatePerimeter( int width, int height )
{
    return width + width + height + height;
}

float CalculateArea( int width, int height )
{
    return width * height;
}

void Exercise2()
{
    bool done = false;
    while ( !done )
    {
        MainMenu();
        
        int choice;
        cout << "Choice: ";
        cin >> choice;
        
        switch( choice )
        {
            case 1:
            {
                int w, h;
                cout << "Width and Height: ";
                cin >> w >> h;
                int perimeter = CalculatePerimeter( w, h );
                DrawPerimeter( w, h );
                cout << "Perimeter: " << perimeter << endl;
            }
            break;
            
            case 2:
            {
                int w, h;
                cout << "Width and Height: ";
                cin >> w >> h;
                int area = CalculateArea( w, h );
                DrawArea( w, h );
                cout << "Area: " << area << endl;
            }
            break;
            
            case 3:
                done = true;
            break;
        }
    }
}

void Exercise3()
{
    string sentence, searchTerm;

    cout << "Enter a sentence: ";
    cin.ignore();
    getline( cin, sentence );

    cout << "Enter a search term: ";
    cin >> searchTerm;

    int wordCount, letterCount, searchHitCount;
    SearchAndAnalyze( sentence, searchTerm, wordCount, letterCount, searchHitCount );

    cout << "Words: " << wordCount << endl;
    cout << "Letters: " << letterCount << endl;
    cout << "Search Hits: " << searchHitCount << endl;
}

