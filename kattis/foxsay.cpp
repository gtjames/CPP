#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <set>

using namespace std;

/*
    The Problem:
        We are documenting the sounds made by a fox
    STEP 1:
        To do so we record all of the sounds of the jungle
            HOWTO:  Read a file of all sounds
                    Break the recording into individual sounds
                    What is the eaaiest and the hardest way to do this?
    STEP 2:
        Fortuanately we know the sounds made by all of the other animals in the jungle
        We can a catelog those sounds to eliminate them from our recording of the jungle sounds.
            HOWTO:  Read the lines of the animal sounds
                    We only need one instance of each sound
                    Store those sounds in a WHAT?
                    What do we need and what is unnecessary to store?
                    How do we know when we have reached the end of the animal sounds?
    STEP 3:
        Scan the jungle sounds and detect known sounds vs. unknown sounds (which must be the sounds of the fox)
        HOWTO:  Do we remove them from the original recording?
                Or do we create a new object to store the sounds of the fox?
                Or do we just print the sounds of the fox as we find them?
*/
int main()
{
    int t;
    cin >> t;     //  get the first token.
                  //  This is expected to be the number of test cases.
                  //  We will loop through each test case and solve it.
    cin.ignore(); //  why are we doing this?
                  //  We need to ignore the newline character after the number of test cases.
                  //  otherwise the first call to getline() will read an empty line.
                  //  getline() just reads up the next new line character.
    while (t--)
    {
        string recording;
        getline(cin, recording); //  read the entire line of the recording.
                                 //  This is the sounds of the jungle.
                                 //  our first challenge is to break the recording into individual sounds
        vector<string> sounds;
        string sound;
        //  STEP 1: break the recording into individual sounds.
        //  what ho! a new object! stringstream! What does it do?
        //  A stringstream allows us to treat a string like a stream (like cin).
        //  we treat the string just as if we were reading for cin or a file.
        stringstream recStream(recording);

        while (recStream >> sound)
        {                            //  read each sound from the recording
            sounds.push_back(sound); //  add the sound to our vector of sounds
        }

        // STEP 2: read the known animal sounds and store them in a set. It only keeps one copy of each sound.
        set<string> knownSounds;

        string line;
        while (getline(cin, line))
        { //  read each line.
            if (line == "what does the fox say?")
            {          //  if we found this text
                break; //  we have reached the end of the known animal sounds.
            }

            string animal, goes, animalSound;
            stringstream lineStream(line);               //  Read the line which contains animal goes sound.
            lineStream >> animal >> goes >> animalSound; //  see how easy stringstream allows us to parse the line?

            knownSounds.insert(animalSound); //  We can toss away the animal and goes, we only care about the sound.
        }

        //  STEP 3: look at each sound in the recording and see if it is a known animal sound.
        bool first = true;
        //  sounds is the sounds of the jungle.
        //  we will look at each sound and see if it is a known animal sound
        for (const string &s : sounds)
        {
            //  Is the jungle sound in the Vector of known animal sounds?
            if (knownSounds.find(s) == knownSounds.end())
            {
                //  If we are here we didn't find this sound in the known animal sounds
                if (!first)
                { //  Why are we doing this check?
                    //  Good: "wa pa pa pa pa pa pow"
                    //   Bad: " wa pa pa pa pa pa pow" (notice the leading space)
                    cout << " "; //  We don't want to print a leading space before the first sound.
                }
                cout << s;     //  print this sound not found in the known animal sounds
                first = false; //  After this point we do want to print a space beforeo the sound.
            }
        }
        cout << endl;
    }

    return 0;
}