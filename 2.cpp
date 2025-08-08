#include <Windows.h>
#include <MMsystem.h>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <chrono>
#include <cwchar>      
#include <cmath>       
#pragma comment(lib, "winmm.lib")
#include <tchar.h>
using namespace std;

//Declarations
int nScreenWidth = 120;         // Console Screen Size X (columns)
int nScreenHeight = 40;         // Console Screen Size Y (rows)
int nMapWidth = 16;             // World Dimensions
int nMapHeight = 16;

float fPlayerX = 14.7f;         // Player Start Position
float fPlayerY = 5.09f;
float fPlayerA = 0.0f;          // Player Start Rotation
float fFOV = 3.14159f / 4.0f;   // Field of View
float fDepth = 16.0f;           // Maximum rendering distance
float fSpeed = 5.0f;            // Walking Speed

// Enemy's Position and Speed
float fEnemyX = 4.0f;           // Enemy's Start Position
float fEnemyY = 8.0f;
float fEnemySpeed = 1.0f;       // Enemy's Chasing Speed

float fExitX = 14.0f;
float fExitY = 15.0f;


void ShowMainMenu() {
    system("cls");
    cout << "\t\t========================================\n";
    std::cout << R"(
           ___________  ___________  ___________  __________  
          ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦ 
          ¦¦¦¯¯¯¯¯¯¯¯¯ ¦¦¦¯¯¯¯¯¯¯¦¦¦¦¦¦¯¯¯¯¯¯¯¯¯ ¦¦¦¯¯¯¯¯¯¯¦¦¦
          ¦¦¦          ¦¦¦       ¦¦¦¦¦¦          ¦¦¦       ¦¦¦
          ¦¦¦_________ ¦¦¦_______¦¦¦¦¦¦_________ ¦¦¦       ¦¦¦
          ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦       ¦¦¦
          ¦¦¦¯¯¯¯¯¯¯¯¯ ¦¦¦¯¯¯¯¦¦¦¯¯ ¦¦¦¯¯¯¯¯¯¯¯¯ ¦¦¦       ¦¦¦
          ¦¦¦          ¦¦¦     ¦¦¦  ¦¦¦          ¦¦¦       ¦¦¦
          ¦¦¦          ¦¦¦      ¦¦¦ ¦¦¦_________ ¦¦¦_______¦¦¦
          ¦¦¦          ¦¦¦       ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦ 
           ¯            ¯         ¯  ¯¯¯¯¯¯¯¯¯¯¯  ¯¯¯¯¯¯¯¯¯¯ 
	)" << '\n'; 
	
    cout << "\t\tNOTE: This Bot is still on Development";
    cout << "\n\t\tVersion: BETA 2.0 - Game by Lance Grant Haboc\n";
	
    cout << "\t\t========================================\n";
    cout << "\t\t1. Start Game\n";
    cout << "\t\t2. Quit\n";
    cout << "\t\t========================================\n";
    cout << "\t\tEnter your choice: ";

}

void ShowCutscene() {
    system("cls");
    std::cout << R"(
        _____       
       /       \\     
      |  O   O  |    Hello Iam Fred your Virtual Best Friend.
      |    ^    |    Nice to meet you!
      |  \\_/   |    
      \\_______/     
        /     \\      
       /       \\     
      /  |   |  \\    
     /   |   |   \\   
    /    |   |    \\  \
   /     |   |     \\ 
  /______|___|______\\\
	)" << '\n'; 
	
	PlaySound(TEXT("V1.wav"), NULL, SND_ASYNC);
	cout << "\n\tPRESS ENTER...\n";
    cin.ignore();
    cin.get();
}

void ShowCutscene1() {
    system("cls");
    std::cout << R"(
        _____       
       /       \\     
      |  O   O  |    I wanna play a game...
      |    ^    |    Are you ready?
      |  \\_/   |    
      \\_______/     
        /     \\      
       /       \\     
      /  |   |  \\    
     /   |   |   \\   
    /    |   |    \\  \
   /     |   |     \\ 
  /______|___|______\\\
	)" << '\n'; 
	
	PlaySound(TEXT("V2.wav"), NULL, SND_ASYNC);
	cout << "\n\tPRESS ENTER...\n";
    cin.get();
}

void ShowCutscene2() {
    system("cls");
    cout << "\n";
    cout << "\t\tYou are deep on your computer\n";
    cout << "\t\tin a dark maze disoriented\n";
    cout << "\t\tYou found a note.\n";
    cout << "\n";
    cout << "\n\tPress ENTER to continue...\n";
    mciSendString(TEXT("pause bgm"), NULL, 0, NULL);
    cin.get();
}

void ShowCutscene3() {
    system("cls");
    cout << "\n";
    cout << "\t\tWatch out.\n";
    cout << "\n";
    cout << "\t\t01000100 01001111 01001110 00100111 01010100 00100000\n";
    cout << "\n";
    cout << "\t\tIt's a seperate reality.\n";
    cout << "\n";
    cout << "\t\t01001100 01001111 01001111 01001011\n";
    cout << "\n";
    cout << "\t\tThe only me is me.\n";
    cout << "\n";
    cout << "\t\t01000001 01010100\n";
    cout << "\n";
    cout << "\t\tAre you sure the only you is you?\n";
    cout << "\n";
    cout << "\t\t01001000 01001001 01001101\n";
	cout << "\n";
	cout << "\t\tYou Read the Back of the note\n";
    cout << "\n\tPress ENTER to continue...\n";
    cin.get();
}

void ShowCutscene4() {
    system("cls");
    cout << "\n";
    cout << "\t\tLEAVE WHILE YOU STILL CAN.\n";
    cout << "\n\t\t(Press W, A, S, D to Move)\n";
    cout << "\n";
    cout << "\n\tPress ENTER to continue...\n";
    PlaySound(TEXT("scawry.wav"), NULL, SND_ASYNC);
    cin.get();
}


    bool bJumpscarePlayed = false;

int main()
{
	//Play Background Sound
	mciSendString(TEXT("open \"song.wav\" type mpegvideo alias bgm"), NULL, 0, NULL);
	mciSendString(TEXT("play bgm repeat"), NULL, 0, NULL);
	
	// Main Menu Logic
    int choice = 0;
    while (choice != 1) {
        ShowMainMenu();
        cin >> choice;
        if (choice == 2) {
            cout << "\nExiting the game. Goodbye!\n";
            PlaySound(NULL, NULL, 0); // Stop playing sound
            return 0;
        } else if (choice != 1) {
            cout << "\nInvalid choice. Please try again.\n";
            Sleep(1000);
        }
    }

    // Show Cutscene
    ShowCutscene();
	system("cls");
	ShowCutscene1();
	system("cls");
	ShowCutscene2();
	system("cls");
	ShowCutscene3();
	system("cls");
	ShowCutscene4();
	
	system("cls");	
    // Create Screen Buffer
    wchar_t *screen = new wchar_t[nScreenWidth * nScreenHeight];
    HANDLE hConsole = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    SetConsoleActiveScreenBuffer(hConsole);
    DWORD dwBytesWritten = 0;

    // Map of maze # = wall block, . = space, E = exit
  wstring map;
    map += L"##############E#";
    map += L"#.......#......#";
    map += L"#..########.####";
    map += L"#..............#";
    map += L"#..#...##......#";
    map += L"#..#...##......#";
    map += L"#..#...........#";
    map += L"####.....#.....#";
    map += L"##.......#.....#";
    map += L"#...#######..###";
    map += L"#......#.......#";
    map += L"#......#.......#";
    map += L"#..............#";
    map += L"#.##############";
    map += L"#..............#";
    map += L"################";  // Exit marked by 'E'

    auto tp1 = chrono::system_clock::now();
    auto tp2 = chrono::system_clock::now();

 // Cooldown timer before enemy spawns
    auto enemySpawnStart = chrono::system_clock::now();
    bool bEnemySpawned = false;

    while (!bEnemySpawned) {
        auto currentTime = chrono::system_clock::now();
        chrono::duration<float> elapsedTime = currentTime - enemySpawnStart;

        if (elapsedTime.count() >= 6.0f) {
            bEnemySpawned = true;
        } else {

            Sleep(500); // Update every half-second for smoother countdown
        }
    }

    while (1)
    {
        // Timing
        tp2 = chrono::system_clock::now();
        chrono::duration<float> elapsedTime = tp2 - tp1;
        tp1 = tp2;
        float fElapsedTime = elapsedTime.count();

        // Player Controls
        if (GetAsyncKeyState((unsigned short)'A') & 0x8000)
            fPlayerA -= (fSpeed * 0.75f) * fElapsedTime;
        if (GetAsyncKeyState((unsigned short)'D') & 0x8000)
            fPlayerA += (fSpeed * 0.75f) * fElapsedTime;

        // Move Player
        float fNewPlayerX = fPlayerX;
        float fNewPlayerY = fPlayerY;

        if (GetAsyncKeyState((unsigned short)'W') & 0x8000)
        {
            fNewPlayerX += sinf(fPlayerA) * fSpeed * fElapsedTime;
            fNewPlayerY += cosf(fPlayerA) * fSpeed * fElapsedTime;
        }
        if (GetAsyncKeyState((unsigned short)'S') & 0x8000)
        {
            fNewPlayerX -= sinf(fPlayerA) * fSpeed * fElapsedTime;
            fNewPlayerY -= cosf(fPlayerA) * fSpeed * fElapsedTime;
        }

        // Collision Detection
        if (map[(int)fNewPlayerY * nMapWidth + (int)fNewPlayerX] != '#')
        {
            fPlayerX = fNewPlayerX;
            fPlayerY = fNewPlayerY;
        }

        // Check if Player has reached the Exit
        if (map[(int)fPlayerY * nMapWidth + (int)fPlayerX] == 'E')
        {
        	system("cls"); 
            cout << endl << "\t\tYOU FOUND THE EXIT! YOU ESCAPED FRED!!!!...";
            cout << endl << "\n";
            cout << endl << "\n\t\tPress ENTER to continue...";
                cin.ignore();
                cin.get();
            break; // Exit the game after winning
        }


        // Enemy Movement (Simple Chase Logic)
        float fDistX = fPlayerX - fEnemyX;
        float fDistY = fPlayerY - fEnemyY;
        float fDistance = sqrt(fDistX * fDistX + fDistY * fDistY);

        if (fDistance > 0.5f) // Chase player if far enough
        {
            fEnemyX += (fDistX / fDistance) * fEnemySpeed * fElapsedTime;
            fEnemyY += (fDistY / fDistance) * fEnemySpeed * fElapsedTime;

            // Prevent enemy from going through walls
            if (map[(int)fEnemyY * nMapWidth + (int)fEnemyX] == '#')
            {
                fEnemyX -= (fDistX / fDistance) * fEnemySpeed * fElapsedTime;
                fEnemyY -= (fDistY / fDistance) * fEnemySpeed * fElapsedTime;
            }
        }
        else
        {
            // Player caught by the enemy, Game Over
            system("cls");
            cout << endl << "\t\tGAME OVER, FRED CORRUPTED YOU...";
            cout << endl << "\n";
            cout << endl << "\n\t\tPress ENTER to continue...";
                cin.ignore();
                cin.get();
            break;
        }
        
        // Ray-casting & Rendering
        for (int x = 0; x < nScreenWidth; x++)
        {
            float fRayAngle = (fPlayerA - fFOV / 2.0f) + ((float)x / (float)nScreenWidth) * fFOV;
            float fStepSize = 0.1f;
            float fDistanceToWall = 0.0f;
            
            bool bHitWall = false;
            bool bBoundary = false;	
            bool bHitEnemy = false;  // Add a flag for enemy detection

            float fEyeX = sinf(fRayAngle);
            float fEyeY = cosf(fRayAngle);
        

 while (!bHitWall && fDistanceToWall < fDepth)
{
   
    fDistanceToWall += fStepSize;
    int nTestX = (int)(fPlayerX + fEyeX * fDistanceToWall);
    int nTestY = (int)(fPlayerY + fEyeY * fDistanceToWall);

    // Check if out of bounds
    if (nTestX < 0 || nTestX >= nMapWidth || nTestY < 0 || nTestY >= nMapHeight)
    {
        bHitWall = true;
        fDistanceToWall = fDepth;
    }
    else if (map.c_str()[nTestY * nMapWidth + nTestX] == '#')
    {
        	// Ray has hit wall
						bHitWall = true;

						vector<pair<float, float>> p;

						// Test each corner of hit tile, storing the distance from
						// the player, and the calculated dot product of the two rays
						for (int tx = 0; tx < 2; tx++)
							for (int ty = 0; ty < 2; ty++)
							{
								// Angle of corner to eye
								float vy = (float)nTestY + ty - fPlayerY;
								float vx = (float)nTestX + tx - fPlayerX;
								float d = sqrt(vx*vx + vy*vy); 
								float dot = (fEyeX * vx / d) + (fEyeY * vy / d);
								p.push_back(make_pair(d, dot));
							} 
						// Sort Pairs from closest to farthest
						sort(p.begin(), p.end(), [](const pair<float, float> &left, const pair<float, float> &right) {return left.first < right.first; });
						
						// First two/three are closest (we will never see all four)
						float fBound = 0.01;
						if (acos(p.at(0).second) < fBound) bBoundary = true;
						if (acos(p.at(1).second) < fBound) bBoundary = true;
						if (acos(p.at(2).second) < fBound) bBoundary = true;
					}
// Check for enemy detection
	else if (!bHitWall && 
         fabs(fEnemyX - (fPlayerX + fEyeX * fDistanceToWall)) < 0.5f &&
         fabs(fEnemyY - (fPlayerY + fEyeY * fDistanceToWall)) < 0.5f)
{
    bHitEnemy = true;

 // Jumpscare and Music Management
        float fDistX = fPlayerX - fEnemyX;
        float fDistY = fPlayerY - fEnemyY;
        float fDistance = sqrt(fDistX * fDistX + fDistY * fDistY);

        if (fDistance < 3.0f) // Enemy is close
        {
            if (!bJumpscarePlayed)
            {
  		// Play jumpscare music
        PlaySound(TEXT("sare.wav"), NULL, SND_ASYNC);
        bJumpscarePlayed = true;

        // Stop background music
        //mciSendString(TEXT("pause bgm"), NULL, 0, NULL);
            }
        }
        else
        {
            if (bJumpscarePlayed)
            {
		PlaySound(NULL, NULL, 0); // Stop jumpscare sound
        bJumpscarePlayed = false;

        // Resume background music
        //mciSendString(TEXT("resume bgm"), NULL, 0, NULL);
            }
        }

}
}


            // Calculate ceiling and floor heights
            int nCeiling = (float)(nScreenHeight / 2.0) - nScreenHeight / ((float)fDistanceToWall);
            int nFloor = nScreenHeight - nCeiling;
            

// Scary Character ASCII Art
wstring enemyArt = 
L"      _____       \n"
L"     /       \\     \n"
L"    |  O   O  |    \n"
L"    |    ^    |    \n"
L"    |  \\_/   |    \n"
L"     \\_______/     \n"
L"      /     \\      \n"
L"     /       \\     \n"
L"    /  |   |  \\    \n"
L"   /   |   |   \\   \n"
L"  /    |   |    \\  \n"
L" /     |   |     \\ \n"
L"/______|___|______\\\n";

// Enemy 2D position and size (projected on the screen)
float fEnemyScreenX = nScreenWidth / 2; // Center of the screen
float fEnemyScreenY = nScreenHeight / 2; // Middle height
int enemyArtWidth = 20;  // Approximate width of the ASCII art
int enemyArtHeight = 13; // Approximate height of the ASCII art

short nShade = ' ';
if (bHitEnemy)
{
    for (int ey = 0; ey < enemyArtHeight; ey++) // Loop through enemy art rows
    {
        for (int ex = 0; ex < enemyArtWidth; ex++) // Loop through enemy art columns
        {
            // Calculate screen position
            int screenX = fEnemyScreenX + ex - enemyArtWidth / 2;
            int screenY = fEnemyScreenY + ey - enemyArtHeight / 2;

            // Check screen bounds
            if (screenX >= 0 && screenX < nScreenWidth && screenY >= 0 && screenY < nScreenHeight)
            {
                // Get character from enemyArt and render to the screen
                int enemyArtIndex = ey * enemyArtWidth + ex;
                if (enemyArtIndex < enemyArt.size())
                {
                    screen[screenY * nScreenWidth + screenX] = enemyArt[enemyArtIndex];
                    
                }
            }
        }
    }
}
else
{
    // Handle regular wall shading
    if (fDistanceToWall <= fDepth / 4.0f)
        nShade = 0x2588; // Full block
    else if (fDistanceToWall < fDepth / 3.0f)
        nShade = 0x2593; // Darker block
    else if (fDistanceToWall < fDepth / 2.0f)
        nShade = 0x2592; // Medium block
    else if (fDistanceToWall < fDepth)
        nShade = 0x2591; // Light block
    else
        nShade = ' ';

        if (bBoundary)		nShade = ' ';

    for (int y = 0; y < nScreenHeight; y++)
    {
        if (y <= nCeiling)
            screen[y * nScreenWidth + x] = ' ';
        else if (y > nCeiling && y <= nFloor)
            screen[y * nScreenWidth + x] = nShade;
        else
            screen[y * nScreenWidth + x] = '.';
    }
}
}

     // Calculate enemy's direction relative to player
	float fAngleToEnemy = atan2(fEnemyY - fPlayerY, fEnemyX - fPlayerX);
	float fRelativeAngle = fAngleToEnemy - fPlayerA;
	if (fRelativeAngle < -3.14159f) fRelativeAngle += 2.0f * 3.14159f;
	if (fRelativeAngle > 3.14159f) fRelativeAngle -= 2.0f * 3.14159f;

	wstring sDirectionMessage;
	if (fDistance < 3.0f) // Only show direction if enemy is close
	{
    if (fRelativeAngle < -3.0f * 3.14159f / 4.0f || fRelativeAngle > 3.0f * 3.14159f / 4.0f)
        sDirectionMessage = L"RUN AWAY DON'T LOOK RUN AWAY DON'T LOOK RUN AWAY DON'T LOOK";
    else if (fRelativeAngle < -3.14159f / 4.0f)
    
        sDirectionMessage = L"HE'S NEAR HE'S NEAR HE'S NEAR HE'S NEAR HE'S NEAR HE'S NEAR HE'S NEAR";
    else if (fRelativeAngle > 3.14159f / 4.0f)
        sDirectionMessage = L"HE'S NEAR HE'S NEAR HE'S NEAR HE'S NEAR HE'S NEAR HE'S NEAR HE'S NEAR HE'S NEAR";
    else
        sDirectionMessage = L"RUN AWAY RUN AWAY RUN AWAY RUN AWAY RUN AWAY RUN AWAY";
		}

	// Display direction message if enemy is close
		swprintf(screen + 0 * nScreenWidth, nScreenWidth, sDirectionMessage.c_str());

        // Display the frame
        screen[nScreenWidth * nScreenHeight - 1] = '\0';
        WriteConsoleOutputCharacterW(hConsole, screen, nScreenWidth * nScreenHeight, { 0, 0 }, &dwBytesWritten);
    }

    // Clean up and end   
	mciSendString(TEXT("stop bgm"), NULL, 0, NULL); // Stop background music
	mciSendString(TEXT("close bgm"), NULL, 0, NULL);
    CloseHandle(hConsole);
    delete[] screen;
    return 0;
}


/* 

	DEV LOG:

	Prototype 0
	- Created Map
	- Added Enemy entity and Player
	- Created Coordinate System
	- Considered player going out of bounds

	Prototype 1
	- Added Warning Messages
	- Added an Enemy Sprite

	ALPHA 0
	- Titled the Project as "FRED"
	- Added new enemy sprite
	- Fixed the exits
	- Changed and Fixed Warning Messages
	- Added Winning and Loosing Messages
	
	ALPHA 1.0
	- Added Menu
	- Added Opening Cutscene
	- Fixed Opening Cutscene bug staying in Winning and Loosing Messages
	
	ALPHA 1.1
	- Added Lore
	
	BETA 0
	- Testing Starts
	- Buffed the map
	
	BETA 1.0
	- Nerfed the map
	- Added Jumpscare Sounds
	- Added pillar outlines
	
	BETA 2.0
	- Added Lore
	- Cutscenes
	- Fixed Issue with Environment

*/
